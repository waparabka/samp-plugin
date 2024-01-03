#include "config.h"


Config::Config() {

    try {

        config_file.open("prmenu.json");
        
        config = json::parse(config_file);
    }
    catch (json::parse_error& ex) {

        // generate config fields
        
        if (config["fractions"]["grove"]["color"].is_null())
            config["fractions"]["grove"]["color"] = "FF009F00";

        if (config["fractions"]["ballas"]["color"].is_null())
            config["fractions"]["ballas"]["color"] = "FFB313E7";

        if (config["fractions"]["rifa"]["color"].is_null())
            config["fractions"]["rifa"]["color"] = "FF2A9170";

        if (config["fractions"]["aztec"]["color"].is_null())
            config["fractions"]["aztec"]["color"] = "FF01FCFF";

        if (config["fractions"]["vagos"]["color"].is_null())
            config["fractions"]["vagos"]["color"] = "FFFFDE24";

        if (config["fractions"]["lcn"]["color"].is_null())
            config["fractions"]["lcn"]["color"] = "FFDDA701";

        if (config["fractions"]["yakuza"]["color"].is_null())
            config["fractions"]["yakuza"]["color"] = "FFFF0000";

        if (config["fractions"]["rm"]["color"].is_null())
            config["fractions"]["rm"]["color"] = "FF114D71";

        if (config["fractions"]["civil"]["color"].is_null())
            config["fractions"]["civil"]["color"] = "FFFFFFFF";

        if (config["bobcats"]["bobcat"].is_null())
            config["bobcats"]["bobcat"] = 422;

        if (config["bobcats"]["yosemite"].is_null())
            config["bobcats"]["yosemite"] = 554;

        if (config["bobcats"]["picador"].is_null())
            config["bobcats"]["picador"] = 600;


        std::ofstream f("prmenu.json");
        f << config;
    }

    config_file.close();
    

    // non-generate config fields
    
    if (config["fractions"]["all"]["color"].is_null())
        config["fractions"]["all"]["color"] = "FFFFFFFF";

    for (const auto& [key, val] : config["fractions"].items())
        config["config"]["fractions"][key]["state"] = false;
    
    config["config"]["misc"]["not_delete_markers"]["state"] = false;
    config["config"]["misc"]["not_delete_incar_players"]["state"] = false;
    config["config"]["misc"]["not_delete_bobcat_players"]["state"] = false;
    config["config"]["misc"]["enable_friend_list"]["state"] = false;
    config["config"]["misc"]["delete_friends_tracers"]["state"] = false;
}