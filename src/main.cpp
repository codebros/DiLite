#include "dilite/di.h"
#include "i_warrior.h"
#include "i_weapon.h"
#include "shuriken.h"
#include "factory.h"

int main(int argc, char const *argv[])
{
	using namespace DiLite;
	using namespace SampleCode;

	DI::GetInstance().Bind<IWeapon, Shuriken>();
	DI::GetInstance().Bind<IWarrior>(&Factory::CreateSamurai);

	IWarrior* w1 = DI::GetInstance().Resolve<IWarrior>();
	IWarrior* w2 = DI::GetInstance().Resolve<IWarrior>();

	w1->SetName("Doi Toshikatsu");
	w2->SetName("Imagawa Yoshimoto");
	w1->Attack(w2);

	delete w1;
	delete w2;

	return 0;
}
