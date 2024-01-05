#include "imgui.h"
#include "imgui_internal.h"


bool ImGui::ImagedButton(const char* str_id, ImTextureID texture_id, ImVec2 size) {

    ImVec2 p = ImGui::GetCursorScreenPos();
    ImDrawList* draw_list = ImGui::GetWindowDrawList();

    ImGui::InvisibleButton(str_id, size);

    if (ImGui::IsItemHovered()) {

        ImU32 col_bg = ImGui::GetColorU32(ImLerp(ImVec4(0.1803921610116959f, 0.1882352977991104f, 0.196078434586525f, 1.0f), ImVec4(0.1803921610116959f, 0.1882352977991104f, 0.196078434586525f, 1.0f), 1.0f));

        draw_list->AddRectFilled(ImVec2(p.x - 1.5f, p.y - 1.5f), ImVec2(p.x + size.x + 1.5f, p.y + size.y + 1.5f), col_bg, (size.y + 1.5f) * 0.5f);
    }

    draw_list->AddImage(texture_id, p, ImVec2(p.x + size.x, p.y + size.y));
    
    return ImGui::IsItemClicked();
}