#pragma once
#include <iostream>
#include <limits>
#include <string>
#include "clsDate.h"
class clsinput
{

public:
	static string Read_String()
	{
		string value = "";
		getline(cin >> ws, value);
		return value;
	}
	static string Read_String(string message)
	{
		string value = "";
		cout << message;
		cin >> value;
		return value;
	}

	template<typename T> static T read_Number(string error_message = "Invalid input. Please enter a valid integer number: ")
	{
		T number;
		while (!(cin >> number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << error_message;
		}
		// discard the rest of the line (e.g. the trailing '\n') so callers won't see leftover input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return number;
	}
	/*static int read_Int_Number(string error_message = "Invalid input. Please enter a valid integer number: ")
	{
		int value;
		while (!(cin >> value))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << error_message;
		}
		return value;
	}
	static float read_Float_Number(string error_message = "Invalid input. Please enter a valid float number: ")
	{
		float value;
		while (!(cin >> value))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << error_message;
		}
		return value;
	}
	static double read_Doubl_Number(string error_message = "Invalid input. Please enter a valid double number: ")
	{
		double value;
		while (!(cin >> value))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << error_message;
		}
		return value;
	}*/
	template<typename T> static T read_number_between(T from, T to, string error_message = "Invalid input. Please enter a valid integer number: ")
	{
		short number = read_Number<short>(error_message);
		while (!Is_number_between<bool>(number, from, to))
		{
			cout << error_message;
			number = read_Number<short>(error_message);
		}
		return number;
	}
	/*static int read_int_number_between(int from, int to, string error_message = "Invalid input. Please enter a valid integer number: ")
	{
		int number = read_Int_Number(error_message);
		while (!Is_number_between(number, from, to))
		{
			cout << error_message;
			number = read_Int_Number(error_message);
		}
		return number;
	}
	static float read_float_number_between(float from, float to, string error_message = "Invalid input. Please enter a valid float number: ")
	{
		float number = read_Float_Number(error_message);
		while (!Is_number_between(number, from, to))
		{
			cout << error_message;
			number = read_Float_Number(error_message);
		}
		return number;
	}
	static double read_double_number_between(double from, double to, string error_message = "Invalid input. Please enter a valid double number: ")
	{
		double number = read_Doubl_Number(error_message);
		while (!Is_number_between(number, from, to))
		{
			cout << error_message;
			number = read_Doubl_Number(error_message);
		}
		return number;
	}*/

	static bool Is_valid_date(clsdate date)
	{
		return clsdate::Is_valid_date(date);
	}
	static bool Is_date_between(clsdate date, clsdate from, clsdate to)
	{
		if (clsdate::Is_Date1_Equal_Date2(date, from) ||
			clsdate::Is_Date1_Equal_Date2(date, to))
		{
			return true;
		}
		if (clsdate::Is_Date1_After_Date2(date, from) &&
			clsdate::Is_Date1_Befor_Date2(date, to))
		{
			return true;
		}
		if (clsdate::Is_Date1_After_Date2(date, to) &&
			clsdate::Is_Date1_Befor_Date2(date, from))
		{
			return true;
		}

		return false;

	}
	static bool Is_valid_Email(string email)
	{
		// Basic validation: check for presence of '@' and '.'
		size_t atPos = email.find('@');
		size_t dotPos = email.find('.', atPos);
		if (atPos == string::npos || dotPos == string::npos)
			return false;
		// Ensure there's at least one character before '@', between '@' and '.', and after '.'
		if (atPos == 0 || dotPos - atPos <= 1 || dotPos >= email.length() - 1)
			return false;
		return true;
	}
	template<typename T> static T Is_number_between(T number, T from, T to)
	{
		return number >= from && number <= to;
	}
	/*static bool Is_number_between(short number, short from, short to)
	{
		return number >= from && number <= to;
	}
	static bool Is_number_between(float number, float from, float to)
	{
		return number >= from && number <= to;
	}
	static bool Is_number_between(double number, double from, double to)
	{
		return number >= from && number <= to;
	}*/
};