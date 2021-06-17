#include"FightingGame.h"
//------------------------------------------------------------------------------------
/*
* This method will create one of 5 environments!
* Input: none
* Output: an environment (private string)
*/
string FightingGame::autoCreateEnvironment()
{
	srand(time(NULL));
	int index = rand() % 5;
	return Environments[index];
}
//----------------------------------------------------------------------------------------
//Default constructor
FightingGame::FightingGame()
{
	this->Environment = autoCreateEnvironment();
}
//------------------------------------------------------------------------------------------
//Constructor with parameter
FightingGame::FightingGame(User* u1, User* u2)
{
	this->Environment = autoCreateEnvironment();
	this->user1 = u1;
	this->user2 = u2;
	//Create a virtual hero to check `KiemTraTuongSinh` and `KiemTraTuongKhac`
	Hero* virtualHeros = Hero::createHero(Environment);
	vector<Hero*> dsTuongUser1 = user1->getHeros();//Get the list heros of user1
	vector<Hero*> dsTuongUser2 = user2->getHeros();//Get the list heros of user2
	for (int i = 0; i < 3; i++)
	{
		Hero* hr1 = dsTuongUser1[i];
		Hero* hr2 = dsTuongUser2[i];
		if (hr1->KiemTraTuongSinh(virtualHeros))
		{
			double mau1 = hr1->getMau();
			mau1 = mau1 * 105 / 100;//mau tang 5 %
			hr1->setMau(mau1);
			double tocdo1 = hr1->getTocDo();
			tocdo1 = tocdo1 * 90 / 100;//toc do giam di 10%
			hr1->setTocDo(tocdo1);
		}
		if (hr1->KiemTraTuongKhac(virtualHeros))
		{
			double mau2 = hr1->getMau();
			mau2 = mau2 * 97 / 100;//mau giam di 3%
			hr1->setMau(mau2);
		}
		if (hr2->KiemTraTuongSinh(virtualHeros))
		{
			double mau3 = hr2->getMau();
			mau3 = mau3 * 105 / 100;//mau tang 5%
			hr2->setMau(mau3);
			double tocdo4 = hr2->getTocDo();
			tocdo4 = tocdo4 * 90 / 100;//toc do giam di 10%
			hr2->setTocDo(tocdo4);
		}
		if (hr2->KiemTraTuongKhac(virtualHeros))
		{
			double mau5 = hr2->getMau();
			mau5 = mau5 * 97 / 100;//mau giam di 3%
			hr2->setMau(mau5);
		}
	}
	delete virtualHeros;
}
//---------------------------------------------------------------------------------------
//destructor
FightingGame::~FightingGame()
{
	if (user1 != nullptr)
		delete user1;
	if (user2 != nullptr)
		delete user2;
}
//---------------------------------------------------------------------------------------
//Getter the environment:
string FightingGame::getEnvironment()
{
	return this->Environment;
}
//---------------------------------------------------------------------------------------
/*
	* This method will start the game and heros will fight together
	* Input: the time for heros fighting
	* Outout: none
*/
void FightingGame::startGame(int _timeset_)
{
	for (int i = 0; i < 3; i++)
	{
		Hero* h1 = user1->getHeros()[i];
		Hero* h2 = user2->getHeros()[i];
		//Chinh sua thuoc tinh neu hai Hero khac nhau:
		if (h1->KiemTraTuongKhac(h2))
		{
			double thu = h1->getThu();
			thu = 0.5 * thu;
			h1->setThu(thu);
			double cong = h2->getCong();
			cong = cong * 110 / 100;
			h2->setCong(cong);
		}
		else if (h2->KiemTraTuongKhac(h1))
		{
			double thu = h2->getThu();
			thu = thu * 0.5;
			h2->setThu(thu);
			double cong = h1->getCong();
			cong = cong * 110 / 100;
			h1->setCong(cong);
		}
		double minSpeed = h1->getTocDo();
		if (minSpeed > h2->getTocDo())
			minSpeed = h2->getTocDo();
		//Hai tuong bat dau danh nhau:
		double mauhero1 = h1->getMau();
		double mauhero2 = h2->getMau();
		double curTime = -minSpeed;
		double nextTimeHero1 = h1->getTocDo();
		double nextTimeHero2 = h2->getTocDo();
		while (mauhero1 > 0 && mauhero2 > 0 && curTime <= _timeset_)
		{
			if (nextTimeHero1 < nextTimeHero2)
			{
				//hero1 tan cong hero2 => hero2 bi hao hut Luong Mau:
				double LuongMauHaoHut = h1->getCong() - h2->getThu();//luong mau hao hut cua hero2
				mauhero2 = mauhero2 - LuongMauHaoHut;	
				nextTimeHero1 += h1->getTocDo();
			}
			else if (nextTimeHero2 < nextTimeHero1)
			{
				//hero2 tan cong hero1 => hero1 bi hao hut Luong Mau
				double LuongMauHaoHut = h2->getCong() - h1->getThu();//luong mau hao hut cua hero1
				mauhero1 = mauhero1 - LuongMauHaoHut;
				nextTimeHero2 += h2->getTocDo();
			}
			else //truong hop nay thi 2 Heros trung nhau ve Toc Do Ra Don
			{
				double LuongMauHaoHut_hero1= h2->getCong() - h1->getThu();
				double LuongMauHaoHut_hero2= h1->getCong() - h2->getThu();
				mauhero1 -= LuongMauHaoHut_hero1;
				mauhero2 -= LuongMauHaoHut_hero2;
			}
			curTime += minSpeed;
			
		}
		//--------------------------------------------------------
		if (mauhero1 < 0)
			h1->setMau(0);
		else
			h1->setMau(mauhero1);
		//--------------------------------------------------------
		if (mauhero2 < 0)
			h2->setMau(0);
		else
			h2->setMau(mauhero2);
		//--------------------------------------------------------
	}
}
//----------------------------------------------------------------------------------------
/*
	* This method to save the result of the fighting game:
	* Input: none
	* Output: vector<string> to show result
*/
vector<string> FightingGame::getResult()
{
	vector<string> arr;
	int checkWin = this->checkWin();//This line will show who is the winner in game!
	string result = "";
	//lấy kết quả người thắng
	if (checkWin == 0)
		result = "End in a draw";
	else if (checkWin == 1)
		result = this->user1->getUsername() + " win";
	else
		result = this->user2->getUsername() + " win";
	arr.push_back(result);
	//
	arr.push_back("Team " + user1->getUsername());
	arr.push_back("Team " + user2->getUsername());
	//
	for (int i = 0; i < 3; i++)
	{
		string s1 = user1->getHeroAt(i)->toString();
		arr.push_back(s1);
		string s2 = user2->getHeroAt(i)->toString();
		arr.push_back(s2);
	}
	string timeSystem = Timing::GetSystemTime();
	arr.push_back(timeSystem);
	//Begining calling method to write history to file Log
	this->WriteLog(arr);
	return arr;
}
//---------------------------------------------------------------------------------------
void FightingGame::showResult()
{
	vector<string> arr = this->getResult();
	cout << setw(58) << right << arr[0] << endl;
	cout << setw(35) << right << arr[1] << setw(52) << arr[2] << endl;
	//-----------------------------------------------------------------------------------
	cout << setw(15) << left << "";
	cout << setw(55) << left << arr[3];
	cout << setw(20) << right << arr[4] << endl;
	//
	cout << setw(15) << left << "";
	cout << setw(55) << left << arr[5];
	cout << setw(20) << right << arr[6] << endl;
	//
	cout << setw(15) << left << "";
	cout << setw(55) << left << arr[7];
	cout << setw(20) << right << arr[8] << endl;
	//
	cout << endl << endl << setw(15) << left;
}
//-----------------------------------------------------------------------------------------
/*
* This method will write history to the text file `Log.txt`
*/
void FightingGame::WriteLog(vector<string>arr)
{
	string _filename_ = "Log.txt";
	stringstream ss;
	ss << arr[9] << "|";
	ss << arr[1] << "|";
	ss << arr[3] << "|";
	ss << arr[5] << "|";
	ss << arr[7] << "|";
	ss << arr[7] << "|";
	ss << arr[2] << "|";
	ss << arr[4] << "|";
	ss << arr[6] << "|";
	ss << arr[8] << "|";
	ss << arr[0] << "\n";
	string str = ss.str();
	fstream f(_filename_, ios::app);
	if (f.is_open())
	{
		f << str;
		f.close();
	}
}
//--------------------------------------------------------------------------------
/*
* This method will show the detail time to screen
* Input: the input time
* Output: result of the matching to screen
*/
int FightingGame::ShowDetailLog(string _time_)
{
	string filename = "Log.txt";
	fstream f(filename, ios::in);
	string line = "";
	if (f.is_open())
	{
		//This while loop to find the line contain `_time_`
		while (getline(f, line))//read step line step
		{
			string Time;
			string temp;
			stringstream ss1(line);
			vector<string> parseLineArr;
			while (getline(ss1, temp, '|'))
			{
				parseLineArr.push_back(temp);//only get the time with `hh:mm:ss,dd/mm/yyyy`
				break;
			}
			stringstream ss2(parseLineArr[0]);
			vector<string> parseTimeArr;
			while (getline(ss2, Time, ','))
			{
				parseTimeArr.push_back(Time);//only get the time with format: `hh:mm:ss`
				break;
			}
			if (parseTimeArr[0] == _time_)
				break;
		}
		//check the line is null?
		if (line == "")
			return 0;
		stringstream ss(line);
		vector<string> infomation;
		string str;
		while (getline(ss, str, '|'))
		{
			infomation.push_back(str);
		}
		//show information to screen:
		cout << setw(58) << right << infomation[10] << endl;
		cout << setw(35) << right << infomation[1] << setw(52) << infomation[6] << endl;
		//-----------------------------------------------------------------------------------
		cout << setw(15) << left << "";
		cout << setw(55) << left << infomation[2];
		cout << setw(20) << right << infomation[7] << endl;
		//
		cout << setw(15) << left << "";
		cout << setw(55) << left << infomation[3];
		cout << setw(20) << right << infomation[8] << endl;
		//
		cout << setw(15) << left << "";
		cout << setw(55) << left << infomation[4];
		cout << setw(20) << right << infomation[9] << endl;
		//
		cout << endl << endl << setw(15) << left;
		f.close();
	}
	return 1;
}
//---------------------------------------------------------------------------------
/*
* This method will show to screen the time of the final matching game!
*/
string FightingGame::ShowOnlyTimeInLog()
{
	string fileName = "Log.txt";
	fstream f(fileName, ios::in);
	string Line = "";
	string finalLine = "";
	if (f.is_open())
	{
		int i = 0;
		while (getline(f, Line))
		{
			finalLine = Line;
		}
		f.close();
	}
	vector<string>arr;
	stringstream ss(finalLine);
	while (getline(ss, Line, ','))
	{
		arr.push_back(Line);
		break;//only get the time in a line
	}
	finalLine = arr[0];//parse the Time in the full final line
	finalLine = "The time of final match is: " + finalLine;
	return finalLine;
}
//--------------------------------------------------------------------------------------
/*
* Kiểm tra xem ai thắng
* Input: none
* Output: 1 nếu user1 thắng
*		  2 nếu user2 thắng
*		  0 nếu hòa
*/
int FightingGame::checkWin()
{
	int countUser1 = 0;
	int countUser2 = 0;
	for(int i=0;i<3;i++)
	{
		if (user1->getHeroAt(i)->getMau() == 0)
			countUser1++;
		if (user2->getHeroAt(i)->getMau() == 0)
			countUser2++;
	}
	if (countUser1 > countUser2)
		return 2;
	else if (countUser2 > countUser1)
		return 1;
	else
		return 0;
	return 0;
}
//----------------------------------------------------------------------------------------------------------