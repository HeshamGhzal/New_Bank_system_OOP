#pragma once
#include"../clsScreen.h"
#include"../GENRAL/clsinput.h"
#include"clsCurrency.h"
class clsCurrency_Calculator_Screen :protected clsscreen
{
private:
	static clsCurrency _Get_Currency_Code(string massege)
	{
		cout << massege << "";
		string currency_code = clsinput::Read_String();
		while (!clsCurrency::Is_currency_Exist(currency_code))
		{
			cout << "NO currency Available ,Pleas Enter again : ";
			currency_code = clsinput::Read_String();
		}
		clsCurrency c = clsCurrency::Find_currency_by_code(currency_code);
		return c;
	}
	static void _Print_Calculation_Result(float value, clsCurrency from, clsCurrency to)
	{
		float value2 = from.Convert_to_other_currency(value, to);
		cout << "\nConverting " << value << " of " << from.Currncy_name() << " to " <<
			to.Currncy_name() << " is " << value2 << " " << to.Currncy_name() << " ." << endl;
	}

public:
	static void Show_Currency_Calculator_screen()
	{
		char answer = 'y';
		while (tolower(answer) == 'y')
		{
			clsutil::cls();
			string tite = "Currency Calculator Screen ";
			_Drow_screen_hider(tite);

			clsCurrency c1 = _Get_Currency_Code("Please Enter Currency_code You wont to Covert From : ");
			clsCurrency::Print_currency_info(c1);
			clsCurrency c2 = _Get_Currency_Code("Please Enter Currency_code You wont to Covert To : ");
			clsCurrency::Print_currency_info(c2);
			cout << "\nPleas Enter Amount to convert : ";
			float value = clsinput::read_Number<float>();
			_Print_Calculation_Result(value, c1, c2);
			cout << "\nDo you wont to perform another calculation ? [Y] OR [N] ";
			cin >> answer;
		}

	}
};