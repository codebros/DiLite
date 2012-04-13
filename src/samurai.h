#ifndef SAMURAI_H
#define SAMURAI_H

#include <string>
#include "i_weapon.h"
#include "i_warrior.h"

namespace SampleCode
{
	/**
	A Samurai warrior
	*/
	class Samurai : public IWarrior
	{
		private:
			/** The weapon of the warrior */
			IWeapon* _weapon;

		public:
			/**
			Constructor.

			@param w The weapon to use
			*/
			Samurai(IWeapon* w);

			/**
			Attack an oppononent.

			@param opponent The opponent to attack.
			@post Does not change the object.
			*/
			void Attack(IWarrior* opponent) const;

			/**
			Take damage from the warrior when hit by opponent

			@param damage The damage to receive.
			*/
			void TakeDamage(int damage);

			/**
			Accessor function for the name.

			@post Does not change the object.
			@return The name of the warrior.
			*/
			std::string GetName() const;

			/**
			Mutator function for the name.

			@param newName The new name for the warrior.
			*/
			void SetName(const std::string& newName);

			/**
			Accessor function for the alive property.
			*/
			bool IsAlive() const;

			/**
			Destructor
			*/
			~Samurai();
	};
}

#endif
