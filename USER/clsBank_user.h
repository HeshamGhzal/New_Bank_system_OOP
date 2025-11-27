#pragma once
#include<iostream>
#include"../GENRAL/clsPerson.h"
#include <string>
#include<vector>
#include<fstream>
#include"../GENRAL/clsDate.h"
#include"../GENRAL/clsUtil.h"

class clsbank_user :public clsperson
{
public:
	struct sRegester_data;
private:
	enum enmode { Empty_mode = 0, Update_mode = 1, Add_new = 2 };
	enmode _mode;
	string _User_name;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete = false;

	static sRegester_data _convert_line_data_to_struct(string line)
	{
		sRegester_data data;
		vector<string> vuser = _spelt_each_word_in_string(line, "#//#");
		// Basic safety: ensure we have expected tokens before accessing
		if (vuser.size() < 4) {
			data.Date = "";
			data.user_name = "";
			data.password = "";
			data.permission = "";
			return data;
		}
		data.Date = vuser.at(0);
		data.user_name = vuser.at(1);
		data.password = clsutil::decrypt_string(vuser.at(2));
		data.permission = vuser.at(3);
		return data;
	}

	string _prepar_user_login_record_to_line(string serarator = "#//#")
	{
		string login_record_line = "";
		login_record_line += clsdate::GetCurrentDateTime() + serarator;
		login_record_line += _User_name + serarator;
		login_record_line += clsutil::encrypt_string(_Password) + serarator;
		login_record_line += to_string(_Permissions);
		return login_record_line;
	}
	static vector<string> _spelt_each_word_in_string(string s, string separator)
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

	static clsbank_user _convert_line_data_to_object(string line)
	{
		vector<string> vuser = _spelt_each_word_in_string(line, "#//#");
		// Basic safety: ensure we have expected tokens before creating object
		if (vuser.size() < 7) {
			return _get_empty_user_object();
		}
		return clsbank_user(Update_mode, vuser.at(0), vuser.at(1),
			vuser.at(2), vuser.at(3), vuser.at(4), clsutil::decrypt_string(vuser.at(5)), stoi(vuser.at(6)));
	}

	static clsbank_user _get_empty_user_object()
	{
		return clsbank_user(Empty_mode, "", "", "", "", "", "", 0);
	}

	static string _convert_object_data_to_line(clsbank_user user, string separator = "#//#")
	{
		string line = "";
		line += user.get_First_Name()+ separator;
		line += user.get_Last_Name() + separator;
		line += user.get_Email() + separator;
		line += user.get_Phone() + separator;
		line += user.get_user_name() + separator;
		line += clsutil::encrypt_string(user.get_Password()) + separator;
		line += to_string(user.GetPermissions());
		return line;
	}

	void _add_data_line_to_file(string line)
	{
		fstream MyFile;
		MyFile.open("User.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << line << endl;
			MyFile.close();
		}
	}

	static void _save_users_to_file(vector<clsbank_user> vuser)
	{
		fstream MyFile;
		string line;
		MyFile.open("User.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsbank_user u : vuser)
			{
				if (u._MarkedForDelete == false)
				{
					line = _convert_object_data_to_line(u);
					MyFile << line << endl;
				}
			}
			MyFile.close();
		}
	}

	static vector<clsbank_user>_load_users_from_file(string filename = "User.txt")
	{
		vector<clsbank_user>vuser;
		fstream MyFile;
		MyFile.open(filename, ios::in);
		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				clsbank_user user = _convert_line_data_to_object(line);
				vuser.push_back(user);
			}
			MyFile.close();
		}
		return vuser;
	}

	void _Update()
	{
		vector<clsbank_user>_vusers = _load_users_from_file("User.txt");
		for (clsbank_user& u : _vusers)
		{
			if (u._User_name == _User_name)
			{
				u = *this;
				break;
			}
		}
		_save_users_to_file(_vusers);
	}
	void _add_new()
	{
		string line = _convert_object_data_to_line(*this);
		_add_data_line_to_file(line);
	}


public:
	struct sRegester_data
	{
		string Date;
		string user_name;
		string password;
		string permission;
	};

	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64, pRegister_list = 128
	};
	clsbank_user(enmode Mode, string first_name, string last_name
		, string Email, string phone, string User_name, string Password, int Permissions)
		: clsperson(first_name, last_name, Email, phone)
	{
		_mode = Mode;
		_User_name = User_name;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool is_empty()
	{
		return _mode == Empty_mode;
	}

	void set_user_name(string user_name)
	{
		_User_name = user_name;
	}
	string get_user_name()
	{
		return _User_name;
	}

	void set_Password(string Password)
	{
		_Password = Password;
	}
	string get_Password()
	{
		return  _Password;
	}

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	int GetPermissions()
	{
		return _Permissions;
	}

	static clsbank_user find_user(string User_name)
	{
		vector<clsbank_user>vclients;
		fstream MyFile;
		MyFile.open("User.txt", ios::in);
		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				clsbank_user user = _convert_line_data_to_object(line);
				if (user.get_user_name() == User_name)
				{
					MyFile.close();
					return user;
				}
			}
			MyFile.close();
		}
		return _get_empty_user_object();
	}
	static clsbank_user find_user(string user_name, string password)
	{
		vector<clsbank_user>vclients;
		fstream MyFile;
		MyFile.open("User.txt", ios::in);
		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				clsbank_user user = _convert_line_data_to_object(line);
				if (user.get_user_name() == user_name && user.get_Password() == password)
				{
					MyFile.close();
					return user;
				}
			}
			MyFile.close();
		}
		return _get_empty_user_object();
	}

	enum ensave_result { sv_fail_empty_object = 0, sv_success = 1, sv_fail_user_name_exist = 2 };
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

		case Add_new:
		{
			if (Is_user_exist(_User_name))
			{
				return sv_fail_user_name_exist;
			}
			_add_new();
			_mode = Update_mode;
			return sv_success;
		}
		}

		return sv_fail_empty_object;
	}

	static clsbank_user Get_Add_new_user_object(string User_name)
	{
		return clsbank_user(Add_new, "", "", "", "", User_name, "", 0);
	}
	bool delete_user()
	{
		vector<clsbank_user>_vclients = _load_users_from_file();
		for (clsbank_user& c : _vclients)
		{
			if (c.get_user_name() == _User_name)
			{
				c._MarkedForDelete = true;
				break;
			}
		}
		_save_users_to_file(_vclients);
		*this = _get_empty_user_object();
		return true;
	}
	static vector<clsbank_user>get_users_list(string filename = "User.txt")
	{
		return _load_users_from_file();
	}

	static bool Is_user_exist(string User_name)
	{
		clsbank_user user = find_user(User_name);
		return !user.is_empty();
	}

	bool check_acceess_permition(enPermissions permission)
	{
		if (this->GetPermissions() == eAll)
		{
			return true;
		}
		if ((this->GetPermissions() & permission) == permission)
		{
			return true;
		}
		else
			return false;
	}

	void save_Regester_login_to_file()
	{
		fstream MyFile;
		string line;
		MyFile.open("Login_register.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			line = _prepar_user_login_record_to_line();
			MyFile << line << endl;
			MyFile.close();
		}
	}
	static vector < sRegester_data > get_Register_login_from_file(string filename = "Login_register.txt")
	{
		vector<sRegester_data>vRegistar_record;
		fstream MyFile;
		MyFile.open(filename, ios::in);
		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				sRegester_data user = _convert_line_data_to_struct(line);
				vRegistar_record.push_back(user);
			}
			MyFile.close();
		}
		return vRegistar_record;
	}
};