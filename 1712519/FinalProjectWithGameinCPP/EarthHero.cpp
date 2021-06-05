#include"EarthHero.h"

int EarthHero::KiemTraTuongSinh(Hero* other)
{
    if (other->getThuocTinh() == "Fire")
        return 1;
    return 0;
}

int EarthHero::KiemTraTuongKhac(Hero* other)
{
    if (other->getThuocTinh() == "Wood")
        return 1;
    return 0;
}

string EarthHero::className()
{
    return "EarthHero";
}

Hero* EarthHero::clone()
{
    return new EarthHero(*this);
}
