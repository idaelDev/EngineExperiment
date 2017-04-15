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

using namespace Wander;

bool Input::startUp()
{
	keyState = Vector<bool>(Event::FINAL_KEYCODE, false);
	events = List<Event>();
	return true;
}

void Input::shutDown()
{
}

void Wander::Input::pushEvent(const Event & e)
{
	if (e.type == Event::KEY_UP || e.type == Event::KEY_DOWN)
	{
		keyState[e.key] = (e.type == Event::KEY_DOWN);
	}
	events.push_back(e);
}

bool Input::getKey(uint16 key) const
{
	return keyState[key];
}

bool Input::popEvent(Event & e)
{
	if (events.empty())
	{
		return false;
	}
	e = events.front();
	events.pop_front();
	return true;
}