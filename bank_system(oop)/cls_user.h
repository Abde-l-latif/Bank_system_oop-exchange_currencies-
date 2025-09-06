#pragma once
#include "cls_person.h"
#include <vector>
#include "cls_string.h"
#include <string>
#include <fstream>
#include "cls_date.h"
#include "cls_util.h"

class cls_user : public cls_person 
{

private : 

	enum en_mode { empty_mode, update_mode, add_mode };
	bool _delete_account = false;
	en_mode _mode;
	int _permissions; 
	string _username; 
	string _password;

    static cls_user _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = cls_string::SplitString(Line, Seperator);

        return cls_user(en_mode::update_mode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], cls_util::decrypt_pass(vUserData[5], 10), stoi(vUserData[6]));

    }

    static string _ConverUserObjectToLine(cls_user User, string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += User.get_first_name() + Seperator;
        UserRecord += User.get_last_name() + Seperator;
        UserRecord += User.get_email() + Seperator;
        UserRecord += User.get_phone() + Seperator;
        UserRecord += User.get_username() + Seperator;
        UserRecord += cls_util::encrypt_pass(User.get_password(), 10) +Seperator;
        UserRecord += to_string(User._permissions);

        return UserRecord;

    }

    static  vector <cls_user> _LoadUsersDataFromFile()
    {

        vector <cls_user> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                cls_user User = _ConvertLinetoUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }

    static void _SaveUsersDataToFile(vector <cls_user> vUsers)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (cls_user U : vUsers)
            {
                if (U.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _ConverUserObjectToLine(U);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <cls_user> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (cls_user& U : _vUsers)
        {
            if (U.get_username() == _username)
            {
                U = *this;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConverUserObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static cls_user _GetEmptyUserObject()
    {
        return cls_user(en_mode::empty_mode, "", "", "", "", "", "", 0);
    }

    string _PrepareLogInRecord(string Seperator = "#//#")
    {
        cls_date date; 
        string LoginRecord = "";
        LoginRecord += date.convert_date_to_string() + " - " + date.convert_time_to_string() + Seperator;
        LoginRecord += _username + Seperator;
        LoginRecord += cls_util::encrypt_pass(_password , 10) + Seperator;
        LoginRecord += to_string(_permissions);
        return LoginRecord;
    }

public : 

	cls_user(en_mode mode , string firstname , string lastname , string email , string phone , string username , string password , int permission)
		: cls_person(firstname , lastname , email , phone)
	{
		_mode = mode; 
		_username = username; 
		_password = password;
		_permissions = permission; 
	}

    static struct s_per {
        static const short show_client_list_permission = 1;
        static const short add_new_client_permission = 2;
        static const short delete_client_permission = 4;
        static const short update_client_permission = 8;
        static const short find_client_permission = 16;
        static const short transaction_permission = 32;
        static const short manage_user_permission = 64;
        static const short login_register_permission = 128;
    };

	bool is_empty()
	{
		return (_mode == en_mode::empty_mode);
	}

    bool MarkedForDeleted()
    {
        return _delete_account;
    }

	//setters & getters

	void set_permission(int per)
	{
		_permissions = per; 
	}

	void set_username(string user)
	{
		_username = user;
	}

	void set_password(string password)
	{
		_password = password;
	}

	int get_permission()
	{
		return _permissions; 
	}

	string get_username()
	{
		return _username;
	}

	string get_password()
	{
		return _password;
	}

	//

    static cls_user Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                cls_user User = _ConvertLinetoUserObject(Line);
                if (User._username == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }

        return _GetEmptyUserObject();
    }

    static cls_user Find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                cls_user User = _ConvertLinetoUserObject(Line);
                if (User._username == UserName && User._password == Password)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

    enSaveResults Save()
    {

        switch (_mode)
        {
        case en_mode::empty_mode:
        {
            if (is_empty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }

        case en_mode::update_mode :
        {
            _Update();
            return enSaveResults::svSucceeded;

            break;
        }

        case en_mode::add_mode:
        {
            //This will add new record to file or database
            if (cls_user::IsUserExist(_username))
            {
                return enSaveResults::svFaildUserExists;
            }
            else
            {
                _AddNew();
                //We need to set the mode to update after add new
                _mode = en_mode::update_mode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }

    }

    static bool IsUserExist(string UserName)
    {

        cls_user User = cls_user::Find(UserName);
        return (!User.is_empty());
    }

    bool Delete()
    {
        vector <cls_user> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (cls_user & U : _vUsers)
        {
            if (U.get_username() == _username)
            {
                U._delete_account = true;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;

    }

    static cls_user GetAddNewUserObject(string UserName)
    {
        return cls_user(en_mode::add_mode, "", "", "", "", UserName, "", 0);
    }

    static vector <cls_user> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }

    static vector<string> ConvertLinetovector(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = cls_string::SplitString(Line, Seperator);

        return vUserData;
    }


    void RegisterLogIn()
    {

        string stDataLine = _PrepareLogInRecord();

        fstream MyFile;
        MyFile.open("login.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }

    static struct s_info {
        string date;
        string username;
        string password;
        short permission;
    };

    static s_info convert_vec_to_struct(vector<string> user)
    {
        s_info register_login;
        register_login.date = user[0];
        register_login.username = user[1];
        register_login.password = cls_util::decrypt_pass(user[2] , 10);
        register_login.permission = stoi(user[3]);
        return register_login;
    }

    static  vector <s_info> LoadloginDataFromFile()
    {

        vector <s_info> vUsers;

        fstream MyFile;

        MyFile.open("login.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {
                s_info info = convert_vec_to_struct(ConvertLinetovector(Line));
                vUsers.push_back(info);
            }

            MyFile.close();

        }

        return vUsers;

    }



};

