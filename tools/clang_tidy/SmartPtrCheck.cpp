#include "clang-tidy/ClangTidyCheck.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang
{
namespace tidy
{
namespace zipview
{

class SmartPtrCheck : public ClangTidyCheck
{
public:
  SmartPtrCheck(StringRef Name, ClangTidyContext* Context) : ClangTidyCheck(Name, Context) {}
  void registerMatchers(ast_matchers::MatchFinder* Finder) override
  {
    Finder->addMatcher(varDecl(hasType(recordDecl(hasName("std::unique_ptr")))).bind("uptr"), this);
    Finder->addMatcher(varDecl(hasType(recordDecl(hasName("std::shared_ptr")))).bind("sptr"), this);
  }
  void check(const MatchFinder::MatchResult& Result) override
  {
    if (const auto* U = Result.Nodes.getNodeAs<clang::VarDecl>("uptr"))
    {
      diag(
        U->getLocation(),
        "std::unique_ptr usage detected — ensure this does not allocate in view/iterator storage");
    }
    if (const auto* S = Result.Nodes.getNodeAs<clang::VarDecl>("sptr"))
    {
      diag(
        S->getLocation(),
        "std::shared_ptr usage detected — ensure this does not allocate in view/iterator storage");
    }
  }
};

} // namespace zipview
} // namespace tidy
} // namespace clang

// Registration is handled by the ZipView module in RegisterZipViewChecks.cpp
