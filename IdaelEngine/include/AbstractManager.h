#pragma once
#include "Utils/Singleton.h"

namespace Idael
{
	/*
	// An abstract for managers.
	// Managers have to be singletons
	*/
	class AbstractManager : public Singleton<AbstractManager>
	{
		friend class Singleton<AbstractManager>;

	public:

		AbstractManager() {};
		virtual ~AbstractManager() {};

		virtual void startUp();
		virtual void shutDown();

	};

}