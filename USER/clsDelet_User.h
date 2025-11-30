#pragma once
#include<iostream>
#include"../clsScreen.h"
#include"clsBank_user.h"
#include"../GENRAL/clsinput.h"


class clsDelet_user :protected clsscreen
{
private:
	static void _Print_user_record(clsbank_user user, short user_counter = 0)
	{
		cout << "\n";
		cout << setw(27) << "" << string(30, '-') << endl;
		cout << left << setw(30) << "" << "User Name   : " << user.get_user_name() << endl;
		cout << left << setw(30) << "" << "Full Name   : " << user.getFullName() << endl;
		cout << left << setw(30) << "" << "Phone       : " << user.get_Phone()<< endl;
		cout << left << setw(30) << "" << "Email       : " << user.get_Email()<< endl;
		cout << left << setw(30) << "" << "Password    : " << user.get_Password() << endl;
		cout << left << setw(30) << "" << "Permissions : " << user.GetPermissions() << endl;
		cout << setw(27) << "" << string(30, '-') << endl;
	}
public:
	static void show_delete_user_screen()
	{
		clsscreen::_Drow_screen_header("Delete User Screen");
		cout << "Please Enter User name : ";
		string  User_name = clsinput::Read_String();
		while (!clsbank_user::Is_user_exist(User_name))
		{
			cout << "Invalid  User name ,please Enter again : ";
			User_name = clsinput::Read_String();
		}
		clsbank_user user1 = clsbank_user::find_user(User_name);
		_Print_user_record(user1);
		char answer = 'n';
		cout << "\nAre you sure to delete this user [y]OR[n] : ";
		cin >> answer;
		if (tolower(answer) == 'y')
		{
			if (user1.delete_user())
			{
				cout << setw(37) << left << "" "\nUser deleted successfully .\n";
				_Print_user_record(user1);
			}
			else
			{
				cout << "Error User was not found .";
			}
		}
	}

};