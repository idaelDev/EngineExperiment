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
#include "wLogger.h"
#pragma endregion

using namespace Wander;

bool Root::startUp()
{
	LOG(LOG_INFO) << "Starting up";
	Sleep(2000); //simulate startup;
	LOG(LOG_INFO) << "Done";
	return true;
}

void Root::shutDown()
{
	LOG(LOG_INFO) << "Shuting down";
}

void Root::run()
{
	LOG(LOG_DEBUG) << "Start running...";
	Time ms_per_update(16000); //dirty
	Timer timer;
	Time elapsed;
	Time lag(0LL);
	while (true)
	{
		elapsed = timer.frame();
		lag += elapsed;
		LOG(LOG_DEBUG3) << "Frame...elapsed : " << elapsed.fSeconds();
		LOG(LOG_DEBUG3) << "Frame...lag : " << lag.fSeconds();
		
		//process input;
		LOG(LOG_DEBUG3) << "Process input...";
		Sleep(4);

		while (lag >= ms_per_update)
		{
			//Update gp
			Sleep(4);
			lag -= ms_per_update;
			LOG(LOG_DEBUG4) << "Upate...lag : " << lag.fSeconds();
		}

		LOG(LOG_DEBUG3) << "render";
		//render(lag/ms_per_update)
		Sleep(8);
	}
}
