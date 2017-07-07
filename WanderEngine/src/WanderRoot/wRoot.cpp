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
#include<string>
#include "wRoot.h"
#include "wTime.h"
#include "wLogger.h"
#pragma endregion

using namespace Wander;

Wander::Root::Root()
{
	sWindow = new Window();
}

bool Root::startUp()
{
	LOG(LOG_INFO) << "Starting up";
	sWindow->startUp();

	std::string title = "Hello World";
	
	if (!sWindow->open(title))
	{
		LOG(LOG_ERROR) << "Fail open window";
		shutDown();
	}

	LOG(LOG_INFO) << "Done";
	return true;
}

void Root::shutDown()
{
	LOG(LOG_INFO) << "Shuting down";
	sWindow->close();
	sWindow->shutDown();
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
		LOG(LOG_DEBUG4) << "Process input...";
		Event e;
		while (sWindow->getNextEvent(e))
		{
			LOG(LOG_DEBUG3) << "Event window : " << e.key;
		}

		while (lag >= ms_per_update)
		{
			//Update gp
			lag -= ms_per_update;
			LOG(LOG_DEBUG4) << "Upate...lag : " << lag.fSeconds();
		}

		LOG(LOG_DEBUG3) << "render";
		//render(lag/ms_per_update)
	}
}
