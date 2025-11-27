#pragma once
#include<iomanip>
#include"clsBank_user.h"
#include"../GENRAL/clsinput.h"
#include"../clsScreen.h"

class clsFind_user :protected clsscreen
{
private:
	static void _Print_user_record(clsbank_user user, short user_counter = 0)
	{
		cout << "\n";
		cout << setw(27) << "" << string(30, '-') << endl;
		cout << left << setw(30) << "" << "User Name   : " << user.get_user_name() << endl;
		cout << left << setw(30) << "" << "Full Name   : " << user.getFullName() << endl;
		cout << left << setw(30) << "" << "Phone       : " << user.get_Phone() << endl;
		cout << left << setw(30) << "" << "Email       : " << user.get_Phone() << endl;
		cout << left << setw(30) << "" << "Password    : " << user.get_Password() << endl;
		cout << left << setw(30) << "" << "Permissions : " << user.GetPermissions() << endl;
		cout << setw(27) << "" << string(30, '-') << endl;
	}
public:
	static void Show_find_user_screen()
	{
		clsscreen::_Drow_screen_hider("Find User Screen");
		cout << "Please Enter User Name : ";
		string User_Name = clsinput::Read_String();
		while (!clsbank_user::Is_user_exist(User_Name))
		{
			cout << "Invalid User Name ,please Enter again : ";
			User_Name = clsinput::Read_String();
		}
		clsbank_user user1 = clsbank_user::find_user(User_Name);
		if (!user1.is_empty())
		{
			cout << "\n" << setw(37) << left << "" << "\tUser found successfully " << endl;
		}
		else
		{
			cout << "Error User was not found .";
		}
		_Print_user_record(user1);
	}

};