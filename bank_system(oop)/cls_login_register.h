#pragma once
#include "cls_screen.h"
#include "cls_user.h"
#include <iomanip>
#include <iostream>

using namespace std; 

class cls_login_register : protected cls_screen
{

    static void _PrintLoginRegisterRecordLine(cls_user::s_info LoginRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.date;
        cout << "| " << setw(20) << left << LoginRegisterRecord.username;
        cout << "| " << setw(20) << left << LoginRegisterRecord.password;
        cout << "| " << setw(10) << left << LoginRegisterRecord.permission;
    }


public :

	static void login_register()
	{
        if (!has_rights(check_if_it_has_permission(cls_user::s_per::login_register_permission)))
        {
            return;
        }
		vector <cls_user::s_info> login_list = cls_user::LoadloginDataFromFile();

        header_screen("\t\tLOGIN REGISTER LIST SCREEN", "(" + to_string(login_list.size()) + ") Records");

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

       if (login_list.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (cls_user::s_info Record : login_list)
            {

                _PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
	}

};

