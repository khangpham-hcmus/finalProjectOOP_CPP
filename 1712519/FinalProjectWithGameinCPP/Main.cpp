#include"ManageHeaders.h"
string _FILENAME_ = "ListHero.txt";
DeclareHeros HEROS_GLOBAL;//declares all heros in the list by object class DeclareHeros
int main() {
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
			if (Menu::function1_InputHero(DanhSachAnhHung) == 0)
				return 0;
		}
		else if (selection == 2)//show log
		{
			if (Menu::function2_ShowLog() == 0)
				return 0;
		}
		else if (selection == 3)//play with NPC
		{
			if(Menu::function3_PlaywithNPC(username1, DanhSachAnhHung)==0)
				return 0;
		}
		else if (selection == 4)//play with other user
		{
			if (Menu::function4_PlaywithOtherUser(username1, DanhSachAnhHung) == 0)
				return 0;
		}
		else if (selection == 5)//exit program
		{
			if (Menu::function5_ExitProgram() == 0)
				return 0;
		}
	}
	return 0;
}