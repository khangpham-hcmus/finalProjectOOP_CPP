#include "FireHero.h"

int FireHero::KiemTraTuongSinh(Hero* other)
{
	if (other->getThuocTinh() == "Wood")
		return 1;
	return 0;
}

int FireHero::KiemTraTuongKhac(Hero* other)
{
	if (other->getThuocTinh() == "Water")
		return 1;
	return 0;
}

string FireHero::className()
{
	return "FireHero";
}

Hero* FireHero::clone()
{
	return new FireHero(*this);
}
