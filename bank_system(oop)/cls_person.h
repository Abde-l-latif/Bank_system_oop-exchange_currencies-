#pragma once
#include <iostream>

using namespace std;

class cls_person
{

private : 
	string _first_name;
	string _last_name; 
	string _email;
	string _phone;
	
public :

	cls_person(string  _first_name, string  _last_name, string  _email, string  _phone)
	{
		this->_first_name = _first_name; 
		this->_last_name = _last_name;
		this->_email = _email;
		this->_phone = _phone;
	}

	//setters 

	void set_firstname(string firstname)
	{
		_first_name = firstname; 
	}

	void set_lastname(string lastname)
	{
		_last_name = lastname;
	}

	void set_email(string email)
	{
		_email = email;
	}

	void set_phone(string phone)
	{
		_phone = phone;
	}

	//getters 

	string get_first_name()
	{
		return _first_name; 
	}

	string get_last_name()
	{
		return _last_name;
	}

	string get_email()
	{
		return _email;
	}

	string get_phone()
	{
		return _phone;
	}

	string full_name()
	{
		return _first_name + " " + _last_name; 
	}
};

