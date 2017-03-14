#pragma once

namespace Wander
{
	class Wander_Window
	{
	public:
		Wander_Window();
		~Wander_Window();

		virtual bool init();
		virtual bool setContext();
		virtual void cleanUp();
		virtual void checkError(int lline = -1);
		
	};

}