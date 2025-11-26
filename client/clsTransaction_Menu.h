#pragma once
#include "../clsScreen.h"
#include "../GENRAL/clsinput.h"
#include "clsDeposit.h"
// #include"clsWithdraw.h"
// #include"clsTotal_balance.h"
// #include"clsShow_Transfer_Screen.h"
// #include"clsShow_Transfer_logs.h"

// using namespace std;

class clsTransaction_Menu : protected clsscreen
{
private:
	enum _enmenu_option
	{
		eDeposit = 1,
		eWithdraw = 2,
		eShow_total_balance = 3,
		eTransfer = 4,
		eTransfer_logs = 5,
		eBack_to_Main_Menu = 6
	};
	static short _Read_transaction_menu_option()
	{
		cout << setw(30) << left << "" << "\tPlease choose what do you want to do ?[ 1 to 6 ] ";
		short choise = clsinput::read_number_between<short>(1, 6,
															"\nInvalid choice, Please enter a number between [1 to 6] : ");
		return choise;
	}
	static void _Go_back_to_transaction_menu()
	{
		cout << setw(37) << left << "" << "\tPress any key to go back to Transaction menu...";
		clsutil::pause();
		show_Transaction_menu_option();
	}
	static void _Deposit_screen()
	{
		clsDeposit::Show_Deposit_screen();
	}
	static void _Withdraw_screen()
	{
		// clsWithdraw::Show_Withdraw_screen();
	}
	static void _Show_Total_balance_screen()
	{
		// clsTotal_balance::Show_total_clients_balance();
	}
	static void _Show_Transfer_screen()
	{
		// clsShow_Transfer_Screen::Show_Transfer_Screen();
	}
	static void _Show_Transfer_logs_screen()
	{
		// clsShow_Transfer_logs::Show_Transfer_logs_screen();
	}
	static void _Perform_transaction_menu_option(_enmenu_option menu_option)
	{
		switch (menu_option)
		{
		case eDeposit:
		{
			clsutil::cls();
			_Deposit_screen();
			_Go_back_to_transaction_menu();
			break;
		}
		case eWithdraw:
		{
			clsutil::cls();
			_Withdraw_screen();
			_Go_back_to_transaction_menu();
			break;
		}
		case eShow_total_balance:
		{
			clsutil::cls();
			_Show_Total_balance_screen();
			_Go_back_to_transaction_menu();
			break;
		}
		case eTransfer:
		{
			clsutil::cls();
			_Show_Transfer_screen();
			_Go_back_to_transaction_menu();
			break;
		}
		case eTransfer_logs:
		{
			clsutil::cls();
			_Show_Transfer_logs_screen();
			_Go_back_to_transaction_menu();
			break;
		}
		case eBack_to_Main_Menu:
		{
		}
		}
	}

public:
	static void show_Transaction_menu_option()
	{

		if (check_permission_right(current_user.pTranactions))
		{
			return;
		}
		clsutil::cls();
		_Drow_screen_hider("Transaction Menu Screen");
		cout << "\n"
			 << endl;
		cout << setw(36) << left << "" << string(45, '*') << endl;
		cout << setw(50) << left << "" << "Transaction Menu Options" << endl;
		cout << setw(36) << left << "" << string(45, '*') << endl;
		cout << setw(37) << left << "" << "\t[1]-Deposit" << endl;
		cout << setw(37) << left << "" << "\t[2]-Withdraw" << endl;
		cout << setw(37) << left << "" << "\t[3]-Show Total Balance" << endl;
		cout << setw(37) << left << "" << "\t[4]-Transfer" << endl;
		cout << setw(37) << left << "" << "\t[5]-Transfer logs" << endl;
		cout << setw(37) << left << "" << "\t[6]-Back to Main Menu" << endl;
		cout << setw(36) << left << "" << string(45, '*') << endl;
		cout << endl;
		_Perform_transaction_menu_option((_enmenu_option)_Read_transaction_menu_option());
	}
};