#pragma once
#include <iostream>
#include <string>
#include <vector>
#include"../clsScreen.h"
#include"../USER/clsBank_user.h"
class clsShow_Register_list :protected clsscreen
{
private:
	static void _Print_Register_list(clsbank_user::sRegester_data user, short user_counter)
	{

		cout << setw(20) << "" << "|";
		//cout << setw(4) << client_counter;
		printf("%03d ", user_counter);


		cout << "|" << left << setw(25) << user.Date << "|"
			<< left << setw(10) << user.user_name << "|"
			<< left << setw(10) << user.password << "|"
			<< left << setw(10) << user.permission << "|"
			<< endl;
	}
public:
	static void show_Register_list()
	{
		if (check_permission_right(current_user.pRegister_list))
		{
			return;
		}
		vector<clsbank_user::sRegester_data>vuser = clsbank_user::get_Register_login_from_file();
		string title = "Login Register list Screen\n";
		string sub_title = to_string(vuser.size()) + " Logins In the System";
		clsscreen::_Drow_screen_header(title, sub_title);

		cout << setw(20) << "" << string(65, '=') << endl;
		cout << setw(20) << "" << "|" << setw(4) << "NO " << "|"

			<< left << setw(25) << "     Date & Time" << "|"
			<< left << setw(10) << "user_name" << "|"
			<< left << setw(10) << "password" << "|"
			<< left << setw(10) << "permission" << "|"
			<< endl;
		cout << setw(20) << "" << string(65, '=') << endl;
		if (vuser.size() == 0)
		{
			cout << setw(30) << "" << "\t No Register Available In the System \n" << endl;
			return;
		}
		else
		{
			short counter = 1;
			for (clsbank_user::sRegester_data u : vuser)
			{
				_Print_Register_list(u, counter++);
			}
		}
		cout << setw(20) << "" << string(65, '-') << endl;
	}

};