#pragma once

#include <windows.h>
#include <cstdint>
#include <map>

#include "proto.h"
#include <kthook/kthook.hpp>


class c_entry {

public:
	
	c_entry();
	~c_entry();

	//std::unique_ptr<cyanide::polyhook_x86<destroy_ri_t, decltype(&destroy_rakclient_interface)>> destroy_ri_hook;
	
	std::unique_ptr<kthook::kthook_simple<prototype::void_t>> test_hook { };

	kthook::kthook_simple<prototype::void_t> ctimer_hook { reinterpret_cast<void*>(0x561B10) };
	void update(const decltype(ctimer_hook)& hook);

} _entry;