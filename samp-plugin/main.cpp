#include "plugin.h"
#include <memory>

std::unique_ptr<Plugin> plugin;


int __stdcall DllMain(HMODULE module_handle, DWORD reason, LPVOID reserved) {

    if (reason == DLL_PROCESS_ATTACH) {

        DisableThreadLibraryCalls(module_handle);
        
        plugin = std::make_unique<Plugin>(module_handle);
    }

    return TRUE;
}