#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"../GENRAL/clsPerson.h"
#include<vector>
#include"../GENRAL/clsinput.h"


class clsbank_client : public clsperson
{
public:
	struct stTransfer_log;
private:
	enum enmode { Empty_mode = 0, Update_mode = 1, add_new = 2 };
	enmode _mode;
	string _account_number;
	string _pin_code;
	float _account_balance;
	bool _MarkedForDelete = false;


	static vector<string> _spelt_each_word_in_string(string s, string separator)
	{
		vector<string> vs;
		size_t pos = s.find(separator);
		string word = "";
		
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
	static clsbank_client _convert_line_data_to_object(string line)
	{
		vector<string> vclient = _spelt_each_word_in_string(line, "#//#");

		return clsbank_client(Update_mode, vclient.at(0), vclient.at(1),
			vclient.at(2), vclient.at(3), vclient.at(4), vclient.at(5),
			stof(vclient.at(6)));
	}
	static clsbank_client _get_empty_client_object()
	{
		return clsbank_client(Empty_mode, "", "", "", "", "", "", 0);
	}

	static string _convert_object_data_to_line(clsbank_client client, string separator = "#//#")
	{
		string line = "";
		line += client.get_First_Name() + separator;
		line += client.get_Last_Name() + separator;
		line += client.get_Email() + separator;
		line += client.get_Phone() + separator;
		line += client.get_account_number()+ separator;
		line += client.get_pin_code()+ separator;
		line += to_string(client.get_Account_Balance());
		return line;
	}
	void _add_data_line_to_file(string line)
	{
		fstream MyFile;
		MyFile.open("Client.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << line << endl;
			MyFile.close();
		}
	}
	static void _save_clients_to_file(vector<clsbank_client> Vclients)
	{
		fstream MyFile;
		string line;
		MyFile.open("Client.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsbank_client c : Vclients)
			{
				if (c._MarkedForDelete == false)
				{
					line = _convert_object_data_to_line(c);
					MyFile << line << endl;
				}
			}
			MyFile.close();
		}
	}
	static vector<clsbank_client>_load_clients_from_file(string filename = "Client.txt")
	{
		vector<clsbank_client>vclients;
		fstream MyFile;
		MyFile.open(filename, ios::in);
		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				clsbank_client client = _convert_line_data_to_object(line);
				vclients.push_back(client);
			}
			MyFile.close();
		}
		return vclients;
	}

	void _Update()
	{
		vector<clsbank_client>_vclients = _load_clients_from_file("Client.txt");
		for (clsbank_client& c : _vclients)
		{
			if (c.get_account_number() == _account_number)
			{
				c = *this;
				break;
			}
		}
		_save_clients_to_file(_vclients);
	}
	void _add_new()
	{
		string line = _convert_object_data_to_line(*this);
		_add_data_line_to_file(line);
	}

	string _prepar_Transfer_log_record_line(float Transfar_amunt, clsbank_client Destnation, string serarator = "#//#")
	{
		string Transfer_record_line = "";
		Transfer_record_line += clsdate::GetCurrentDateTime() + serarator;
		Transfer_record_line += _account_number + serarator;
		Transfer_record_line += Destnation._account_number + serarator;
		Transfer_record_line += to_string(_account_balance) + serarator;
		Transfer_record_line += to_string(Destnation._account_balance) + serarator;
		Transfer_record_line += to_string(Transfar_amunt) + serarator;
		// Transfer_record_line += current_user.get_user_name();
        Transfer_record_line += "Hesham"; // Temporary stub for current_user
		return Transfer_record_line;
	}
	void _Register_Transfers_Log_file(float Transfar_amunt, clsbank_client Destnation)
	{
		fstream MyFile;
		string line;
		MyFile.open("Transfer.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			line = _prepar_Transfer_log_record_line(Transfar_amunt, Destnation);
			MyFile << line << endl;
			MyFile.close();
		}
	}

	static stTransfer_log _convert_line_data_to_stTransfer(string line)
	{
		stTransfer_log Transfer_log;
		vector<string> vline = _spelt_each_word_in_string(line, "#//#");
		Transfer_log.Date_and_Time = vline.at(0);
		Transfer_log.Source_Account = vline.at(1);
		Transfer_log.Destnation_Account = vline.at(2);
		Transfer_log.Source_Balance = vline.at(3);
		Transfer_log.Destnation_Balance = vline.at(4);
		Transfer_log.Transfer_amount = vline.at(5);
		Transfer_log.User_name = vline.at(6);
		return Transfer_log;
	}



public:
	clsbank_client(enmode mode, string first_name, string last_name, string Email,
		string phone, string account_number, string pin_code, float account_balance)
		: clsperson(first_name, last_name, Email, phone)
	{
		_mode = mode;
		_account_number = account_number;
		_pin_code = pin_code;
		_account_balance = account_balance;
	}

	struct stTransfer_log
	{
		string Date_and_Time;
		string Source_Account;
		string Destnation_Account;
		string Source_Balance;
		string Destnation_Balance;
		string Transfer_amount;
		string User_name;
	};
	bool is_empty()
	{
		return _mode == Empty_mode;
	}

	string get_account_number()
	{
		return _account_number;
	}
	// __declspec(property(get = get_account_number)) string account_number;

	void set_pin_code(string pin_code)
	{
		_pin_code = pin_code;
	}
	string get_pin_code()
	{
		return _pin_code;
	}
	// __declspec(property(get = get_pin_code, put = set_pin_code)) string pin_code;

	void set_Account_Balance(float balance)
	{
		_account_balance = balance;
	}
	float get_Account_Balance()
	{
		return _account_balance;
	}
	// __declspec(property(get = get_Account_Balance, put = set_Account_Balance)) float Account_Balance;

	static clsbank_client find_client(string account_number)
	{
		vector<clsbank_client>vclients;
		fstream MyFile;
		MyFile.open("Client.txt", ios::in);
		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				clsbank_client client = _convert_line_data_to_object(line);
				if (client._account_number == account_number)
				{
					MyFile.close();
					return client;
				}
			}
			MyFile.close();
		}
		return _get_empty_client_object();
	}
	static clsbank_client find_client(string account_number, string pin_code)
	{
		vector<clsbank_client>vclients;
		fstream MyFile;
		MyFile.open("Client.txt", ios::in);
		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				clsbank_client client = _convert_line_data_to_object(line);
				if (client._account_number == account_number && client._pin_code == pin_code)
				{
					cout << "--Client Found Successfully--" << endl;
					MyFile.close();
					return client;
				}
			}
			MyFile.close();
		}
		return _get_empty_client_object();
	}
	enum ensave_result { sv_fail_empty_object = 0, sv_success = 1, sv_fail_account_number_exist = 2 };
	ensave_result save()
	{
		switch (_mode)
		{
		case Empty_mode:
		{
			return sv_fail_empty_object;
		}

		case Update_mode:
		{
			_Update();
			return sv_success;
		}

		case add_new:
		{
			if (Is_client_exist(_account_number))
			{
				return sv_fail_account_number_exist;
			}
			_add_new();
			_mode = Update_mode;
			return sv_success;
		}
		}

		return sv_fail_empty_object;
	}

	static clsbank_client Get_Add_new_clien_object(string account_number)
	{
		return clsbank_client(add_new, "", "", "", "", account_number, "", 0);
	}
	bool delete_client()
	{
		vector<clsbank_client>_vclients = _load_clients_from_file();
		for (clsbank_client& c : _vclients)
		{
			if (c._account_number == _account_number)
			{
				c._MarkedForDelete = true;
				break;
			}
		}
		_save_clients_to_file(_vclients);
		*this = _get_empty_client_object();
		return true;
	}
	static vector<clsbank_client>get_clients_list()
	{
		return _load_clients_from_file();
	}
	static double get_total_clients_balance()
	{
		vector<clsbank_client>vclients = _load_clients_from_file();
		double total_balance = 0;

		for (clsbank_client client : vclients)
		{
			total_balance += client._account_balance;
		}
		return total_balance;
	}
	static bool Is_client_exist(string account_number)
	{
		clsbank_client client = find_client(account_number);
		return !client.is_empty();
	}
	void Deposit(float amount)
	{
		_account_balance += amount;
		save();
	}
	bool Withdraw(float amount)
	{
		if (amount > _account_balance)
		{
			return false;
		}
		_account_balance -= amount;
		save();
		return true;
	}
	bool Transfer(float amount, clsbank_client& Destnation_client)
	{
		if (amount > Destnation_client._account_balance)
		{
			return false;
		}
		Withdraw(amount);
		Destnation_client.Deposit(amount);
		_Register_Transfers_Log_file(amount, Destnation_client);
		return true;
	}

	static vector < stTransfer_log > get_Transfers_log_list_from_file(string filename = "Transfer.txt")
	{
		vector<stTransfer_log>Transfer_logs;
		fstream MyFile;
		MyFile.open(filename, ios::in);
		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				stTransfer_log log = _convert_line_data_to_stTransfer(line);
				Transfer_logs.push_back(log);
			}
			MyFile.close();
		}
		return Transfer_logs;
	}

};