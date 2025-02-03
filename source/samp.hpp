#ifndef SAMP_HPP
#define SAMP_HPP

#include <RakHook/detail.hpp>
#include "offsets.hpp"

#define VERSION rakhook::detail::to_underlying(rakhook::samp_version())


class c_chat {
	
public:
	c_chat*& reference() {
		return *(c_chat**)rakhook::samp_addr(offsets::chat::reference[VERSION]);
	}
	
	void add_message(unsigned long color, const char* text) {
		((void(__thiscall*)(c_chat*, unsigned long, const char*))rakhook::samp_addr(offsets::chat::add_message[VERSION]))(this, color, text);
	}
};


#undef VERSION

#endif // SAMP_HPP
