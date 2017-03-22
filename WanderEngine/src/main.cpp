// Headerphile.com OpenGL Tutorial part 1
// A Hello World in the world of OpenGL ( creating a simple windonw and setting background color )
// Source code is an C++ adaption / simplicication of : https://www.opengl.org/wiki/Tutorial1:_Creating_a_Cross_Platform_OpenGL_3.2_Context_in_SDL_(C_/_SDL)
// Compile : clang++ main.cpp -lGL -lSDL2 -std=c++11 -o Test

// C++ Headers
#include <string>
#include <iostream>

// OpenGL / glew Headers
#define GL3_PROTOTYPES 1

// SDL2 Headers
#include <SDL2/SDL.h>
#include "wanderGLRendererManager.h"


std::string programName = "Headerphile SDL2 - OpenGL thing";

WanderGLRendererManager rendererManager;

void RunGame();

int main(int argc, char *argv[])
{
	if (!rendererManager.startUp())
		return -1;

	// Clear our buffer with a black background
	// This is the same as :
	// 		SDL_SetRenderDrawColor(&renderer, 255, 0, 0, 255);
	// 		SDL_RenderClear(&renderer);
	//
	rendererManager.clearColor(0.0, 0.0, 0.0);
	rendererManager.clear();
	rendererManager.swapBuffers();

	RunGame();

	rendererManager.shutDown();


	return 0;
}

void RunGame()
{
	bool loop = true;

	while (loop)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				loop = false;

			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					loop = false;
					break;
				case SDLK_r:
					// Cover with red and update
					rendererManager.clearColor(1.0, 0.0, 0.0, 1.0);
					rendererManager.clear();
					rendererManager.swapBuffers();
					break;
				case SDLK_g:
					// Cover with green and update
					rendererManager.clearColor(0.0, 1.0, 0.0, 1.0);
					rendererManager.clear();
					rendererManager.swapBuffers();
					break;
				case SDLK_b:
					// Cover with blue and update
					rendererManager.clearColor(0.0, 0.0, 1.0, 1.0);
					rendererManager.clear();
					rendererManager.swapBuffers();
					break;
				default:
					break;
				}
			}
		}

		// Swap our back buffer to the front
		// This is the same as :
		// 		SDL_RenderPresent(&renderer);
	}
}
