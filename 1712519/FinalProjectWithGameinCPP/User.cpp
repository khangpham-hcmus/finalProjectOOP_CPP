#include"User.h"
//------------------------------------------------------------------------------------
//default constructor
User::User()
{
	danhsachTuong.resize(0);
	username = "";
}
//------------------------------------------------------------------------------------
//constructor will 3 parameter
User::User(string nameHero, Hero* ah1, Hero* ah2, Hero* ah3)
{
	this->username = nameHero;
	this->danhsachTuong.push_back(ah1);
	this->danhsachTuong.push_back(ah2);
	this->danhsachTuong.push_back(ah3);
	this->AutoFixInSameTeam();
}
//------------------------------------------------------------------------------------
//static method to create NPC player
/*
* Input: none
* Output: an User object
*/
User* User::createNPC()
{
	vector<Hero*> HerosList = Hero::GET_LIST_HEROS_FROM_FILE("ListHero.txt");
	int sizeList = HerosList.size();
	vector<Hero*> dsTuong;
	dsTuong.resize(3);
	srand(time(NULL));
	int count = 0;
	for (int j = 0; j < 3; j++)
	{
		int i = rand() % sizeList;
		dsTuong[count++] = HerosList[i];
	}
	return new User("NPC",dsTuong[0],dsTuong[1],dsTuong[2]);
}
//------------------------------------------------------------------------------------
string User::getUsername()
{
	return this->username;
}
//------------------------------------------------------------------------------------
vector<Hero*> User::getHeros()
{
	return this->danhsachTuong;
}
//------------------------------------------------------------------------------------
Hero* User::getHeroAt(int index)
{
	if (index >= 0 && index < danhsachTuong.size())
		return danhsachTuong[index];
	return nullptr;
}
//------------------------------------------------------------------------------------
void User::setUsername(string name)
{
	this->username = name;
}
//------------------------------------------------------------------------------------
/*
* This method will auto custom the attribute attack,fense,blood of heros in the same team
* Input: none
* Output: none but the attribute of these heros will autofix internal
*/
void User::AutoFixInSameTeam()
{
	for (int i = 0; i < NUMBER_OF_HEROS; i++)
	{
		for (int j = 0; j < NUMBER_OF_HEROS; j++)
		{
			if (i == j)
				continue;
			else
			{
				Hero* currentHero = danhsachTuong[j];
				if (currentHero->KiemTraTuongKhac(danhsachTuong[i]))
				{
					double tocdo_ = currentHero->getTocDo() + 0.1 * currentHero->getTocDo();
					currentHero->setTocDo(tocdo_);
				}
				if (currentHero->KiemTraTuongSinh(danhsachTuong[i]))
				{
					double mau_ = currentHero->getMau() + 0.15 * currentHero->getMau();
					currentHero->setMau(mau_);
				}
			}
		}
	}
}
//------------------------------------------------------------------------------------
/*
* This static method will create an user object
*/
User* User::CreateUser(string name, vector<Hero*> ListOfHeros)
{
	vector<Hero*> heros;
	heros.resize(3);
	int selection = 0;
	Hero::showHeros();
	cout << "---------------------------------------------------------------------" << endl;
	cout << "Choose 3 hero in list:\n";
	//select hero 1:
	while (true)
	{
		try
		{
			cout << "First hero is ?: " << endl;
			if (!(cin >> selection))
				throw - 1;
			else if (!(selection > 0 && selection <= ListOfHeros.size()))
				throw - 1;
			else {
				heros[0] = (ListOfHeros[selection-1])->clone();
				break;
			}
		}
		catch (int)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Warning invalid value. Select again!" << endl;
			system("pause");
			system("cls");
			Hero::showHeros();
			cout << "----------------------------------------------------------------" << endl;
		}
	}
	//select hero 2:
	while (true)
	{
		try
		{
			cout << "Second hero is ?: " << endl;
			if (!(cin >> selection))
				throw - 1;
			else if (!(selection > 0 && selection <= ListOfHeros.size()))
				throw - 1;
			else {
				heros[1] = (ListOfHeros[selection-1])->clone();
				break;
			}
		}
		catch (int)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Warning invalid value. Select again!" << endl;
			system("pause");
			system("cls");
			Hero::showHeros();
			cout << "-------------------------------------------------------------------" << endl;
		}
	}
	//select hero 3:
	while (true)
	{
		try
		{
			cout << "Third hero is ?: " << endl;
			if (!(cin >> selection))
				throw - 1;
			else if (!(selection > 0 && selection <= ListOfHeros.size()))
				throw - 1;
			else {
				heros[2] = (ListOfHeros[selection-1])->clone();
				break;
			}
		}
		catch (int)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Warning invalid value. Select again!" << endl;
			system("pause");
			system("cls");
			Hero::showHeros();
			cout << "----------------------------------------------------------------" << endl;
		}
	}
	return new User(name, heros[0], heros[1], heros[2]);
}
//------------------------------------------------------------------------------------
string User::toString()
{
	stringstream ss;
	ss << this->username << ",";
	ss<<  danhsachTuong[0]->getTen() << "/";
	ss << danhsachTuong[1]->getTen() << "/";
	ss << danhsachTuong[2]->getTen();
	return ss.str();
}
//------------------------------------------------------------------------------------

