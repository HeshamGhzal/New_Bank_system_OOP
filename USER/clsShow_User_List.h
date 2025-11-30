#pragma once
#include<iostream>
#include<iomanip>
#include"clsBank_user.h"
#include"../clsScreen.h"
#include"../GENRAL/clsUtil.h"

using namespace std;
class clsShow_user_list :protected clsscreen
{
private:
	static void _Print_user_record(clsbank_user user, short user_counter)
	{

		cout << setw(12) << "" << "|";
		//cout << setw(4) << client_counter;
		printf("%03d ", user_counter);


		cout << "|" << left << setw(12) << user.get_user_name() << "|"
			<< left << setw(23) << user.getFullName() << "|"
			<< left << setw(10) << user.get_Phone() << "|"
			<< left << setw(20) << user.get_Email() << "|"
			<< left << setw(10) << user.get_Password() << "|"
			<< left << setw(12) << user.GetPermissions() << "|" << endl;
	}
public:
	static void show_users_list()
	{
		vector<clsbank_user>vuser = clsbank_user::get_users_list();
		string title = "User List Screen";
		string sub_title = to_string(vuser.size()) + " Users Available In the System";
		clsscreen::_Drow_screen_header(title, sub_title);

		cout << setw(12) << "" << string(99, '=') << endl;
		cout << setw(12) << "" << "|" << setw(4) << "NO " << "|"

			<< left << setw(12) << "User name" << "|"
			<< left << setw(23) << "Full Name" << "|"
			<< left << setw(10) << "Phone" << "|"
			<< left << setw(20) << "Email" << "|"
			<< left << setw(10) << "Password" << "|"
			<< left << setw(12) << "Permissions" << "|" << endl;
		cout << setw(12) << "" << string(99, '=') << endl;
		if (vuser.size() == 0)
		{
			cout << setw(37) << "" << "\tNo Users Available In the System \n" << endl;
			return;
		}
		else
		{
			short counter = 1;
			for (clsbank_user u : vuser)
			{
				_Print_user_record(u, counter++);
			}
		}
		cout << setw(12) << "" << string(99, '-') << endl;
	}

};