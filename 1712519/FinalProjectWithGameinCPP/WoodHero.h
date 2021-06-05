#pragma once
#include"Hero.h"
class WoodHero:public Hero
{
public:
	WoodHero()
	{
		this->TenAnhHung = "null";
		this->ThuocTinh = "Wood";
		this->Mau = 0;
		this->Cong = 0;
		this->Thu = 0;
		this->TocDo = 0;
		addHero(this);
	}
	WoodHero(string _TenAnhHung_, double _Mau_, double _Cong_, double _Thu_, double _TocDo_)
	{
		this->TenAnhHung = _TenAnhHung_;
		this->ThuocTinh = "Wood";
		this->Mau = _Mau_;
		this->Cong = _Cong_;
		this->Thu = _Thu_;
		this->TocDo = _TocDo_;
		addHero(this);
	}
	WoodHero(const WoodHero& other)
	{
		this->TenAnhHung = other.TenAnhHung;
		this->ThuocTinh = "Wood";
		this->Mau = other.Mau;
		this->Cong = other.Cong;
		this->Thu = other.Thu;
		this->TocDo = other.TocDo;
		addHero(this);
	}
public:
	int KiemTraTuongSinh(Hero* other);
	int KiemTraTuongKhac(Hero* other);
public:
	string className();
	Hero* clone();
};