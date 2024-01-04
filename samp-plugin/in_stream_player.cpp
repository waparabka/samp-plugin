#include "in_stream_player.h"


bool InStreamPlayer::is_contains(uint16_t player_id) {
	
	return players_iterator.find(player_id) != players_iterator.end();
}


void InStreamPlayer::add(world_player_add_s world_player) {

	if (!is_contains(world_player.player_id)) {
        
		players_iterator.insert(world_player.player_id);
		players.push_back(world_player);

        if (!should_be_deleted(world_player.player_id))
            create(world_player);
	}
}


void InStreamPlayer::remove(uint16_t player_id) {
	
	if (is_contains(player_id)) {

		players_iterator.erase(player_id);

		for (auto it = players.begin(); it != players.end(); it++)
			if (it->player_id == player_id) {
				players.erase(it); break; }

        auto player = samp::RefNetGame()->GetPlayerPool()->GetPlayer(player_id);

        if (!player)
            return;

        player->SetMarkerState(0);
	}
}


void InStreamPlayer::create(world_player_add_s world_player) {
    
    RakNet::BitStream bs { };
    
    bs.Write((char*)&world_player, sizeof(world_player_add_s));
    
    uint16_t skill[11] = { };
    std::fill_n(skill, 11, 1000);
    
    bs.Write((char*)&skill, sizeof(skill));

    rakhook::emul_rpc(32, bs);
}


void InStreamPlayer::clear() {

    players.clear();
    players_iterator.clear();
}


bool InStreamPlayer::should_be_deleted(uint16_t player_id) { // TODO : add skin's condition

    auto player = samp::RefNetGame()->GetPlayerPool()->GetPlayer(player_id);

    std::stringstream player_color;
    player_color << std::hex << std::uppercase << player->GetColorAsARGB();


    for (const auto& [key, val] : config->config["config"]["fractions"].items()) {
        
        for (const auto& [key_2, val_2] : val.items()) {
            
            if (config->config["config"]["fractions"]["all"]["state"].get<bool>())
                return true;
            

            if (config->config["config"]["misc"]["not_delete_incar_players"]["state"].get<bool>()) {

                auto vehicle = player->m_pVehicle;

                if (vehicle && vehicle->DoesExist())
                    return false;
            }

            
            if (config->config["config"]["misc"]["not_delete_bobcat_players"]["state"].get<bool>()) {

                bool is_bobcat = false;

                for (auto const& [key_3, val_3] : config->config["bobcats"].items()) {

                    auto vehicle = player->m_pVehicle;

                    if (!vehicle || !vehicle->DoesExist())
                        break;

                    if (vehicle->GetModelIndex() == val_3) {
                        is_bobcat = true; break; }
                }

                if (is_bobcat)
                    return false;
            }


            if (config->config["config"]["misc"]["enable_friend_list"]["state"].get<bool>()) {

                std::string name = samp::RefNetGame()->GetPlayerPool()->GetName(player_id);

                bool is_friend = false;

                for (auto const& [key_3, val_3] : config->config["friends"].items())
                    if (key_3 == name) {
                        is_friend = true; break; }

                if (is_friend)
                    return false;
            }
            

            std::string config_color = config->config["fractions"][key]["color"].get<std::string>();

            if (val_2 && player_color.str() == config_color)
                return true;
        }
    }
    
    return false;
}


bool InStreamPlayer::is_afk(uint16_t player_id) {

    auto player = samp::RefNetGame()->GetPlayerPool()->GetPlayer(player_id);

    if (!player)
        return true;

    return (player->m_lastUpdate < GetTickCount() - 2500);
}


void InStreamPlayer::process() {

    for (auto it = begin(); it != end(); it++) {

        auto player = samp::RefNetGame()->GetPlayerPool()->GetPlayer(*it);

        if (!player)
            continue;

        if (!is_afk(*it))
            update(*it);

        
        bool should_be_deleted = this->should_be_deleted(*it);
        
        if (should_be_deleted && player->DoesExist() ) {
            player->Remove();
        }
        else if (config->toggled && !player->DoesExist()) {
            create(get(*it));
        }
        
        
        if (config->config["config"]["misc"]["not_delete_markers"]["state"].get<bool>()) {
            
            if (player->DoesExist())
                continue;

            auto world_player = get(*it);
            
            player->SetMarkerPosition(world_player.x, world_player.y, world_player.z);
        }
        else if (config->toggled) {
            player->SetMarkerState(0);
        }
    }
    
    if (config->toggled)
        config->toggled = false;
}


InStreamPlayer::world_player_add_s InStreamPlayer::get(uint16_t player_id) {

    for (auto it = players.begin(); it != players.end(); it++)
        if (it->player_id == player_id)
            return *it;

    return { 0 };
}


void InStreamPlayer::update(uint16_t player_id) {

    auto player = samp::RefNetGame()->GetPlayerPool()->GetPlayer(player_id);

    if (!player)
        return;

	
	for (auto it = players.begin(); it != players.end(); it++) {

		if (it->player_id == player_id) {
            
            sampapi::CVector position = { };

            if (player->m_pVehicle)
                position = player->m_incarData.m_position;
            else if (player->m_nSeatId > 0)
                position = player->m_passengerData.m_position;
            else
                position = player->m_onfootData.m_position;
            

            world_player_add_s updated = *it;
            
			updated.x = position.x; updated.y = position.y; updated.z = position.z;

            players.erase(it);
            players.push_back(updated);

			break;
		}
	}
}


std::set<uint16_t>::iterator InStreamPlayer::begin() {

	return players_iterator.begin();
}


std::set<uint16_t>::iterator InStreamPlayer::end() {

	return players_iterator.end();
}