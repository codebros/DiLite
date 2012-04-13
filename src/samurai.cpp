#include <iostream>
#include "samurai.h"

namespace SampleCode
{
	Samurai::Samurai(IWeapon* w) : IWarrior("Unnamed Samurai", 100), _weapon(w) {}

	void Samurai::Attack(IWarrior* opponent) const
	{
		int damage = _weapon->Use();
		std::cout << _name << " hits " << opponent->GetName() << " with a \"" << _weapon->GetName() << "\", dealing " << damage << " points of damage!" << std::endl;
		opponent->TakeDamage(damage);
	}

	void Samurai::TakeDamage(int damage)
	{
		if (_life > 0)
		{
			if (damage == 0)
			{
				std::cout << _name << " laughs at the pointless attack!" << std::endl;
			}
			else
			{
				_life -= damage;
				if (_life <= 0)
				{
					std::cout << _name << " dies" << std::endl;
				}
			}
		} 
		else
		{
			std::cout << "Leave " << _name << " alone!" << std::endl;
		}
	}

	std::string Samurai::GetName() const
	{
		return _name;
	}

	void Samurai::SetName(const std::string& newName)
	{
		_name = newName;
	}

	bool Samurai::IsAlive() const
	{
		return !(_life <= 0);
	}
	
	Samurai::~Samurai()
	{
		delete _weapon;
	}
}
