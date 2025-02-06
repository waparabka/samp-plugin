#include "plugin.hpp"


void c_plugin::update(const decltype(update_hook)& hook) {

    static bool initialized = false;
    
    if (!initialized && c_chat().reference() != nullptr && rakhook::initialize()) {
        
        c_chat().reference()->add_message(-1, "samp plugin initialized");

        initialized = true;
    }
    return hook.call_trampoline();
}
