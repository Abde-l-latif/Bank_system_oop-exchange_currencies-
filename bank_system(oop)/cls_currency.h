#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "cls_string.h"
#include <string>

using namespace std; 


class cls_currency
{

private :

	enum e_mode {empty_mode , update_mode};

	e_mode _mode; 
	string _country; 
	string _code;
	string _currency_name; 
	float _rate;


	string _convert_object_to_string(cls_currency object , string sep = "#//#")
	{
		string line = "";
		line += object.get_country() + sep; 
		line += object.get_code() + sep; 
		line += object.get_currency_name() + sep; 
		line += to_string(object.get_rate());
		return line;
	}

	void _write_file(vector <cls_currency> v_records)
	{
		fstream my_file; 
		my_file.open("curr.txt", ios::out); 
		if (my_file.is_open())
		{
			for (cls_currency& v_record : v_records)
			{
				my_file << _convert_object_to_string(v_record) << endl;
			}

			my_file.close(); 
		}

	}

	void _update()
	{
		vector <cls_currency> v_records = load_data_from_file();

		for (cls_currency & v_record : v_records)
		{
			if (v_record.get_code() == _code)
			{
				v_record = *this;
				break;
			}
		}

		_write_file(v_records);
	}

	static cls_currency _get_empty_object()
	{
		return cls_currency(e_mode::empty_mode, "", "", "", 0);
	}

	static cls_currency _convert_line_to_object(string line)
	{
		vector <string> data = cls_string::SplitString(line , "#//#");
		return cls_currency(e_mode::update_mode, data[0], data[1], data[2], stof(data[3]));
	}

public :

	cls_currency(e_mode mode , string country , string code , string currency_name , float rate )
	{
		_mode = mode;
		_country = country;
		_code = code; 
		_currency_name = currency_name; 
		_rate = rate;
	}

	bool is_empty()
	{
		return (_mode == e_mode::empty_mode);
	}
	
	string get_country()
	{
		return _country;
	}
	string get_code()
	{
		return _code;
	}
	string get_currency_name()
	{
		return _currency_name;
	}
	float get_rate()
	{
		return _rate; 
	}

	void update_rate(float new_rate)
	{
		_rate = new_rate; 
		_update();
	}

	static vector <cls_currency> load_data_from_file()
	{
		vector <cls_currency> v_records;
		fstream my_file;

		my_file.open("curr.txt", ios::in);

		if (my_file.is_open())
		{
			string line = "";

			while (getline(my_file, line))
			{
				cls_currency object = _convert_line_to_object(line);
				v_records.push_back(object);
			}

			my_file.close();

		}

		return v_records;
	}

	static cls_currency find_by_code(string code)
	{
		fstream my_file; 
		string CODE = cls_string::convert_to_upper(code);

		my_file.open("curr.txt", ios::in);

		if (my_file.is_open())
		{
			string line = ""; 

			while (getline(my_file, line))
			{
				cls_currency object = _convert_line_to_object(line);
				if (object.get_code() == CODE)
				{
					my_file.close();
					return object;
				}
			}

			my_file.close(); 
		}

		return _get_empty_object();
	}
	static cls_currency find_by_country(string country)
	{
		fstream my_file;
		string COUNTRY = cls_string::convert_to_upper(country);

		my_file.open("curr.txt", ios::in);

		if (my_file.is_open())
		{
			string line = "";

			while (getline(my_file, line))
			{
				cls_currency object = _convert_line_to_object(line);
				if ((cls_string::convert_to_upper(object.get_country())) == COUNTRY)
				{
					my_file.close();
					return object;
				}
			}

			my_file.close();
		}

		return _get_empty_object();
	}

	static bool is_exist(string currency_code)
	{
		cls_currency c = cls_currency::find_by_code(currency_code);
		return (!c.is_empty());
	}
	static bool is_exist_by_country(string country)
	{
		cls_currency c = cls_currency::find_by_country(country);
		return (!c.is_empty());
	}

	static float convert_to_dollar(float amount, float base_rate)
	{
		return (amount / base_rate);
	}

	static float convert_currencies(float amount , float base_rate , float second_rate)
	{
		return convert_to_dollar(amount, base_rate) * second_rate;
	}

};

