/**********************************************************************
//File			main
//Author		Judicael Abecassis
//Last modified	15/04/2017 01:50:40
//Definition

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
**********************************************************************/

#pragma region Includes
#include "wLogger.h"
#pragma endregion

using namespace Wander;

int main(int argc, char* argv[])
{
	try
	{
		FILELog::ReportingLevel() = FILELog::FromString(argv[1] ? argv[1] : "DEBUG1");
		const int count = 3;
		FILE_LOG(logDEBUG) << "A loop with " << count << " iterations";
		for (int i = 0; i != count; ++i)
		{
			FILE_LOG(logDEBUG1) << "the counter i = " << i;
		}
		return 0;
	}
	catch (const std::exception& e)
	{
		FILE_LOG(logERROR) << e.what();
	}
	return -1;
}