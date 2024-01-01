#pragma once

#include <stdint.h>
#include <set>
#include <vector>
#include <sampapi/CVector.h>


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
	void add(world_player_add_s player);
	void remove(uint16_t player_id);
	world_player_add_s get_updated(uint16_t player_id, sampapi::CVector position);

	std::set<uint16_t>::iterator begin();
	std::set<uint16_t>::iterator end();

private:
	std::vector<world_player_add_s> players;
	std::set<uint16_t> players_iterator;
};