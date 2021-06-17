#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"EarthHero.h";
#include"FireHero.h"
#include"MetalHero.h"
#include"WaterHero.h"
#include"WoodHero.h"
#include"User.h"
#include"FightingGame.h"
#include<iomanip>
using namespace std;
class Menu {
public:
	//show main menu to screen
	static int Show();
	//check program is continue:
	static int isContinue();
	//ask user to see detail log?
	static int isShowDetailLog();
private:
	static int showMenuTime();
public:
	//functions of project
	static int function1_InputHero(vector<Hero*> ListOfHeros);
	static int function2_ShowLog();
	static int function3_PlaywithNPC(string username,vector<Hero*> ListOfHeros);
	static int function4_PlaywithOtherUser(string username1,vector<Hero*>ListOfHeros);
	static int function5_ExitProgram();
};