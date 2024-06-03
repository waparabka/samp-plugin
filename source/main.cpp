#include "main.h"
#include <sampapi/CChat.h>
#include <sampapi/CInput.h>
#include <RakHook/rakhook.hpp>

namespace samp = sampapi::v037r3;


c_entry::c_entry() {
    
#ifdef _DEBUG
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
    
    printf("ctor");
#endif

    using namespace std::placeholders;
    
    ctimer_hook.set_cb(std::bind(&c_entry::update, this, _1));
    ctimer_hook.install();
}


void c_entry::update(const decltype(ctimer_hook)& hook) {

    static bool inited = false;

    if (!inited && samp::RefChat() != nullptr && rakhook::initialize()) {
        
        samp::RefChat()->AddMessage(-1, "samp-plugin works");

        rakhook::on_receive_rpc += [](unsigned char& id, RakNet::BitStream* bs) {
            
            if (id == 93) { // scr_ClientMessage
                
                bs->IgnoreBits(32);

                uint32_t length;
                bs->Read(length);

                std::string text(length, '\0');
                bs->Read(text.data(), length);
                
                samp::RefChat()->AddMessage(-1, std::string("[HK] " + text).c_str());

                return false;
            }

            return true;
        };
        
        inited = true;
    }

    return hook.get_trampoline()();
}


c_entry::~c_entry() {

    ctimer_hook.remove();
	
#ifdef _DEBUG
    printf("dctor");
	FreeConsole();
#endif
}