#include "clang-tidy/ClangTidyCheck.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang
{
namespace tidy
{
namespace zipview
{

class RttiCheck : public ClangTidyCheck
{
public:
  RttiCheck(StringRef Name, ClangTidyContext* Context) : ClangTidyCheck(Name, Context) {}
  void registerMatchers(ast_matchers::MatchFinder* Finder) override
  {
    Finder->addMatcher(cxxDynamicCastExpr().bind("dyn"), this);
  }
  void check(const MatchFinder::MatchResult& Result) override
  {
    if (const auto* D = Result.Nodes.getNodeAs<clang::CXXDynamicCastExpr>("dyn"))
    {
      diag(D->getExprLoc(),
           "dynamic_cast used — runtime polymorphism is forbidden by project policy");
    }
  }
};

} // namespace zipview
} // namespace tidy
} // namespace clang

// Registration is handled by the ZipView module in RegisterZipViewChecks.cpp
