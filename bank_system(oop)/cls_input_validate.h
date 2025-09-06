#pragma once
#include "cls_date.h"
#include <regex>
#include <sstream>

using namespace std; 

class cls_input_validate
{
public : 
	static bool is_number_between(int num, int from, int to)
	{
		if (num >= from && num <= to)
			return true;
		else
			return false;
	}
	static bool is_number_between(double num, double from, double to)
	{
		if (num >= from && num <= to)
			return true;
		else
			return false;
	}	
	static bool is_number_between(float num, float from, float to)
	{
		if (num >= from && num <= to)
			return true;
		else
			return false;
	}
	static bool is_date_between(cls_date date, cls_date date1, cls_date date2)
	{
		if (cls_date::check_if_date1_before_date2(date2, date1))
		{
			cls_date::swip(date1, date2);
		}

		if (cls_date::check_if_date1_after_date2(date, date1) && cls_date::check_if_date1_before_date2(date, date2))
			return true; 

		return false; 
	}
	static int read_number_input(string msg)
	{
		int num = 0 ;
		
		cout << msg;
		cin >> num; 

		while (cin.fail())
		{
			cin.clear(); 
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			cout << "wrong Data type try again  :  " << endl;
			cin >> num;
		}

		return num;
	}
	static double read_double_number_input(string msg)
	{
		string input;
		double num;

		regex doublePattern(R"(^[+-]?\d*\.\d+$)");

		while (true)
		{
			cout << msg;
			cin >> input;

			if (regex_match(input, doublePattern))
			{
				stringstream ss(input);
				ss >> num;
				if (!ss.fail()) return num;
			}

			cout << "something went wrong !!" << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	static float read_float_number_input(string msg)
	{
		string input;
		float num;

		regex floatPattern(R"(^[+-]?\d*\.\d+$)");

		while (true)
		{
			cout << msg;
			cin >> input;

			if (regex_match(input, floatPattern))
			{
				stringstream ss(input);
				ss >> num;
				if (!ss.fail()) return num;
			}

			cout << "something went wrong !!" << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	static int read_int_number_between(short from, short to, string message)
	{
		int number = 0; 
		cout << message;
		cin >> number;


		while (number < from || number > to)
		{
			if (cin.rdbuf()->in_avail() > 0)
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Number out of range try again!! : " << endl;
			cin >> number; 
		}
		return number; 

	}
	static bool is_validate_date(cls_date date)
	{
		date.is_validate_date();
	}

	static int read_double_between_input(double from, double to, string message)
	{
		double num = read_double_number_input("wrong data type try again");
		while (num < from || num > to)
		{
			cout << message << endl;
			num = read_double_number_input("wrong data type try again");
		}
		return num; 
	}

	static string  read_string(string msg)
	{
		string s = ""; 
		cout << msg << endl; 
		getline(cin >> ws, s);
		return s; 
	}
};

