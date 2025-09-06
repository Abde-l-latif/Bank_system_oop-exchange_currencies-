#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_currency.h"

class cls_currency_list_screen : protected cls_screen
{

private : 

	static void _print_header_table()
	{
		cout << "\t ------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\t| " << left << setw(25) << "Country";
		cout << "\t| " << left << setw(8) << "Code";
		cout << "\t| " << left << setw(40) << "Name";
		cout << "\t| " << left << setw(10) << "Rate/($1)" << endl;
		cout << "\t ------------------------------------------------------------------------------------------------------------" << endl << endl;
	}
	static void _print_body_table(cls_currency info)
	{
		cout << "\t| " << left << setw(25) << info.get_country();
		cout << "\t| " << left << setw(8) << info.get_code();
		cout << "\t| " << left << setw(40) << info.get_currency_name();
		cout << "\t| " << left << setw(10) << info.get_rate() << endl;
	}

public : 

	static void currency_list_screen()
	{
		vector <cls_currency> records = cls_currency::load_data_from_file(); 
		header_screen("\t\tCurrency List Screen", "  ( " + to_string(records.size()) + ") Currency");
		_print_header_table(); 
		for (cls_currency& record : records)
		{
			_print_body_table(record);
		}
	}

};

