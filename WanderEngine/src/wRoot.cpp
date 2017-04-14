/**********************************************************************
//File			WanderCPP
//Author		Judicael Abecassis
//Last modified	08/04/2017 15:58:03
//Definition

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
**********************************************************************/

#pragma region Includes
#include <iostream>
#include <windows.h>

#include "wRoot.h"
#include "wTime.h"
#pragma endregion

using namespace Wander;

bool Root::startUp()
{
	std::cout << "Starting up" << std::endl;
	Sleep(2000); //simulate startup;
	std::cout << "Done" << std::endl;
	return true;
}

void Root::shutDown()
{
	std::cout << "Shuting down" << std::endl;
}

void Root::run()
{
	std::cout << "Start running..." << std::endl;
	Time ms_per_update(16000); //dirty
	Timer timer;
	Time elapsed;
	Time lag(0LL);
	while (true)
	{
		elapsed = timer.frame();
		lag += elapsed;
		std::cout << "Frame...elapsed : " << elapsed.fSeconds() << std::endl;
		std::cout << "Frame...lag : " << lag.fSeconds() << std::endl;
		
		//process input;
		std::cout << "Process input..." << std::endl;
		Sleep(4);

		while (lag >= ms_per_update)
		{
			//Update gp
			Sleep(4);
			lag -= ms_per_update;
			std::cout << "Upate...lag : " << lag.fSeconds() << std::endl;
		}

		std::cout << "render" << std::endl;
		//render(lag/ms_per_update)
		Sleep(8);
	}
}
