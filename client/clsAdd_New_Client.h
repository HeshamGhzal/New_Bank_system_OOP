#pragma once
#include<iostream>
#include<string>
#include "../clsScreen.h"
#include"clsBank_Client.h"
using namespace std;
class clsAdd_new_client :protected clsscreen
{
private:
	static void _Read_client_info(clsbank_client& client)
	{
		cout << setw(37) << left << "" << "Enter First Name : ";
		client.set_First_Name(clsinput::Read_String()) ;
		cout << setw(37) << left << "" << "Enter Last Name : ";
		client.set_Last_Name(clsinput::Read_String()) ;
		cout << setw(37) << left << "" << "Enter Email : ";
		client.set_Email(clsinput::Read_String());
		cout << setw(37) << left << "" << "Enter Phone : ";
		client.set_Phone( clsinput::Read_String());
		cout << setw(37) << left << "" << "Enter pin code : ";
		client.set_pin_code(clsinput::Read_String()) ;
		cout << setw(37) << left << "" << "Enter Account Balance : ";
		client.set_Account_Balance(clsinput::read_Number<float>()) ;
	}
	static void _print_client(clsbank_client client)
	{
		cout << setw(10) << left << "" << "\n\tClient Details: \n" << endl;

		cout << setw(37) << left << "" << string(40, '=') << endl;
		cout << setw(37) << left << "" << "\tFirst Name     : " << client.get_First_Name() << endl;
		cout << setw(37) << left << "" << "\tLast Name      : " << client.get_Last_Name() << endl;
		cout << setw(37) << left << "" << "\tFull Name      : " << client.getFullName()<< endl;
		cout << setw(37) << left << "" << "\tPhone          : " << client.get_Phone()<< endl;
		cout << setw(37) << left << "" << "\tEmail          : " << client.get_Email() << endl;
		cout << setw(37) << left << "" << "\tAccount Number : " << client.get_account_number() << endl;
		cout << setw(37) << left << "" << "\tPin Code       : " << client.get_pin_code() << endl;
		cout << setw(37) << left << "" << "\tAccount Balance: " << client.get_Account_Balance() << endl;
		cout << setw(37) << left << "" << string(40, '=') << endl;
	}
public:
	static void Add_new_client_screen()
	{
		if (check_permission_right(current_user.pAddNewClient))
		{
			return;
		}
		_Drow_screen_hider("Add New Client Screen");
		cout << setw(37) << left << "" << "Please Enter Account Number : ";
		string account_number = clsinput::Read_String();
		while (clsbank_client::Is_client_exist(account_number))
		{
			cout << setw(20) << left << "" <<
				"Account Number is already exist, please enter another Account Number : ";
			account_number = clsinput::Read_String();
		}
		clsbank_client client = clsbank_client::Get_Add_new_clien_object(account_number);
		_Read_client_info(client);
		clsbank_client::ensave_result save_result = client.save();
		switch (save_result)
		{
		case clsbank_client::sv_success:
		{
			cout << setw(37) << left << "" << "New Client added successfully " << endl;
			_print_client(client);
			break;
		}
		case clsbank_client::sv_fail_empty_object:
		{
			cout << setw(37) << left << "" << "Error : Client object is empty , can not save it " << endl;
			break;
		}
		case clsbank_client::sv_fail_account_number_exist:
		{
			cout << setw(37) << left << "" << "Error : Account Number is already exist , can not add it " << endl;
			break;
		}

		}
	}
};