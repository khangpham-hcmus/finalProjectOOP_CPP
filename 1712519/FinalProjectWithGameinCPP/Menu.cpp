#include"Menu.h"
//-------------------------------------------------------------------------------------
int Menu::Show()
{
	int selection;
	while (true)
	{
		cout << "---------------------------Menu---------------------------" << endl;
		cout << "1. Input a hero" << endl;
		cout << "2. Show log" << endl;
		cout << "3. Play with NPC" << endl;
		cout << "4. Play with other user" << endl;
		cout << "5. Exit" << endl;
		cout << "----------------------------------------------------------" << endl;
		try
		{
			cout << "Your selection is ?: ";
			if (!(cin >> selection))
				throw - 1;
			else if (!(selection >= 1 && selection <= 5))
				throw - 1;
			else
				break;
		}
		catch (int)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Warning invalid value. Input again!\n";
			system("pause");
			system("cls");
		}
	}
	return selection;
}
//-------------------------------------------------------------------------------------
int Menu::isContinue()
{
	int isContinueValue;
	while (true)
	{
		system("cls");
		cout << "--------------------------------------------------------" << endl;
		cout << "Do you want to continue or exit the gaming program?" << endl;
		cout << "1. Press `1` to continue" << endl;
		cout << "2. Press `2` to exit" << endl;
		cout << "--------------------------------------------------------" << endl;
		try
		{
			cout << "Press . . .";
			if (!(cin >> isContinueValue))
				throw - 1;
			else if (isContinueValue != 1 && isContinueValue != 2)
				throw - 1;
			else
				break;
		}
		catch (int)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Warning invalid number. Input again!\n";
			system("pause");
			system("cls");
		}
	}
	if (isContinueValue == 2) {
		Menu::function5_ExitProgram();
	}
	else 
	{
		system("cls"); 
	}
	return isContinueValue;
}
//-------------------------------------------------------------------------------------
int Menu::isShowDetailLog()
{
	int isDetail = 0;
	cout << "----------------------------------------------------------" << endl;
	cout << "Do you want to show detail log?" << endl;
	cout << "1. Press 1 to yes." << endl;
	cout << "2. Press 2 to no, only see the final time." << endl;
	cout << "----------------------------------------------------------" << endl;
	while (true)
	{
		try
		{
			cout << "Press . . . " << endl;
			if (!(cin >> isDetail))
				throw - 1;
			else if (isDetail != 1 && isDetail != 2)
				throw - 1;
			else
				break;
		}
		catch (int)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Warning invalid value. Press again!" << endl;
			system("pause");
			system("cls");
		}
	}
	return isDetail;
}
//-------------------------------------------------------------------------------------
int Menu::showMenuTime()
{
	int selection = 0;
	while (true)
	{
		cout << "---------------Menu time---------------" << endl;
		cout << "1. one minute" << endl;
		cout << "2. two minutes" << endl;
		cout << "5. five minutes" << endl;
		cout << "Press `1` or `2` or `5` to selection an option!!!\n";
		cout << "Press . . .";
		try {
			if (!(cin >> selection))
				throw - 1;
			else if (!(selection==1||selection==2||selection==5))
				throw - 1;
			else
				return selection;
		}
		catch (int)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Warning invalid value. Select again!!!";
			system("pause");
			system("cls");
		}
	}
	return 0;
}
//-------------------------------------------------------------------------------------
//Function to input the hero of game
int Menu::function1_InputHero(vector<Hero*> ListOfHeros)
{
	cin.ignore();
	system("cls");
	cout << "Input a hero:\n";
	int checkInsert = Hero::INSERT_HERO_TO_FILE();
	system("pause");
	int checkContinue = Menu::isContinue();
	if (checkContinue == 2)
		return 0;
	else
	{
		system("cls");
		return 1;
	}
}
//-------------------------------------------------------------------------------------
//Function to show the log when you play game
int Menu::function2_ShowLog()
{
	cin.ignore();
	system("cls");
	if (Menu::isShowDetailLog() == 2)
	{
		system("cls");
		string str = FightingGame::ShowOnlyTimeInLog();
		cout << str << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cin.ignore();
		system("cls");
		cout << "Input the time of the match with format hh:mm:ss . . . ";
		string _time_ = "";
		getline(cin, _time_);
		if (FightingGame::ShowDetailLog(_time_)) {

		}
		else
			cout<<"There is no suitable time and history log to show for you. Thank you!\n";
		system("pause");
		system("cls");
	}
	int checkContinue = Menu::isContinue();
	if (checkContinue == 2)
		return 0;
	else
		return 1;
}
//-------------------------------------------------------------------------------------
//Function to play with NPC
int Menu::function3_PlaywithNPC(string username, vector<Hero*> ListOfHeros)
{
		system("cls");
		User* player = User::CreateUser(username,ListOfHeros);
		User* NPC = User::createNPC();
		system("cls");
		FightingGame* vanGame = new FightingGame(player, NPC);
		vanGame->startGame(60000);
		vanGame->showResult();
		//---------------------------------------------------------------
		system("pause");
		int checkContinue = Menu::isContinue();
		if (checkContinue == 2)
			return 0;
		else
		{
			system("cls");
			return 1;
		}
		delete vanGame;
		//---------------------------------------------------------------

}
//-------------------------------------------------------------------------------------
int Menu::function4_PlaywithOtherUser(string username1,vector<Hero*> ListOfHeros)
{
	system("cls");
	cout << "Hi,when you will play game with the other user!!!\n";
	cout << "First, select heros for you:\n";
	User* player1 = User::CreateUser(username1, ListOfHeros);
	system("cls");
	cout << "Here, waiting for the second user to input name: . . .\nInput please. . . ";
	string username2;
	cin.ignore();
	getline(cin, username2);
	system("cls");
	cout << "Hi " << username2 << " !!";
	cout << "\nThen, Waiting "<< username2<<" select heros:\n";
	User* player2 = User::CreateUser(username2, ListOfHeros);
	system("cls");
	cout << "Here, let's see the menu time below and select the time we will fight the game\n";
	int _time1_ = Menu::showMenuTime();
	_time1_ = _time1_ * 60000;//convert from minutes to miliseconds
	FightingGame* vanGame = new FightingGame(player1, player2);
	system("cls");
	vanGame->startGame(_time1_);
	vanGame->showResult();
	//---------------------------------------------------------------
	system("pause");
	int checkContinue = Menu::isContinue();
	if (checkContinue == 2)
		return 0;
	else
	{
		system("cls");
		return 1;
	}
	delete vanGame;
	return 0;
}
//-------------------------------------------------------------------------------------
int Menu::function5_ExitProgram()
{
	cout << "=============================================END=============================================" << endl;
	return 0;
}

