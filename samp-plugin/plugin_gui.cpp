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
}


void PluginGUI::process() {
    
    if (!menu_open)
        return;

    static bool main_window_inited = false;
    
    ImVec2 window_pos;
    float width = 640, height = 520;
    
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
        ImGui::GetWindowDrawList()->AddImageRounded(texture_logo, p_min, p_max, ImVec2(0, 0), ImVec2(1, 1), ImGui::GetColorU32(ImVec4(1, 1, 1, 1)), diameter * 0.5f);

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

        ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(IM_COL32(255, 255, 255, 255)), "all");
        ImGui::SameLine();
        ImGui::ToggleButton("##all", &config->config_default["config"]["fractions"]["all"]["state"].get_ref<bool&>());
        if (ImGui::IsItemClicked())
            config->toggled = true;

        i++;

        try {
            for (const auto& [key, val] : config->config["config"]["fractions"].items()) {

                if (config->config["config"]["fractions"][key]["color"].is_null())
                    continue;

                ImU32 color;

                int a, r, g, b;
                std::sscanf(config->config["config"]["fractions"][key]["color"].get<std::string>().c_str(), "%02x%02x%02x%02x", &a, &r, &g, &b);

                color = IM_COL32(r, g, b, 255);

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
        }
        catch (...) { };
        

        ImGui::SetCursorPosY(270);
        ImGui::Spacing();
        
        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Spacing();
        
        ImGui::Text(reinterpret_cast<const char*>(u8"Не удалять маркеры игроков на радаре"));
        ImGui::SameLine();
        ImGui::ToggleButton("not_delete_markers", &config->config_default["config"]["misc"]["not_delete_markers"]["state"].get_ref<bool&>());
        if (ImGui::IsItemClicked())
            config->toggled = true;

        ImGui::Text(reinterpret_cast<const char*>(u8"Не удалять игроков в машинах"));
        ImGui::SameLine();
        ImGui::ToggleButton("not_delete_incar_players", &config->config_default["config"]["misc"]["not_delete_incar_players"]["state"].get_ref<bool&>());
        
        ImGui::Text(reinterpret_cast<const char*>(u8"Не удалять игроков в мясовозках"));
        ImGui::SameLine();
        ImGui::ToggleButton("not_delete_bobcat_players", &config->config_default["config"]["misc"]["not_delete_bobcat_players"]["state"].get_ref<bool&>());
        
        ImGui::Text(reinterpret_cast<const char*>(u8"Мгновенно удалять мертвых игроков"));
        ImGui::SameLine();
        ImGui::ToggleButton("instant_delete_dead_players", &config->config_default["config"]["misc"]["instant_delete_dead_players"]["state"].get_ref<bool&>());
        if (ImGui::IsItemClicked())
            config->toggled = true;

        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Spacing();

        ImGui::Text(reinterpret_cast<const char*>(u8"Включить френд лист"));
        ImGui::SameLine();
        ImGui::ToggleButton("enable_friend_list", &config->config_default["config"]["misc"]["enable_friend_list"]["state"].get_ref<bool&>());


        if (config->config_default["config"]["misc"]["enable_friend_list"]["state"].get<bool>()) {

            ImGui::Spacing();
            
            ImGui::InputText(reinterpret_cast<const char*>(u8"Никнейм друга или @id"), imgui_input_friend, sizeof(imgui_input_friend));

            if (ImGui::Button(reinterpret_cast<const char*>(u8"Добавить"))) {

                auto name = std::string(imgui_input_friend);

                if (name.length() > 0) {

                    if (name.starts_with("@")) {

                        name.erase(std::remove(name.begin(), name.end(), '@'), name.end());

                        auto player_id = atoi(name.c_str());
                        auto player = samp::RefNetGame()->GetPlayerPool()->GetPlayer(player_id);

                        if (!player) {

                            samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Игрока с ID " + std::to_string(player_id) + " нет на сервере").c_str());

                            return;
                        }

                        auto player_name = samp::RefNetGame()->GetPlayerPool()->GetName(player_id);

                        strncpy(imgui_input_friend, player_name, strlen(player_name));
                    }
                    
                    
                    for (auto const& [key, val] : config->config_default["config"]["friends"].items()) {

                        if (key.c_str() == name) {

                            memset(imgui_input_friend, '\0', sizeof(imgui_input_friend));

                            return;
                        }
                    }


                    samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Игрок " + std::string(imgui_input_friend) + " добавлен в список друзей").c_str());
                    
                    config->config_default["config"]["friends"][imgui_input_friend] = 1;
                    memset(imgui_input_friend, '\0', sizeof(imgui_input_friend));

                    config->save("default.json", config->config_default);
                }
                else {
                    samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Пустой никнейм не добавлю").c_str());
                }
            }

            ImGui::SameLine();

            if (ImGui::Button(reinterpret_cast<const char*>(u8"Удалить"))) {

                auto name = std::string(imgui_input_friend);

                if (name.length() > 0) {

                    if (name.starts_with("@")) {

                        name.erase(std::remove(name.begin(), name.end(), '@'), name.end());

                        auto player_id = atoi(name.c_str());
                        auto player = samp::RefNetGame()->GetPlayerPool()->GetPlayer(player_id);

                        if (!player)
                            return;

                        name = samp::RefNetGame()->GetPlayerPool()->GetName(player_id);

                        strncpy(imgui_input_friend, name.c_str(), name.size());
                    }

                    for (auto const& [key, val] : config->config_default["config"]["friends"].items()) {

                        if (key.c_str() == name) {

                            samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Игрок " + std::string(imgui_input_friend) + " удален из списка друзей").c_str());

                            config->config_default["config"]["friends"].erase(name);
                            memset(imgui_input_friend, '\0', sizeof(imgui_input_friend));
                            
                            config->save("default.json", config->config_default);

                            return;
                        }
                    }

                    samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Игрока " + std::string(imgui_input_friend) + " нет в списке друзей").c_str());
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
            ImGui::ToggleButton("delete_friends_tracers", &config->config_default["config"]["misc"]["delete_friends_tracers"]["state"].get_ref<bool&>());
            

            if (friends_menu_open) {

                ImVec2 friend_list_window_pos = window_pos;

                friend_list_window_pos.x += width + 15;

                ImGui::SetNextWindowPos(friend_list_window_pos);
                ImGui::SetNextWindowSize(ImVec2(180, height));

                if (ImGui::Begin(reinterpret_cast<const char*>(u8"PR Menu | Друзья"), &friends_menu_open, ImGuiWindowFlags_UnsavedDocument | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_None | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove)) {
                    
                    for (auto const& [key, val] : config->config_default["config"]["friends"].items())
                        ImGui::Text(key.c_str());

                    ImGui::End();
                }
            }
        }
        
        const ImGuiWindow* window = ImGui::GetCurrentWindow();
        const ImRect title_bar_rect = window->TitleBarRect();

        ImGui::PushClipRect(title_bar_rect.Min, title_bar_rect.Max, false);
        ImGui::SetCursorPos(ImVec2(580.0f, 3.0f));

        if (ImGui::ImagedButton("settings", texture_settings, ImVec2(16, 16)))
            settings_menu_open = !settings_menu_open;

        ImGui::PopClipRect();

        
        if (settings_menu_open) {

            ImVec2 settings_window_pos = window_pos;
            ImVec2 settings_window_size = ImVec2(450, height);
            
            settings_window_pos.x = window_pos.x - (settings_window_size.x + 15);
            settings_window_pos.y = window_pos.y + (height / 2 - settings_window_size.y / 2);
            
            ImGui::SetNextWindowPos(settings_window_pos);
            ImGui::SetNextWindowSize(ImVec2(settings_window_size.x, settings_window_size.y));
            
            if (ImGui::Begin(reinterpret_cast<const char*>(u8"PR Menu | Настройки"), &settings_menu_open, ImGuiWindowFlags_UnsavedDocument | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove)) {

                std::string config_name (std::string(samp::RefNetGame()->m_szHostAddress) + ".json");

                ImGui::Text(reinterpret_cast<const char*>(u8"Конфиг будет сохранен под названием: "));
                ImGui::SameLine();
                ImGui::Text(config_name.c_str());
                

                ImGui::Spacing();
                ImGui::Spacing();


                bool is_fraction_selected = config->selected_item.length() > 0;
                
                ImGui::Text(reinterpret_cast<const char*>(u8"Добавление фракции в конфиг, выбранная фракция: "));
                ImGui::SameLine();
                ImGui::Text(!is_fraction_selected ? reinterpret_cast<const char*>(u8"Не выбрано") : cp1251_to_utf8(config->selected_item.c_str()).c_str());


                ImGui::InputText(reinterpret_cast<const char*>(u8"##fraction"), imgui_input_fraction, sizeof(imgui_input_fraction));

                if (ImGui::Button(reinterpret_cast<const char*>(u8"Добавить"))) {

                    std::string adding_fraction (imgui_input_fraction);

                    if (adding_fraction.size()) {
                        config->items.insert({ imgui_input_fraction, false });
                        config->selected_item = adding_fraction;
                        config->config["config"]["fractions"][config->selected_item]["state"] = false;
                        config->config_default["config"]["selected"] = config_name;
                        config->save("default.json", config->config_default);
                    }
                }

                ImGui::SameLine();
                ImGui::Button(reinterpret_cast<const char*>(u8"Удалить"));

                
                if (!is_fraction_selected) {
                    ImGui::End(); return; }
                
                
                ImGui::ListBoxHeader(reinterpret_cast<const char*>(u8"Список созданных фракций"), ImVec2(settings_window_size.x / 2, 60));

                for (const auto& item : config->items)
                    if (ImGui::Selectable(item.first.c_str(), item.second))
                        config->selected_item = item.first;
                
                ImGui::ListBoxFooter();
                
                
                ImGui::Separator();
                ImGui::Spacing();
                ImGui::Spacing();

                ImGui::Text(reinterpret_cast<const char*>(u8"Игрок должен находиться в зоне прорисовки!"));

                ImGui::Spacing();
                ImGui::Spacing();
                ImGui::Separator();


                ImGui::Spacing();
                ImGui::Spacing();


                ImGui::Text(reinterpret_cast<const char*>(u8"Добавление цвета в конфиг > @id игрока"));
                ImGui::InputText("##color", imgui_input_color, sizeof(imgui_input_color));

                if (ImGui::Button(reinterpret_cast<const char*>(u8"Добавить ##color"))) {

                    std::string player_id_input(imgui_input_color);

                    if (!player_id_input.length())
                        return;

                    if (player_id_input.starts_with("@")) {

                        player_id_input.erase(std::remove(player_id_input.begin(), player_id_input.end(), '@'), player_id_input.end());

                        auto player_id = atoi(player_id_input.c_str());
                        auto player = samp::RefNetGame()->GetPlayerPool()->GetPlayer(player_id);

                        if (!player) {
                            samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Игрока с ID " + std::to_string(player_id) + " нет на сервере").c_str());
                            return;
                        }

                        std::stringstream player_color;
                        player_color << std::hex << std::uppercase << player->GetColorAsARGB();

                        config->config["config"]["fractions"][config->selected_item]["color"] = player_color.str();

                        config->save(config_name, config->config);

                        samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Цвет " + player_color.str() + " добавлен в конфиг фракции " + config->selected_item).c_str());
                        samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Конфиг " + config_name + " сохранен!").c_str());

                        memset(imgui_input_color, '\0', sizeof(imgui_input_color));
                    }
                }

                ImGui::SameLine();

                if (ImGui::Button(reinterpret_cast<const char*>(u8"Удалить ##color"))) {

                    std::string player_id_input(imgui_input_color);

                    if (!player_id_input.length())
                        return;

                    if (player_id_input.starts_with("@")) {

                        player_id_input.erase(std::remove(player_id_input.begin(), player_id_input.end(), '@'), player_id_input.end());

                        auto player_id = atoi(player_id_input.c_str());
                        auto player = samp::RefNetGame()->GetPlayerPool()->GetPlayer(player_id);

                        if (!player) {
                            samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Игрока с ID " + std::to_string(player_id) + " нет на сервере").c_str());
                            return;
                        }

                        std::stringstream player_color;
                        player_color << std::hex << std::uppercase << player->GetColorAsARGB();

                        auto color = &config->config["config"]["fractions"][config->selected_item]["color"];

                        for (auto it = color->begin(); it < color->end(); it++) {

                            if (*it == player_color.str()) {

                                color->erase(it);

                                config->save(config_name, config->config);

                                samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Цвет " + player_color.str() + " удален из конфига фракции " + config->selected_item).c_str());
                                samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Конфиг " + config_name + " сохранен!").c_str());

                                memset(imgui_input_color, '\0', sizeof(imgui_input_color));

                                ImGui::End();

                                return;
                            }
                        }
                        samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Цвет " + player_color.str() + " не найден в конфиге фракции " + config->selected_item).c_str());
                    }
                }

                ImGui::Spacing();
                ImGui::Spacing();


                ImGui::Text(reinterpret_cast<const char*>(u8"Добавление скина в конфиг > ID скина или @id (если по игроку)"));
                ImGui::InputText("##skin", imgui_input_skin, sizeof(imgui_input_skin));

                if (ImGui::Button(reinterpret_cast<const char*>(u8"Добавить ##skin"))) {
                    
                    std::string skin(imgui_input_skin);

                    if (!skin.length())
                        return;

                    auto skin_id = atoi(skin.c_str());

                    if (skin.starts_with("@")) {

                        skin.erase(std::remove(skin.begin(), skin.end(), '@'), skin.end());

                        auto player_id = atoi(skin.c_str());
                        auto player = samp::RefNetGame()->GetPlayerPool()->GetPlayer(player_id);

                        if (!player) {
                            samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Игрока с ID " + std::to_string(player_id) + " нет на сервере").c_str());
                            return;
                        }

                        auto ped = player->m_pPed;

                        if (!ped) {
                            samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Игрока с ID " + std::to_string(player_id) + " нет в зоне прорисовки").c_str());
                            return;
                        }

                        skin_id = ped->GetModelIndex();
                    }
                    
                    config->config["config"]["fractions"][config->selected_item]["skins"] += skin_id;

                    config->save(config_name, config->config);
                    
                    samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Скин " + std::to_string(skin_id) + " добавлен в конфиг фракции " + config->selected_item).c_str());
                    samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Конфиг " + config_name + " сохранен!").c_str());

                    memset(imgui_input_skin, '\0', sizeof(imgui_input_skin));
                }

                ImGui::SameLine();

                if (ImGui::Button(reinterpret_cast<const char*>(u8"Удалить ##skin"))) {

                    std::string skin(imgui_input_skin);

                    if (!skin.length())
                        return;

                    auto skin_id = atoi(skin.c_str());

                    if (skin.starts_with("@")) {

                        skin.erase(std::remove(skin.begin(), skin.end(), '@'), skin.end());

                        auto player_id = atoi(skin.c_str());
                        auto player = samp::RefNetGame()->GetPlayerPool()->GetPlayer(player_id);

                        if (!player) {
                            samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Игрока с ID " + std::to_string(player_id) + " нет на сервере").c_str());
                            return;
                        }

                        auto ped = player->m_pPed;

                        if (!ped) {
                            samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Игрока с ID " + std::to_string(player_id) + " нет в зоне прорисовки").c_str());
                            return;
                        }

                        skin_id = ped->GetModelIndex();
                    }


                    auto skins = &config->config["config"]["fractions"][config->selected_item]["skins"];

                    for (auto it = skins->begin(); it < skins->end(); it++) {

                        if (*it == skin_id) {

                            skins->erase(it);

                            config->save(config_name, config->config);

                            samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Скин под ID " + std::to_string(skin_id) + " удален из конфига фракции " + config->selected_item).c_str());
                            samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Конфиг " + config_name + " сохранен!").c_str());

                            memset(imgui_input_skin, '\0', sizeof(imgui_input_skin));

                            ImGui::End();

                            return;
                        }
                    }
                    samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Скин под ID " + std::to_string(skin_id) + " не найден в конфиге фракции " + config->selected_item).c_str());
                }


                ImGui::Spacing();
                ImGui::Spacing();
                

                ImGui::Text(reinterpret_cast<const char*>(u8"Добавление мясовозок в конфиг > ID мясовозки"));
                ImGui::InputText("##bobcats", imgui_input_bobcat, sizeof(imgui_input_bobcat));
                
                if (ImGui::Button(reinterpret_cast<const char*>(u8"Добавить ##bobcats"))) {

                    std::string bobcat(imgui_input_bobcat);

                    if (!bobcat.length())
                        return;

                    auto bobcat_id = atoi(bobcat.c_str());

                    config->config["config"]["bobcats"] += bobcat_id;

                    config->save(config_name, config->config);

                    samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Мясовозка под ID " + std::to_string(bobcat_id) + " добавлена в конфиг").c_str());
                    samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Конфиг " + config_name + " сохранен!").c_str());

                    memset(imgui_input_bobcat, '\0', sizeof(imgui_input_bobcat));
                }
                
                ImGui::SameLine();
                
                if (ImGui::Button(reinterpret_cast<const char*>(u8"Удалить ##bobcats"))) {

                    std::string bobcat(imgui_input_bobcat);

                    if (!bobcat.length())
                        return;

                    auto bobcat_id = atoi(bobcat.c_str());
                    auto bobcats = &config->config["config"]["bobcats"];

                    for (auto it = bobcats->begin(); it < bobcats->end(); it++) {

                        if (*it == bobcat_id) {

                            bobcats->erase(it);
                            
                            config->save(config_name, config->config);

                            samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Мясовозка под ID " + std::to_string(bobcat_id) + " удалена из конфига").c_str());
                            samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Конфиг " + config_name + " сохранен!").c_str());
                            
                            memset(imgui_input_bobcat, '\0', sizeof(imgui_input_bobcat));

                            ImGui::End();

                            return;
                        }
                    }
                    samp::RefChat()->AddMessage(-1, std::string("{6959ba}[PR Menu]{ffffff} Мясовозка под ID " + std::to_string(bobcat_id) + " не найдена в конфиге").c_str());
                }

                ImGui::End();
            }
        }

        ImGui::End();
    }
}