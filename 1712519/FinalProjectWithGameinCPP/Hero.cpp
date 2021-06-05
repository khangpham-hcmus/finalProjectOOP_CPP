#include"Hero.h"
//
vector<Hero*> Hero::ListOfHeros;
string Hero::toString()
{
    stringstream ss;
    ss << "Ten anh hung: " << this->getTen() << endl;
    ss << "Thuoc tinh: " << this->getThuocTinh() << endl;
    ss << "Mau: " << this->getMau() << endl;
    ss << "Cong: " << this->getCong() << endl;
    ss << "Thu: " << this->getThu() << endl;
    ss << "Toc do: " << this->getTocDo() << endl;
    return ss.str();
}
void Hero::addHero(Hero* otherHero)
{
    if (otherHero == nullptr)
        return;
    int pos = ListOfHeros.size();
    while (--pos>=0)
    {
        Hero* hr = ListOfHeros[pos];
        if (hr->className() == otherHero->className())
            return;
    }
    ListOfHeros.push_back(otherHero);
}

Hero* Hero::createHero(string _TenThuocTinh_)
{
    if (_TenThuocTinh_.size() == 1)
        return nullptr;
    int pos = ListOfHeros.size();
    while (--pos >= 0)
    {
        Hero* hr = ListOfHeros[pos];
        if (hr->getThuocTinh() == _TenThuocTinh_)
            return hr->clone();
    }
    return nullptr;
}
