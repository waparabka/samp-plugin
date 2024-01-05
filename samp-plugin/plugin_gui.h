#pragma once

#include <Windows.h>
#include <d3d9.h>
#include <imgui_impl_dx9.h>
#include <imgui_impl_win32.h>
#include "imgui_internal.h"
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

	IDirect3DTexture9* texture_logo = nullptr;
	IDirect3DTexture9* texture_settings = nullptr;

private:
	char imgui_input_friend[25];
	char imgui_input_fraction[8];
	char imgui_input_skin[5];
	char imgui_input_color[5];
	char imgui_input_bobcat[5];
	bool friends_menu_open = false;
	bool settings_menu_open = false;

    std::string cp1251_to_utf8(const char* str) {

        std::string res;

        WCHAR* ures = NULL;
        char* cres = NULL;

        int result_u = MultiByteToWideChar(1251, 0, str, -1, 0, 0);
        if (result_u != 0)
        {
            ures = new WCHAR[result_u];
            if (MultiByteToWideChar(1251, 0, str, -1, ures, result_u))
            {
                int result_c = WideCharToMultiByte(CP_UTF8, 0, ures, -1, 0, 0, 0, 0);
                if (result_c != 0)
                {
                    cres = new char[result_c];
                    if (WideCharToMultiByte(CP_UTF8, 0, ures, -1, cres, result_c, 0, 0))
                    {
                        res = cres;
                    }
                }
            }
        }

        delete[] ures;
        delete[] cres;

        return res;
    }

	Config* config = Config::Get();
};