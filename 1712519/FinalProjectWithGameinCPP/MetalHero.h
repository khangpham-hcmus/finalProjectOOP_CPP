#pragma once
#include"Hero.h"
class MetalHero :public Hero 
{
public:
	MetalHero()
	{
		this->TenAnhHung = "null";
		this->ThuocTinh = "Metal";
		this->Mau = 0;
		this->Cong = 0;
		this->Thu = 0;
		this->TocDo = 0;
		addHero(this);
	}
	MetalHero(string _TenAnhHung_, double _Mau_, double _Cong_, double _Thu_, double _TocDo_) 
	{
		this->TenAnhHung = _TenAnhHung_;
		this->ThuocTinh = "Metal";
		this->Mau = _Mau_;
		this->Cong = _Cong_;
		this->Thu = _Thu_;
		this->TocDo = _TocDo_;
		addHero(this);
	}
	MetalHero(const MetalHero& other)
	{
		this->TenAnhHung = other.TenAnhHung;
		this->ThuocTinh = "Metal";
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