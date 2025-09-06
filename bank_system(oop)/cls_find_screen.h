#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_input_validate.h"
#include "cls_currency.h"


class cls_find_screen : protected cls_screen
{

private : 

	enum e_status {code = 1 , country};

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
	
	static void find_currency_screen()
	{
		header_screen("\t\t Find Currency Screen");
		cout << "Find By : [1] Code or [2] Country ? : ";
		e_status choice = (e_status)cls_input_validate::read_int_number_between(1, 2, "");
		string answer = "";
		switch (choice)
		{
		case e_status::code : 
		{
			cout << "please enter currency code :  ";
			cin >> answer;
			if (cls_currency::is_exist(answer))
			{
				cout << "Currency Found : -) " << endl;
				cls_currency object = cls_currency::find_by_code(answer);
				_print_currency_card(object);
			}
			else
			{
				cout << "Currency not Found : -( " << endl;
			}
			break;
		}
		case e_status::country:
		{
			cout << "please enter country name :  ";
			cin >> answer;
			if (cls_currency::is_exist_by_country(answer))
			{
				cout << "Currency Found : -) " << endl;
				cls_currency object = cls_currency::find_by_country(answer);
				_print_currency_card(object);
			}
			else
			{
				cout << "Currency not Found : -( " << endl;
			}
			break;
		}
		}
	}

};

