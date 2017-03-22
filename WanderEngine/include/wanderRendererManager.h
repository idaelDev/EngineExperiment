#pragma once
#include "wanderAbstractManager.h"

/*Manage all render aspect and make interface with */
class WanderRendererManager : public WanderAbstractManager
{
public :
	WanderRendererManager() {};
	virtual ~WanderRendererManager(){};

	virtual bool startUp() = 0;
	virtual void shutDown() = 0;
	
	virtual void clearColor(float r, float g, float b, float a = 1.0) = 0;
	virtual void clear() = 0;
	virtual void swapBuffers() = 0;

protected:

	virtual void checkError(int line = -1) = 0;
	virtual void printAttributes() = 0;

};