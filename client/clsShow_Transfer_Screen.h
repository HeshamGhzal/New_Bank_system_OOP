#pragma once
#include"../GENRAL/clsUtil.h"
#include"../clsScreen.h"
#include"clsBank_Client.h"
class clsShow_Transfer_Screen :clsscreen
{
private:
	static void _print_client(clsbank_client client)
	{
		cout << setw(10) << left << "" << "\n\tClient Details: \n" << endl;
		cout << setw(37) << left << "" << string(40, '=') << endl;
		cout << setw(37) << left << "" << "\tFull Name      : " << client.getFullName() << endl;
		cout << setw(37) << left << "" << "\tAccount Number : " << client.get_account_number() << endl;
		cout << setw(37) << left << "" << "\tAccount Balance: " << client.get_Account_Balance() << endl;
		cout << setw(37) << left << "" << string(40, '=') << endl;
	}
	static string _Read_Account_number()
	{
		string account_number = clsinput::Read_String();
		while (!clsbank_client::Is_client_exist(account_number))
		{
			cout << "\nAccount number is not found, choose another one: ";
			account_number = clsinput::Read_String();
		}
		return account_number;
	}
	static float _Read_amount(clsbank_client sourc_client)
	{
		double amount = 0;
		cout << "Enter Transfer amount : ";
		amount = clsinput::read_Number<double>();
		while (amount > sourc_client.get_Account_Balance())
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			amount = clsinput::read_Number<double>();
		}
		return amount;
	}
public:

	static void Show_Transfer_Screen()
	{

		_Drow_screen_hider("Transfer Screen");
		cout << "\nPleas Enter Account_NO you wont to transfer from : ";
		clsbank_client sourc_client = clsbank_client::find_client(_Read_Account_number());
		_print_client(sourc_client);
		cout << "\nPleas Enter Account_NO you wont to transfer to : ";
		clsbank_client Destnation_client = clsbank_client::find_client(_Read_Account_number());
		_print_client(Destnation_client);

		double amount = _Read_amount(sourc_client);
		cout << "Are you sure you wont to perform this operation? [Y] OR [N]";
		char answer = 'n';
		cin >> answer;
		if (tolower(answer) != 'y')
		{
			cout << "Transfer canceled";
			return;
		}
		if (sourc_client.Transfer(amount, Destnation_client))
		{
			cout << "\nTransfer done successfully\n";
		}
		else
		{
			cout << "\nTransfer Failed \n";
		}

		_print_client(sourc_client);
		_print_client(Destnation_client);
	}
};