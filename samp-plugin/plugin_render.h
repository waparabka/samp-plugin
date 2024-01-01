#pragma once

#include "plugin_gui.h"
#include <kthook/kthook.hpp>
#include <optional>

#include <d3dx9.h>
#include <d3d9.h>
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

using present_t = HRESULT(__stdcall*)(IDirect3DDevice9*, const RECT*, const RECT*, HWND, const RGNDATA*);
using reset_t = HRESULT(__stdcall*)(IDirect3DDevice9*, D3DPRESENT_PARAMETERS*);
using wnd_proc_t = HRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM);


class PluginRender {
	
private:
	bool imgui_init;
	
	kthook::kthook_signal<present_t> present_hook { };
	kthook::kthook_signal<reset_t> reset_hook { };
	kthook::kthook_simple<wnd_proc_t> wnd_proc_hook { };
	
	std::optional<HRESULT> d3d9_present(const decltype(present_hook)& hook, IDirect3DDevice9* device, CONST RECT* src_rect, CONST RECT* dest_rect, HWND dest_window, CONST RGNDATA* dirty_region);
	std::optional<HRESULT> d3d9_lost(const decltype(reset_hook)& hook, LPDIRECT3DDEVICE9 device, D3DPRESENT_PARAMETERS* present_params);
	void d3d9_reset(const decltype(reset_hook)& hook, HRESULT& return_value, IDirect3DDevice9* device, D3DPRESENT_PARAMETERS* params);
	HRESULT wnd_proc_handler(const decltype(wnd_proc_hook)& hook, HWND hwnd, UINT u_msg, WPARAM w_param, LPARAM l_param);
	
public:
	PluginGUI GUI;
	
	void setup_d3d9_hooks();

	PluginRender();
	~PluginRender();
};