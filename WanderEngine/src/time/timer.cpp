/**********************************************************************
//File			timer
//Author		Judicael Abecassis
//Last modified	09/04/2017 15:28:31
//Definition

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
**********************************************************************/

#pragma region Includes
#include "time/timer.h"
#pragma endregion

using namespace Wander;

Wander::Timer::Timer()
: last(Time::now()), paused(false) {}

void Wander::Timer::setoff()
{
	last = Time::now();
}

Time Wander::Timer::frame()
{
	if(!paused)
	{
		Time now(Time::now());
		Time wtr(now - last);
		last = now;
		return wtr;
	}
	return 0;
}

Time Wander::Timer::since() const
{
	return Time::now() - last;
}

bool Wander::Timer::every(const Time & span)
{
	Time now(Time::now());
	if (last < now - span && !paused)
	{
		last = now;
		return true;
	}
	else return false;
}

void Timer::pause()
{
	if (!paused)
	{
		last -= Time::now();
		paused = true;
	}
}

void Wander::Timer::unpause()
{
	if (!paused)
	{
		last += Time::now();
		paused = false;
	}
}

void Wander::Timer::togglePause()
{
	if (paused)
	{
		unpause();
	}
	else
	{
		pause();
	}
}

bool Wander::Timer::gPaused()
{
	return paused;
}

