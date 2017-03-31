/**********************************************************************
//File			input
//Author		Judicael Abecassis
//Last modified	31/03/2017 18:48:28
//Definition input.h

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
**********************************************************************/

#pragma region Includes
#include"System\input.h"
#pragma endregion

bool Wander::Input::startUp()
{
	keyState = Vector<bool>(Event::FINAL_KEYCODE, false);
	keyDown = Vector<bool>(Event::FINAL_KEYCODE, false);
	keyUp = Vector<bool>(Event::FINAL_KEYCODE, false);
	events = List<Event>();
	return true;
}

void Wander::Input::shutDown()
{
}

bool Wander::Input::getKeyDown(uint16 key)
{
	return keyDown[key];
}

bool Wander::Input::getKeyUp(uint16 key)
{
	return keyUp[key];
}

bool Wander::Input::getKey(uint16 key)
{
	return keyState[key];
}

bool Wander::Input::popEvent(Event & e)
{
	if (events.empty())
	{
		return false;
	}
	e = events.front();
	events.pop_front();
	return true;
}