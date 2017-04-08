/**********************************************************************
//File			window
//Author		Judicael Abecassis
//Last modified	27/03/2017 16:45:40
//Definition	window.h
http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
**********************************************************************/
#pragma region Includes
#include "System\window.h"
#pragma endregion

using namespace Wander;

#ifdef OS_WINDOWS
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}
#endif // OS_WINDOWS

bool Window::open(std::string & title, size_t width, size_t height, size_t flags)
{
	if (opened()) return  true;
#ifdef OS_WINDOWS
	WNDCLASS wc;

	PIXELFORMATDESCRIPTOR pfd;
	int format;

	// Register window class
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = GetModuleHandle(NULL);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "WanderWindowClass";
	
	if (!RegisterClass(&wc))
	{
		std::cerr << "Window registration failed" << std::endl;
		return false;
	}

	DWORD wStyle = WS_CAPTION
		| WS_MINIMIZEBOX
		| 0
		| 0
		| WS_SYSMENU | WS_VISIBLE;
	
	// Find out needed window size for wanted client area size
	RECT rect = { 0,0,(int)width,(int)height };
	AdjustWindowRect(&rect, wStyle, false);
	width = rect.right - rect.left;
	height = rect.bottom - rect.top;

	// Create window
	hWND = CreateWindow("WanderWindow", title.c_str(), wStyle,   // Properties
		CW_USEDEFAULT, CW_USEDEFAULT, width, height,
		NULL, NULL, GetModuleHandle(NULL), NULL);
	
	hDC = GetDC(hWND); //Get the device context (DC)
	ZeroMemory(&pfd, sizeof(pfd)); // set the pixel format for the DC
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 24;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;
	format = ChoosePixelFormat(hDC, &pfd);
	SetPixelFormat(hDC, format, &pfd);
	hRC = wglCreateContext(hDC); // create and enable the render context (RC)
	wglMakeCurrent(hDC, hRC);
#endif // OS_WINDOWS
	return true;
}

void Window::close()
{
#ifdef OS_WINDOWS
	DestroyWindow(hWND);
	hWND = 0;
#endif // OS_WINDOWS
}

bool Window::opened()
{
#ifdef OS_WINDOWS
	return (hWND);
#endif // OS_WINDOWS
}

LRESULT Window::MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	Event e;
	switch (uMsg) {
	case WM_CREATE:
		return 0;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		hWND = 0;
		return 0;
		break;
	case WM_KEYDOWN: case WM_KEYUP: // Key pressed
		e.type = (uMsg == WM_KEYDOWN) ? Event::KEY_DOWN : Event::KEY_UP;
		switch (wParam) {
#define MAP(a,b) case a: e.key = Event::b; break;
			MAP(VK_LBUTTON, MOUSE_LBUTTON) MAP(VK_RBUTTON, MOUSE_RBUTTON) MAP(VK_MBUTTON, MOUSE_MBUTTON)
				MAP(VK_BACK, BACKSPACE) MAP(VK_TAB, TAB)
				MAP(VK_RETURN, RETURN)
				MAP(VK_PAUSE, PAUSE)
				MAP(VK_CAPITAL, CAPSLOCK)
				MAP(VK_ESCAPE, ESCAPE)
				MAP(VK_SPACE, SPACE)
				MAP(VK_PRIOR, PAGEUP) MAP(VK_NEXT, PAGEDOWN) MAP(VK_END, END) MAP(VK_HOME, HOME)
				MAP(VK_LEFT, LEFT_ARROW) MAP(VK_UP, UP_ARROW) MAP(VK_RIGHT, RIGHT_ARROW) MAP(VK_DOWN, DOWN_ARROW)
				MAP(VK_INSERT, INSERT) MAP(VK_DELETE, DEL)
				MAP(VK_NUMPAD0, NUM_0)
				MAP(VK_NUMPAD1, NUM_1) MAP(VK_NUMPAD2, NUM_2) MAP(VK_NUMPAD3, NUM_3)
				MAP(VK_NUMPAD4, NUM_4) MAP(VK_NUMPAD5, NUM_5) MAP(VK_NUMPAD6, NUM_6)
				MAP(VK_NUMPAD7, NUM_7) MAP(VK_NUMPAD8, NUM_8) MAP(VK_NUMPAD9, NUM_9)
				MAP(VK_MULTIPLY, NUM_MULT) MAP(VK_ADD, NUM_ADD) MAP(VK_SUBTRACT, NUM_SUB) MAP(VK_DECIMAL, NUM_DECIMAL) MAP(VK_DIVIDE, NUM_DIV)
				MAP(VK_F1, F1) MAP(VK_F2, F2) MAP(VK_F3, F3) MAP(VK_F4, F4)
				MAP(VK_F5, F5) MAP(VK_F6, F6) MAP(VK_F7, F7) MAP(VK_F8, F8)
				MAP(VK_F9, F9) MAP(VK_F10, F10) MAP(VK_F11, F11) MAP(VK_F12, F12)
				MAP(VK_NUMLOCK, NUMLOCK)
				MAP(VK_LSHIFT, LSHIFT) MAP(VK_RSHIFT, RSHIFT)
				MAP(VK_LCONTROL, LCTRL) MAP(VK_RCONTROL, RCTRL)
				MAP(VK_LMENU, LALT) MAP(VK_RMENU, RALT)
#undef MAP
		default:
			if ((wParam >= 0x30 && wParam <= 0x39) || (wParam >= 0x41 && wParam <= 0x5A))
				e.key = (Event::KeyCode)wParam;
			else return 0;
		}
		break;
	case WM_MOUSEMOVE: 
		e.type = Event::MOUSE_MOVE;
		
		e.x = GET_X_LPARAM(lParam);
		e.y = GET_Y_LPARAM(lParam);
		break;
	case WM_MOUSEWHEEL:
		e.type = Event::MOUSE_WHEEL;
		e.y = GET_WHEEL_DELTA_WPARAM(wParam);
		break;
	default: return DefWindowProc(hwnd, uMsg, wParam, lParam); break;
	}
	Input::Instance().pushEvent(e);
	return 0;
}

bool Wander::Window::startUp()
{
	return true;
}

void Wander::Window::shutDown()
{
	if (opened())
		close();
}
