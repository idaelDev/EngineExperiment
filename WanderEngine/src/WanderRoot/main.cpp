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
#include "wRoot.h"
#include "wLogger.h"
#pragma endregion

using namespace Wander;

#ifdef OS_WINDOWS
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
#else
int main(int argc, char* argv[])
#endif // OS_WINDOWS
{
	FILE* pFile;
	fopen_s(&pFile, "application.log", "w");
	OutputPolicy::Stream() = pFile;

	Root engine;
	engine.startUp();
	engine.run();
	engine.shutDown();

	return 0;
}