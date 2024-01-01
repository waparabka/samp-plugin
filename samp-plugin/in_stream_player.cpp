#include "in_stream_player.h"


bool InStreamPlayer::is_contains(uint16_t player_id) {
	
	return players_iterator.find(player_id) != players_iterator.end();
}


void InStreamPlayer::add(world_player_add_s player) {

	if (!is_contains(player.player_id)) {

		players_iterator.insert(player.player_id);
		players.push_back(player);
	}
}


void InStreamPlayer::remove(uint16_t player_id) {

	if (is_contains(player_id)) {

		players_iterator.erase(player_id);

		for (auto it = players.begin(); it != players.end(); it++)
			if (it->player_id == player_id) {
				players.erase(it); break; }
	}
}


InStreamPlayer::world_player_add_s InStreamPlayer::get_updated(uint16_t player_id, sampapi::CVector position) {
	
	world_player_add_s updated { };

	for (auto it = players.begin(); it != players.end(); it++) {

		if (it->player_id == player_id) {

			updated = *it;

			if (position.x == 0 && position.y == 0 && position.z == 0)
				break;
			
			updated.x = position.x; updated.y = position.y; updated.z = position.z;

			break;
		}
	}
	
	return updated;
}


std::set<uint16_t>::iterator InStreamPlayer::begin() {

	return players_iterator.begin();
}


std::set<uint16_t>::iterator InStreamPlayer::end() {

	return players_iterator.end();
}