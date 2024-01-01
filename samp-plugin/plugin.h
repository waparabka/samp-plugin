#pragma once

#include <kthook/kthook.hpp>
#include <RakHook/rakhook.hpp>
#include <RakNet/BitStream.h>
#include <RakNet/PacketEnumerations.h>
#include "plugin_render.h"

using gameloop_t = void(__cdecl*)();


class Plugin {

public:
	Plugin(HMODULE handle);
	HMODULE module_handle;

private:
	bool inited;
	PluginRender render;
	
	kthook::kthook_simple<gameloop_t> hook_gameloop { reinterpret_cast<void*>(0x561B10) };
	void gameloop(const decltype(hook_gameloop)& hook);
	

	template <typename T>
	std::string read_with_size(RakNet::BitStream& bs) {
		T size;
		if (!bs.Read(size) || size <= 0)
			return {};
		std::string str(size, '\0');
		bs.Read(str.data(), size);
		return str;
	}
	template <typename T>
	void write_with_size(RakNet::BitStream& bs, std::string_view str) {
		T size = static_cast<T>(str.size());
		bs.Write(size);
		bs.Write(str.data(), size);
	}

	bool on_receive_rpc(unsigned char& id, RakNet::BitStream* bs);
	bool on_receive_packet(Packet* packet);
	

	struct world_player_add_s {
		uint16_t playerid;
		uint8_t team;
		uint32_t skinid;
		float x, y, z, fa;
		uint32_t color;
		uint8_t fstyle;
		uint16_t skill;
	};

	std::vector<world_player_add_s> in_stream_players{ };
};