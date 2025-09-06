#pragma once
#include "cls_date.h"
#include <iostream>
#include "cls_string.h"

using namespace std; 

class cls_login
{

	string _get_login_date()
	{
		cls_date Date;
		string TEXT = Date.convert_date_to_string() + " - " + Date.convert_time_to_string();
		return TEXT;
	}

	string _date;
	string _username; 
	string _password; 
	short _permission; 

	static string _ConvertLoginObjectToLine(cls_login User, string Seperator = "#//#")
	{

		string UserRecord = "";
		UserRecord += User._date + Seperator;
		UserRecord += User._username + Seperator;
		UserRecord += User._password + Seperator;
		UserRecord += to_string(User._permission);

		return UserRecord;

	}

	static void _SaveLoginDataToFile(cls_login vUsers)
	{

		fstream MyFile;
		MyFile.open("login.txt", ios::app | ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			DataLine = _ConvertLoginObjectToLine(vUsers);
			MyFile << DataLine << endl;

			MyFile.close();

		}

	}



public : 

	cls_login(string username , string password , short permission)
	{
		_date = _get_login_date();
		_username = username;
		_password = password;
		_permission = permission;
	}

	void save_login_data()
	{
		_SaveLoginDataToFile(*this);
	}

};

