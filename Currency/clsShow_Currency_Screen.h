#pragma once
#include"../clsScreen.h"
#include"../GENRAL/clsinput.h"
#include"clsCurrency_List_Screen.h"
#include"clsFind_Currency.h"
#include"clsUpdate_Currency.h"
#include"clsCurrency_Calculator.h"
class clsShow_currency_screen :protected clsscreen
{
private:
	enum _encurrency { eList_Currency = 1, eFind_Currncy = 2, eUpdate_Rate = 3, eCurrency_calculator = 4, eMain_Menu = 5 };
	static short _Read_currency_menu_option()
	{
		cout << setw(30) << left << "" << "\tPlease choose what do you want to do ?[ 1 to 5 ] ";
		short choise = clsinput::read_number_between<short>(1, 5,
			"\nInvalid choice, Please enter a number between [1 to 5 : ");
		return choise;
	}

	static void _Show_currency_list()
	{
		clsCurrency_List_Screen::show_Currency_list();
	}
	static void _Find_Currency()
	{
		clsFind_Currency_Screen::Find_currency_Screen();
	}
	static void _Update_Rate()
	{
		clsUpdate_currency_Screen::Update_currency_Screen();
	}
	static void _Currency_calculator()
	{
		clsCurrency_Calculator_Screen::Show_Currency_Calculator_screen();
	}
	static void _Go_back_currency_menu()
	{
		cout << "\n" << setw(39) << "" << "Press Any Kay To Go Back To currency menu ";
		clsutil::pause();
		clsutil::cls();
		Show_Currency_menu();
	}

	static void _Perform_currency_menu(_encurrency option)
	{
		switch (option)
		{
		case eList_Currency:
		{
			clsutil::cls();
			_Show_currency_list();
			_Go_back_currency_menu();
			break;
		}
		case eFind_Currncy:
		{
			clsutil::cls();
			_Find_Currency();
			_Go_back_currency_menu();
			break;
		}
		case eUpdate_Rate:
		{
			clsutil::cls();
			_Update_Rate();
			_Go_back_currency_menu();
			break;
		}
		case eCurrency_calculator:
		{
			clsutil::cls();
			_Currency_calculator();
			_Go_back_currency_menu();
			break;
		}
		case eMain_Menu:
		{
		}
		}
	}
public:
	static void Show_Currency_menu()
	{
		string tite = "Currency Exchange Main Screen ";
		_Drow_screen_hider(tite);
		cout << string(33, ' ') << string(45, '-') << endl;
		cout << string(50, ' ') << "Currency Exchange Menu" << endl;
		cout << string(33, ' ') << string(45, '-') << endl;

		cout << string(40, ' ') << "[1] Show currency list " << endl;
		cout << string(40, ' ') << "[2] Find Currency " << endl;
		cout << string(40, ' ') << "[3] Update Rate " << endl;
		cout << string(40, ' ') << "[4] Currency calculator  " << endl;
		cout << string(40, ' ') << "[5] Main Menu " << endl;
		cout << string(33, ' ') << string(45, '-') << endl;

		_Perform_currency_menu((_encurrency)_Read_currency_menu_option());
	}

};