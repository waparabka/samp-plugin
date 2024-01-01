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

        world_player_add_s in_stream_player = { 0 };
        bs->Read((char*)&in_stream_player, sizeof(world_player_add_s));

        in_stream_players.push_back(in_stream_player);
    }

    if (id == 163) {
        
        uint16_t playerid;
        bs->Read(playerid);

        std::vector<world_player_add_s> in_stream_players_updated{ };

        for (const auto& in_stream_player : in_stream_players)
            if (in_stream_player.playerid != playerid)
                in_stream_players_updated.push_back(in_stream_player);

        in_stream_players = in_stream_players_updated;
    }
    
    for (const auto& [key, val] : GUI->config["config"]["fractions"].items()) { // rework this shit later

        for (auto const& [key_2, val_2] : val.items()) {

            for (auto const& it : in_stream_players) {

                auto player = samp::RefNetGame()->GetPlayerPool()->GetPlayer(it.playerid);

                if (player == nullptr)
                    continue;
                
                
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

                    std::string name = samp::RefNetGame()->GetPlayerPool()->GetName(it.playerid);

                    bool is_friend = false;

                    for (auto const& [key_3, val_3] : GUI->config["friends"].items())
                        if (key_3 == name) {
                            is_friend = true;
                            break;
                        }

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

                        RakNet::BitStream bs{ };
                        
                        bs.Write((char*)&it, sizeof(world_player_add_s));

                        rakhook::emul_rpc(32, bs);
                    }
                }
            }
        }
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

        render.setup_d3d9_hooks();
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
    }

    return hook.get_trampoline()();
}