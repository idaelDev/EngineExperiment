/**********************************************************************
//File			event
//Author		Judicael Abecassis
//Last modified	27/03/2017 16:45:40
//brief			Contain events data for human interface

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
	class Event
	{
	public:
		typedef enum
		{
			NONE,
			KEY_UP,
			KEY_DOWN,
			MOUSE_MOVE,
			MOUSE_WHEEL,

			FINAL_EVENT
		} EventType;

		typedef enum
		{
			MOUSE_LBUTTON = 0x01, MOUSE_RBUTTON,
			MOUSE_MBUTTON = 0x04,
			BACKSPACE = 0x08, TAB,
			RETURN = 0x0D,
			PAUSE = 0x13, CAPSLOCK,
			ESCAPE = 0x1B,
			SPACE = 0x20, PAGEUP, PAGEDOWN, END, HOME, LEFT_ARROW, UP_ARROW, RIGHT_ARROW, DOWN_ARROW,
			INSERT = 0x2C, DELETE,
			KEY_0 = 0x30, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY9,
			A = 0x41, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
			NUM_0 = 0x60, NUM_1, NUM_2, NUM_3, NUM_4, NUM_5, NUM_6, NUM_7, NUM_8, NUM_9, NUM_MULT, NUM_ADD,
			NUM_SUB = 0x6D, NUM_DECIMAL, NUM_DIV,
			F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
			NUM_LOCK = 0x90,
			LSHIFT = 0xA0, RSHIFT, LCTRL, RCTRL, LALT, RALT,
			FINAL_KEYCODE
		} KeyCode;

		union
		{
			struct {
				int32 x;
				int32 y;
			};
			EventType type;
			KeyCode key;
		};
	};
}