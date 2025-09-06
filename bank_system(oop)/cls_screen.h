#pragma once
#include <iostream>
#include "cls_user.h"
#include "global.h"
#include "cls_date.h"

using namespace std; 

class cls_screen
{
protected  : 

	static void header_screen(string title , string sub = "")
	{
		cls_date date; 
		cout << "\t\t\t\t________________________________________________" << endl << endl; 
		cout << "\t\t\t\t" << title << endl; 
		if(sub != "")
			cout << "\t\t\t\t\t\t" << sub << endl;
		cout << "\t\t\t\t________________________________________________" << endl;
		cout << "\t\t\t\tUser :  " << current_user.get_username() << endl;
		cout << "\t\t\t\tDate :  " << date.convert_date_to_string() << endl;
	}

	static void display_message(string msg)
	{
		cout << "________________________________________________________" << endl << endl;
		cout << msg << endl;
		cout << "________________________________________________________" << endl << endl;
	}

	static void custom_pause(string msg)
	{
		cout << msg;
		if (cin.rdbuf()->in_avail() > 0)
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
	}
	
	static bool check_if_it_has_permission(short permission)
	{
		if (current_user.get_permission() == -1)
			return true; 
		if ((current_user.get_permission() & permission) == permission)
			return true; 
		return false;
	}

	static bool has_rights(bool permission)
	{
		if (!permission)
		{
			header_screen("Access denied, contact your admin !!");
			return false;
		}
		else {
			return true;
		}
	}
};

