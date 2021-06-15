#include"Menu.h"

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
	if (isContinueValue == 2)
		Menu::ExitProgram();
	return isContinueValue;
}

void Menu::ExitProgram()
{
	cout << "=============================================END=============================================" << endl;
}

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
			cout << "Press please . . . " << endl;
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

