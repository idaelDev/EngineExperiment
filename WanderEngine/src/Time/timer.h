/**********************************************************************
//File			timer
//Author		Judicael Abecassis
//Last modified	09/04/2017 15:19:10
//brief			Mesure elapsed time for otpimisation and timeline option	

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
#include "time.h"
#pragma endregion

namespace Wander
{
	class Timer
	{
	private:
		Time last;
		bool paused;

	public:
		Timer();
		void setoff();
		Time frame();
		Time since() const;
		bool every(const Time& span);
		void pause();
		void unpause();
		void togglePause();
		bool gPaused();
	};
}
