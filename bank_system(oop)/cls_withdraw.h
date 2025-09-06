#pragma once
#include "cls_screen.h"
#include <iostream>
#include "cls_bank_client.h"
#include "cls_input_validate.h"

using namespace std; 


class cls_withdraw : protected cls_screen
{
private:

    static void _print_client(cls_bank_client c)
    {
        cout << "\nClient Card:";
        cout << "\n__________________________________________";
        cout << "\nFirstName   : " << c.get_first_name();
        cout << "\nLastName    : " << c.get_last_name();
        cout << "\nFull Name   : " << c.full_name();
        cout << "\nEmail       : " << c.get_email();
        cout << "\nPhone       : " << c.get_phone();
        cout << "\nAcc. Number : " << c.get_account_number();
        cout << "\nPassword    : " << c.get_pin_code();
        cout << "\nBalance     : " << cls_util::remove_zero_fragments(to_string(c.get_account_balance()));
        cout << "\n_________________________________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }

public:

    static void withdraw_operation()
    {
        display_message("WITHDRAW SCREEN");
        string AccountNumber = _ReadAccountNumber();


        while (!cls_bank_client::is_client_exist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        cls_bank_client Client1 = cls_bank_client::Find(AccountNumber);
        _print_client(Client1);

        double Amount = 0;
        cout << "\nPlease enter withdraw amount? ";
        Amount = cls_input_validate::read_double_number_input("");

        cout << "\nAre you sure you want to perform this transaction? y/n : ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client1.Withdraw(Amount))
            {
                cout << "\nAmount withdrawed Successfully.\n";
                cout << "\nNew Balance Is: " << cls_util::remove_zero_fragments(to_string(Client1.get_account_balance()));
            }
            else {
                cout << "\n can not withdraw, insuffecient balance ! .\n";
                cout << "Amount to withdraw is :  " << Amount << endl;
                cout << "your balance is :  " << to_string(Client1.get_account_balance()) << endl;
            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
    }

};

