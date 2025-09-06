#pragma once
#include "cls_screen.h"
#include <iostream>
#include "cls_bank_client.h"
#include "cls_input_validate.h"
#include "cls_util.h"

using namespace std; 

class cls_update_client : protected cls_screen
{

private : 

	static void _read_new_info_client(cls_bank_client& client)
	{
		client.set_firstname(cls_input_validate::read_string("please enter firstname  :"));
		client.set_lastname(cls_input_validate::read_string("please enter lastname  :"));
		client.set_email(cls_input_validate::read_string("please enter email  :"));
		client.set_phone(cls_input_validate::read_string("please enter phone number  :"));
		client.set_pin_code(cls_input_validate::read_number_input("please enter pin code  :"));
		client.set_account_balance(cls_input_validate::read_float_number_input("please enter account balance  :"));
	}

	static void _print_update_client(cls_bank_client c)
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

	static void update_client()
	{
		if (!has_rights(check_if_it_has_permission(cls_user::s_per::update_client_permission)))
		{
			return;
		}
		display_message("UPDATE CLIENT SCREEN");
	    string account_number = cls_input_validate::read_string("please enter account number  :");
	
	    while (!cls_bank_client::is_client_exist(account_number))
	    {
	        display_message("this account number does not exist !!");
	        account_number = cls_input_validate::read_string("please enter account number  :");
	    }
	
	    cls_bank_client get_client = cls_bank_client::Find(account_number); 
		_print_update_client(get_client);

		char answer = 'n'; 

		cout << "are you sure you wanna update this client !! y/n : ";
		cin >> answer; 

		if (answer == 'n' || answer == 'N')
		{
			display_message("updating proccess failed");
			return;
		}
	
	    display_message("Update client information");
	    _read_new_info_client(get_client); 
	
	    cls_bank_client::en_save save_in_backend = get_client.save();
	
	    switch (save_in_backend)
	    {
	    case  cls_bank_client::en_save::saving_failed:
	        display_message("saving proccess failed");
	        break; 
	    case  cls_bank_client::en_save::saving_success:
	        display_message("saving proccess successfully done");
			_print_update_client(get_client);
			break;
	    }
	
	} 
};

