/**********************************************************************
//File			IManager
//Author		Judicael Abecassis
//Last modified	31/03/2017 18:35:33
//brief			Abstract class of managers, contain virtual fonction for startup and shut down modules

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
#include "Utils\Singleton.h"
#pragma endregion

namespace Wander
{
	template<class T>
	class IManager: public Singleton<T>
	{

		friend Singleton<T>;

	protected:
		IManager() {};
		~IManager() {};

	public:
		virtual bool startUp() = 0;
		virtual void shutDown() = 0;
	};
}
