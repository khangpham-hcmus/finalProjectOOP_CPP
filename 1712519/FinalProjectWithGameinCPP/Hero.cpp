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

vector<Hero*> Hero::GET_LIST_HEROS_FROM_FILE(string filename__)
{
    vector<Hero*> DanhSachAnhHung;
    fstream f;
    f.open(filename__, ios::in);
    if (f.is_open())
    {
        string lineinfo;
        string temp;
        Hero* hr = nullptr;
        while (getline(f, lineinfo))
        {
            vector<string>arr;
            stringstream ss(lineinfo);
            while (getline(ss, temp,';'))
            {
                arr.push_back(temp);
            }
            hr = Hero::createHero(arr[1]);
            hr->setTen(arr[0]);
            hr->setMau(stof(arr[2]));
            hr->setCong(stof(arr[3]));
            hr->setThu(stof(arr[4]));
            hr->setTocDo(stof(arr[5]));
            DanhSachAnhHung.push_back(hr);
        }
        f.close();
    }
    return DanhSachAnhHung;
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
