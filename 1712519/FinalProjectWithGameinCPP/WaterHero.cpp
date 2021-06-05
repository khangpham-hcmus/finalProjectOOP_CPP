#include"WaterHero.h"

int WaterHero::KiemTraTuongSinh(Hero* other)
{
	if (other->getThuocTinh() == "Metal")
		return 1;
	return 0;
}

int WaterHero::KiemTraTuongKhac(Hero* other)
{
	if (other->getThuocTinh() == "Earth")
		return 1;
	return 0;
}

string WaterHero::className()
{
	return "WaterHero";
}

Hero* WaterHero::clone()
{
	return new WaterHero(*this);
}
