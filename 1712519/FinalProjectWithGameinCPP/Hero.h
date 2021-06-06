#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;
class Hero
{
protected:
	string TenAnhHung;
	string ThuocTinh;
	double Mau;
	double Cong;
	double Thu;
	double TocDo;
public://destructor:
	virtual ~Hero() {}
public://getter:
	string getTen()
	{
		return this->TenAnhHung;
	}
	string getThuocTinh()
	{
		return this->ThuocTinh;
	}
	double getMau()
	{
		return this->Mau;
	}
	double getCong()
	{
		return this->Cong;
	}
	double getThu()
	{
		return this->Thu;
	}
	double getTocDo()
	{
		return this->TocDo;
	}
public://setter:
	void setTen(string _TenAnhHung_)
	{
		this->TenAnhHung = _TenAnhHung_;
	}
	void setMau(double _Mau_)
	{
		this->Mau = _Mau_;
	}
	void setCong(double _Cong_)
	{
		this->Cong = _Cong_;
	}
	void setThu(double _Thu_)
	{
		this->Thu = _Thu_;
	}
	void setTocDo(double _TocDo_)
	{
		this->TocDo = _TocDo_;
	}
public:
	string toString();
public:
	//static vector<Hero*> GET_LIST_HERO_FROM_TEXT(string filename);
public:
	virtual int KiemTraTuongSinh(Hero* other) = 0;
	virtual int KiemTraTuongKhac(Hero* other) = 0;
public:
	virtual string className() = 0;
	virtual Hero* clone() = 0;
protected:
	static vector<Hero*> ListOfHeros;
	void addHero(Hero* otherHero);
public:
	static Hero* createHero(string _TenThuocTinh_);
public:
	static vector<Hero*> GET_LIST_HEROS_FROM_FILE(string filename__);

};