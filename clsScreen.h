#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsBank_user.h"
#include"GENRAL/Global.h"
#include"GENRAL/clsDate.h"

using namespace std;
class clsscreen
{
protected:

	static void _Drow_screen_hider(string tite, string SubTitle = "")
	{
		cout << endl;
		cout << string(33, ' ') << string(45, '=') << endl;
		cout << string(45, ' ') << tite << endl;
		if (SubTitle != "")
		{
			cout << setw(37) << "\t" << SubTitle << endl;
		}
		cout << string(33, ' ') << string(45, '=') << endl;

		cout << "\tDate : " << clsdate::GetCurrentDateTime() << endl;
		cout << "\tUSER : " << current_user.get_user_name() << endl;
		cout << "\tName : " << current_user.getFullName()<< endl;
		//cout << "Date : " << clsdate::DateToString(clsdate()) << endl;
	}

public:
	static bool check_permission_right(clsbank_user::enPermissions permission)
	{
		if (!current_user.check_acceess_permition(permission))
		{
			cout << setw(30) << "" << string(43, '-') << endl;
			cout << setw(35) << "" << "Access Denied! contact your Admin" << endl;
			cout << setw(30) << "" << string(43, '-') << endl;
			return false;
		}
		else
		{
			return false;
		}
	}

};