#include "plugin_gui.h"


PluginGUI::PluginGUI() : menu_open(false) { }


void PluginGUI::init() {

    ImGuiStyle& style = ImGui::GetStyle();

    style.Alpha = 1.0f;
    style.WindowPadding = ImVec2(12.0f, 12.0f);
    style.WindowRounding = 11.5f;
    style.WindowBorderSize = 0.0f;
    style.WindowMinSize = ImVec2(20.0f, 20.0f);
    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
    style.WindowMenuButtonPosition = ImGuiDir_Right;
    style.ChildRounding = 0.0f;
    style.ChildBorderSize = 1.0f;
    style.PopupRounding = 0.0f;
    style.PopupBorderSize = 1.0f;
    style.FramePadding = ImVec2(20.0f, 3.400000095367432f);
    style.FrameRounding = 11.89999961853027f;
    style.FrameBorderSize = 0.0f;
    style.ItemSpacing = ImVec2(4.300000190734863f, 5.5f);
    style.ItemInnerSpacing = ImVec2(7.099999904632568f, 1.799999952316284f);
    style.IndentSpacing = 0.0f;
    style.ColumnsMinSpacing = 4.900000095367432f;
    style.ScrollbarSize = 11.60000038146973f;
    style.ScrollbarRounding = 15.89999961853027f;
    style.GrabMinSize = 3.700000047683716f;
    style.GrabRounding = 20.0f;
    style.TabRounding = 0.0f;
    style.TabBorderSize = 0.0f;
    style.ColorButtonPosition = ImGuiDir_Right;
    style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

    style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.2745098173618317f, 0.3176470696926117f, 0.4509803950786591f, 1.0f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.0784313753247261f, 0.08627451211214066f, 0.1019607856869698f, 1.0f);
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.09411764889955521f, 0.1019607856869698f, 0.1176470592617989f, 1.0f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.0784313753247261f, 0.08627451211214066f, 0.1019607856869698f, 1.0f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.1568627506494522f, 0.168627455830574f, 0.1921568661928177f, 1.0f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0784313753247261f, 0.08627451211214066f, 0.1019607856869698f, 1.0f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.1137254908680916f, 0.125490203499794f, 0.1529411822557449f, 1.0f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.1568627506494522f, 0.168627455830574f, 0.1921568661928177f, 1.0f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.1568627506494522f, 0.168627455830574f, 0.1921568661928177f, 1.0f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.0470588244497776f, 0.05490196123719215f, 0.07058823853731155f, 1.0f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.0470588244497776f, 0.05490196123719215f, 0.07058823853731155f, 1.0f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.0784313753247261f, 0.08627451211214066f, 0.1019607856869698f, 1.0f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.09803921729326248f, 0.105882354080677f, 0.1215686276555061f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.0470588244497776f, 0.05490196123719215f, 0.07058823853731155f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.1176470592617989f, 0.1333333402872086f, 0.1490196138620377f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.1568627506494522f, 0.168627455830574f, 0.1921568661928177f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.1176470592617989f, 0.1333333402872086f, 0.1490196138620377f, 1.0f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.9725490212440491f, 1.0f, 0.4980392158031464f, 1.0f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.9725490212440491f, 1.0f, 0.4980392158031464f, 1.0f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(1.0f, 0.7960784435272217f, 0.4980392158031464f, 1.0f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.1176470592617989f, 0.1333333402872086f, 0.1490196138620377f, 1.0f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.1803921610116959f, 0.1882352977991104f, 0.196078434586525f, 1.0f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.1529411822557449f, 0.1529411822557449f, 0.1529411822557449f, 1.0f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.1411764770746231f, 0.1647058874368668f, 0.2078431397676468f, 1.0f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.105882354080677f, 0.105882354080677f, 0.105882354080677f, 1.0f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.0784313753247261f, 0.08627451211214066f, 0.1019607856869698f, 1.0f);
    style.Colors[ImGuiCol_Separator] = ImVec4(0.1294117718935013f, 0.1490196138620377f, 0.1921568661928177f, 1.0f);
    style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.1568627506494522f, 0.1843137294054031f, 0.250980406999588f, 1.0f);
    style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.1568627506494522f, 0.1843137294054031f, 0.250980406999588f, 1.0f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1450980454683304f, 1.0f);
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.9725490212440491f, 1.0f, 0.4980392158031464f, 1.0f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_Tab] = ImVec4(0.0784313753247261f, 0.08627451211214066f, 0.1019607856869698f, 1.0f);
    style.Colors[ImGuiCol_TabHovered] = ImVec4(0.1176470592617989f, 0.1333333402872086f, 0.1490196138620377f, 1.0f);
    style.Colors[ImGuiCol_TabActive] = ImVec4(0.1176470592617989f, 0.1333333402872086f, 0.1490196138620377f, 1.0f);
    style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.0784313753247261f, 0.08627451211214066f, 0.1019607856869698f, 1.0f);
    style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.125490203499794f, 0.2745098173618317f, 0.572549045085907f, 1.0f);
    style.Colors[ImGuiCol_PlotLines] = ImVec4(0.5215686559677124f, 0.6000000238418579f, 0.7019608020782471f, 1.0f);
    style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.03921568766236305f, 0.9803921580314636f, 0.9803921580314636f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.8823529481887817f, 0.7960784435272217f, 0.5607843399047852f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.95686274766922f, 0.95686274766922f, 0.95686274766922f, 1.0f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.9372549057006836f, 0.9372549057006836f, 0.9372549057006836f, 1.0f);
    style.Colors[ImGuiCol_DragDropTarget] = ImVec4(0.4980392158031464f, 0.5137255191802979f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.2666666805744171f, 0.2901960909366608f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(0.4980392158031464f, 0.5137255191802979f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.196078434586525f, 0.1764705926179886f, 0.5450980663299561f, 0.501960813999176f);
    style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.196078434586525f, 0.1764705926179886f, 0.5450980663299561f, 0.501960813999176f);
    

    memset(imgui_input, '\0', sizeof(imgui_input));
}


void PluginGUI::process() {
    
    if (!menu_open)
        return;

    static bool main_window_inited = false;

    ImVec2 window_pos;
    float width = 640, height = 500;
    
    auto window_size = ImGui::GetIO().DisplaySize;
    auto window_center = ImVec2(window_size.x / 2 - width / 2, window_size.y / 2 - height / 2);

    if (!main_window_inited) {

        ImGui::SetCursorScreenPos(window_center);
        ImGui::SetNextWindowPos(window_center);
        ImGui::SetNextWindowSize(ImVec2(width, height));

        main_window_inited = true;
    }

    if (ImGui::Begin("PR Menu | Author: waparabka", &menu_open, ImGuiWindowFlags_UnsavedDocument | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_None | ImGuiWindowFlags_NoResize)) {

        window_pos = ImGui::GetWindowPos();

        auto draw = ImGui::GetWindowDrawList();

        float diameter = 15.f;

        ImVec2 p_min = ImGui::GetCursorScreenPos();
        p_min.y -= 3;

        ImVec2 p_max = ImVec2(p_min.x + 616, p_min.y + 80);
        ImGui::GetWindowDrawList()->AddImageRounded(texture, p_min, p_max, ImVec2(0, 0), ImVec2(1, 1), ImGui::GetColorU32(ImVec4(1, 1, 1, 1)), diameter * 0.5f);

        ImGui::SetCursorPosY(120);

        ImGui::Separator();
        ImGui::Spacing();

        ImGui::Text(reinterpret_cast<const char*>(u8"Выбери кого нужно удалить"));

        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Spacing();


        int rows = 0;
        int i = 0;

        float initial_y_offset = ImGui::GetCursorPos().y;

        for (const auto& [key, val] : config->config["fractions"].items()) {

            ImU32 color;

            for (const auto& it : val.items()) {
                
                int a, r, g, b;
                std::sscanf(it.value().get<std::string>().c_str(), "%02x%02x%02x%02x", &a, &r, &g, &b);
                
                color = IM_COL32(r, g, b, 255);
            }

            auto text_offset = ImGui::GetCursorPos().x + rows * 120;

            ImGui::SetCursorPosX(text_offset);

            ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(color), key.c_str());
            ImGui::SameLine();
            
            auto button_offset = text_offset + 50;

            ImGui::SetCursorPosX(button_offset);
            
            ImGui::ToggleButton(key.c_str(), &config->config["config"]["fractions"][key]["state"].get_ref<bool&>());
            if (ImGui::IsItemClicked())
                config->toggled = true;
            
            i++;

            if (i > 0 && i % 5 == 0) {
                ImGui::SetCursorPosY(initial_y_offset);
                rows++;
            }
        }
        

        ImGui::SetCursorPosY(270);
        ImGui::Spacing();

        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Spacing();
        
        ImGui::Text(reinterpret_cast<const char*>(u8"Не удалять маркеры игроков на радаре"));
        ImGui::SameLine();
        ImGui::ToggleButton("not_delete_markers", &config->config["config"]["misc"]["not_delete_markers"]["state"].get_ref<bool&>());
        if (ImGui::IsItemClicked())
            config->toggled = true;

        ImGui::Text(reinterpret_cast<const char*>(u8"Не удалять игроков в машинах"));
        ImGui::SameLine();
        ImGui::ToggleButton("not_delete_incar_players", &config->config["config"]["misc"]["not_delete_incar_players"]["state"].get_ref<bool&>());
        
        ImGui::Text(reinterpret_cast<const char*>(u8"Не удалять игроков в мясовозках"));
        ImGui::SameLine();
        ImGui::ToggleButton("not_delete_bobcat_players", &config->config["config"]["misc"]["not_delete_bobcat_players"]["state"].get_ref<bool&>());
        
        /*ImGui::Text(reinterpret_cast<const char*>(u8"Мгновенно удалять мертвых игроков"));
        ImGui::SameLine();
        ImGui::ToggleButton("instant_delete_dead_players", &config->config["config"]["misc"]["instant_delete_dead_players"]["state"].get_ref<bool&>());
        if (ImGui::IsItemClicked())
            config->toggled = true;*/

        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Spacing();

        ImGui::Text(reinterpret_cast<const char*>(u8"Включить френд лист"));
        ImGui::SameLine();
        ImGui::ToggleButton("enable_friend_list", &config->config["config"]["misc"]["enable_friend_list"]["state"].get_ref<bool&>());


        if (config->config["config"]["misc"]["enable_friend_list"]["state"].get<bool>()) {

            ImGui::Spacing();
            
            ImGui::InputText(reinterpret_cast<const char*>(u8"Никнейм друга или @id"), imgui_input, sizeof(imgui_input));

            if (ImGui::Button(reinterpret_cast<const char*>(u8"Добавить"))) {

                auto name = std::string(imgui_input);

                if (name.length() > 0) {

                    if (name.starts_with("@")) {

                        name.erase(std::remove(name.begin(), name.end(), '@'), name.end());

                        auto playerid = atoi(name.c_str());
                        auto player = samp::RefNetGame()->GetPlayerPool()->GetPlayer(playerid);

                        if (!player) {

                            samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Игрока с ID " + std::to_string(playerid) + " нет на сервере").c_str());

                            return;
                        }

                        auto player_name = samp::RefNetGame()->GetPlayerPool()->GetName(playerid);

                        strncpy(imgui_input, player_name, strlen(player_name));
                    }
                    
                    
                    for (auto const& [key, val] : config->config["friends"].items()) {

                        if (key.c_str() == name) {

                            memset(imgui_input, '\0', sizeof(imgui_input));

                            return;
                        }
                    }


                    samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Игрок " + std::string(imgui_input) + " добавлен в список друзей").c_str());
                    
                    config->config["friends"][imgui_input] = 1;
                    memset(imgui_input, '\0', sizeof(imgui_input));

                    std::ofstream f("prmenu.json");
                    
                    f.flush();
                    f << config;
                }
                else {
                    samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Пустой никнейм не добавлю").c_str());
                }
            }

            ImGui::SameLine();

            if (ImGui::Button(reinterpret_cast<const char*>(u8"Удалить"))) {

                auto name = std::string(imgui_input);

                if (name.length() > 0) {

                    if (name.starts_with("@")) {

                        name.erase(std::remove(name.begin(), name.end(), '@'), name.end());

                        auto playerid = atoi(name.c_str());
                        auto player = samp::RefNetGame()->GetPlayerPool()->GetPlayer(playerid);

                        if (!player)
                            return;

                        name = samp::RefNetGame()->GetPlayerPool()->GetName(playerid);

                        strncpy(imgui_input, name.c_str(), name.size());
                    }

                    for (auto const& [key, val] : config->config["friends"].items()) {

                        if (key.c_str() == name) {

                            samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Игрок " + std::string(imgui_input) + " удален из списка друзей").c_str());

                            config->config["friends"].erase(name);
                            memset(imgui_input, '\0', sizeof(imgui_input));

                            std::ofstream f("prmenu.json");

                            f.flush();
                            f << config;

                            return;
                        }
                    }

                    samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Игрока " + std::string(imgui_input) + " нет в списке друзей").c_str());
                }
                else {
                    samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Пустой никнейм не удалю").c_str());
                }
            }

            ImGui::SameLine();

            if (ImGui::Button(reinterpret_cast<const char*>(u8"Список друзей")))
                friends_menu_open = !friends_menu_open;

            ImGui::Spacing();
            ImGui::Separator();
            ImGui::Spacing();

            ImGui::Text(reinterpret_cast<const char*>(u8"Удалять трасеры друзей"));
            ImGui::SameLine();
            ImGui::ToggleButton("delete_friends_tracers", &config->config["config"]["misc"]["delete_friends_tracers"]["state"].get_ref<bool&>());
            

            if (friends_menu_open) {

                ImVec2 friend_list_window_pos = window_pos;

                friend_list_window_pos.x += width + 15;

                ImGui::SetNextWindowPos(friend_list_window_pos);
                ImGui::SetNextWindowSize(ImVec2(180, height));

                if (ImGui::Begin(reinterpret_cast<const char*>(u8"PR Menu | Друзья"), &friends_menu_open, ImGuiWindowFlags_UnsavedDocument | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_None | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove)) {
                    
                    for (auto const& [key, val] : config->config["friends"].items())
                        ImGui::Text(key.c_str());
                }
            }
        }

        ImGui::End();
    }
}