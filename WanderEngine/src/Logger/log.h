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

#include <sstream>
#include <string>
#include <stdio.h>
#include "macros.h"
#include "wTime.h"
#pragma endregion

namespace Wander
{

	enum TLogLevel { logERROR, logWARNING, logINFO, logDEBUG, logDEBUG1, logDEBUG2, logDEBUG3, logDEBUG4 };

	template <typename T>
	class Log
	{
	public:
		Log();
		virtual ~Log();
		std::ostringstream& Get(TLogLevel level = logINFO);
	public:
		static TLogLevel& ReportingLevel();
		static std::string ToString(TLogLevel level);
		static TLogLevel FromString(const std::string& level);
	protected:
		std::ostringstream os;
	private:
		Log(const Log&);
		Log& operator =(const Log&);
	};

	class Output2FILE
	{
	public:
		static FILE*& Stream();
		static void Output(const std::string& msg);
	};

	inline FILE*& Output2FILE::Stream()
	{
		static FILE* pStream = stderr;
		return pStream;
	}

	inline void Output2FILE::Output(const std::string& msg)
	{
		FILE* pStream = Stream();
		if (!pStream)
			return;
		fprintf(pStream, "%s", msg.c_str());
		fflush(pStream);
	}

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#   if defined (BUILDING_FILELOG_DLL)
#       define FILELOG_DECLSPEC   __declspec (dllexport)
#   elif defined (USING_FILELOG_DLL)
#       define FILELOG_DECLSPEC   __declspec (dllimport)
#   else
#       define FILELOG_DECLSPEC
#   endif // BUILDING_DBSIMPLE_DLL
#else
#   define FILELOG_DECLSPEC
#endif // _WIN32

	class FILELOG_DECLSPEC FILELog : public Log<Output2FILE> {};
	//typedef Log<Output2FILE> FILELog;

#ifndef FILELOG_MAX_LEVEL
#define FILELOG_MAX_LEVEL logDEBUG4
#endif

#define FILE_LOG(level) \
    if (level > FILELOG_MAX_LEVEL) ;\
    else if (level > FILELog::ReportingLevel() || !Output2FILE::Stream()) ; \
    else FILELog().Get(level)
}