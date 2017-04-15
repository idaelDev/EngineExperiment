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
#include<vector>
#include "macros.h"
#pragma endregion

namespace Wander
{
	template <class T>
	class Vector : public std::vector<T>
	{
	public:
		Vector() : std::vector<T>(){}
		Vector(std::vector<T>& v) : std::vector<T>(v){}
		Vector(size_t size, const T& val = T()) : std::vector<T>(size, val) {}
		template <class InputIterator> Vector(InputIterator first, InputIterator last) : std::vector<T>(first, last) {};

		//Operator
		bool operator==(const Vector& other) const;
		Vector& operator+=(const Vector& other);
		Vector& operator+=(const T& other);

	};

	template<class T>
	inline bool Vector<T>::operator==(const Vector & other) const
	{
		if (std::vector<T>::size() != other.size())
		{
			return false;
		}
		for (uint32 i(0); i < std::vector<T>.size(); i++)
		{
			if (std::vector<T>::operator[](i) != other[i])
			{
				return false;
			}
		}
		return true;
	}

	template<class T>
	inline Vector & Vector<T>::operator+=(const Vector & other)
	{
		std::vector<T>::insert(std::vector<T>::end(), other.begin(), other.end());
		return (*this);
	}
	template<class T>
	inline Vector & Vector<T>::operator+=(const T & other)
	{
		std::vector<T>::push_back(other);
		return (*this);
	}
}