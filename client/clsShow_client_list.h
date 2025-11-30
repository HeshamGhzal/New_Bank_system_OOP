#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"clsBank_Client.h"
#include"../clsScreen.h"

using namespace std;

class clsShow_client_list :protected clsscreen
{
private:
	static void _Print_client_record(clsbank_client client, short client_counter)
	{

		cout << setw(12) << "" << "|";
		//cout << setw(4) << client_counter;
		printf("%03d ", client_counter);

		cout << "|" << left << setw(10) << client.get_account_number() << "|"
			<< left << setw(12) << client.get_First_Name() << "|"
			<< left << setw(12) << client.get_Last_Name() << "|"
			<< left << setw(20) << client.get_Email() << "|"
			<< left << setw(10) << client.get_Phone() << "|"
			<< left << setw(10) << client.get_pin_code() << "|"
			<< left << setw(12) << client.get_Account_Balance() << "|" << endl;
	}
public:
	static void show_clients_list()
	{
		if (check_permission_right(current_user.pListClients))
		{
			return;
		}
		vector<clsbank_client>vclient = clsbank_client::get_clients_list();
		string title = "Client List Screen";
		string sub_title = to_string(vclient.size()) + " Clients Available In the System";
		clsscreen::_Drow_screen_header(title, sub_title);

		cout << setw(12) << "" << string(99, '=') << endl;
		cout << setw(12) << "" << "|" << setw(4) << "NO " << "|"
			<< left << setw(10) << "Account NO" << "|"
			<< left << setw(12) << "First Name" << "|"
			<< left << setw(12) << "Last Name" << "|"
			<< left << setw(20) << "Email" << "|"
			<< left << setw(10) << "Phone" << "|"
			<< left << setw(10) << "Pin Code" << "|"
			<< left << setw(12) << "Balance" << "|" << endl;
		cout << setw(12) << "" << string(99, '=') << endl;
		if (vclient.size() == 0)
		{
			cout << setw(37) << "" << "\tNo Clients Available In the System \n" << endl;
			return;
		}
		else
		{
			short client_counter = 1;
			for (clsbank_client client : vclient)
			{
				_Print_client_record(client, client_counter++);
			}
		}
		cout << setw(12) << "" << string(99, '-') << endl;
	}
};