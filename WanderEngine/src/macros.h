/**********************************************************************
//File			macros
//Author		Judicael Abecassis
//Last modified	27/03/2017 16:45:40
//brief			Define all global macros

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
**********************************************************************/

#pragma once

#if defined _WIN32 || __WINDOWS__
#define OS_WINDOWS
#elif defined  __linux__
#define OS_LINUX
#endif // 0

namespace Wander {
	typedef signed char        int8;
	typedef short              int16;
	typedef int                int32;
	typedef long long          int64;
	typedef unsigned char      uint8;
	typedef unsigned short     uint16;
	typedef unsigned int       uint32;
	typedef unsigned long long uint64;
}