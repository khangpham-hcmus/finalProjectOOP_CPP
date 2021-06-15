#pragma once
#include"ManageHeaders.h"
#include<ctime>
const int NUMBER_OF_HEROS = 3;
using namespace std;
class User
{
protected:
	string username;
	vector<Hero*> danhsachTuong;
protected:
	//default constructor
	User();
public:
	//getter
	string getUsername();
	vector<Hero*> getHeros();
public:
	//setter
	void setUsername(string name);
public:
	//constructor with parameters for username
	User(string nameHero, Hero* ah1, Hero* ah2, Hero* ah3);
protected:
	/*
	* This method will be auto fix the attribute these Hero in the same team!!
	* Input: none
	* Output: internal attribute will be fixed
	*/
	void AutoFixInSameTeam();
public:
	//create Player is NPC:
	static User* createNPC();
public:
	//create Player is user:
	static User* CreateUser(string name, vector<Hero*> ListOfHeros);
public:
	string toString();
public://destructor:
	~User() {}
};