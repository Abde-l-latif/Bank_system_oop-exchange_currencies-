#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_input_validate.h"
#include "cls_currency.h"

class cls_update_screen : protected cls_screen
{

private :

	static void _print_currency_card(cls_currency object)
	{
		cout << "Currency Card : " << endl;
		cout << "---------------------------------" << endl;
		cout << "Country      :  " << object.get_country() << endl;
		cout << "Code         :  " << object.get_code() << endl;
		cout << "Name         :  " << object.get_currency_name() << endl;
		cout << "Rate(1$)     :  " << to_string(object.get_rate()) << endl;
		cout << "---------------------------------" << endl;
	}

public : 

	static void update_screen()
	{
		header_screen("\t  Update currency screen");
		string code = cls_input_validate::read_string("Please enter currency code  : ");
		while (!cls_currency::is_exist(code))
		{
			cout << "Currency code not found try again !!" << endl;
			code = cls_input_validate::read_string("Please enter currency code  : ");
		}
		cls_currency object = cls_currency::find_by_code(code); 
		_print_currency_card(object);

		char answer = 'n';
		cout << "Are you sure you want to update the rate of this currency y/n : ";
		cin >> answer; 

		if (answer == 'y' || answer == 'Y')
		{
			float Rate;
			cout << "Update currency rate" << endl; 
			cout << "________________________________" << endl;
			cout << "Enter new rate : "; 
			cin >> Rate;
			object.update_rate(Rate); 
			display_message("Currency rate updated successfully !");
			_print_currency_card(object);
		}
		else {
			display_message("updating rate Operation denied!");
		}
	}
};

