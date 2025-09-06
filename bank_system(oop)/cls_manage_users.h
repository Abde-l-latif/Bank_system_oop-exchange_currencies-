#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_input_validate.h"
#include <iomanip>
#include "clsListUsersScreen.h"
#include "cls_add_new_user.h"
#include "cls_delete_user.h"
#include "cls_update_user.h"
#include "cls_find_user.h"

using namespace std;

class cls_manage_users :protected cls_screen
{

private:

    enum enManageUsersMenueOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };

    static enManageUsersMenueOptions ReadManageUsersMenueOption()
    {
        cout << setw(37) << left << "" ;
        short Choice = cls_input_validate::read_int_number_between(1, 6, "Choose what do you want to do? [1 to 6]?  :  ");
        return (enManageUsersMenueOptions)Choice;
    }

    static void _ShowListUsersScreen()
    {
        clsListUsersScreen::ShowUsersList();
        custom_pause("Press any key to go back to main menu : ");
    }

    static void _ShowAddNewUserScreen()
    {
        cls_add_new_user::add_new_user();
        custom_pause("Press any key to go back to main menu : ");
    }

    static void _ShowDeleteUserScreen()
    {
        cls_delete_user::delete_user(); 
        custom_pause("Press any key to go back to main menu : ");
    }

    static void _ShowUpdateUserScreen()
    {
        cls_update_user::update_user();
        custom_pause("Press any key to go back to main menu : ");
    }

    static void _ShowFindUserScreen()
    {
        cls_find_user::find_user();
        custom_pause("Press any key to go back to main menu : ");
    }

    static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
    {

        switch (ManageUsersMenueOption)
        {
        case enManageUsersMenueOptions::eListUsers:
        {
            system("cls");
            _ShowListUsersScreen();
            break;
        }

        case enManageUsersMenueOptions::eAddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            break;
        }

        case enManageUsersMenueOptions::eDeleteUser:
        {
            system("cls");
            _ShowDeleteUserScreen();

            break;
        }

        case enManageUsersMenueOptions::eUpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            break;
        }

        case enManageUsersMenueOptions::eFindUser:
        {
            system("cls");
            _ShowFindUserScreen();
            break;
        }

        }

    }

public:

    static void ShowManageUsersMenue()
    {
        if (!has_rights(check_if_it_has_permission(cls_user::s_per::manage_user_permission)))
        {
            custom_pause("press enter to go back to main menu : ");
            return;
        }
        enManageUsersMenueOptions choice;
        do {
            system("cls");
            header_screen("\t    Manage Users Screen");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] List Users.\n";
            cout << setw(37) << left << "" << "\t[2] Add New User.\n";
            cout << setw(37) << left << "" << "\t[3] Delete User.\n";
            cout << setw(37) << left << "" << "\t[4] Update User.\n";
            cout << setw(37) << left << "" << "\t[5] Find User.\n";
            cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            choice = ReadManageUsersMenueOption();
            _PerformManageUsersMenueOption(choice);

        } while (choice != enManageUsersMenueOptions::eMainMenue);
    }

};
