#pragma once
#pragma warning(disable: 4996)
#include<iostream>
#include<ctime>
using namespace std;
class Timing {
public:
	/*
	* Static method to get system time:
	* Input: none
	* Output: string show time
	*/
	static string GetSystemTime() {
		time_t now = time(0);
		tm* ltm = localtime(&now);
		string GioPhutGiay = to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
		string NgayThangNam = to_string(ltm->tm_mday) + "/";
		NgayThangNam += to_string(1 + ltm->tm_mon) + "/";
		NgayThangNam += to_string(1900 + ltm->tm_year);
		string str = GioPhutGiay + "," + NgayThangNam;
		return str;
	}
};