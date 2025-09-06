#pragma once
#include "cls_screen.h"
#include <iomanip>
#include "global.h"
#include "cls_user.h"
#include "cls_main_screen.h"


class cls_login_screen : protected cls_screen
{

private : 

	static void _login()
	{
		string username , password;
		bool login_failed = false;
		do
		{
			if (login_failed)
			{
				cout << "Login failed, try again !!" << endl;
				counter--;
				cout << "you still have " << counter << " trials to login !" << endl;
				if (counter == 0)
				{
					display_message("You are locked after 3 failed trails");
					return;
				}
			}
			cout << left << setw(15) << "Username" << ":";
			cin >> username;
			cout << endl; 
			cout << left << setw(15) << "Password" << ":";
			cin >> password;
			current_user = cls_user::Find(username, password); 
			login_failed = current_user.is_empty();
			if (!login_failed)
			{
				counter = 3; 
			}
		} while (login_failed); 
		current_user.RegisterLogIn();
		cls_main_screen::show_main_menu();
	}

public : 
	
	static void login_screen()
	{
		system("cls");
		display_message("LOGIN SCREEN"); 
		_login();
	}

};

