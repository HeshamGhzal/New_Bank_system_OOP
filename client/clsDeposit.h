#pragma once
#include<iostream>
#include<string>
#include "../clsScreen.h"
#include"../GENRAL/clsUtil.h"
#include"../client/clsBank_Client.h"

using namespace std;

class clsDeposit :protected clsscreen
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
	static string _Read_Account_number()
	{
		cout << setw(30) << left << "" << "\tPlease enter account number : ";
		string account_number = clsinput::Read_String();
		return account_number;
	}
public:
	static void Show_Deposit_screen()
	{
		clsutil::cls();
		_Drow_screen_header("Deposit Screen");
		string account_number = _Read_Account_number();
		while (!clsbank_client::Is_client_exist(account_number))
		{
			cout << setw(30) << left << "" << "\tAccount number is not found, please try again." << endl;
			account_number = _Read_Account_number();
		}
		clsbank_client client = clsbank_client::find_client(account_number);
		_print_client(client);
		cout << setw(30) << left << "" << "\tEnter amount to deposit : ";
		float amount = clsinput::read_Number<float>();
		cout << setw(30) << left << "" << "\tAre you sure you want to deposit "
			<< amount << " to account " << account_number << " ? [Y/N] : ";
		char confirm = 'N';
		cin >> confirm;
		if (tolower(confirm) != 'y')
		{
			cout << setw(30) << left << "" << "\tDeposit cancelled." << endl;
			return;
		}
		client.Deposit(amount);
		cout << setw(30) << left << "" << "\tAmount " << amount << " deposited successfully to account "
			<< account_number << "." << endl;
		cout << setw(30) << left << "" << "\tNew Balance is : " << client.get_Account_Balance() << endl;

	}
};