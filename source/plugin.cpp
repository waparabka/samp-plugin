#include "plugin.hpp"

using namespace std::placeholders;


c_plugin::c_plugin() {

    update_hook.set_cb(std::bind(&c_plugin::update, this, _1));
    update_hook.install();
}


void c_plugin::update(const decltype(update_hook)& hook) {

    static bool initialized = false;
    
    if (!initialized && c_chat().reference() != nullptr && rakhook::initialize()) {
        
        c_chat().reference()->add_message(-1, "samp plugin initialized");

        initialized = true;
    }
    return hook.call_trampoline();
}


c_plugin::~c_plugin() {

    update_hook.remove();

    rakhook::destroy();
}