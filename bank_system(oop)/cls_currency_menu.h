#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_currency_list_screen.h"
#include "cls_find_screen.h"
#include "cls_update_screen.h"
#include "cls_currency_calculator.h"

using namespace std; 


class cls_currency_menu : protected cls_screen
{

private:

	enum e_choice { e_list_curr = 1  , e_find_curr , e_update_rate , e_curr_calculator , e_main_menu};

	static e_choice _read_choice()
	{
		cout << setw(37) << left << "";
		short Choice = cls_input_validate::read_int_number_between(1, 5, "Choose what do you want to do? [1 to 5]? ");
		e_choice result = (e_choice)Choice;
		return result;
	}

	static void _show_currency_list()
	{
		cls_currency_list_screen::currency_list_screen();
		custom_pause("press enter to go back to the currency menu :  ");
	}

	static void _show_find_currency()
	{
		cls_find_screen::find_currency_screen();
		custom_pause("press enter to go back to the currency menu :  ");
	}

	static void _show_update_rate()
	{
		cls_update_screen::update_screen();
		custom_pause("press enter to go back to the currency menu :  ");
	}

	static void _show_currency_calculator()
	{
		cls_currency_calculator::currencies_calculator(); 
		custom_pause("press enter to go back to the currency menu :  ");
	}

	static void _check_user_choice(e_choice choice)
	{
		switch (choice)
		{
		case e_choice::e_list_curr:
			system("cls");
			_show_currency_list();
			break;
		case e_choice::e_find_curr:
			system("cls");
			_show_find_currency();
			break;
		case e_choice::e_update_rate:
			system("cls");
			_show_update_rate();
			break;
		case e_choice::e_curr_calculator:
			system("cls");
			_show_currency_calculator();
			break;
		}
	}

public : 

	static void currency_exchange_menu()
	{
		e_choice choice;

		do {

			system("cls");
			header_screen("\t\tCurrency Exchange Main screen");
			cout << "\t\t\t\t =================================================" << endl;
			cout << "\t\t\t\t\t\t Currency Exchange Menu " << endl;
			cout << "\t\t\t\t =================================================" << endl;
			cout << "\t\t\t\t  [1]  List currencies ." << endl;
			cout << "\t\t\t\t  [2]  Find currency ." << endl;
			cout << "\t\t\t\t  [3]  Update rate ." << endl;
			cout << "\t\t\t\t  [4]  Currency calculator ." << endl;
			cout << "\t\t\t\t  [5]  Main menu ." << endl;
			cout << "\t\t\t\t =================================================" << endl;

			choice = _read_choice();

			_check_user_choice(choice);

		} while (choice != e_choice::e_main_menu);


	}

};

