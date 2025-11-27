#pragma once
#include<iostream>
#include"clsScreen.h"
#include"USER/clsBank_user.h"
#include"clsMain_menu.h"
#include"GENRAL/Global.h"

class clsLogin_screen :protected clsscreen
{
private:
	static bool _login()
	{
		bool login_faild = false;
		string user_name, password;
		short trial = 3;

		do
		{
			if (login_faild)
			{
				cout << "\n \tInvalid username/password.\n\n";
				cout << "\tYou have [" << trial << "] Trial(s) to login.\n" << endl;
			}
			if (trial == 0)
			{
				cout << "\n\t" << string(73, '#') << endl;
				cout << "\n\t\t!You are reached Maximum Trials to Login - you are locked!.\n";
				cout << "\n\t" << string(73, '#') << endl;
				return false;
			}
			cout << "\tPleas Enter your User Name : ";
			cin >> user_name;
			cout << "\tPlease Enter your Password : ";
			cin >> password;

			current_user = clsbank_user::find_user(user_name, password);
			login_faild = current_user.is_empty();
			trial--;
		} while (login_faild);
		current_user.save_Regester_login_to_file();
		clsMain_menu::ShowMinMenuOptions();
		return true;
	}


public:
	static bool Show_Login_Screen()
	{
		clsutil::cls();
		clsscreen::_Drow_screen_hider("Show Login screen");
		return _login();
	}

};