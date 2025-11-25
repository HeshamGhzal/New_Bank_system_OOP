#pragma once
#include <iostream>
#include <string>


using namespace std;
class clsperson
{
private:
	string _FirstName;
	string _LastName;
	string _address;
	string _phone;
	string _emaile;
	string _name() { return _FirstName + " " + _LastName; }
	int _age;

public:
	clsperson(string first_name, string last_name, string Email,
		string phone)
	{
		_FirstName = first_name;
		_LastName = last_name;
		_phone = phone;
		_emaile = Email;
	}
	void set_First_Name(string name)
	{
		_FirstName = name;
	}

	string get_First_Name()
	{
		return _FirstName;
	}
	// __declspec(property(get = get_First_Name, put = set_First_Name)) string First_Name;

	void set_Last_Name(string last_name)
	{
		_LastName = last_name;
	}
	string get_Last_Name()
	{
		return _LastName;
	}
	// __declspec(property(get = get_Last_Name, put = set_Last_Name)) string Last_Name;

	void set_Address(string address)
	{
		_address = address;
	}
	string get_Address()
	{
		return _address;
	}
	// __declspec(property(get = get_Address, put = set_Address)) string Address;

	void set_Phone(string phone)
	{
		_phone = phone;
	}
	string get_Phone()
	{
		return _phone;
	}
	// __declspec(property(get = get_Phone, put = set_Phone)) string Phone;

	void set_Email(string email)
	{
		_emaile = email;
	}
	string get_Email()
	{
		return _emaile;
	}
	// __declspec(property(get = get_Email, put = set_Email)) string Email;

	void set_Age(int age)
	{
		_age = age;
	}
	int get_Age()
	{
		return _age;
	}
	// __declspec(property(get = get_Age, put = set_Age)) int Age;

	string getFullName()
	{
		return _name();
	}
	// __declspec(property(get = getFullName)) string FullName;

	void sendEmail(string email)
	{
		cout << "--Email sent to " << email << endl;
	}
	void sendSMS(string phone)
	{
		cout << "--SMS sent to " << phone << endl;
	}


};