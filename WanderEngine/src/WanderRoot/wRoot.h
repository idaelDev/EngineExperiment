/**********************************************************************
//File			wRoot.h
//Author		Judicael Abecassis
//Last modified	08/04/2017 15:54:47
//brief	..

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
#include "WanderWindow\window.h"
#include "Containers\List.h"
#pragma endregion

namespace Wander
{
	class Root
	{
	public:

		Root();
		virtual ~Root() {}

		bool startUp();
		void shutDown();

		void run();

	private:
		Window* sWindow;
	};
}
