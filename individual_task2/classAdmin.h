#pragma once
#include <vector>
#include <iostream>
#include "classUser.h"
#include "classGuest.h"

class Admin :public User {
private:
	vector<Guest> users;
public:
	Admin() :users({}) { Registration(); }
	Admin(const string& path)
	{
		Registration();

		fstream file(path, ios::in);
		string text;
		while (getline(file, text).good()) {
			Guest newGuest;
			newGuest.SetPib(text);

			getline(file, text);
			newGuest.SetAddress(text);

			getline(file, text);
			newGuest.SetPhoneNumber(text);

			getline(file, text);
			newGuest.SetLogin(text);

			getline(file, text);
			newGuest.SetPassword(text);

			getline(file, text);
			newGuest.SetEncryptionKey(atoi(text.c_str()));

			newGuest.DeEncrypt(login);
			newGuest.DeEncrypt(password);

			while (getline(file, text) && text != "") {
				auto j = text;
				while (getline(file, text) && text != ";") {
					newGuest.grades[j].emplace_back(atoi(text.c_str()));
				}
			}
			users.push_back(newGuest);
		}
		file.close();
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