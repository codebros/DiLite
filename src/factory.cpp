#include "factory.h"
#include "i_weapon.h"
#include "samurai.h"

namespace SampleCode
{
	IWarrior* Factory::CreateSamurai()
	{
		return new Samurai(DiLite::DI::GetInstance().Resolve<IWeapon>());
	}
}
