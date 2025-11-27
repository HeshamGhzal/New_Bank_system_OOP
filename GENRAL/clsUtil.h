#pragma once
#include <iostream>
#include <limits>
#include <string>
//#include <cstdlib>
#include <ctime>
#include"clsDate.h"

using namespace std;
class clsutil
{
public:
	static void cls()
	{
#ifdef _WIN32
		system("cls");
#else
		system("clear");
#endif
	}
	
	static void pause()
	 {
    // std::cout << "Press Enter to continue..." ;
	std::cout<< std::flush;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cin.get(); 
}


	static void random()
	{
		srand(static_cast<unsigned>(time(NULL)));
	}
	static int random_number(int from, int to)
	{
		return rand() % (to - from + 1) + from;
	}
	enum enchar_type
	{
		smool_letter = 1, captal_letter = 2, digit = 3, special_character = 4, mix = 5
	};
	static char get_rondom_character(enchar_type char_type = mix)
	{

		switch (char_type)
		{
		case smool_letter:
		{
			return char(random_number(97, 122));
			break;
		}
		case captal_letter:
		{
			return char(random_number(65, 90));
			break;
		}
		case digit:
		{
			return char(random_number(48, 57));
			break;
		}
		case special_character:
		{
			return char(random_number(33, 47));
			break;
		}
		case mix:
		{
			return get_rondom_character((enchar_type)random_number(smool_letter, digit));
			break;
		}
		return '\0';
		}
	}
	static string genrate_rondom_word(int num_of_char = 4)
	{
		string word;
		for (short i = 0; i < num_of_char; i++)
		{
			word += get_rondom_character();
		}
		return word;
	}
	static string genrate_key(int num_of_word = 4)
	{

		string line = "";

		for (short i = 0; i < num_of_word; i++)
		{
			if (i < num_of_word - 1)
				line += genrate_rondom_word() + '-';
			else
				line += genrate_rondom_word();
		}
		return line;
	}
	static void genrat_number_of_keys(int number_of_keys)
	{
		for (short i = 0; i < number_of_keys; i++)
		{
			if (i < number_of_keys - 1)
				cout << "key[" << i + 1 << "] : " << genrate_key() << endl;
			else
				cout << "key[" << i + 1 << "] : " << genrate_key();

		}
	}
	static void print_array(int arr[], int siz)
	{
		for (int i = 0; i < siz; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	static void print_array(string arr[], int siz)
	{
		for (int i = 0; i < siz; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	
	static void swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	static void swap(short& a, short& b)
	{
		short temp = a;
		a = b;
		b = temp;
	}
	static void swap(char& a, char& b)
	{
		char temp = a;
		a = b;
		b = temp;
	}
	static void swap(string& a, string& b)
	{
		string temp = a;
		a = b;
		b = temp;
	}
	static void swap(float& a, float& b)
	{
		float temp = a;
		a = b;
		b = temp;
	}
	static void swap(double& a, double& b)
	{
		double temp = a;
		a = b;
		b = temp;
	}
	static void swap(clsdate& date1, clsdate& date2)
	{
		clsdate temp = date1;
		date1 = date2;
		date2 = temp;
	}
	static void shaffile_array(int arr[], int siz)
	{
		for (int i = 0; i < siz; i++)
		{
			swap(arr[random_number(1, siz) - 1], arr[random_number(1, siz) - 1]);
		}
	}
	static void shaffile_array(string arr[], int siz)
	{
		for (int i = 0; i < siz; i++)
		{
			swap(arr[random_number(1, siz) - 1], arr[random_number(1, siz) - 1]);
		}
	}
	static void fill_array_with_random_number(int arr[], int& size, int from, int to)
	{
		cout << "pleas Enter size of array : ";
		cin >> size;
		for (int i = 0; i < size; i++)
		{
			arr[i] = random_number(from, to);
		}
	}
	static void fill_array_with_random_words(string arr[], int& size)
	{
		cout << "pleas Enter size of array : ";
		cin >> size;
		for (int i = 0; i < size; i++)
		{
			arr[i] = clsutil::genrate_rondom_word();
		}
	}
	static void fill_array_with_random_keys(string arr[], int& size)
	{
		cout << "pleas Enter size of array : ";
		cin >> size;
		for (int i = 0; i < size; i++)
		{
			arr[i] = clsutil::genrate_key();
		}
	}
	static string tab(short num_of_tabs = 1)
	{
		string tab = "";
		for (short i = 0; i < num_of_tabs; i++)
			tab += "\t";
		return tab;
	}
	static string encrypt_string(string to_encrypt, short enc_key = 5)
	{
		string encrypted = "";
		for (char c : to_encrypt)
			encrypted += c + enc_key;
		return  encrypted;
	}
	static string decrypt_string(string to_decrypt, short enc_key = 5)
	{
		string encrypted = "";
		for (char c : to_decrypt)
			encrypted += c - enc_key;
		return  encrypted;
	}

	/*static string N_to_txt_1to19(short n)
	{
		const string arr[] = { "","one","two","three","four","five","six","seven","eight"
			,"nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen",
			"seventeen","eighteen","nineteen" };
		if (n < 0 || n >= 20)
			return "";
		return arr[n];
	}
	static string N_to_txt_20to99(short n)
	{
		const string arr2[] = { "","","twenty","thirty","forty","fifty","sixty",
		"seventy","eighty","ninety" };
		if (n < 20 || n >= 100)
			return "";
		return arr2[n / 10];
	}*/
	static string Number_to_txt(int N)
	{
		if (N == 0)
		{
			return "";
		}

		if (N >= 1 && N <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[N] + " ";

		}

		if (N >= 20 && N <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[N / 10] + " " + Number_to_txt(N % 10);
		}

		if (N >= 100 && N <= 199)
		{
			return  "One Hundred " + Number_to_txt(N % 100);
		}

		if (N >= 200 && N <= 999)
		{
			return   Number_to_txt(N / 100) + "Hundreds " + Number_to_txt(N % 100);
		}

		if (N >= 1000 && N <= 1999)
		{
			return  "One Thousand " + Number_to_txt(N % 1000);
		}

		if (N >= 2000 && N <= 999999)
		{
			return   Number_to_txt(N / 1000) + "Thousands " + Number_to_txt(N % 1000);
		}

		if (N >= 1000000 && N <= 1999999)
		{
			return  "One Million " + Number_to_txt(N % 1000000);
		}

		if (N >= 2000000 && N <= 999999999)
		{
			return   Number_to_txt(N / 1000000) + "Millions " + Number_to_txt(N % 1000000);
		}

		if (N >= 1000000000 && N <= 1999999999)
		{
			return  "One Billion " + Number_to_txt(N % 1000000000);
		}
		else
		{
			return   Number_to_txt(N / 1000000000) + "Billions " + Number_to_txt(N % 1000000000);
		}


	}




};