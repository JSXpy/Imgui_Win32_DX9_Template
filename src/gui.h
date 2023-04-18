#pragma once

#include "../imgui_dc_stack/imgui.h"
#include "../imgui_dc_stack/imgui_impl_dx9.h"
#include "../imgui_dc_stack/imgui_impl_win32.h"

#include <functional>

#include <d3d9.h>


namespace Imgui_Helper
{
	static LPDIRECT3D9              g_pD3D;
	static LPDIRECT3DDEVICE9        g_pd3dDevice;
	static D3DPRESENT_PARAMETERS    g_d3dpp;

	bool CreateDeviceD3D(HWND hWnd);
	void CleanupDeviceD3D();
	void ResetDevice();

	class Window_Engine
	{
	private:
		WNDCLASSEXW wc = {};
		HWND hwnd = NULL;
		
		//std::function<void()> gui;

	public:
		Window_Engine();

		MSG msg{};
		
		static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		void BeginRedenring();
		void EndRedenring();
		void Cleanup_Engine();

	};
};

