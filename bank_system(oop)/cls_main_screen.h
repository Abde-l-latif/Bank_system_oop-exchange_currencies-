#pragma once
#include <iostream>
#include "cls_screen.h"
#include "cls_input_validate.h"
#include "cls_all_client_screen.h"
#include "cls_add_client_screen.h"
#include "cls_delete_client.h"
#include "cls_update_client.h"
#include "cls_find_client.h"
#include "cls_transaction_menu.h"
#include "cls_manage_users.h"
#include "global.h"
#include "cls_login_register.h"
#include "cls_currency_menu.h"



using namespace std;

class cls_main_screen : protected cls_screen
{
private :

    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, login_reg = 8 , eCurrency = 9 , eExit = 10
    };

    static enMainMenueOptions _get_main_menu_choice()
    {
        cout << setw(37) << left << "";
        short Choice = cls_input_validate::read_int_number_between(1, 10, "Choose what do you want to do? [1 to 10]? ");
        enMainMenueOptions result = (enMainMenueOptions)Choice;
        return result;
    }

    static void _ShowAllClientsScreen()
    {
        cls_all_client_screen::print_clients_list();
        custom_pause("press enter to go back to the main menu");
    }

    static void _ShowAddNewClientsScreen()
    {
        cls_add_client_screen::add_new_client();
        custom_pause("press enter to go back to the main menu");
    }

    static void _ShowDeleteClientScreen()
    {
        cls_delete_client::delete_account();
        custom_pause("press enter to go back to the main menu");
    }

    static void _ShowUpdateClientScreen()
    {
        cls_update_client::update_client();
        custom_pause("press enter to go back to the main menu");
    }

    static void _ShowFindClientScreen()
    {
        cls_find_client::find_client();
        custom_pause("press enter to go back to the main menu");
    }

    static void _ShowTransactionsMenue()
    {
        cls_transaction_menu::ShowTransactionsMenue(); 
    }

    static void _ShowManageUsersMenue()
    {
        cls_manage_users::ShowManageUsersMenue(); 
    }

    static void _Showloginregister()
    {
        cls_login_register::login_register(); 
        custom_pause("press enter to go back to the main menu");
    }

    static void _show_currency_menu()
    {
        cls_currency_menu::currency_exchange_menu();
    }

    static void _logout()
    {
        current_user = current_user.Find("", "");
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            break;
        case enMainMenueOptions::login_reg:
            system("cls");
            _Showloginregister();
            break;
        case enMainMenueOptions::eCurrency:
            system("cls");
            _show_currency_menu();
            break;
        case enMainMenueOptions::eExit:
            system("cls");
            _logout();
            break;
        }

    }

public :

	static void show_main_menu()
	{
        enMainMenueOptions choice;
        do
        {
            system("cls");
            header_screen("\t\tMAIN MENU SCREEN");
            cout << endl;
            cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
            cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
            cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
            cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
            cout << setw(37) << left << "" << "\t[5] Find Client.\n";
            cout << setw(37) << left << "" << "\t[6] Transactions.\n";
            cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
            cout << setw(37) << left << "" << "\t[8] Login register.\n";
            cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
            cout << setw(37) << left << "" << "\t[10] Logout.\n";
            cout << setw(32) << left << "" << "________________________________________________\n";
            choice = _get_main_menu_choice();
            _PerfromMainMenueOption(choice);
        } while (choice != enMainMenueOptions::eExit);

	}
};

