#include "config.h"


Config::Config() {

    if (!std::filesystem::is_directory("prmenu"))
        std::filesystem::create_directory("prmenu");
    
    try {
        
        config_file.open("prmenu/default.json");
        config_default = json::parse(config_file);

        if (config_default["config"]["misc"].size() < 6)
            throw std::invalid_argument("bad size");
    }
    catch (...) {

        // generate config fields

        config_default["config"]["selected"] = "";

        config_default["config"]["fractions"]["all"]["state"] = false;

        config_default["config"]["misc"]["not_delete_markers"]["state"] = false;
        config_default["config"]["misc"]["not_delete_incar_players"]["state"] = false;
        config_default["config"]["misc"]["not_delete_bobcat_players"]["state"] = false;
        config_default["config"]["misc"]["instant_delete_dead_players"]["state"] = false;
        config_default["config"]["misc"]["enable_friend_list"]["state"] = true;
        config_default["config"]["misc"]["delete_friends_tracers"]["state"] = false;

        config_file.close();
    }
    
    save("default.json", config_default);
}


bool Config::load(std::string config_file) {

    try {
        
        std::ifstream f;

        f.open("prmenu/" + config_file);
        
        config = json::parse(f);

        f.close();
        
        for (const auto& [key, val] : config["config"]["fractions"].items()) {
            
            items.insert({ key, false });
            selected_item = key;
            config["config"]["fractions"][key]["state"] = false;
        }

        config_default["config"]["selected"] = config_file;
        save("default.json", config_default);
    }
    catch (...) { return false; }

    return true;
}


void Config::save(std::string config_file, json config) {

    std::ofstream ff;

    ff.open("prmenu/" + config_file);
    
    ff.flush();
    ff << config;

    ff.close();
}