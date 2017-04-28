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

	LOG(LOG_ERROR) << "Error";
	LOG(LOG_WARNING) << "Warning";
	LOG(LOG_INFO) << "Info";
	LOG(LOG_DEBUG) << "Debug";
	LOG(LOG_DEBUG1) << "Debug 1";
	LOG(LOG_DEBUG2) << "Debug 2";
	LOG(LOG_DEBUG3) << "Debug 3";
	LOG(LOG_DEBUG4) << "Debug 4";

	return 0;
}