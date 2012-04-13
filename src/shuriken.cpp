#include <iostream>
#include "shuriken.h"

namespace SampleCode
{
	Shuriken::Shuriken() : _damage(20), _quantity(100) {}

	int Shuriken::Use()
	{
		if(!IsBroken())
		{
			_quantity -= 10;
			return _damage;
		}
		else
		{
			return 0;
		}
	}

	std::string Shuriken::GetName() const
	{
		return "Shuriken of Might";
	}

	bool Shuriken::IsBroken() const
	{
		return _quantity <= 0;
	}
}
