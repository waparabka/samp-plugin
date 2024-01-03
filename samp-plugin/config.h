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
	bool toggled = false;

	Config();
};

