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
#include "wRoot.h"
#include "wTime.h"
#pragma endregion


bool Wander::Root::startUp()
{
	return true;
}

void Wander::Root::shutDown()
{
}

void Wander::Root::run()
{
	Time ms_per_update(60000); //dirty
	Timer timer;
	Time elapsed;
	Time lag(0LL);
	while (true)
	{
		elapsed = timer.frame();
		lag += elapsed;

		//processInput

		if (lag >= ms_per_update)
		{
			//Update gp
			lag -= ms_per_update;
		}

		//render(lag/ms_per_update)

	}
}