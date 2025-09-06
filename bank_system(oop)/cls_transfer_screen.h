#pragma once
#include "cls_screen.h"
#include "cls_bank_client.h"

class cls_transfer_screen : protected cls_screen 
{

private :

	static void _print_client_card(cls_bank_client account)
	{
		cout << "--------------------------------------" << endl;
		cout << "   Client Card" << endl; 
		cout << "--------------------------------------" << endl;
		cout << "Full name     : " << account.full_name() << endl ; 
		cout << "Acc number    : " << account.get_account_number() << endl ;
		cout << "Balance       : " << cls_util::remove_zero_fragments(to_string(account.get_account_balance())) << endl ;
		cout << "--------------------------------------" << endl;
	}

	static string _read_account_number(string msg)
	{
		string account_number = cls_input_validate::read_string(msg);
		while (!cls_bank_client::is_client_exist(account_number))
		{
			cout << "this account number doesn't exist !! try again ." << endl;
			account_number = cls_input_validate::read_string(msg);
		}
		return account_number; 
	}

public : 

	static void transfer_screen()
	{
		display_message("TRANSFER SCREEN");

		cls_bank_client account_from = cls_bank_client::Find(_read_account_number("Please enter account number to transfer from : "));

		_print_client_card(account_from);

		cls_bank_client account_to = cls_bank_client::Find(_read_account_number("Please enter account number to transfer to : "));

		while (account_from.get_account_number() == account_to.get_account_number())
		{
			cout << "this account number is where you starting transfer from !! try again ." << endl;
			account_to = cls_bank_client::Find(_read_account_number("Please enter account number to transfer to : "));
		}

		_print_client_card(account_to);

		double amount = 0; 

		cout << "Enter transfer Amount :  ";
		cin >> amount;

		while (account_from.get_account_balance() < amount)
		{
			cin.ignore(1000, '\n');
			display_message("Amount Exceeds the available balance ! Enter another amount : ");
			cin >> amount;
		}

		char answer = 'n';

		cout << "Are you sure you wanna perform this ? y/n  :  ";
		cin >> answer; 

		if (answer == 'y' || answer == 'Y')
		{
			account_from.transfer(amount, account_to); 
			display_message("Transfer Done successfully !");
			_print_client_card(account_from);
			_print_client_card(account_to);
		}
			
	}

};

