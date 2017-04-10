/**********************************************************************
//File			time
//Author		Judicael Abecassis
//Last modified	08/04/2017 16:57:40
//Definition

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
**********************************************************************/

#pragma region Includes
#include "time/time.h"

#include <ctime>
#if defined OS_WINDOWS
#include <sys/timeb.h>
#elif defined OS_LINUX
#include <sys/time.h>
#endif
#pragma endregion

using namespace Wander;

Time::Time(){}

Time::Time(long long useconds)
	:usec(useconds){}

Time::Time(long useconds, long mseconds, long seconds, long minutes, long hours, long days)
	:usec(useconds + mseconds * 1000LL + seconds * 1000000LL + minutes * 60000000LL + hours * 3600000000LL + days * 86400000000LL){}

Time Time::operator+(const Time & other) const
{
	return Time(usec+other.usec);
}

Time Time::operator-(const Time & other) const
{
	return Time(usec-other.usec);
}

Time Time::operator*(const long long & v) const
{
	return Time(usec*v);
}

Time Time::operator/(const long long & v) const
{
	return Time(usec/v);
}

bool Time::operator==(const Time & other) const
{
	return usec == other.usec;
}

bool Time::operator!=(const Time & other) const
{
	return usec != other.usec;
}

bool Time::operator>(const Time & other) const
{
	return usec > other.usec;
}

bool Time::operator<(const Time & other) const
{
	return usec < other.usec;
}

bool Time::operator>=(const Time & other) const
{
	return usec >= other.usec;
}

bool Time::operator<=(const Time & other) const
{
	return usec <= other.usec;
}

Time& Time::operator+=(const Time & other)
{
	usec += other.usec;
	return *this;
}

Time& Time::operator-=(const Time & other)
{
	usec -= other.usec;
	return *this;
}

double Wander::Time::fSeconds() const
{
	return ((double)seconds()) + ((double)(microseconds() % 1000000LL) / 1000000.0);
}

Time Wander::Time::now()
{
#if defined OS_WINDOWS
	struct _timeb timebuffer;
	_ftime(&timebuffer);
	return Time(0, timebuffer.millitm, timebuffer.time);
#elif defined OS_LINUX
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return Time(tv.tv_usec, 0, tv.tv_sec);
#endif
}
