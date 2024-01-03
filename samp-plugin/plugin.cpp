#include "plugin.h"

PluginGUI* GUI = nullptr;


Plugin::Plugin(HMODULE handle) : module_handle(handle), inited(false), render() {
    
    using namespace std::placeholders;

    hook_gameloop.set_cb(std::bind(&Plugin::gameloop, this, _1));
    hook_gameloop.install();
}


bool Plugin::on_receive_rpc(unsigned char& id, RakNet::BitStream* bs) {
    
    if (id == 32) {

        InStreamPlayer::world_player_add_s in_stream_player = { 0 };
        bs->Read((char*)&in_stream_player, sizeof(InStreamPlayer::world_player_add_s));

        stream_players.add(in_stream_player);

        return false;
    }

    if (id == 163) {

        uint16_t player_id;
        bs->Read(player_id);

        stream_players.remove(player_id);
    }

    return true;
}


bool Plugin::on_receive_packet(Packet* packet) {
    
    RakNet::BitStream bs(packet->data, packet->length, false);
    
    uint8_t packet_id;
    bs.Read(packet_id);


    if (packet_id == PacketEnumeration::ID_CONNECTION_REQUEST_ACCEPTED) {
        
        samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Загружен! Автор плагина : {6959ba}waparabka").c_str());
    }


    if (packet_id == PacketEnumeration::ID_BULLET_SYNC) {
        
        if (!config->config["config"]["misc"]["enable_friend_list"]["state"].get<bool>() || !config->config["config"]["misc"]["delete_friends_tracers"]["state"].get<bool>())
            return true;

        uint16_t player_id;
        bs.Read(player_id);
        
        if (!stream_players.is_contains(player_id))
            return true;

        samp::Synchronization::BulletData data = { 0 };

        bs.Read((char*)&data, sizeof(samp::Synchronization::BulletData));

        if (data.m_nTargetId == samp::RefNetGame()->GetPlayerPool()->m_localInfo.m_nId)
            return false;
    }


    if (packet_id == PacketEnumeration::ID_VEHICLE_SYNC) {
        
        if (config->config["config"]["fractions"]["all"]["state"].get<bool>())
            return true;


        if (!config->config["config"]["misc"]["not_delete_incar_players"]["state"].get<bool>() && !config->config["config"]["misc"]["not_delete_bobcat_players"]["state"].get<bool>())
            return true;

        uint16_t player_id;
        bs.Read(player_id);

        if (!stream_players.is_contains(player_id))
            return true;
        
        auto player = samp::RefNetGame()->GetPlayerPool()->GetPlayer(player_id);
        
        if (player->DoesExist())
            return true;

        stream_players.create(stream_players.get_updated(player_id, player->m_onfootData.m_position));
    }

    return true;
}


void Plugin::gameloop(const decltype(hook_gameloop)& hook) {

    static bool inited = false;
    
    if (!inited && samp::RefChat() != nullptr && rakhook::initialize()) {
        
        using namespace std::placeholders;

        GUI = &render.GUI;

        rakhook::on_receive_rpc += std::bind(&Plugin::on_receive_rpc, this, _1, _2);
        rakhook::on_receive_packet += std::bind(&Plugin::on_receive_packet, this, _1);

        samp::RefInputBox()->AddCommand("prmenu", [](const char* p) {
            
            GUI->menu_open = !GUI->menu_open;
        });

        inited = true;
    }
    else if (inited) {

        if (GUI->menu_open) {
            GUI->close_once = false;
            samp::RefInputBox()->Close();
            samp::RefGame()->SetCursorMode(samp::CURSOR_LOCKCAM, false);
        }
        else if (samp::RefGame()->m_nCursorMode == samp::CURSOR_LOCKCAM && !GUI->close_once) {
            GUI->close_once = true;
            samp::RefGame()->SetCursorMode(samp::CURSOR_NONE, true);
        }
        
        stream_players.process();
    }

    return hook.get_trampoline()();
}