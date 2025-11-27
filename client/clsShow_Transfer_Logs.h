#pragma once
#include"../clsScreen.h"
#include"clsBank_Client.h"

class clsShow_Transfer_logs :protected clsscreen
{
private:
	static void _Print_Transfer_logs(clsbank_client::stTransfer_log log, short logs_counter)
	{

		cout << setw(3) << "" << "|";
		//cout << setw(4) << logs_counter;
		printf("%03d ", logs_counter);


		cout << "|" << left << setw(25) << log.Date_and_Time << "|"
			<< left << setw(10) << log.Source_Account << "|"
			<< left << setw(10) << log.Destnation_Account << "|"
			<< left << setw(15) << log.Source_Balance << "|"
			<< left << setw(15) << log.Destnation_Balance << "|"
			<< left << setw(15) << log.Transfer_amount << "|"
			<< left << setw(10) << log.User_name << "|"
			<< endl;
	}
public:
	static void Show_Transfer_logs_screen()
	{
		/*if (check_permission_right(current_user.pRegister_list))
		{
			return;
		}*/
		vector<clsbank_client::stTransfer_log>vuser = clsbank_client::get_Transfers_log_list_from_file();
		string title = "Transfer logs Screen\n";
		string sub_title = to_string(vuser.size()) + " Transfer logs System";
		clsscreen::_Drow_screen_hider(title, sub_title);

		cout << setw(3) << "" << string(113, '=') << endl;
		cout << setw(3) << "" << "|" << setw(4) << "NO " << "|"

			<< left << setw(25) << "     Date & Time" << "|"
			<< left << setw(10) << "S_Account" << "|"
			<< left << setw(10) << "D_Account" << "|"
			<< left << setw(15) << "S_Balance" << "|"
			<< left << setw(15) << "D_Balance" << "|"
			<< left << setw(15) << "T_amount" << "|"
			<< left << setw(10) << "User_name" << "|"
			<< endl;
		cout << setw(3) << "" << string(113, '=') << endl;
		if (vuser.size() == 0)
		{
			cout << setw(30) << "" << "\t No Transfer logs Available In the System \n" << endl;
			return;
		}
		else
		{
			short counter = 1;
			for (clsbank_client::stTransfer_log u : vuser)
			{
				_Print_Transfer_logs(u, counter++);
			}
		}
		cout << setw(3) << "" << string(113, '-') << endl;
	}


};