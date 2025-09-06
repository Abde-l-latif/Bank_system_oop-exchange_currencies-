#pragma once
#include "cls_screen.h"
#include <iostream>
#include "cls_bank_client.h"
#include <iomanip>

using namespace std;


class cls_total_balance : protected cls_screen
{

private : 

    static void _total_balances_header(vector <cls_bank_client> & Clients)
    {
        cout << "\t\t\t\t Client list (" << Clients.size() << ") Client(s)" << endl;
        cout << "________________________________________________________________________________________\n\n";
        cout << "| " << left << setw(18) << "Account number";
        cout << "| " << left << setw(40) << "Client name";
        cout << "| " << left << setw(20) << "Balance";
        cout << endl;
        cout << "________________________________________________________________________________________\n";
    }

    static void _total_balances_body(cls_bank_client & C )
    {
        cout << "\n";
        cout << "| " << left << setw(18) << C.get_account_number();
        cout << "| " << left << setw(40) << C.full_name();
        cout << "| " << left << setw(20) << cls_util::remove_zero_fragments(to_string(C.get_account_balance()));
        cout << endl;
        cout << "________________________________________________________________________________________\n";
    }
    
    static void _total_balance_footer()
    {
        cout << "\n\t\t\t\t\t    Total Balances = " << cls_util::remove_zero_fragments(to_string(cls_bank_client::get_total_balances())) << endl;
        cout << "\n\t\t\t\t\t    ("<< cls_util::convert_numbers(abs(cls_bank_client::get_total_balances())) <<")" << endl;
    
    }

public:
    
    static void total_balances()
    {
        vector <cls_bank_client> Clients = cls_bank_client::get_clients();
        _total_balances_header(Clients);
        for (cls_bank_client& C : Clients)
        {
            _total_balances_body(C);
        }
        _total_balance_footer(); 
    }
};

