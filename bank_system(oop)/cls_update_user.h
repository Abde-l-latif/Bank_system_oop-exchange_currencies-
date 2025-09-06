#pragma once
#include "cls_screen.h"
#include "cls_user.h"
#include "cls_input_validate.h"

class cls_update_user : protected cls_screen 
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

	static void _read_permission(cls_user& user)
	{
		cls_user::s_per all_permissions;
		short permission = 0;
		char answer = 'n';
		cout << "you wanna give it permission to show client list ? y/n : ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			permission += all_permissions.show_client_list_permission;
		}
		cout << "you wanna give it permission to add new clients ? y/n : ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			permission += all_permissions.add_new_client_permission;
		}
		cout << "you wanna give it permission to delete clients ? y/n : ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			permission += all_permissions.delete_client_permission;
		}
		cout << "you wanna give it permission to update clients ? y/n : ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			permission += all_permissions.update_client_permission;
		}
		cout << "you wanna give it permission to find clients ? y/n : ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			permission += all_permissions.find_client_permission;
		}
		cout << "you wanna give it permission to do transactions ? y/n : ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			permission += all_permissions.transaction_permission;
		}
		cout << "you wanna give it permission to manage users ? y/n : ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			permission += all_permissions.manage_user_permission;
		}
		user.set_permission(permission);
	}

	static void _read_new_info(cls_user& user)
	{
		user.set_username(cls_input_validate::read_string("Enter username : "));
		user.set_firstname(cls_input_validate::read_string("Enter first name : "));
		user.set_lastname(cls_input_validate::read_string("Enter last name : "));
		user.set_email(cls_input_validate::read_string("Enter email : "));
		user.set_phone(cls_input_validate::read_string("Enter phone number : "));
		user.set_password(cls_input_validate::read_string("Enter password : "));
		_read_permission(user);
	}


public : 

	static void update_user()
	{
		display_message("UPDATE USER SCREEN");
		string username = cls_input_validate::read_string("Enter user name : ");
		while (!cls_user::IsUserExist(username))
		{
			cout << "this username doesn't exists try again !!" << endl;
			username = cls_input_validate::read_string("Enter user name : ");
		}

		cls_user user = cls_user::Find(username);
		_print_user(user);
		_read_new_info(user);

		cls_user::enSaveResults result = user.Save();

		switch (result)
		{
		case cls_user::enSaveResults::svSucceeded:
			display_message("The user has been updated successfully .");
			break;
		case cls_user::enSaveResults::svFaildUserExists:
			display_message("User saving failed <Already exists> .");
			break;
		case cls_user::enSaveResults::svFaildEmptyObject:
			display_message("User saving failed < Object is empty > .");
			break;
		}
	}


};

