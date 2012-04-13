#ifndef SWORD_H
#define SWORD_H

#include <string>
#include "i_weapon.h"

namespace SampleCode
{
	/**
	A classic sword for use by warriors.
	*/
	class Sword : public IWeapon
	{
		private:
			/** The damage given by the weapon on hit */
			int _damage;

		public:
			/** Default constructor */
			Sword();

			/**
			Use the weapon

			@return The amount of damage given by the weapon.
			*/
			int Use();

			/**
			Accessor function for the name

			@post Does not change the object.
			@return The name of the weapon.
			*/
			std::string GetName() const;

			/**
			Accessor function for the broken property

			@post Does not change the object.
			@return True if weapon is broken.
			*/
			bool IsBroken() const;
	};
}

#endif
