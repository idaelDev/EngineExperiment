#pragma once
#include "Utils/Singleton.h"


/*
// An abstract for managers.
// Managers have to be singletons
*/
class WanderAbstractManager
{
public:
	WanderAbstractManager() {};
	virtual ~WanderAbstractManager() {};

	virtual bool startUp() = 0 ;
	virtual void shutDown() = 0;
};