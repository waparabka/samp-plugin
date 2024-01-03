#pragma once

#include <stdint.h>
#include <set>
#include <vector>
#include <sampapi/CVector.h>
#include <RakNet/BitStream.h>
#include <RakHook/rakhook.hpp>
#include "config.h"


class InStreamPlayer {
	
public:
	struct world_player_add_s {
		uint16_t player_id;
		uint8_t team;
		uint32_t skinid;
		float x, y, z, fa;
		uint32_t color;
		uint8_t fstyle;
		uint16_t skill;
	};

	bool is_contains(uint16_t player_id);
	void add(world_player_add_s world_player);
	void remove(uint16_t player_id);
	void create(world_player_add_s world_player);
	bool should_be_deleted(uint16_t player_id);
	bool is_afk(uint16_t player_id);
	void process();
	world_player_add_s get_updated(uint16_t player_id, sampapi::CVector position);
	world_player_add_s get(uint16_t player_id);

	std::set<uint16_t>::iterator begin();
	std::set<uint16_t>::iterator end();

private:
	std::vector<world_player_add_s> players;
	std::set<uint16_t> players_iterator;

	Config* config = Config::Get();
};