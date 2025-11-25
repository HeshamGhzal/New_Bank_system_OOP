#pragma once
#include<iostream>
#include<string>
// #include "clsScreen.h"
#include"clsBank_Client.h"
#include"../GENRAL/clsinput.h"

using namespace std;

class clsDelete_clint :protected clsscreen
{
private:
	static void _print_client(clsbank_client client)
	{
		cout << setw(10) << left << "" << "\n\tClient Details: \n" << endl;

		cout << setw(37) << left << "" << string(40, '=') << endl;
		cout << setw(37) << left << "" << "\tFirst Name     : " << client.get_First_Name() << endl;
		cout << setw(37) << left << "" << "\tLast Name      : " << client.get_Last_Name() << endl;
		cout << setw(37) << left << "" << "\tFull Name      : " << client.getFullName() << endl;
		cout << setw(37) << left << "" << "\tPhone          : " << client.get_Phone() << endl;
		cout << setw(37) << left << "" << "\tEmail          : " << client.get_Email() << endl;
		cout << setw(37) << left << "" << "\tAccount Number : " << client.get_account_number() << endl;
		cout << setw(37) << left << "" << "\tPin Code       : " << client.get_pin_code() << endl;
		cout << setw(37) << left << "" << "\tAccount Balance: " << client.get_Account_Balance() << endl;
		cout << setw(37) << left << "" << string(40, '=') << endl;
	}
public:
	static void show_delete_client()
	{
		if (check_permission_right(current_user.pDeleteClient))
		{
			return;
		}
		clsscreen::_Drow_screen_hider("Delete Client Screen");
		cout << "Please Enter Account Number : ";
		string Account_number = clsinput::Read_String();
		while (!clsbank_client::Is_client_exist(Account_number))
		{
			cout << "Invalid account number ,please Enter again : ";
			Account_number = clsinput::Read_String();
		}
		clsbank_client client1 = clsbank_client::find_client(Account_number);
		_print_client(client1);
		char answer = 'n';
		cout << "\nAre you sure to delete this client [y]OR[n] : ";
		cin >> answer;
		if (tolower(answer) == 'y')
		{
			if (client1.delete_client())
			{
				cout << setw(37) << left << "" "\nClient deleted successfully .\n";
				_print_client(client1);
			}
			else
			{
				cout << "Error Client was not found .";
			}
		}
	}
};