#include "MetalHero.h"

int MetalHero::KiemTraTuongSinh(Hero* other)
{
	if (other->getThuocTinh() == "Water")
		return 1;
	return 0;
}

int MetalHero::KiemTraTuongKhac(Hero* other)
{
	if (other->getThuocTinh() == "Fire")
		return 1;
	return 0;
}

string MetalHero::className()
{
	return "MetalHero";
}

Hero* MetalHero::clone()
{
	return new MetalHero(*this);
}
