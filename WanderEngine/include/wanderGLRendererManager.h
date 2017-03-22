#pragma once

// C++ Headers
#include <string>
#include <iostream>

// SDL2 Headers
#include <SDL2/SDL.h>
#include "wanderGLRendererManager.h"

#include <GL/glew.h>
#include "wanderRendererManager.h"

class WanderGLRendererManager : public WanderRendererManager
{
private:
	std::string programName = "Headerphile SDL2 - OpenGL thing";

	// Our SDL_Window ( just like with SDL2 wihout OpenGL)
	SDL_Window *mainWindow;

	// Our opengl context handle
	SDL_GLContext mainContext;

protected:
	virtual void checkError(int line = -1) override;
	virtual void printAttributes() override;

public:
	WanderGLRendererManager() {}
	virtual ~WanderGLRendererManager() {};


	// Hérité via WanderRendererManager
	virtual bool startUp() override;

	virtual void shutDown() override;

	virtual void clearColor(float r, float g, float b, float a = 1.0) override;

	virtual void clear() override;

	virtual void swapBuffers() override;
};