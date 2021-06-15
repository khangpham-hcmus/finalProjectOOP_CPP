#include"ManageHeaders.h"
string _FILENAME_ = "ListHero.txt";
DeclareHeros HEROS_GLOBAL;
int main() {
	User* player1 = nullptr;
	User* player2 = nullptr;
	User* NPC = nullptr;
	cout << "Input username: ";
	string username1;
	getline(cin, username1);
	cout << "Hi " + username1 << endl;
	cout << "Let's see the menu in game!!" << endl;
	while (true)
	{
		vector<Hero*> DanhSachAnhHung = Hero::GET_LIST_HEROS_FROM_FILE(_FILENAME_);
		int selection = Menu::Show();
		int checkContinue = -1;
		if (selection == 1)//input hero
		{
			cin.ignore();
			system("cls");
			cout << "Input a hero:\n";
			int checkInsert=Hero::INSERT_HERO_TO_FILE();
			system("pause");
			checkContinue = Menu::isContinue();
			if (checkContinue == 2)
				return 0;
		}
		else if (selection == 2)//show log
		{
			cin.ignore();
			system("cls");
			if (Menu::isShowDetailLog() == 2) 
			{
				cout << Timing::GetSystemTime() << endl;
				system("pause");
			}
			else
			{
				cout << "Detail log is:" << endl;
				system("pause");
			}
			checkContinue = Menu::isContinue();
			if (checkContinue == 2)
				return 0;
		}
		else if (selection == 3)//play with NPC
		{
			system("cls");
			player1=User::CreateUser(username1,DanhSachAnhHung);
			cout << "Danh sach tuong User:\n";
			cout << player1->toString() << endl;
			cout << "Danh sach tuong NPC:\n";
			NPC=User::createNPC();
			cout << NPC->toString() << endl;
		}
		else if (selection == 4)//play with other user
		{
		}
		else if (selection == 5)//exit program
		{
			Menu::ExitProgram();
			return 0;
		}
	}
	
	return 0;
}