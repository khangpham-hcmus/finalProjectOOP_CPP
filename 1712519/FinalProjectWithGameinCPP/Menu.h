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
using namespace std;
class Menu {
public:
	//show main menu to screen
	static int Show();
	//check program is continue:
	static int isContinue();
	//exit program screen
	static void ExitProgram();
	//ask user to see detail log?
	static int isShowDetailLog();
	//get 3 heros from player:
};