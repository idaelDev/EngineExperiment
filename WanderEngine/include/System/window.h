/**********************************************************************
//File			window
//Author		Judicael Abecassis
//Last modified	27/03/2017 16:45:40
//brief			Window création and management

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
#include "IManager.h"
#include "input.h"
#ifdef OS_WINDOWS
#include <windows.h>
#endif 
#pragma endregion


namespace Wander
{
	class Window : public IManager<Window>
	{

		friend Input;

	public:
		
		~Window() {};

		virtual bool open(std::string & title, size_t width = 800, size_t height = 600, size_t flags = 0);
		virtual void close();
		virtual bool opened();

		// Hérité via IManager
		virtual bool startUp() override;

		virtual void shutDown() override;

	private:

		Window() : IManager<Window>() {};

#ifdef OS_WINDOWS
		
		HWND hWND;
		HDC hDC;
		HGLRC hRC;

		LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#endif // OS_WINDOWS



	};
}