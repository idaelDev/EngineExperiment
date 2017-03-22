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
		
		virtual void open(std::string & title, size_t width = 800, size_t height = 600, size_t flags = 0) = 0;
		virtual void close() = 0;
		virtual bool opened() = 0;

	private:
#ifdef OS_WINDOWS
		HWND hWND;
		HDC hDC;
		HGLRC hRC;
#endif // OS_WINDOWS

	};
}