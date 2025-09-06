#pragma once
#include "cls_screen.h" ;
#include "cls_input_validate.h"
#include "cls_user.h"

class cls_find_user : protected cls_screen
{
private : 
	static void _print_user(cls_user user)
	{
		cout << "---------------------------------" << endl;
		cout << "            USER CARD            " << endl;
		cout << "---------------------------------" << endl;
		cout << "Full name   :" << user.full_name() << endl;
		cout << "Username    :" << user.get_username() << endl;
		cout << "Email       :" << user.get_email() << endl;
		cout << "Phone       :" << user.get_phone() << endl;
		cout << "Password    :" << user.get_password() << endl;
		cout << "Permission  :" << user.get_permission() << endl;
		cout << "---------------------------------" << endl;
	}

public : 

	static void find_user()
	{
		display_message("FIND USER SCREEN");
		string username = cls_input_validate::read_string("Enter user name : ");
		while (!cls_user::IsUserExist(username))
		{
			cout << "this username doesn't exists try again !!" << endl;
			username = cls_input_validate::read_string("Enter user name : ");
		}

		cls_user user = cls_user::Find(username);
		if (user.is_empty())
		{
			display_message("USER NOT FOUND !!");
		}
		else
		{
			_print_user(user);
		}
	}

};

