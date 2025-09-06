#pragma once

#include <iostream>
#include "cls_screen.h"
#include "cls_user.h"
#include <iomanip>

class clsListUsersScreen :protected cls_screen
{

private:
    static void _PrintUserRecordLine(cls_user User)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << User.get_username();
        cout << "| " << setw(25) << left << User.full_name();
        cout << "| " << setw(12) << left << User.get_phone();
        cout << "| " << setw(20) << left << User.get_email();
        cout << "| " << setw(10) << left << User.get_password();
        cout << "| " << setw(12) << left << User.get_permission();

    }

public:

    static void ShowUsersList()
    {
        vector <cls_user> vUsers = cls_user::GetUsersList();

        string Title = "\t  User List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";

        header_screen(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (cls_user User : vUsers)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};


