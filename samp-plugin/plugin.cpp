#include "plugin.h"


Plugin::Plugin(HMODULE handle) : module_handle(handle) {
    
    using namespace std::placeholders;

    hook_gameloop.set_cb(std::bind(&Plugin::gameloop, this, _1));
    hook_gameloop.install();
}


void Plugin::gameloop(const decltype(hook_gameloop)& hook) {

    static bool inited = false;
    
    if (!inited && samp::RefChat() != nullptr && rakhook::initialize()) {
        
        using namespace std::placeholders;
        
        

        inited = true;
    }

    return hook.get_trampoline()();
}