#include "clang-tidy/ClangTidyCheck.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/Basic/ExceptionSpecificationType.h"

using namespace clang::ast_matchers;

namespace clang
{
namespace tidy
{
namespace zipview
{

class NoexceptThrowCheck : public ClangTidyCheck
{
public:
  NoexceptThrowCheck(StringRef Name, ClangTidyContext* Context) : ClangTidyCheck(Name, Context) {}
  void registerMatchers(ast_matchers::MatchFinder* Finder) override
  {
    Finder->addMatcher(cxxThrowExpr().bind("throw"), this);
  }
  void check(const MatchFinder::MatchResult& Result) override
  {
    const auto* T = Result.Nodes.getNodeAs<clang::CXXThrowExpr>("throw");
    if (!T) return;
    // Find the enclosing function (semantic parent)
    auto Parents = Result.Context->getParents(*T);
    for (const auto& P : Parents)
    {
      if (const auto* FD = P.get<clang::FunctionDecl>())
      {
        if (clang::isNoexceptExceptionSpec(FD->getExceptionSpecType()))
        {
          diag(T->getExprLoc(), "throw in noexcept function detected — check exception-safety");
        }
        break;
      }
    }
  }
};

} // namespace zipview
} // namespace tidy
} // namespace clang

// Registration is handled by the ZipView module in RegisterZipViewChecks.cpp
