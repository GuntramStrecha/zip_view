#include "clang-tidy/ClangTidy.h"
#include "clang-tidy/ClangTidyModule.h"
#include "clang-tidy/ClangTidyModuleRegistry.h"

// Include check implementations so the factory can construct them.
#include "NoVirtualCheck.cpp"
#include "NoexceptThrowCheck.cpp"
#include "RttiCheck.cpp"
#include "SmartPtrCheck.cpp"

namespace clang
{
namespace tidy
{
namespace zipview
{

// Forward declarations of checks (defined in separate translation units).
class NoVirtualCheck;
class RttiCheck;
class SmartPtrCheck;
class NoexceptThrowCheck;

class ZipViewModule : public ClangTidyModule
{
public:
  void addCheckFactories(ClangTidyCheckFactories& Factories) override
  {
    Factories.registerCheck<NoVirtualCheck>("zipview-no-virtual");
    Factories.registerCheck<RttiCheck>("zipview-no-rtti");
    Factories.registerCheck<SmartPtrCheck>("zipview-smartptr-usage");
    Factories.registerCheck<NoexceptThrowCheck>("zipview-noexcept-throw");
  }
};

// Register the ZipViewModule using this statically initialized variable.
static ClangTidyModuleRegistry::Add<ZipViewModule> X("zipview-module",
                                                     "Adds zip_view custom checks.");

} // namespace zipview
} // namespace tidy
} // namespace clang

// This anchor is used to force the linker to link in the generated object file
volatile int ZipViewModuleAnchorSource = 0;
