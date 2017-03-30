/**********************************************************************
//File			List
//Author		Judicael Abecassis
//Last modified	28/03/2017 08:57:27
//brief			List container extended from std::list
				- Constant insert and remove operation

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
**********************************************************************/

#pragma once
#pragma region Includes
#include <list>
#pragma endregion

namespace Wander
{
	template <class T>
	class List : public std::list<T> {
	public:
		List() : std::list<T>() {}
		List(const std::list<T>& v) : std::list<T>(v) {}
		List(size_t n, const T& val = T()) : std::list<T>(n, val) {}
	};
}
