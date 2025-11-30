#include"clsBank_user.h"
#include"../GENRAL/clsinput.h"
#include"../clsScreen.h"
class clsUpdate_user_info :protected clsscreen
{
private:
	static void _Read_user_info(clsbank_user& user)
	{
		cout << setw(37) << left << "" << "Enter First Name ["<<user.get_First_Name()<<"] : ";
		user.set_First_Name( clsinput::Read_String()) ;
		cout << setw(37) << left << "" << "Enter Last Name ["<<user.get_Last_Name()<<"] : ";
		user.set_Last_Name(clsinput::Read_String()) ;
		cout << setw(37) << left << "" << "Enter Email ["<<user.get_Email()<<"] : ";
		user.set_Email(clsinput::Read_String());
		cout << setw(37) << left << "" << "Enter Phone ["<<user.get_Phone()<<"] : ";
		user.set_Phone(clsinput::Read_String()) ;
		cout << setw(37) << left << "" << "Enter Password ["<<user.get_Password()<<"] : ";
		user.set_Password(clsinput::Read_String()) ;
		cout << setw(37) << left << "" << "Enter Permission ["<<user.GetPermissions()<<"] : ";
		user.SetPermissions(_Read_permission_to_set()) ;
	}

	static void _Print_user_record(clsbank_user user, short user_counter = 0)
	{
		cout << "\n";
		cout << setw(27) << "" << string(30, '-') << endl;
		cout << left << setw(30) << "" << "User Name   : " << user.get_user_name() << endl;
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
		cout << "\n Show client list, permission ? [Y] or [N] ";
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

	static void Show_update_user_screen()
	{
		clsscreen::_Drow_screen_header("Update User Info Screen");

		string User_name = clsinput::Read_String("\tpleas Enter User name : ");
		while (!clsbank_user::Is_user_exist(User_name))
		{
			cout << "\tInvalid User name  , pleas try again : ";
			User_name = clsinput::Read_String();
		}

		clsbank_user user1 = clsbank_user::find_user(User_name);
		_Print_user_record(user1);
		cout << "\n\tAre you going to update this user info ? [y]OR[n] : ";
		char answer = 'n';
		cin >> answer;
		if (tolower(answer) != 'y')
			return;

		cout << "\n\tUpdate User Info : " << endl;
		cout << setw(37) << left << "" << string(40, '=') << endl;
		_Read_user_info(user1);
		clsbank_user::ensave_result save_result;
		save_result = user1.save();
		switch (save_result)
		{
		case clsbank_user::sv_fail_empty_object:
			cout << "Error : User object is empty , can not save it " << endl;
			break;
		case clsbank_user::sv_fail_user_name_exist:
			cout << "Error : User name already exists , can not save it " << endl;
			break;
		case clsbank_user::sv_success:
			cout << "User info updated successfully :-) " << endl;
			_Print_user_record(user1);
			break;
		}

	}

};