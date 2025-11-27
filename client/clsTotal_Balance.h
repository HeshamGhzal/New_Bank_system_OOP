#pragma once
//#include<iostream>
//#include<string>
//#include<vector>
//#include"clsutil.h"
#include"clsBank_Client.h"
#include"../clsScreen.h"
//#include<iomanip>

//using namespace std;

class clsTotal_balance : protected clsscreen
{
private:
	static void _Print_client_record_balance_line(clsbank_client client, short client_counter = 0)
	{
		cout << setw(23) << left << "" << "|";
		//cout << setw(4) << client_counter;
		printf("%03d ", client_counter);
		cout << "|" << "\t " << setw(15) << left << client.get_account_number()
			<< " | " << setw(25) << left << client.getFullName()
			<< " | " << setw(15) << left << client.get_Account_Balance() << " |" << endl;
	}
public:
	static void Show_total_clients_balance()
	{
		clsutil::cls();
		short counter = 1;
		vector<clsbank_client> vclient = clsbank_client::get_clients_list();
		string Titel = "Total Clients Balance Screen";
		string subTitel = "\t\t" + to_string(vclient.size()) + " Clients.";
		_Drow_screen_hider(Titel, subTitel);
		cout << setw(23) << left << "" << string(73, '=') << endl;
		cout << setw(23) << left << "" << "|" << setw(4) << "NO " << "|";
		cout << "\t " << setw(15) << left << "Account Number"
			<< " | " << setw(25) << left << "Full Name"
			<< " | " << setw(15) << left << "Balance" << " |" << endl;
		cout << setw(23) << left << "" << string(73, '=') << endl;
		if (vclient.size() == 0)
		{
			cout << setw(37) << left << "" << "\t " << setw(51) << left << "No Clients Available"
				<< " " << endl;
		}
		else
		{
			for (clsbank_client client : vclient)
			{
				_Print_client_record_balance_line(client, counter++);
			}
		}
		cout << setw(23) << left << "" << string(73, '=') << endl;
		double total_balance = clsbank_client::get_total_clients_balance();
		cout << setw(25) << left << "" << "\tTotal Balance for all clients is : " << total_balance << endl;
		cout << setw(26) << left << "" << clsutil::Number_to_txt(total_balance) << endl;

	}
};