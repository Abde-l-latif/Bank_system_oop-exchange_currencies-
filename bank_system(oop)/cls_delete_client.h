#pragma once
#include "cls_screen.h"
#include <iostream>
#include "cls_input_validate.h"
#include "cls_bank_client.h"

using namespace std;

class cls_delete_client : protected cls_screen
{

private : 

	static void _print_delete_client(cls_bank_client c)
	{
		cout << "\nClient Card:";
		cout << "\n__________________________________________";
		cout << "\nFirstName   : " << c.get_first_name();
		cout << "\nLastName    : " << c.get_last_name();
		cout << "\nFull Name   : " << c.full_name();
		cout << "\nEmail       : " << c.get_email();
		cout << "\nPhone       : " << c.get_phone();
		cout << "\nAcc. Number : " << c.get_account_number();
		cout << "\nPassword    : " << c.get_pin_code();
		cout << "\nBalance     : " << cls_util::remove_zero_fragments(to_string(c.get_account_balance()));
		cout << "\n_________________________________________\n";

	}

public :

	static void delete_account()
	{
		if (!has_rights(check_if_it_has_permission(cls_user::s_per::delete_client_permission)))
		{
			return;
		}
	    display_message("DELETE CLIENT SCREEN");
	
	    string account_number = cls_input_validate::read_string("Enter account number  : "); 
	
	    while (!cls_bank_client::is_client_exist(account_number))
	    {
	        display_message("this account number does not exist !!");
	        account_number = cls_input_validate::read_string("please enter account number  :");
	    }
	
	    cls_bank_client client = cls_bank_client::Find(account_number); 
	
		_print_delete_client(client);
	
	    char answer = 'n'; 
	
	    display_message("Are you sure you wanna delete this account ! y/n : "); 
	
	    cin >> answer; 
	
	    if (answer == 'y' || answer == 'Y')
	    {
	        client.delete_account();
			_print_delete_client(client);
	    }
	    else {
	        display_message("The operation has been denied");
	    }
	}
};

