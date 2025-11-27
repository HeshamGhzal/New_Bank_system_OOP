#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "GENRAL/clsinput.h"
#include "client/clsShow_client_list.h"
#include "client/clsAdd_New_Client.h"
#include "client/clsDelete_Client.h"
#include "client/clsUpdate_Client_Info.h"
#include "client/clsFind_Client.h"
#include"client/clsTransaction_Menu.h"
// #include"clsManage_user.h"
#include "GENRAL/Global.h"
// #include"clsShow_Register_list.h"
#include"Currency/clsShow_Currency_Screen.h"

using namespace std;

class clsMain_menu : protected clsscreen
{
private:
	enum _enmenu_option
	{
		eShow_Client_list = 1,
		eAdd_New_Client = 2,
		eDelete_Client = 3,
		eUpdate_Client_Info = 4,
		eFind_Client = 5,
		eTransaction_Menu = 6,
		eMenu_Manage_Users = 7,
		eRegister = 8,
		eCurrency_Menu = 9,
		eLog_out = 10
	};
	static short _Read_main_menu_option()
	{
		cout << setw(30) << left << "" << "\tPlease choose what do you want to do ?[ 1 to 10 ] ";
		short choise = clsinput::read_number_between<short>(1, 10,
															"\nInvalid choice, Please enter a number between [1 to 10] : ");
		return choise;
	}
	static void _Go_back_to_main_menu()
	{
		cout << setw(37) << left << "" << "\tPress [Enter] key to go back to Main menu...";
		clsutil::pause();
		ShowMinMenuOptions();
	}
	static void _Show_client_list_screen()
	{
		clsShow_client_list::show_clients_list();
	}
	static void _Add_new_client_screen()
	{
		clsAdd_new_client::Add_new_client_screen();
	}
	static void _Delete_client_screen()
	{
		clsDelete_clint::show_delete_client();
	}
	static void _Update_client_info_screen()
	{
		clsUpdate_client_info::Show_update_client_screen();
	}
	static void _Find_client_screen()
	{
		clsfind_client::Show_find_client_screen();
	}
	static void _Transaction_menu_screen()
	{
		clsTransaction_Menu::show_Transaction_menu_option();
	}
	static void _Manage_users_screen()
	{
		// clsManage_user::Show_Manage_user_menu();
	}
	static void _Register_screen()
	{
		// clsShow_Register_list::show_Register_list();
	}
	static void _Currency_Exchange()
	{
		clsShow_currency_screen::Show_Currency_menu();
	}
	static void _Log_out_screen()
	{
		current_user = clsbank_user::find_user("", "");
	}

	static void _Perform_main_menu_option(_enmenu_option option)
	{
		switch (option)
		{
		case eShow_Client_list:
		{
			clsutil::cls();
			_Show_client_list_screen();
			_Go_back_to_main_menu();
			break;
		}
		case eAdd_New_Client:
		{
			clsutil::cls();
			_Add_new_client_screen();
			_Go_back_to_main_menu();
			break;
		}
		case eDelete_Client:
		{
			clsutil::cls();
			_Delete_client_screen();
			_Go_back_to_main_menu();
			break;
		}
		case eUpdate_Client_Info:
		{
			clsutil::cls();
			_Update_client_info_screen();
			_Go_back_to_main_menu();
			break;
		}
		case eFind_Client:
		{
			clsutil::cls();
			_Find_client_screen();
			_Go_back_to_main_menu();
			break;
		}
		case eTransaction_Menu:
		{
			clsutil::cls();
			_Transaction_menu_screen();
			_Go_back_to_main_menu();
			break;
		}
		case eMenu_Manage_Users:
		{
			clsutil::cls();
			_Manage_users_screen();
			_Go_back_to_main_menu();
			break;
		}
		case eRegister:
		{
			clsutil::cls();
			_Register_screen();
			_Go_back_to_main_menu();
			break;
		}
		case eCurrency_Menu:
		{
			clsutil::cls();
			_Currency_Exchange();
			_Go_back_to_main_menu();
			break;
		}
		case eLog_out:
		{
			clsutil::cls();
			_Log_out_screen();
			break;
		}
		}
	}

public:
	static void ShowMinMenuOptions()
	{
		clsutil::cls();
		_Drow_screen_hider("Main Screen");
		cout << endl;
		cout << string(33, ' ') << string(45, '*') << endl;
		cout << string(47, ' ') << left << setw(20) << "Main menu option" << endl;
		cout << string(33, ' ') << string(45, '*') << endl;

		cout << string(37, ' ') << "[1]- Show Client list" << endl;
		cout << string(37, ' ') << "[2]- Add New Client" << endl;
		cout << string(37, ' ') << "[3]- Delete Client" << endl;
		cout << string(37, ' ') << "[4]- Update Client Info" << endl;
		cout << string(37, ' ') << "[5]- Find Client" << endl;
		cout << string(37, ' ') << "[6]- Transaction Menu" << endl;
		cout << string(37, ' ') << "[7]- Manage Users" << endl;
		cout << string(37, ' ') << "[8]- Login Register" << endl;
		cout << string(37, ' ') << "[9]- Currency Exchange" << endl;
		cout << string(37, ' ') << "[10]-Log Out" << endl;
		cout << string(33, ' ') << string(45, '*') << endl;

		_Perform_main_menu_option((_enmenu_option)_Read_main_menu_option());
	}
};