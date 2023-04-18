// Dear ImGui: standalone example application for DirectX 9
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "../imgui_dc_stack/imgui.h"
#include "gui.h"
#include "IconsFontAwesome6.h"

#include <string>
#include <iostream>

namespace App_State
{
    // Our state
    bool show_demo_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    char user[16] = "";
    char password[16] = "";
}

void Gui_Test(ImGuiIO& io);
void Gui_Doc_Test(ImGuiIO& io);

void Apply_Style();
ImVec2 Layout_VH_Center_Hlp();

int main(int, char**)
{

    Imgui_Helper::Window_Engine root_window {};

    ImGuiIO& io = ImGui::GetIO();

    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    //io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    static const ImWchar icon_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };

    ImFontConfig config;
    config.MergeMode = true;
    config.GlyphMinAdvanceX = 20.0f; // make the icon monospaced

    //io.Fonts->AddFontDefault();
    //ImFont* font1 = io.Fonts->AddFontFromFileTTF(".\\fonts\\Roboto-Light.ttf", 20.0f);
    ImFont* roboto = io.Fonts->AddFontFromFileTTF(".\\fonts\\Roboto-Regular.ttf", 20.0f, 0, io.Fonts->GetGlyphRangesDefault());
    ImFont* fa_regular = io.Fonts->AddFontFromFileTTF(".\\fonts\\fa-regular-400.ttf", 16.0f, &config, icon_ranges);
    ImFont* fa_solid = io.Fonts->AddFontFromFileTTF(".\\fonts\\fa-solid-900.ttf", 16.0f, &config, icon_ranges);
    io.Fonts->Build();

    Apply_Style();

    // Main loop
    while (root_window.msg.message != WM_QUIT)
    {
        root_window.BeginRedenring();

        Gui_Doc_Test(io);

        root_window.EndRedenring();
    }

    root_window.Cleanup_Engine();

    return 0;
}

void Gui_Test(ImGuiIO& io)
{
    if (App_State::show_demo_window)
        ImGui::ShowDemoWindow(&App_State::show_demo_window);

    {
        //ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
        //ImGui::SetNextWindowPos({ 0,0 });
        ImGui::Begin("JSX", NULL /* ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse */);

        

        ImGui::BeginHorizontal("LOGIN_H", Layout_VH_Center_Hlp(), 0.5f);
        ImGui::BeginVertical("LOGIN_V", Layout_VH_Center_Hlp(), 0.5f);

        ImGui::Spring();

        ImGui::Checkbox("DEMO", &App_State::show_demo_window);
        ImGui::PushItemWidth(200);
        ImGui::InputText("User", App_State::user, IM_ARRAYSIZE(App_State::user));
        ImGui::InputText("Password", App_State::password, IM_ARRAYSIZE(App_State::password));
        ImGui::PopItemWidth();
        ImGui::Button("Login");
        
        ImGui::Spring();

        ImGui::EndVertical();
        ImGui::EndHorizontal();

        ImGui::End();
    }
}

void Gui_Doc_Test(ImGuiIO& io)
{
    

    ImGuiWindowFlags window_flags =  ImGuiWindowFlags_MenuBar |  ImGuiWindowFlags_NoDocking;
    window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    //window_flags |= ImGuiWindowFlags_NoBackground;

    

    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);
    ImGui::SetNextWindowViewport(viewport->ID);

    //bool p_open = false;

    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(10, 10));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
    
    ImGui::Begin("JSX", NULL, ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBringToFrontOnFocus);

    ImGui::PopStyleVar();
    ImGui::PopStyleVar();
    ImGui::PopStyleVar();

    ImGui::BeginChild("JSX_2", ImVec2(0,0), false, window_flags);

    if (ImGui::BeginMenuBar())
    {
        
        if (ImGui::BeginMenu("Options"))
        {
            ImGui::MenuItem("Padding", NULL, false);
            ImGui::Separator();

            if (ImGui::MenuItem("Demo", "", &App_State::show_demo_window, true))
            {
            }

            if (ImGui::MenuItem("Close", NULL, false))
            {
            }

            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }

    

    ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

    ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
    ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f));

    
    ImGui::EndChild();

    ImGui::End();

    
    //ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);
    if (App_State::show_demo_window)
        ImGui::ShowDemoWindow(&App_State::show_demo_window);

    ImGui::Begin("Win_1", NULL);
    ImGui::Checkbox("DEMO", &App_State::show_demo_window);
    ImGui::End();

    ImGui::Begin("Win_2", NULL);
    ImGui::End();
}

void Apply_Style()
{
    // Nice green #13F35BFF

    ImGuiStyle& style = ImGui::GetStyle();

    style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.38f, 0.38f, 0.38f, 1.00f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.67f, 0.67f, 0.67f, 0.39f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.11f, 0.64f, 0.92f, 1.00f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.11f, 0.64f, 0.92f, 1.00f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.08f, 0.50f, 0.72f, 1.00f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.38f, 0.38f, 0.38f, 1.00f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.67f, 0.67f, 0.67f, 0.39f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.22f, 0.22f, 0.22f, 1.00f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.67f, 0.67f, 0.67f, 0.39f);
    style.Colors[ImGuiCol_Separator] = style.Colors[ImGuiCol_Border];
    style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.41f, 0.42f, 0.44f, 1.00f);
    style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.29f, 0.30f, 0.31f, 0.67f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
    style.Colors[ImGuiCol_Tab] = ImVec4(0.08f, 0.08f, 0.09f, 0.83f);
    style.Colors[ImGuiCol_TabHovered] = ImVec4(0.33f, 0.34f, 0.36f, 0.83f);
    style.Colors[ImGuiCol_TabActive] = ImVec4(0.23f, 0.23f, 0.24f, 1.00f);
    style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
    style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
    //style.Colors[ImGuiCol_DockingPreview] = ImVec4(0.26f, 0.59f, 0.98f, 0.70f);
    //style.Colors[ImGuiCol_DockingEmptyBg] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
    style.Colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
    style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
    style.Colors[ImGuiCol_DragDropTarget] = ImVec4(0.11f, 0.64f, 0.92f, 1.00f);
    style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
    style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
    style.GrabRounding = style.FrameRounding = 2.3f;
}

ImVec2 Layout_VH_Center_Hlp()
{
    ImVec2 widget_aera_size;
    widget_aera_size.x = floorf(ImGui::GetContentRegionAvail().x / 2);
    widget_aera_size.y = floorf(ImGui::GetContentRegionAvail().y / 2);

    return ImVec2(widget_aera_size.x * 2, widget_aera_size.y * 2);
}