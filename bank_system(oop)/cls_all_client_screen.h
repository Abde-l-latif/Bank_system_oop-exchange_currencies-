#pragma once
#include <iostream>
#include "cls_bank_client.h"
#include "cls_util.h"
#include "cls_screen.h"
#include <iomanip>
#include "cls_user.h"

using namespace std; 

class cls_all_client_screen : cls_screen
{

private : 

    static void _print_clients_list_header()
    {
        cout << "__________________________________________________________________________________________________________________\n\n";
        cout << "| " << left << setw(18) << "Account number";
        cout << "| " << left << setw(20) << "Client name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(25) << "Email ";
        cout << "| " << left << setw(10) << "Pin code ";
        cout << "| " << left << setw(10) << "Account balance";
        cout << endl;
        cout << "__________________________________________________________________________________________________________________\n";
    }

    static void _print_clients_list_body(cls_bank_client& C)
    {
        cout << "\n";
        cout << "| " << left << setw(18) << C.get_account_number();
        cout << "| " << left << setw(20) << C.full_name();
        cout << "| " << left << setw(12) << C.get_phone();
        cout << "| " << left << setw(25) << C.get_email();
        cout << "| " << left << setw(10) << to_string(C.get_pin_code());
        cout << "| " << left << setw(10) << cls_util::remove_zero_fragments(to_string(C.get_account_balance()));
        cout << endl << endl;
        cout << "__________________________________________________________________________________________________________________\n";
    }

public :

    static void print_clients_list()
    {
        if (!has_rights(check_if_it_has_permission(cls_user::s_per::show_client_list_permission)))
        {
            return; 
        }
        vector <cls_bank_client> Clients = cls_bank_client::get_clients();
        header_screen("\t\tCLIENT LIST SCREEN", "   " + to_string(Clients.size()) + " Client(s)");
        _print_clients_list_header();
        if (Clients.size() == 0)
            cout << "No clients found!!!" << endl;
        else
        {
            for (cls_bank_client& C : Clients)
            {
                _print_clients_list_body(C);
            }
        }
    }
};

