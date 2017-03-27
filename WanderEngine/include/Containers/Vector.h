/**********************************************************************
//File			Vector
//Author		Judicael Abecassis
//Last modified	27/03/2017 16:45:40
//brief			Vector class extended from std::vector

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
**********************************************************************/

#pragma once
#pragma region Includes
#include<iostream>
#include<vector>
#pragma endregion

namespace Wander
{
	template <class T>
	class Vector<T> : public std::vector<T>
	{
	public:
		Vector() : std::vector<T>(){}
		Vector(std::vector<T>& v) : std::vector<T>(v){}
		Vector(size_t size, const T& val = T()) : std::vector(size, val) {}
		template <class InputIterator> Vector(InputIterator first, InputIterator last) : std::vector(first, last) {};

		//Operator
		bool operator==(const Vector& other) const;
		Vector& operator+=(const Vector& other);
		Vector& operator+=(const T& other);
		Vector operator+(const Vector& other);
		Vector operator+(const T& other);

	};
}