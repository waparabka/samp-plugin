#include "plugin.h"
#include <sampapi/CChat.h>
#include <sampapi/CInput.h>
#include <sampapi/CGame.h>
#include <sampapi/CNetGame.h>

namespace samp = sampapi::v037r1;

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
    }

    if (id == 163) {
        
        uint16_t player_id;
        bs->Read(player_id);

        stream_players.remove(player_id);
    }

    return true;
}


bool Plugin::on_receive_packet(Packet* packet) {

    if (!GUI->config["config"]["misc"]["delete_friends_tracers"]["state"].get<bool>())
        return true;


    RakNet::BitStream bs(packet->data, packet->length, false);

    uint8_t packet_id;
    bs.Read(packet_id);

    if (packet_id == PacketEnumeration::ID_BULLET_SYNC) {

        samp::Synchronization::BulletData data = { 0 };

        bs.Read((char*)&data, sizeof(samp::Synchronization::BulletData));

        if (data.m_nTargetId == samp::RefNetGame()->GetPlayerPool()->m_localInfo.m_nId)
            return false;
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


        samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Загружен! Автор плагина : {6959ba}waparabka").c_str());
        
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


        for (const auto& [key, val] : GUI->config["config"]["fractions"].items()) {

            for (const auto& [key_2, val_2] : val.items()) {

                for (auto it = stream_players.begin(); it != stream_players.end(); it++) {
                    
                    auto player = samp::RefNetGame()->GetPlayerPool()->GetPlayer(*it);
                    
                    if (!player) {

                        stream_players.remove(*it);
                        it = stream_players.begin();

                        continue;
                    }
                    

                    if (GUI->config["config"]["misc"]["not_delete_incar_players"]["state"].get<bool>()) {

                        auto vehicle = player->m_pVehicle;

                        if (vehicle && vehicle->DoesExist())
                            continue;
                    }


                    if (GUI->config["config"]["misc"]["not_delete_bobcat_players"]["state"].get<bool>()) {

                        bool is_bobcat = false;

                        for (auto const& [key_3, val_3] : GUI->config["bobcats"].items()) {

                            auto vehicle = player->m_pVehicle;

                            if (!vehicle || !vehicle->DoesExist())
                                break;

                            if (vehicle->GetModelIndex() == val_3) {
                                is_bobcat = true;
                                break;
                            }
                        }

                        if (is_bobcat)
                            continue;
                    }


                    if (GUI->config["config"]["misc"]["enable_friend_list"]["state"].get<bool>()) {

                        std::string name = samp::RefNetGame()->GetPlayerPool()->GetName(*it);

                        bool is_friend = false;

                        for (auto const& [key_3, val_3] : GUI->config["friends"].items())
                            if (key_3 == name) {
                                is_friend = true; break; }

                        if (is_friend)
                            continue;
                    }

                    std::stringstream color;
                    color << std::hex << std::uppercase << player->GetColorAsARGB();

                    std::string player_color = GUI->config["fractions"][key]["color"].get<std::string>();

                    if (val_2) {

                        if (player->DoesExist() && player_color == color.str())
                            player->Remove();
                    }
                    else {

                        if (!player->DoesExist() && player_color == color.str()) {

                            RakNet::BitStream bs { };

                            auto add_player = stream_players.get_updated(*it, player->m_onfootData.m_position);
                            bs.Write((char*)&add_player, sizeof(InStreamPlayer::world_player_add_s));

                            rakhook::emul_rpc(32, bs);
                        }
                    }
                }
            }
        }
    }

    return hook.get_trampoline()();
}