#pragma once
#include"../clsScreen.h"
#include"clsCurrency.h"
#include"../GENRAL/clsinput.h"
class clsUpdate_currency_Screen :protected clsscreen
{
private:
	static void _Print_currency_info(clsCurrency c1)
	{
		cout << "\n" << string(35, ' ') << string(38, '=') << endl;
		cout << string(35, ' ') << "\tCountry       : " << c1.Country() << endl;
		cout << string(35, ' ') << "\tCurrency_code : " << c1.Currncy_code() << endl;
		cout << string(35, ' ') << "\tCurrency_name : " << c1.Currncy_name() << endl;
		cout << string(35, ' ') << "\tRate          : " << c1.Rate() << endl;
		cout << string(35, ' ') << string(38, '=') << endl;
	}
	static void _Perform_update(clsCurrency c1)
	{
		cout << "Please Enter Rate To Update : ";
		float Rate = clsinput::read_Number<float>();
		cout << "Are you sure you wont to Update [Y] OR [N] : ";
		char Answer = 'n';
		cin >> Answer;
		Answer = tolower(Answer);
		if (Answer != 'y')
		{
			cout << "Update Canceled ";
			return;
		}
		c1.Update_Rate(Rate);
		cout << "\n" << string(35, ' ') << "Currency Updated Successfully :-) \n";
		_Print_currency_info(c1);

	}
	static void _show_Result(clsCurrency c1)
	{
		if (!c1.Is_empty())
		{
			cout << "\n" << string(35, ' ') << "Currency Found Successfully :-) \n";
			_Print_currency_info(c1);
			_Perform_update(c1);
		}
		else
		{
			cout << "\n" << string(35, ' ') << "Currency Not Found :-( \n";

		}
	}

public:
	static void Update_currency_Screen()
	{
		clsscreen::_Drow_screen_hider("Update currency Screen");
		cout << "\nPlease Select :" << endl;
		cout << "[1]Find By Code To Update" << endl;
		cout << "[2]Find By country To Update " << endl;
		short sellction = clsinput::read_number_between<short>(1, 2);
		switch (sellction)
		{
		case 1:
		{
			cout << "Please Enter Currency Code : ";
			string Answer = clsinput::Read_String();
			clsCurrency currency = clsCurrency::Find_currency_by_code(Answer);
			_show_Result(currency);
			break;
		}
		case 2:
		{
			cout << "Please Enter Currency Country : ";
			string Answer = clsinput::Read_String();
			clsCurrency currency = clsCurrency::Find_currency_by_country(Answer);
			_show_Result(currency);
			break;
		}
		}
	}

};