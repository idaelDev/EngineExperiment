//////
//File window.h
/////

#pragma once
#include <iostream>
#include "macros.h"

#ifdef OS_WINDOWS
#include <windows.h>
#endif 

namespace Wander
{
	class Window
	{
	public:

		Window();
		
		virtual bool open(std::string & title, size_t width = 800, size_t height = 600, size_t flags = 0);
		virtual void close();
		virtual bool opened();

	private:
#ifdef OS_WINDOWS
		
		HWND hWND;
		HDC hDC;
		HGLRC hRC;

		LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#endif // OS_WINDOWS

	};
}