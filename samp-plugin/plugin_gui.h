#pragma once

#include <Windows.h>
#include <d3d9.h>
#include <imgui_impl_dx9.h>
#include <imgui_impl_win32.h>
#include <fstream>
#include <nlohmann/json.hpp>
#include "config.h"

using json = nlohmann::json;


class PluginGUI {

public:
	bool menu_open;
	bool close_once = false;
	void init();
	void process();
	
	PluginGUI();

	IDirect3DTexture9* texture = nullptr;

private:
	char imgui_input[25];
	bool friends_menu_open = false;

	Config* config = Config::Get();
};