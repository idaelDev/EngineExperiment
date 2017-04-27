/**********************************************************************
//File			log
//Author		Judicael Abecassis
//Last modified	26/04/2017 18:17:58
//Definition

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
**********************************************************************/

#pragma region Includes
#include "log.h"
#include "wTime.h"
#pragma endregion

using namespace Wander;

template <typename T>
Log<T>::Log()
{
}

template <typename T>
std::ostringstream& Log<T>::Get(TLogLevel level)
{
	os << "- " << NowTime();
	os << " " << ToString(level) << ": ";
	os << std::string(level > logDEBUG ? level - logDEBUG : 0, '\t');
	return os;
}

template <typename T>
Log<T>::~Log()
{
	os << std::endl;
	T::Output(os.str());
}

template <typename T>
TLogLevel& Log<T>::ReportingLevel()
{
	static TLogLevel reportingLevel = logDEBUG4;
	return reportingLevel;
}

template <typename T>
std::string Log<T>::ToString(TLogLevel level)
{
	static const char* const buffer[] = { "ERROR", "WARNING", "INFO", "DEBUG", "DEBUG1", "DEBUG2", "DEBUG3", "DEBUG4" };
	return buffer[level];
}

template <typename T>
TLogLevel Log<T>::FromString(const std::string& level)
{
	if (level == "DEBUG4")
		return logDEBUG4;
	if (level == "DEBUG3")
		return logDEBUG3;
	if (level == "DEBUG2")
		return logDEBUG2;
	if (level == "DEBUG1")
		return logDEBUG1;
	if (level == "DEBUG")
		return logDEBUG;
	if (level == "INFO")
		return logINFO;
	if (level == "WARNING")
		return logWARNING;
	if (level == "ERROR")
		return logERROR;
	Log<T>().Get(logWARNING) << "Unknown logging level '" << level << "'. Using INFO level as default.";
	return logINFO;
}
