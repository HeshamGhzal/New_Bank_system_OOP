#pragma once
#include"../clsScreen.h"
#include"../GENRAL/clsinput.h"
#include"clsShow_User_List.h"
#include"clsAdd_New_User.h"
#include"clsDelet_User.h"
#include"clsUpdate_User_Info.h"
#include"clsFind_User.h"
class clsManage_user :protected clsscreen
{
private:
	enum _eManage_user 
    {
		eUser_list = 1, eAdd_New_User = 2, eDelete_User = 3,
		eUpdate_user = 4, eFind_user = 5, eMain_Menu = 6
	};
	static short _Read_User_menu_option()
	{
		cout << setw(30) << left << "" << "\tPlease choose what do you want to do ?[ 1 to 6 ] ";
		short choise = clsinput::read_number_between<short>(1, 6,
			"\nInvalid choice, Please enter a number between [1 to 6] : ");
		return choise;
	}
	static void _Show_user_list()
	{
		clsShow_user_list::show_users_list();
	}
	static void _Add_New_User()
	{
		clsAdd_new_user_screen::Add_new_user_screen();
	}
	static void _Delete_User()
	{
		clsDelet_user::show_delete_user_screen();
	}
	static void _Update_user()
	{
		clsUpdate_user_info::Show_update_user_screen();
	}
	static void _Find_user()
	{
		clsFind_user::Show_find_user_screen();
	}
	static void _Go_back_to_user_menu()
	{
		cout << "\n" << setw(39) << "" << "Press [Enter] Kay To Go Back To User Menu ";
		clsutil::pause();
		clsutil::cls();
		Show_Manage_user_menu();
	}
	static void _Perform_User_Menu(_eManage_user option)
	{
		switch (option)
		{
		case eUser_list:
		{
			clsutil::cls();
			_Show_user_list();
			_Go_back_to_user_menu();
			break;
		}
		case eAdd_New_User:
		{
			clsutil::cls();
			_Add_New_User();
			_Go_back_to_user_menu();
			break;
		}
		case eDelete_User:
		{
			clsutil::cls();
			_Delete_User();
			_Go_back_to_user_menu();
			break;
		}
		case eUpdate_user:
		{
			clsutil::cls();
			_Update_user();
			_Go_back_to_user_menu();
			break;
		}
		case eFind_user:
		{
			clsutil::cls();
			_Find_user();
			_Go_back_to_user_menu();
			break;
		}
		case eMain_Menu:
		{

		}
		}
	}

public:
	static void Show_Manage_user_menu()
	{
		if (check_permission_right(current_user.pManageUsers))
		{
			return;
		}
		string tite = "Manage User Screen ";
		_Drow_screen_header(tite);
		cout << string(33, ' ') << string(45, '-') << endl;
		cout << string(50, ' ') << "Manage User" << endl;
		cout << string(33, ' ') << string(45, '-') << endl;

		cout << string(40, ' ') << "[1] User list " << endl;
		cout << string(40, ' ') << "[2] Add New User " << endl;
		cout << string(40, ' ') << "[3] Delete User " << endl;
		cout << string(40, ' ') << "[4] Update user  " << endl;
		cout << string(40, ' ') << "[5] Find user  " << endl;
		cout << string(40, ' ') << "[6] Main Menu " << endl;
		cout << string(33, ' ') << string(45, '-') << endl;

		_Perform_User_Menu((_eManage_user)_Read_User_menu_option());
	}
};