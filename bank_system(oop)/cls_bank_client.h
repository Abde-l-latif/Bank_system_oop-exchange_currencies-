#pragma once
#include "cls_person.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "cls_util.h"
#include "cls_string.h"

using namespace std; 

class cls_bank_client : public cls_person
{

private : 

	enum en_mode {empty_mode , update_mode , add_mode};

	en_mode _mode; 
	string _account_number; 
	int _pin_code;
	float _account_balance;
	bool _delete_account = false; 

	static vector <cls_bank_client> _load_client_data_from_file()
	{
		vector <cls_bank_client> Clients; 
		fstream my_file; 

		my_file.open("bank_clients.txt", ios::in);

		if (my_file.is_open())
		{
			string line; 
			while (getline(my_file, line))
			{
				cls_bank_client client = _convert_line_to_client_object(line);
				Clients.push_back(client); 
			}

			my_file.close(); 
		}

		return Clients;
	}

	static cls_bank_client _convert_line_to_client_object(string record)
	{
		vector <string> v_client = cls_string::SplitString(record, "#//#"); 

		cls_bank_client client = cls_bank_client(en_mode::update_mode, v_client[0], v_client[1],
			v_client[2], v_client[3], v_client[4], stoi(v_client[5]), stof(v_client[6]));

		return client; 
	}

	static cls_bank_client _get_empty_client_object()
	{
		return cls_bank_client(en_mode::empty_mode, "", "", "", "", "", 0000, 0); 
	}

	static string _convert_object_to_line(cls_bank_client Client, string Seperator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += Client.get_first_name() + Seperator;
		stClientRecord += Client.get_last_name() + Seperator;
		stClientRecord += Client.get_email() + Seperator;
		stClientRecord += Client.get_phone() + Seperator;
		stClientRecord += Client.get_account_number() + Seperator;
		stClientRecord += to_string(Client.get_pin_code()) + Seperator;
		stClientRecord += to_string(Client.get_account_balance());

		return stClientRecord;

	}

	static void _save_client_data_to_file(vector <cls_bank_client> & vClients)
	{

		fstream MyFile;
		MyFile.open("bank_clients.txt", ios::out);

		string data_line = "";

		if (MyFile.is_open())
		{

			for (cls_bank_client & C : vClients)
			{
				data_line = _convert_object_to_line(C);
				MyFile << data_line << endl;

			}

			MyFile.close();
		}

	}

	void _update_client()
	{
		vector <cls_bank_client> _vClients;
		_vClients = _load_client_data_from_file();

		for (cls_bank_client & C : _vClients)
		{
			if (C.get_account_number() == get_account_number())
			{
				C = *this;
				break;
			}

		}

		_save_client_data_to_file(_vClients);
	}

	void _add_client_object_to_file(string client)
	{
		fstream my_file; 

		my_file.open("bank_clients.txt", ios::out | ios::app);

		if (my_file.is_open())
		{

			my_file << client << endl; 

			my_file.close(); 
		}
	}

	void _add_new_client_to_file()
	{
		_add_client_object_to_file(_convert_object_to_line(*this));
	}

	static void _delete_client_data_from_file(vector <cls_bank_client>& vClients)
	{

		fstream MyFile;

		MyFile.open("bank_clients.txt", ios::out);

		string data_line = "";

		if (MyFile.is_open())
		{

			for (cls_bank_client& C : vClients)
			{
				if (C._delete_account == false)
				{
					data_line = _convert_object_to_line(C);
					MyFile << data_line << endl;
				}
			}

			MyFile.close();
		}

	}

	

public : 

	cls_bank_client(en_mode mode , string firstname , string lastname , string email , string phone , string account_number , 
		int pin_code , float account_balance) : cls_person(firstname , lastname , email , phone)
	{
		_mode = mode; 
		_account_number = account_number; 
		_pin_code = pin_code;
		_account_balance = account_balance;
	}

	bool is_empty()
	{
		return (_mode == en_mode::empty_mode);
	}

	// getters

	string get_account_number()
	{
		return _account_number; 
	}

	int get_pin_code()
	{
		return _pin_code;
	}

	float get_account_balance()
	{
		return _account_balance;
	}

	// setters 

	void set_pin_code(int pin)
	{
		_pin_code = pin; 
	}

	void set_account_balance(int balance)
	{
		_account_balance = balance ;
	}

	// find object 

	static cls_bank_client Find(string account_number)
	{
		fstream MyFile;
		MyFile.open("bank_clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				cls_bank_client client = _convert_line_to_client_object(Line);
				if (client.get_account_number() == account_number)
				{
					MyFile.close();
					return client;
				}

			}

			MyFile.close();

		}

		return _get_empty_client_object();
	}

	static cls_bank_client Find(string account_number , int code)
	{
		fstream MyFile;
		MyFile.open("bank_clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				cls_bank_client client = _convert_line_to_client_object(Line);
				if (client.get_account_number() == account_number && client.get_pin_code() == code)
				{
					MyFile.close();
					return client;
				}

			}

			MyFile.close();

		}

		return _get_empty_client_object();
	}

	static bool is_client_exist(string account_number)
	{

		cls_bank_client Client1 = cls_bank_client::Find(account_number);
		return (!Client1.is_empty());
	}

	enum en_save { saving_failed , saving_success , saving_failed_accountnum_exist };

	en_save save()
	{
		switch (_mode)
		{
		case en_mode::empty_mode : 
			return en_save::saving_failed; 
		case en_mode::update_mode : 
			_update_client(); 
			return en_save::saving_success;
		case en_mode::add_mode : 
			if (is_client_exist(get_account_number()))
				return en_save::saving_failed_accountnum_exist;
			else
			{
				_add_new_client_to_file();
				return en_save::saving_success;
			}
			break; 
		}
	}

	void Deposit(double amount)
	{
		this->set_account_balance(amount + get_account_balance()); 
		this->save(); 
	}

	bool Withdraw(double amount)
	{
		if (amount > get_account_balance())
		{
			return false;
		}
		else {
			this->set_account_balance(get_account_balance() - amount);
			this->save();
		}
	}

	static struct s_transfer {
		string date;
		string from_account;
		string to_account;
		double amount_transfer;
		double user1_balance;
		double user2_balance;
		string username;
	};

	string _prepare_transfer_log(s_transfer record, string sep = "#//#")
	{
		string line = record.date + sep;
		line += record.from_account + sep;
		line += record.to_account + sep;
		line += to_string(record.amount_transfer) + sep;
		line += to_string(record.user1_balance) + sep;
		line += to_string(record.user2_balance) + sep;
		line += record.username;
		return line;
	}

	s_transfer _transfer_log_struct(double amount, cls_bank_client to)
	{
		cls_date DATE;
		s_transfer info;
		info.date = DATE.convert_date_to_string() + " - " + DATE.convert_time_to_string();
		info.from_account = this->get_account_number();
		info.to_account = to.get_account_number();
		info.amount_transfer = amount;
		info.user1_balance = this->get_account_balance();
		info.user2_balance = to.get_account_balance();
		info.username = current_user.get_username();
		return info;
	}

	void _save_in_transfer_file(string line)
	{
		fstream my_file;
		my_file.open("transfer.txt", ios::app | ios::out);
		if (my_file.is_open())
		{
			my_file << line << endl;
			my_file.close();
		}
	}

	static vector <string> _convert_line_to_vector(string line)
	{
		return cls_string::SplitString(line, "#//#");
	}

	static s_transfer _convert_vector_to_struct(vector <string> data)
	{
		s_transfer info;
		info.date = data[0];
		info.from_account = data[1];
		info.to_account = data[2];
		info.amount_transfer = stod(data[3]);
		info.user1_balance = stod(data[4]);
		info.user2_balance = stod(data[5]);
		info.username = data[6];
		return info;
	}



	bool transfer(double amount , cls_bank_client & to)
	{
		if (amount > get_account_balance())
		{
			return false;
		}
		else
		{
			this->Withdraw(amount); 
			to.Deposit(amount); 
			string line = _prepare_transfer_log(_transfer_log_struct(amount, to));
			_save_in_transfer_file(line);
			return true; 
		}
	}

	static vector <s_transfer> read_transfer_file()
	{
		fstream my_file;
		vector <s_transfer> v_records;
		my_file.open("transfer.txt", ios::in);
		if (my_file.is_open())
		{
			string line = "";

			while (getline(my_file, line))
			{
				s_transfer data = _convert_vector_to_struct(_convert_line_to_vector(line));
				v_records.push_back(data);
			}

			my_file.close();
		}

		return v_records;
	}


	static cls_bank_client get_add_new_client(string AccountNumber)
	{
		return cls_bank_client(en_mode::add_mode, "", "", "", "", AccountNumber, 0, 0);
	}

	bool delete_account()
	{
		vector <cls_bank_client> all_clients = _load_client_data_from_file(); 

		for (cls_bank_client & C : all_clients)
		{
			if (C.get_account_number() == this->_account_number)
			{
				C._delete_account = true; 
				break; 
			}
		}

		_delete_client_data_from_file(all_clients); 

		*this = _get_empty_client_object();

		return true;

	}

	static vector<cls_bank_client> get_clients()
	{
		return  _load_client_data_from_file();
	}

	static float get_total_balances()
	{
		vector<cls_bank_client> All_clients = _load_client_data_from_file();

		float total_balances = 0;

		for (cls_bank_client& C : All_clients)
		{
			total_balances += C.get_account_balance(); 
		}

		return total_balances;

	}

};

