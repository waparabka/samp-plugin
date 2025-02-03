#ifndef PLUGIN_HPP
#define PLUGIN_HPP

#include <windows.h>

#include <kthook/kthook.hpp>
#include <RakHook/rakhook.hpp>

#include "samp.hpp"


class c_plugin {

public:
	c_plugin();
	~c_plugin();
	
	kthook::kthook_simple<void(__cdecl*)()> update_hook { reinterpret_cast<void*>(0x561B10) };
	void update(const decltype(update_hook)& hook);
};


#endif // PLUGIN_HPP