#ifndef FACTORY_H
#define FACTORY_H

#include "dilite/di.h"
#include "i_warrior.h"

namespace SampleCode
{
	/**
	A factory class to instantiate objects in the program.
	Provides coupling between the running program and the
	DI framework.

	@author SW801
	*/
	class Factory
	{
		public:
			/**
			Creates a new Samurai using the DI framework.

			@return IWarrior pointer to the Samurai object.
			*/
			static IWarrior* CreateSamurai();
	};
}
#endif
