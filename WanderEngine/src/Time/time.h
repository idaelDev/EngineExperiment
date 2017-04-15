/**********************************************************************
//File			time.h
//Author		Judicael Abecassis
//Last modified	08/04/2017 16:37:38
//brief			Get the time, the date, manage time operations

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
#pragma endregion

namespace Wander
{
	class Time
	{
	protected:
		long long usec;

	public:
		Time();
		Time(long long useconds);
		Time(long useconds, long mseconds, long seconds = 0, long minutes = 0, long hours = 0, long days = 0);
		
		Time operator+(const Time& other) const;
		Time operator-(const Time& other) const;
		Time operator*(const long long& v) const;
		Time operator/(const long long& v) const;
		bool operator==(const Time& other) const;
		bool operator!=(const Time& other) const;
		bool operator>(const Time& other) const;
		bool operator<(const Time& other) const;
		bool operator>=(const Time& other) const;
		bool operator<=(const Time& other) const;
		Time& operator+=(const Time& other);
		Time& operator-=(const Time& other);

		inline long days() const { return (long)(usec / 86400000000LL); }
		inline long hours() const { return (long)(usec / 3600000000LL); }
		inline long minutes() const { return (long)(usec / 60000000LL); }
		inline long seconds() const { return (long)(usec / 1000000LL); }
		inline long long milliseconds() const { return usec / 1000LL; }
		inline long long microseconds() const { return usec; }
	
		double fSeconds() const;
	
		static Time now();
	};
}
