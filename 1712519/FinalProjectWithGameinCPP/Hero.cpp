#include"Hero.h"

//
vector<Hero*> Hero::ListOfHeros;
string Hero::toString()
{
    stringstream ss;
    ss << this->getTen() << ";";
    ss << this->getThuocTinh() << ";";
    ss << this->getMau() << ";";
    ss << this->getCong() << ";";
    ss << this->getThu() << ";";
    ss << this->getTocDo() << "\n";
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
            if (lineinfo == "")
                continue;
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
//
Hero* Hero::InputHero()
{
    string ten;
    string thuoctinh;
    double mau = 0;
    double cong = 0;
    double thu = 0;
    double tocdo = 0;
    //
    vector<string> DanhSachThuocTinh = {"Metal","Wood","Water","Fire","Earth"};
    //
    cout << "Hero name: ";
    getline(cin, ten);
    //
    cout << "Input a number to choose one of these attributes: [1.Metal; 2.Wood; 3.Water; 4.Fire; 5.Earth]\n";
    while (true)
    {
        cout << "Number is ?: ";
        getline(cin, thuoctinh);
        if(thuoctinh=="1"||thuoctinh=="2"||thuoctinh=="3"||thuoctinh=="4"||thuoctinh=="5") 
            break;
        else {
            cout << "Invalid value. Input attribute again!\n";
        }
    }
    int index = stoi(thuoctinh);
    thuoctinh = DanhSachThuocTinh[index - 1];
    //mau
    while (true)
    {
        try {
            cout << "Hero blood value is ?: ";
            if (!(cin >> mau)) {
                throw - 1;
            }
            else if (mau <= 0)
                throw - 1;
            else 
                break;
           
        }
        catch (int)
        {
            cout << "Invalid value. Input again!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
    }
    //cong
    while (true)
    {
        try {
            cout << "Hero attack value is ?: ";
            if (!(cin >> cong))
                throw - 1;
            else if (cong <= 0)
                throw - 1;
            else
                break;
        }
        catch (int)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid value. Input again!\n";
        }
    }
    //thu
    while (true)
    {
        try 
        {
            cout << "Defense value is ?: ";
            if (!(cin >> thu))
                throw - 1;
            else if (thu <= 0)
                throw - 1;
            else
                break;
        }
        catch (int)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid value. Input again!\n";
        }
    }
    //tocdo
    while (true)
    {
        try
        {
            cout << "Speed value is ?: ";
            if (!(cin >> tocdo))
                throw - 1;
            else if (thu <= 0)
                throw - 1;
            else
                break;
        }
        catch (int)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid value. Input again!\n";
        }
    }
    //
    Hero* hero_ = Hero::createHero(thuoctinh);
    if (hero_ != nullptr) {
        hero_->setTen(ten);
        hero_->setMau(mau);
        hero_->setThu(thu);
        hero_->setCong(cong);
        hero_->setTocDo(tocdo);
    }
    return hero_;
}
//
int Hero::INSERT_HERO_TO_FILE()
{
    int checkInsert = 0;
    string fileName = "ListHero.txt";
    fstream f;
    Hero* anhhung = Hero::InputHero();
    if (anhhung != nullptr) 
    {
        //insert hero
        f.open(fileName, ios::app);
        if (f.is_open())
        {
            f << endl;
            f << anhhung->toString();
        }
        f.close();
        checkInsert = 1;
        //format file
        //read file without bank line
        queue<string> danhsach;
        string str;
        fstream f2;
        f2.open(fileName, ios::in);
        int i = 0;
        while (getline(f2, str)||str.empty()==true) {
            if (f2.eof() == true)
                break;
            if (str != "")
                danhsach.push(str);
        }
        f2.close();
        //------------------------------------------------------------
        //append line to file
        fstream f3;
        f3.open(fileName, ios::out);
        string line = "";
        while (!danhsach.empty())
        {
            line = danhsach.front() + "\n";
            f3 << line;
            danhsach.pop();
        }
        f3.close();
    }
    return checkInsert;
}
//
Hero* Hero::showHeros()
{
    vector<string> listName;
    vector<Hero*> danhsachTuong = Hero::GET_LIST_HEROS_FROM_FILE("ListHero.txt");
    
    int count = 1;
    cout << "--------------------------------Heros--------------------------------" << endl;
    for (Hero* i : danhsachTuong)
    {
        cout << count++ << ". ";
        cout << i->getTen() << endl;
    }
    return nullptr;
}
//
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
