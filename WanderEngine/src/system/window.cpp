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
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

bool Wander::Window::startUp()
{
	return false;
}

void Wander::Window::shutDown()
{
}
