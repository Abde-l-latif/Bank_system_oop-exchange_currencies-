#pragma once
#include "cls_screen.h"
#include <iomanip>
#include <iostream>
#include "cls_input_validate.h"
#include "cls_deposit.h"
#include "cls_withdraw.h"
#include "cls_total_balance.h"
#include "cls_transfer_screen.h"
#include "cls_transferLog_screen.h"

using namespace std; 


class cls_transaction_menu : protected cls_screen
{

private : 

    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eTransfer = 4, eTransferLog = 5, eShowMainMenue = 6
    };

    static enTransactionsMenueOptions ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "";
        short Choice = cls_input_validate::read_int_number_between(1, 6, "Choose what do you want to do? [1 to 6]? : ");
        return (enTransactionsMenueOptions)Choice;
    }

    static void _ShowDepositScreen()
    {
        cls_deposit::deposit_operation();
        custom_pause("\npress enter to go back to the transaction menu");
    }

    static void _ShowWithdrawScreen()
    {
        cls_withdraw::withdraw_operation();
        custom_pause("\npress enter to go back to the transaction menu");
    }

    static void _ShowTotalBalancesScreen()
    {
        cls_total_balance::total_balances(); 
        custom_pause("press enter to go back to the transaction menu");
    }

    static void _ShowTransferScreen()
    {
        cls_transfer_screen::transfer_screen();
        custom_pause("\npress enter to go back to the transaction menu");
    }

    static void _ShowTransferLogScreen()
    {
        cls_transferLog_screen::transfer_log_screen();
        custom_pause("\npress enter to go back to the transaction menu");
    }

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            break;
        }

        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            break;
        }
        case enTransactionsMenueOptions::eTransfer:
        {
            system("cls");
            _ShowTransferScreen();
            break;
        }
        case enTransactionsMenueOptions::eTransferLog:
        {
            system("cls");
            _ShowTransferLogScreen();
            break;
        }
        }
    }

public : 

    static void ShowTransactionsMenue()
    {
        if (!has_rights(check_if_it_has_permission(cls_user::s_per::transaction_permission)))
        {
            return;
        }
        enTransactionsMenueOptions choice;

        do {

            system("cls");
            header_screen("\t\t  TRANSACTION SCREEN");
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Deposit.\n";
            cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
            cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
            cout << setw(37) << left << "" << "\t[4] Transfer.\n";
            cout << setw(37) << left << "" << "\t[5] Transfer log.\n";
            cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
            cout << setw(37) << left << "" << "===========================================\n";
            choice = ReadTransactionsMenueOption();
            _PerformTransactionsMenueOption(choice);

        } while (choice != enTransactionsMenueOptions::eShowMainMenue); 

    }

};

