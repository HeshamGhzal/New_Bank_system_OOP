#pragma once
#include"clsCurrency.h"
#include"../clsScreen.h"
class clsCurrency_List_Screen :protected clsscreen
{
private:

	static void _Print_client_record(clsCurrency currency, short currency_counter)
	{

		cout << setw(12) << "" << "|";
		//cout << setw(4) << currency_counter;
		printf("%03d ", currency_counter);

		cout << "|" << left << setw(30) << currency.Country() << "|"
			<< left << setw(6) << currency.Currncy_code() << "|"
			<< left << setw(40) << currency.Currncy_name() << "|"
			<< left << setw(10) << currency.Rate() << "|" << endl;
	}
public:
	static void show_Currency_list()
	{
		vector<clsCurrency>vCurrency = clsCurrency::Get_Currency_list();
		string title = "Currency List Screen";
		string sub_title = to_string(vCurrency.size()) + " Currencies Available ";
		clsscreen::_Drow_screen_header(title, sub_title);

		cout << setw(12) << "" << string(96, '=') << endl;
		cout << setw(12) << "" << "|" << setw(4) << "NO " << "|"
			<< left << setw(30) << "Country" << "|"
			<< left << setw(6) << "Code" << "|"
			<< left << setw(40) << "Name" << "|"
			<< left << setw(10) << "Rate/(1$)" << "|" << endl;
		cout << setw(12) << "" << string(96, '=') << endl;
		if (vCurrency.size() == 0)
		{
			cout << setw(37) << "" << "\tNo Currency Available \n" << endl;
			return;
		}
		else
		{
			short Currency_counter = 1;
			for (clsCurrency Currency : vCurrency)
			{
				_Print_client_record(Currency, Currency_counter++);
			}
		}
		cout << setw(12) << "" << string(96, '-') << endl;
	}

};