#pragma once
#include "Singleton.h"

/*
// An abstract for managers.
// Managers have to be singletons 
*/
class AbstractManager : public Singleton<AbstractManager>
{
	friend class Singleton<AbstractManager>;

public:
	
	AbstractManager(){}; 
	virtual ~AbstractManager(){};

	virtual void startUp();
	virtual void shutDown();

};