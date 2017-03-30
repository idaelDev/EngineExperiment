/**********************************************************************
//File			input
//Author		Judicael Abecassis
//Last modified	30/03/2017 18:29:58
//brief			Manage all Input event
				Singleton
				Contain getter fonction for key and mouse events

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
**********************************************************************/

#pragma once
#pragma region Includes
#include "Utils\Singleton.h"
#include "macros.h"
#include "Containers\Vector.h"
#include "Containers\List.h"
#include "System\event.h"
#pragma endregion

namespace Wander
{
	class Input : public Singleton<Input>
	{
		friend Singleton<Input>;
	public: 
		Vector<bool> keystate;
		Vector<bool> keyUp;
		Vector<bool> keyDown;
		List<Event> events;

		void startUp();
		void shutDown();
		virtual ~Input();
		
		bool getKeyDown(uint16 key);
		bool getKeyUp(uint16 key);
		bool getKey(uint16 key);

	private:
		Input();
	};

}
