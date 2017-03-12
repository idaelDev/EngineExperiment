#pragma once
#include <SDL2/SDL.h>
#include "AbstractManager.h"

class ApplicationManager : public AbstractManager
{
public:
	ApplicationManager() {};
	~ApplicationManager() {};

	virtual void startUp();
	virtual void shutDown();

};