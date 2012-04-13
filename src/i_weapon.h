#ifndef I_WEAPON_H
#define I_WEAPON_H

#include <string>

namespace SampleCode
{
	/**
	Interface for weapons.
	*/
	class IWeapon
	{
		public:
			/**
			Use the weapon.

			@post Does not change the object.
			@return The damage given by the weapon.
			*/
			virtual int Use() = 0;

			/**
			Accessor function for the name.

			@post Does not change the object.
			@return The name of the weapon.
			*/
			virtual std::string GetName() const = 0;

			/**
			Accessor function for the broken property.

			@post Does not change the object.
			@return True if broken.
			*/
			virtual bool IsBroken() const = 0;

			/**
			Empty deconstructor.
			*/
			virtual ~IWeapon() {}
	};
}

#endif
