#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
// #include"clsstring.h"


class clsCurrency
{
private:
	enum enMode { Empty_mode = 0, Update_mode = 1 };

	enMode _Mode;
	string _Country;
	string _Currncy_code;
	string _Currncy_name;
	float _Rate;

	static string _convert_currency_object_to_line(clsCurrency Currency, string seperator = "#//#") {
		string currency_line = "";
		currency_line += Currency.Country() + seperator;
		currency_line += Currency.Currncy_code() + seperator;
		currency_line += Currency.Currncy_name() + seperator;
		currency_line += to_string(Currency.Rate());
		return currency_line;
	}
	static vector<string> _spelt_each_word_in_string(string s, string separator = "#//#")
	{
		vector<string> vs;
		size_t pos = s.find(separator);
		string word = "";
		int counter = 0;

		while ((pos = s.find(separator)) != string::npos)
		{
			word = s.substr(0, pos);
			/*if (word != "")
			{*/
			vs.push_back(word);
			//}
			s = s.substr(pos + separator.length());
		}
		if (s != "")
			vs.push_back(s);
		return vs;
	}
	static clsCurrency _convert_line_to_currency_object(string line, string separator = "#//#")
	{
		vector < string > vcurrency = _spelt_each_word_in_string(line);
		return clsCurrency(Update_mode, vcurrency.at(0), vcurrency.at(1), vcurrency.at(2), stof(vcurrency.at(3)));
	}
	static void _add_data_line_to_file(string line, string file_name = "Currencies.txt")
	{
		fstream MyFile;
		MyFile.open(file_name, ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << line << endl;
			MyFile.close();
		}
	}
	static vector<clsCurrency>_load_currency_objects_from_file(string filename = "Currencies.txt")
	{
		vector<clsCurrency>currency_objects;
		fstream MyFile;
		MyFile.open(filename, ios::in);
		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				clsCurrency object = _convert_line_to_currency_object(line);
				currency_objects.push_back(object);
			}
			MyFile.close();
		}
		return currency_objects;
	}
	static void _save_currency_objects_to_file(vector<clsCurrency> vuser, string filename = "Currencies.txt")
	{
		fstream MyFile;
		string line;
		MyFile.open(filename, ios::out);
		if (MyFile.is_open())
		{
			for (clsCurrency object : vuser)
			{
				line = _convert_currency_object_to_line(object);
				MyFile << line << endl;
			}
			MyFile.close();
		}
	}
	void _Update()
	{
		vector<clsCurrency>currency_objects = _load_currency_objects_from_file();
		for (clsCurrency& c : currency_objects)
		{
			if (c.Currncy_code() == Currncy_code())
			{
				c = *this;
				break;
			}
		}
		_save_currency_objects_to_file(currency_objects);
	}
	static clsCurrency _Get_empty_currency_object() {
		return clsCurrency(Empty_mode, "", "", "", 0);
	}


public:
	clsCurrency(enMode Mode, string Country, string Currncy_code, string Currncy_name, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_Currncy_name = Currncy_name;
		_Currncy_code = Currncy_code;
		_Rate = Rate;
	}
	static vector<clsCurrency>Get_all_USD_Rate()
	{
		return _load_currency_objects_from_file();
	}
	bool Is_empty()
	{
		return (_Mode == Empty_mode);
	}
	string Country() {
		return _Country;
	}
	string Currncy_name() {
		return _Currncy_name;
	}
	string Currncy_code() {
		return _Currncy_code;
	}
	void Update_Rate(float Rate) {
		_Rate = Rate;
		_Update();
	}
	float Rate() {
		return _Rate;
	}

	static clsCurrency Find_currency_by_code(string Currncy_code, string filename = "Currencies.txt")
	{
		Currncy_code = clsstring::to_upper_string(Currncy_code);
		fstream Myfile;
		Myfile.open(filename, ios::in);
		if (Myfile.is_open())
		{
			string line;
			while (getline(Myfile, line))
			{
				clsCurrency currency = _convert_line_to_currency_object(line);
				if (clsstring::to_upper_string(currency.Currncy_code()) == Currncy_code)
				{
					Myfile.close();
					return currency;
				}
			}
			Myfile.close();
		}
		return _Get_empty_currency_object();
	}
	static clsCurrency Find_currency_by_country(string country, string filename = "Currencies.txt")
	{
		country = clsstring::to_upper_string(country);
		fstream Myfile;
		Myfile.open(filename, ios::in);
		if (Myfile.is_open())
		{
			string line;
			while (getline(Myfile, line))
			{
				clsCurrency currency = _convert_line_to_currency_object(line);
				if (clsstring::to_upper_string(currency.Country()) == country)
				{
					Myfile.close();
					return currency;
				}
			}
			Myfile.close();
		}
		return _Get_empty_currency_object();
	}
	static void Print_currency_info(clsCurrency c1)
	{
		cout << string(38, ' ') << string(38, '=') << endl;
		cout << string(40, ' ') << "Country      : " << c1.Country() << endl;
		cout << string(40, ' ') << "Currncy_code : " << c1.Currncy_code() << endl;
		cout << string(40, ' ') << "Currncy_name : " << c1.Currncy_name() << endl;
		cout << string(40, ' ') << "Rate /($)    : " << c1.Rate() << endl;
		cout << string(38, ' ') << string(38, '=') << endl;
	}

	static bool Is_currency_Exist(string Currncy_code)
	{
		clsCurrency c = Find_currency_by_code(Currncy_code);
		return (!c.Is_empty());
	}

	static  vector<clsCurrency>Get_Currency_list()
	{
		return _load_currency_objects_from_file();
	}
	static float Convert_USD_doler_to_other_Currency(float Doler_value, string currency_code)
	{
		clsCurrency c = clsCurrency::Find_currency_by_code(currency_code);
		if (c.Is_empty() || c.Rate() == 0.0f) return 0.0f;
		return Doler_value * c.Rate();
	}
	static float Convert_Currency_to_USD_Dolar(float currency_value, string currency_code)
	{
		clsCurrency c = clsCurrency::Find_currency_by_code(currency_code);
		if (c.Is_empty() || c.Rate() == 0.0f) return 0.0f;
		return currency_value / c.Rate();
	}
	float Convert_to_USD_doler(float value)
	{
		if (_Rate == 0.0f) return 0.0f;
		return value / _Rate;
	}
	float Convert_to_other_currency(float value, clsCurrency other_currency)
	{
		float value_in_Dolar = Convert_to_USD_doler(value);
		other_currency = Find_currency_by_code(other_currency._Currncy_code);
		if (other_currency.Is_empty()) {
			//target currency not found - return 0 to indicate failure
			return 0.0f;
		}
		if (other_currency._Currncy_code == "USD")
		{
			return value_in_Dolar;
		}
		else
		{
			if (other_currency.Rate() == 0.0f) return 0.0f;
			return value_in_Dolar * (other_currency.Rate());
		}
	}
};