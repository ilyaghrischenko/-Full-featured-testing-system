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

	void show() const
	{
		for (int i = 0; i < users.size(); ++i) {
			cout << users[i];
		}
	}
};