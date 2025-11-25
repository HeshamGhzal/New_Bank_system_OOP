#pragma once
#include <iostream>
#include <string>
// #include "clsScreen.h"
#include"clsBank_Client.h"
#include <iomanip>
#include "../GENRAL/clsUtil.h"
#include "../GENRAL/clsinput.h"

using namespace std;

class clsUpdate_client_info : protected clsscreen
{
private:
	static void _print_client(clsbank_client client)
	{
		cout << setw(10) << left << "" << "\n\tClient Details: \n"
			 << endl;
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
	static void _Read_client_info(clsbank_client &client)
	{
		cout << setw(37) << left << "" << "Enter First Name [" << client.get_First_Name() << "] : ";
		string first_name = clsinput::Read_String();
		if (first_name != "")
			client.set_First_Name(first_name);
		cout << setw(37) << left << "" << "Enter Last Name [" << client.get_Last_Name() << "] : ";
		string last_name = clsinput::Read_String();
		if (last_name != "")
			client.set_Last_Name(last_name);
		cout << setw(37) << left << "" << "Enter Email [" << client.get_Email() << "] : ";
		string email = clsinput::Read_String();
		if (email != "")
			client.set_Email(email);
		cout << setw(37) << left << "" << "Enter Phone [" << client.get_Phone() << "] : ";
		string phone = clsinput::Read_String();
		if (phone != "")
			client.set_Phone(phone);
		cout << setw(37) << left << "" << "Enter pin code [" << client.get_pin_code() << "] : ";
		string pin_code = clsinput::Read_String();
		if (pin_code != "")
			client.set_pin_code(pin_code);
		cout << setw(37) << left << "" << "Enter Account Balance [" << client.get_Account_Balance() << "] : ";
		string balance_str = clsinput::Read_String();
		if (balance_str != "")
			client.set_Account_Balance(stof(balance_str));
	}

public:
	static void Show_update_client_screen()
	{
		if (check_permission_right(current_user.pUpdateClients))
		{
			return;
		}
		clsscreen::_Drow_screen_hider("Update Client Info Screen");

		string account_number = clsinput::Read_String("\tpleas Enter AccountNumber : ");
		while (!clsbank_client::Is_client_exist(account_number))
		{
			cout << "\tInvalid Account Number , pleas try again : ";
			account_number = clsinput::Read_String();
		}

		clsbank_client client1 = clsbank_client::find_client(account_number);
		_print_client(client1);
		cout << "\n\tAre you going to update this client info ? [y]OR[n] : ";
		char answer = 'n';
		cin >> answer;
		if (tolower(answer) != 'y')
			return;

		cout << "\n\tUpdate Client Info : " << endl;
		cout << setw(37) << left << "" << string(40, '=') << endl;
		_Read_client_info(client1);
		clsbank_client::ensave_result save_result;
		save_result = client1.save();
		switch (save_result)
		{
		case clsbank_client::sv_fail_empty_object:
		{
			cout << "Error : Client object is empty , can not save it " << endl;
			break;
		}
		case clsbank_client::sv_success:
		{
			cout << "Client info updated successfully :-) " << endl;
			break;
		}
		}
	}
};