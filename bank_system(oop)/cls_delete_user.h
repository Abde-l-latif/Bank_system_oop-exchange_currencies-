#pragma once
#include "cls_screen.h"


class cls_delete_user : protected cls_screen
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
	
	static void delete_user()
	{
		display_message("DELETE USER SCREEN");
		string username = cls_input_validate::read_string("Enter user name : ");
		while (!cls_user::IsUserExist(username))
		{
			cout << "this username doesn't exists try again !!" << endl;
			username = cls_input_validate::read_string("Enter user name : ");
		}

		cls_user user = cls_user::Find(username);
		_print_user(user);
		char answer = 'n'; 
		cout << "are you sure you wanna delete this user y/n : ";
		cin >> answer; 
		if (answer == 'y' || answer == 'Y')
		{
			user.Delete();
			display_message("user has been deleted successfully ."); 
		}
		else
			display_message("The operation has been denied !"); 
	};


};

