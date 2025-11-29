#pragma once
#include<iostream>
#include"clsBank_user.h"
#include"../clsScreen.h"
#include"../GENRAL/clsinput.h"

class clsAdd_new_user_screen :protected clsscreen
{
private:
	static void _Read_user_info(clsbank_user& user)
	{
		cout << setw(37) << left << "" << "Enter First Name : ";
		user.set_First_Name(clsinput::Read_String());
		cout << setw(37) << left << "" << "Enter Last Name : ";
		user.set_Last_Name(clsinput::Read_String());
		cout << setw(37) << left << "" << "Enter Email : ";
		user.set_Email(clsinput::Read_String());
		cout << setw(37) << left << "" << "Enter Phone : ";
		user.set_Phone(clsinput::Read_String());
		cout << setw(37) << left << "" << "Enter Password : ";
		user.set_Password(clsinput::Read_String());
		cout << setw(37) << left << "" << "Enter Permission : ";
		user.SetPermissions(_Read_permission_to_set());
	}

	static void _Print_user_record(clsbank_user user, short user_counter = 0)
	{
		cout << "\n";
		cout << setw(27) << "" << string(30, '-') << endl;
		cout << left << setw(30) << "" << "User Name   : " << user.get_user_name()<< endl;
		cout << left << setw(30) << "" << "Full Name   : " << user.getFullName() << endl;
		cout << left << setw(30) << "" << "Phone       : " << user.get_Phone() << endl;
		cout << left << setw(30) << "" << "Email       : " << user.get_Email() << endl;
		cout << left << setw(30) << "" << "Password    : " << user.get_Password() << endl;
		cout << left << setw(30) << "" << "Permissions : " << user.GetPermissions() << endl;
		cout << setw(27) << "" << string(30, '-') << endl;
	}

	static int _Read_permission_to_set()
	{
		int permission = 0;
		char answer = 'n';
		cout << "Do you wont to give full access to user ? [Y] or [N]";
		cin >> answer;
		if (answer == tolower('y'))
		{
			return permission = clsbank_user::eAll;
		}

		cout << "Do you wont to give access to user to :" << endl;
		cout << "\nTo Show client list, permission ? [Y] or [N] ";
		cin >> answer;
		if (answer == tolower('y'))
		{
			permission += clsbank_user::pListClients;
		}
		cout << "\n Add new client, permission ? [Y] or [N] ";
		cin >> answer;
		if (answer == tolower('y'))
		{
			permission += clsbank_user::pAddNewClient;
		}
		cout << "\n Delete client, permission ? [Y] or [N] ";
		cin >> answer;
		if (answer == tolower('y'))
		{
			permission += clsbank_user::pDeleteClient;
		}
		cout << "\n Update client, permission ? [Y] or [N] ";
		cin >> answer;
		if (answer == tolower('y'))
		{
			permission += clsbank_user::pUpdateClients;
		}
		cout << "\n Find client, permission ? [Y] or [N] ";
		cin >> answer;
		if (answer == tolower('y'))
		{
			permission += clsbank_user::pFindClient;
		}
		cout << "\n Transaction, permission ? [Y] or [N] ";
		cin >> answer;
		if (answer == tolower('y'))
		{
			permission += clsbank_user::pTranactions;
		}
		cout << "\n Manage, permission ? [Y] or [N] ";
		cin >> answer;
		if (answer == tolower('y'))
		{
			permission += clsbank_user::pManageUsers;
		}
		cout << "\n Show Register Login list ? [Y] or [N] ";
		cin >> answer;
		if (answer == tolower('y'))
		{
			permission += clsbank_user::pRegister_list;
		}
		return permission;

	}
public:
	static void Add_new_user_screen()
	{
		_Drow_screen_hider("Add New User Screen");
		cout << setw(37) << left << "" << "Please Enter user name : ";
		string user_name = clsinput::Read_String();
		while (clsbank_user::Is_user_exist(user_name))
		{
			cout << setw(20) << left << "" <<
				"User name is already exist, please enter another user name : ";
			user_name = clsinput::Read_String();
		}
		clsbank_user User = clsbank_user::Get_Add_new_user_object(user_name);
		User.set_user_name(user_name);
		_Read_user_info(User);
		clsbank_user::ensave_result save_result = User.save();
		switch (save_result)
		{
		case clsbank_user::sv_success:
		{
			cout << setw(37) << left << "" << "New User added successfully " << endl;
			_Print_user_record(User);
			break;
		}
		case clsbank_user::sv_fail_empty_object:
		{
			cout << setw(37) << left << "" << "Error : User object is empty , can not save it " << endl;
			break;
		}
		case clsbank_user::sv_fail_user_name_exist:
		{
			cout << setw(30) << left << "" << "Error : Account Number is already exist , can not add it " << endl;
			break;
		}

		}
	}

};