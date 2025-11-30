#pragma once
#include<iostream>
#include<string>
#include "../clsScreen.h"
#include"clsBank_Client.h"
#include<iomanip>

using namespace std;

class clsfind_client :protected clsscreen
{
private:
	static void _print_client(clsbank_client client)
	{
		cout << setw(10) << left << "" << "\n\tClient Details: \n" << endl;
		cout << setw(37) << left << "" << string(40, '=') << endl;
		cout << setw(37) << left << "" << "\tFirst Name     : " << client.get_First_Name()<< endl;
		cout << setw(37) << left << "" << "\tLast Name      : " << client.get_Last_Name() << endl;
		cout << setw(37) << left << "" << "\tFull Name      : " << client.getFullName()<< endl;
		cout << setw(37) << left << "" << "\tPhone          : " << client.get_Phone()<< endl;
		cout << setw(37) << left << "" << "\tEmail          : " << client.get_Email()<< endl;
		cout << setw(37) << left << "" << "\tAccount Number : " << client.get_Email()<< endl;
		cout << setw(37) << left << "" << "\tPin Code       : " << client.get_pin_code()<< endl;
		cout << setw(37) << left << "" << "\tAccount Balance: " << client.get_Account_Balance() << endl;
		cout << setw(37) << left << "" << string(40, '=') << endl;
	}
public:
	static void Show_find_client_screen()
	{
		if (check_permission_right(current_user.pFindClient))
		{
			return;
		}
		clsscreen::_Drow_screen_header("Find Client Screen");
		cout << "Please Enter Account Number : ";
		string Account_number = clsinput::Read_String();
		while (!clsbank_client::Is_client_exist(Account_number))
		{
			cout << "Invalid account number ,please Enter again : ";
			Account_number = clsinput::Read_String();
		}
		clsbank_client client1 = clsbank_client::find_client(Account_number);
		if (!client1.is_empty())
		{
			cout << "\n" << setw(37) << left << "" << "\tClient found successfully " << endl;
		}
		else
		{
			cout << "Error Client was not found .";
		}
		_print_client(client1);
	}
};