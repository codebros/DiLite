#include "sword.h"

namespace SampleCode
{
	Sword::Sword() : _damage(5) {}

	int Sword::Use()
	{
		return _damage;
	}

	std::string Sword::GetName() const
	{
		return "Deadly sharp sword";
	}

	bool Sword::IsBroken() const
	{
		return false;
	}
}
