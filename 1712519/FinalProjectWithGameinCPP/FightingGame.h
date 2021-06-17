#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"MetalHero.h"
#include"WaterHero.h"
#include"FireHero.h"
#include"Timing.h"
#include"EarthHero.h"
#include"WoodHero.h"
#include"User.h"
#include<iomanip>
using namespace std;
//
class FightingGame {
private:
	//Const list attributes
	vector<string> Environments = { "Metal","Wood","Water","Fire","Earth" };
private:
	string Environment;
	User* user1;
	User* user2;
private:
	//--------------------------------------------------------------------------------------
	/*
	* This method will auto creater an environment when we create an User!!
	* Input: none
	* Output: string to show attribut of environment
	*/
	string autoCreateEnvironment();
	//--------------------------------------------------------------------------------------
	/*
	* Kiểm tra xem ai thắng
	* Input: none
	* Output: 1 nếu user1 thắng
	*		  2 nếu user2 thắng
	*		  0 nếu hòa
	*/
	int checkWin();
public:
	//default constructor
	FightingGame();
	//parameters constructor
	FightingGame(User* u1, User* u2);
	//destructor
	~FightingGame();
public:
	//------------------------------------------------------------------------------------------
	//Get the environment
	string getEnvironment();
	//------------------------------------------------------------------------------------------
	/*
	* This method will start the game and heros will fight together
	* Input: the time for heros fighting
	* Outout: none
	*/
	void startGame(int _timeset_);
	//------------------------------------------------------------------------------------------
	/*
	* This method to save the result of the fighting game:
	* Input: none
	* Output: vector<string> to show result
	*/
	vector<string> getResult();
	//------------------------------------------------------------------------------------------
	/*
	* This method will show the result on the screen
	*/
	void showResult();
	//------------------------------------------------------------------------------------------
private:
	/*
	* This method will write history match to the Log file
	* Input: vector<string> which information the matching
	* Output: none
	*/
	void WriteLog(vector<string>arr);
public:
	//----------------------------------------------------------------------------------
	/*
	* This method will show detail log:
	*/
	static int ShowDetailLog(string _time_);
	//----------------------------------------------------------------------------------
	/*
	* This method only show the final time:
	*/
	static string ShowOnlyTimeInLog();
	//----------------------------------------------------------------------------------
};