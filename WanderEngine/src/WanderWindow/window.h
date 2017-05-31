/**********************************************************************
//File			window
//Author		Judicael Abecassis
//Last modified	27/03/2017 16:45:40
//brief			Window cr�ation and management

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
**********************************************************************/

#pragma once
#pragma region Includes
#include <iostream>
#include "macros.h"
#include "event.h"
#include "wContainers.h"
#ifdef OS_WINDOWS
#include <windows.h>
#include <Windowsx.h>
#endif 
#pragma endregion


namespace Wander
{
	class Window
	{

	public:

		Window() {};
		~Window() {};

		virtual bool open(std::string & title, size_t width = 800, size_t height = 600, size_t flags = 0);
		virtual void close();
		virtual bool opened();

		virtual bool startUp();

		virtual void shutDown();

		virtual bool getNextEvent(Event &e);

	private:


#ifdef OS_WINDOWS

		HWND hWND;
		HDC hDC;
		HGLRC hRC;

		//LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#endif // OS_WINDOWS



	};
}