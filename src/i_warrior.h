#ifndef I_WARRIOR
#define I_WARRIOR

#include <string>

namespace SampleCode
{
	/**
	Interface for warriors.
	*/
	class IWarrior
	{

		protected:
			/** The name of the warrior */
			std::string _name;

			/** The remaining life of the warrior */
			int _life;

		public:
			/**
			Constructor

			@param name The name of the warrior.
			@param life The initial life of the warrior.
			*/
			IWarrior(const std::string& name, int life): _name(name), _life(life) {}

			/**
			Attacks an opponent.

			@param opponent The opponent to attack.
			*/
			virtual void Attack(IWarrior* opponent) const = 0;

			/**
			Takes damage from an opponents hit.

			@param damage The damage to receive.
			*/
			virtual void TakeDamage(int damage) = 0;

			/**
			Accessor function for the name.

			@post Does not change the object.
			@return Name of the warrior.
			*/
			virtual std::string GetName() const = 0;

			/**
			Mutator function for the name.

			@param newName The new name for the warrior.
			*/
			virtual void SetName(const std::string& newName) = 0;

			/**
			Accessor function for the alive property of the warrior.

			@post Does not change the object.
			@return True if alive.
			*/
			virtual bool IsAlive() const = 0;

			/**
			Empty deconstructor.
			*/
			virtual ~IWarrior() {}
	};
}

#endif
