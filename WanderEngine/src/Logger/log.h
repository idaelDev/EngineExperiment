/**********************************************************************
//File			log.h
//Author		Judicael Abecassis
//Last modified	09/04/2017 15:19:10
//brief			Logger system with level managment
				Type-safe, thread safe
				This work is base on Dr'dobbs article http://www.drdobbs.com/cpp/logging-in-c

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

	enum TLogLevel { LOG_ERROR, LOG_WARNING, LOG_INFO, LOG_DEBUG, LOG_DEBUG1, LOG_DEBUG2, LOG_DEBUG3, LOG_DEBUG4 };


	//Create a manage a stringstream object for output
	//The template parameter is fill with a output policy class that manage output configurations
	template <typename T>
	class Log
	{
	public:

		Log();
		virtual ~Log();
		std::ostringstream& get(TLogLevel level = LOG_INFO);

	public:

		static TLogLevel& reportingLevel();
		std::string Log<T>::toString(TLogLevel level);

	protected:
		std::ostringstream os;

	private:
		Log(const Log&);
		//Log& operator =(const Log&);

	};

	template<typename T>
	inline Log<T>::Log()
	{
	}

	template<typename T>
	inline Log<T>::~Log()
	{
		os << std::endl;
		T::Output(os.str());
	}

	template<typename T>
	inline std::ostringstream & Log<T>::get(TLogLevel level)
	{
		os << "- " << Time::now().milliseconds();
		os << " " << toString(level) << ": ";
		os << std::string(level > LOG_DEBUG ? level - LOG_DEBUG : 0, '\t');
		return os;
	}

	template<typename T>
	inline TLogLevel & Log<T>::reportingLevel()
	{
		static TLogLevel reportingLevel = LOG_DEBUG4;
		return reportingLevel;
	}

	template<typename T>
	inline std::string Log<T>::toString(TLogLevel level)
	{
		static const char* const buffer[] = { "ERROR", "WARNING", "INFO", "DEBUG", "DEBUG1", "DEBUG2", "DEBUG3", "DEBUG4" };
		return buffer[level];
	}


	class OutputPolicy
	{
	public:
		static FILE*& Stream();
		static void Output(const std::string& msg);
	};

	inline FILE*& OutputPolicy::Stream()
	{
		static FILE* pStream = stderr;
		return pStream;
	}

	inline void OutputPolicy::Output(const std::string& msg)
	{
		FILE* pStream = Stream();
		if (!pStream)
			return;
		fprintf(pStream, "%s", msg.c_str());
		fflush(pStream);
	}


	typedef Log<OutputPolicy> FLOG;

#ifndef LOG_MAX_LEVEL
#define LOG_MAX_LEVEL LOG_DEBUG4
#endif

#define LOG(level) \
    if (level > LOG_MAX_LEVEL) ;\
    else if (level > FLOG::reportingLevel() || !OutputPolicy::Stream()) ; \
    else FLOG().get(level)
}