#pragma once
#include <vector>
#include <iostream>
#include "classUser.h"
#include "classGuest.h"

vector<Guest> GetArrFile(const string& path)
{
	vector<Guest> arr;

	fstream file(path, ios::in);
	string text;
	while (getline(file, text).good()) {
		Guest newGuest;

		string pib = text;

		getline(file, text);
		string address = text;

		getline(file, text);
		string phone = text;

		getline(file, text);
		string login = text;

		getline(file, text);
		string pass = text;

		getline(file, text);
		int key = atoi(text.c_str());

		DeEncrypt(newGuest, login);
		DeEncrypt(newGuest, pass);

		dictionary grades = newGuest.GetGrades();
		while (getline(file, text) && text != "") {
			auto j = text;
			while (getline(file, text) && text != ";") {
				grades[j].emplace_back(atoi(text.c_str()));
			}
		}
		Guest NEW(pib, address, phone, grades, true, login, pass, key);
		arr.push_back(NEW);
	}
	file.close();

	return arr;
}

class Admin :public User {
private:
	vector<Guest> users;
public:
	Admin():users({}) { Registration(); }
	Admin(const string& path)
	{
		Registration();
		users = GetArrFile("..\\reg_obj.txt");
	}

	inline vector<Guest> GetUsers() const
	{
		return users;
	}
	void show() const
	{
		for (int i = 0; i < users.size(); ++i) {
			cout << users[i];
		}
	}

	void AddUser()
	{
		Guest obj;
		cin >> obj;
		users.emplace_back(obj);
		Save("..\\reg_obj.txt", obj);
	}
	void DelUser()
	{

	}

	friend ostream& operator<<(ostream& s, const Admin& obj)
	{
		for (int i = 0; i < obj.users.size(); ++i) {
			cout << obj.users[i];
		}
		return s;
	}
};