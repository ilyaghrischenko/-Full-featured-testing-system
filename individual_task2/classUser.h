#pragma once
#include <iostream>
#include <string>
using namespace std;

class User {
protected:
	bool isRegistered;
	string login;
	string password;
	int encryption_key;

	void CheckIsRight(string& text)
	{
		bool isAccepted = false;
		while (!isAccepted) {
			cin >> text;
			int kilk_upper = 0;
			int kilk_numbers = 0;
			for (int i = 0; i < text.length(); ++i) {
				if (isdigit(text[i])) ++kilk_numbers;
				else if (text[i] == toupper(text[i])) ++kilk_upper;
			}
			if (kilk_upper >= 1 && kilk_numbers >= 3) isAccepted = true;
			else cout << "Помилка при введенні!\nВведіть повторно: ";
		}
	}
	void EncryptText(string& text)
	{
		for (int i = 0; i < text.length(); ++i) {
			text[i] += encryption_key;
		}
	}
	void DeEncrypt(string& text)
	{
		for (int i = 0; i < text.length(); ++i) {
			text[i] -= encryption_key;
		}
	}
	void Registration()
	{
		cout << "Реєстрація користувача:\n1)Ваш логін і пароль повинен містити хоча б 1 велику літеру.\n2)Ваш логін і пароль повинен містити хоча б 3 цифри.\n3)Логін і пароль повинні бути різними.\n\n";

		cout << "Логін: ";
		CheckIsRight(login);

		cout << "Пароль: ";
		CheckIsRight(password);

		isRegistered = true;

		if (login == password) {
			cout << "Логін і пароль повинні бути різними!\n\n";
			Registration();
			return;
		}

		EncryptText(login);
		EncryptText(password);

		cout << "\nРеєстрація пройшла успішно!\n\n";
		system("pause");
		system("cls");
	}
public:
	User() :isRegistered(false), login("NoLogin"), password("NoPassword"), encryption_key(3) {}
	User(const bool& isRegistered, const string& login, const string& password, const int& encryption_key)
		:isRegistered(isRegistered), login(login), password(password), encryption_key(encryption_key) {}

	inline void SetLogin(const string& login)
	{
		this->login = login;
	}
	inline void SetPassword(const string& password)
	{
		this->password = password;
	}
	inline void SetEncryptionKey(const int& key)
	{
		encryption_key = key;
	}
};