#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_currency.h"


class cls_currency_calculator : protected cls_screen
{

private :

	static string _read_currency_code(string msg)
	{
		string code =  cls_input_validate::read_string(msg);
		while (!cls_currency::is_exist(code))
		{
			cout << "this currency code doesn't exist try again !" << endl;
			code = cls_input_validate::read_string(msg);
		}
		return code;
	}
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
		
	static void currencies_calculator()
	{
		char answer = 'n'; 

		do {
			system("cls");
			header_screen("\t Currencies calculator screen ");
			string first_currency_code = _read_currency_code("Please Enter first Currency code  :  ");
			string second_currency_code = _read_currency_code("Please Enter second Currency code  :  ");

			float amount;
			cout << "Enter amount to exchange : " << endl;
			cin >> amount;

			cls_currency first_object = cls_currency::find_by_code(first_currency_code);
			_print_currency_card(first_object);

			cout << cls_util::remove_zero_fragments(to_string(amount)) + " " + first_object.get_currency_name() + " = " +
				cls_util::remove_zero_fragments(to_string(cls_currency::convert_to_dollar(amount, first_object.get_rate()))) + " USD " << endl;

			cls_currency second_object = cls_currency::find_by_code(second_currency_code);
			if (second_object.get_currency_name() != "USD")
			{
				cout << "Converting from USD to " + second_object.get_currency_name() << endl;
				_print_currency_card(second_object);
				cout << cls_util::remove_zero_fragments(to_string(amount)) + " " + first_object.get_currency_name() + " = " +
					cls_util::remove_zero_fragments(to_string(cls_currency::convert_currencies(amount, first_object.get_rate(), second_object.get_rate())))
					+ " " + second_object.get_currency_name() << endl;
			}
			cout << "Do you want to perform another calculation y/n : "; 
			cin >> answer;

		} while (answer == 'y' || answer == 'Y');

	}
};

