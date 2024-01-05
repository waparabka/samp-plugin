#pragma once

#include <nlohmann/json.hpp>
#include <fstream>
#include "singleton.h"
#include <sampapi/CChat.h>
#include <sampapi/CInput.h>
#include <sampapi/CGame.h>
#include <sampapi/CNetGame.h>
#include <sampapi/sampapi.h>

namespace samp = sampapi::v037r1;

using json = nlohmann::json;


class Config : public Singleton<Config> {

private:
	std::ifstream config_file;

public:
	json config;
	json config_default;

	std::string selected_item = "";
	std::map<std::string, bool> items;

	bool toggled = false;

	bool load(std::string config_file);
	void save(std::string config_file, json config);

	Config();
};

