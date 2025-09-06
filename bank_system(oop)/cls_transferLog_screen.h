#pragma once
#include "cls_screen.h"
#include "cls_bank_client.h"

class cls_transferLog_screen : protected cls_screen
{

private : 

    static void PrintTransferLogRecordLine(cls_bank_client::s_transfer TransferLogRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.date;
        cout << "| " << setw(8) << left << TransferLogRecord.from_account;
        cout << "| " << setw(8) << left << TransferLogRecord.to_account;
        cout << "| " << setw(8) << left << cls_util::remove_zero_fragments(to_string(TransferLogRecord.amount_transfer));
        cout << "| " << setw(10) << left << cls_util::remove_zero_fragments(to_string(TransferLogRecord.user1_balance));
        cout << "| " << setw(10) << left << cls_util::remove_zero_fragments(to_string(TransferLogRecord.user2_balance));
        cout << "| " << setw(8) << left << TransferLogRecord.username;

    }

public :

	static void transfer_log_screen()
	{
		 ;
        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t    (" + to_string(cls_bank_client::read_transfer_file().size()) + ") Record(s).";

        header_screen(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        vector <cls_bank_client::s_transfer> records =  cls_bank_client::read_transfer_file();
        if (cls_bank_client::read_transfer_file().size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (cls_bank_client::s_transfer & Record : records)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
	}

};

