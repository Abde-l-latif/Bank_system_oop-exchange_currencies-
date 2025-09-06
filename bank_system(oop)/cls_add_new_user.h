#pragma once
#include "cls_screen.h"
#include "cls_input_validate.h"
#include "cls_user.h"

class cls_add_new_user : cls_screen
{

private : 

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
		cout << "you wanna give it permission to login register ? y/n : ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			permission += all_permissions.login_register_permission;
		}
		user.set_permission(permission);
	}

	static void _read_new_user(cls_user & user)
	{
		user.set_firstname(cls_input_validate::read_string("Enter first name : ")); 
		user.set_lastname(cls_input_validate::read_string("Enter last name : "));
		user.set_email(cls_input_validate::read_string("Enter email : "));
		user.set_phone(cls_input_validate::read_string("Enter phone number : "));
		user.set_password(cls_input_validate::read_string("Enter password : "));
		_read_permission(user);
	}

public:

	static void add_new_user()
	{
		display_message("ADD NEW USER SCREEN");
		string username = cls_input_validate::read_string("Enter user name : ");
		while (cls_user::IsUserExist(username))
		{
			cout << "this username already exists try again !!" << endl; 
			username = cls_input_validate::read_string("Enter user name : ");
		}

		cls_user new_user = cls_user::GetAddNewUserObject(username); 

		_read_new_user(new_user); 

		cls_user::enSaveResults result = new_user.Save();

		switch (result)
		{
		case cls_user::enSaveResults::svSucceeded:
			display_message("The user has been added successfully ."); 
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

