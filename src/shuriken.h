#ifndef SHURIKEN_H
#define SHURIKEN_H

#include <string>
#include "i_weapon.h"

namespace SampleCode
{
	/**
	A Shuriken (ancient Japanese) weapon
	that can be used by warriors
	*/
	class Shuriken : public IWeapon
	{
		private:
			/** The damage given by the weapon */
			int _damage;

			/** The remaining quantity of shurikens */
			int _quantity;

		public:
			/**
			Default constructor

			@post The damage and quantity are initialized to zero.
			*/
			Shuriken();

			/**
			Use the weapon.

			@return Damage given by weapon
			*/
			int Use();

			/**
			Accessor function for the name.

			@return The weapons name.
			*/
			std::string GetName() const;

			/**
			Accessor function for the broken property.

			@return True if the weapon is broken.
			*/
			bool IsBroken() const;
	};
}

#endif
