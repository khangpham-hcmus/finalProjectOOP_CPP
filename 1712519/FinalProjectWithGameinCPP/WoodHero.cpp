#include"WoodHero.h"

int WoodHero::KiemTraTuongSinh(Hero* other)
{
	if (other->getThuocTinh() == "Water")
		return 1;
	return 0;
}

int WoodHero::KiemTraTuongKhac(Hero* other)
{
	if (other->getThuocTinh() == "Metal")
		return 1;
	return 0;
}

string WoodHero::className()
{
	return "WoodHero";
}

Hero* WoodHero::clone()
{
	return new WoodHero(*this);
}
