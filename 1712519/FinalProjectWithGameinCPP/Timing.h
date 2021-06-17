#pragma once
#pragma warning(disable: 4996)
#include<iostream>
#include<string>
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
		string gio = to_string(ltm->tm_hour);
		//format time: hh:mm:ss
		if (gio.size() < 2)
			gio = "0" + gio;
		string phut = to_string(ltm->tm_min);
		if (phut.size() < 2)
			phut = "0" + phut;
		string giay = to_string(ltm->tm_sec);
		if (giay.size() < 2)
			giay = "0" + giay;
		string GioPhutGiay = gio + ":" + phut + ":" + giay;
		string NgayThangNam = to_string(ltm->tm_mday) + "/";
		NgayThangNam += to_string(1 + ltm->tm_mon) + "/";
		NgayThangNam += to_string(1900 + ltm->tm_year);
		string str = GioPhutGiay + "," + NgayThangNam;
		return str;
	}
};