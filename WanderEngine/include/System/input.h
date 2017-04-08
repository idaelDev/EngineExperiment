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
#include "macros.h"
#include "IManager.h"
#include "Containers\Vector.h"
#include "Containers\List.h"
#include "System\event.h"
#pragma endregion

namespace Wander
{
	class Input : public IManager<Input>
	{
		friend Singleton<Input>;
	public: 
		
		~Input(){};

		void pushEvent(const Event& e);

		bool getKey(uint16 key) const;

		bool popEvent(Event& e);

		// Hérité via IManager
		virtual bool startUp() override;

		virtual void shutDown() override;

	private:
		Input() : IManager<Input>() {}
		
		Vector<bool> keyState;
		List<Event> events;
	};

}
