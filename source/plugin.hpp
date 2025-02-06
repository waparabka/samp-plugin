#ifndef PLUGIN_HPP
#define PLUGIN_HPP

#include <windows.h>

#include <kthook/kthook.hpp>
#include <RakHook/rakhook.hpp>

#include "samp.hpp"

using namespace std::placeholders;


class c_plugin {

public:
	c_plugin() = default;
	~c_plugin() { rakhook::destroy(); };
	
	kthook::kthook_simple<void(__cdecl*)()> update_hook { reinterpret_cast<void*>(0x561B10), std::bind(&c_plugin::update, this, _1) };
	void update(const decltype(update_hook)& hook);
};


#endif // PLUGIN_HPP
