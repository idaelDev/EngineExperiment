/**********************************************************************
//File			log.h
//Author		Judicael Abecassis
//Last modified	25/04/2017 08:48:20
//brief			Simple console log system
				- priority levels
				- can bee extend
				- WARNING not thread safe yet

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
**********************************************************************/

#pragma once
#pragma region Includes
#include <iostream>
#include "macros.h"
#include "wTime.h"
#pragma endregion

namespace Wander
{

	using namespace std;

	enum typelog {
		DEBUG,
		INFO,
		WARN,
		ERROR
	};

	//Configs
	struct structlog {
		bool headers = false;
		typelog level = WARN;
	};

	extern structlog LOGCFG;

	class Log {
	public:
		Log() {}
		Log(typelog type) {
			msglevel = type;
			if (LOGCFG.headers) {
				operator << ( "[" + Time::now().milliseconds + "]" + "[" + getLabel(type) + "]");
			}
		}
		~Log() {
			if (opened) {
				cout << endl;
			}
			opened = false;
		}
		template<class T>
		Log &operator<<(const T &msg) {
			if (msglevel >= LOGCFG.level) {
				cout << msg;
				opened = true;
			}
			return *this;
		}
	private:

		bool opened = false;
		typelog msglevel = DEBUG;
		inline string getLabel(typelog type) {
			string label;
			switch (type) {
			case DEBUG: label = "DEBUG"; break;
			case INFO:  label = "INFO "; break;
			case WARN:  label = "WARN "; break;
			case ERROR: label = "ERROR"; break;
			}
			return label;
		}
	};
}
