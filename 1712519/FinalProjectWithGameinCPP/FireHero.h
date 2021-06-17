#pragma once
#include"Hero.h"
class FireHero :public Hero
{
public:
	//default constructor
	FireHero()
	{
		this->TenAnhHung = "null";
		this->ThuocTinh = "Fire";
		this->Mau = 0;
		this->Cong = 0;
		this->Thu = 0;
		this->TocDo = 0;
		addHero(this);
	}
	//constructor with parameters
	FireHero(string _TenAnhHung_, double _Mau_, double _Cong_, double _Thu_, double _TocDo_)
	{
		this->TenAnhHung = _TenAnhHung_;
		this->ThuocTinh = "Fire";
		this->Mau = _Mau_;
		this->Cong = _Cong_;
		this->Thu = _Thu_;
		this->TocDo = _TocDo_;
		addHero(this);
	}
	//copy constructor
	FireHero(const FireHero& other)
	{
		this->TenAnhHung = other.TenAnhHung;
		this->Mau = other.Mau;
		this->ThuocTinh = "Fire";
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