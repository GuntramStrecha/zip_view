#include "clang-tidy/ClangTidyCheck.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang
{
namespace tidy
{
namespace zipview
{

class NoVirtualCheck : public ClangTidyCheck
{
public:
  NoVirtualCheck(StringRef Name, ClangTidyContext* Context) : ClangTidyCheck(Name, Context) {}
  void registerMatchers(ast_matchers::MatchFinder* Finder) override
  {
    Finder->addMatcher(cxxMethodDecl(isVirtual()).bind("virt"), this);
  }
  void check(const MatchFinder::MatchResult& Result) override
  {
    const auto* M = Result.Nodes.getNodeAs<clang::CXXMethodDecl>("virt");
    if (!M) return;
    diag(M->getLocation(),
         "virtual method declared — project policy forbids virtual functions (use composition or "
         "templates)");
  }
};

} // namespace zipview
} // namespace tidy
} // namespace clang

// Registration is handled by the ZipView module in RegisterZipViewChecks.cpp
