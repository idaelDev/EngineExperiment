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
#include "window.h"
#include "wLogger.h"
#pragma endregion

using namespace Wander;

List<Event> events;

#ifdef OS_WINDOWS
LRESULT CALLBACK WndProc(HWND hWND, UINT uMsg, WPARAM wParam, LPARAM lParam)
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
	default: return DefWindowProc(hWND, uMsg, wParam, lParam); break;
	}
	events.push_back(e);
	return 0;
}
#endif // OS_WINDOWS

bool Window::open(std::string & title, size_t width, size_t height, size_t flags)
{
	WNDCLASSEX wc;
	HWND hwnd;


	//Step 1: Registering the Window Class
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = GetModuleHandle(NULL);;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "Window";
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Window Registration Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	// Step 2: Creating the Window
	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		"Window",
		"The title of my window",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,
		NULL, NULL, GetModuleHandle(NULL), NULL);

	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return false;
	}

	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);
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

bool Wander::Window::getNextEvent(Event &e)
{
#ifdef OS_WINDOWS
	MSG Msg;
	while (PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
#endif // OS_WINDOWS

	if (events.empty())
	{
		return false;
	}

	e = events.front();
	events.pop_front();
	return true;
}

bool Wander::Window::startUp()
{
	events = List<Event>();
	return true;
}

void Wander::Window::shutDown()
{
	if (opened())
		close();
}
