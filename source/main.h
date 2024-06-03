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

	kthook::kthook_simple<prototype::void_t> ctimer_hook { reinterpret_cast<void*>(0x561B10) };
	void update(const decltype(ctimer_hook)& hook);

} _entry;
