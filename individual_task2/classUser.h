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
			else cout << "������� ��� �������!\n������ ��������: ";
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
		cout << "��������� �����������:\n1)��� ���� � ������ ������� ������ ���� � 1 ������ �����.\n2)��� ���� � ������ ������� ������ ���� � 3 �����.\n3)���� � ������ ������ ���� ������.\n\n";

		cout << "����: ";
		CheckIsRight(login);

		cout << "������: ";
		CheckIsRight(password);

		isRegistered = true;

		if (login == password) {
			cout << "���� � ������ ������ ���� ������!\n\n";
			Registration();
			return;
		}

		EncryptText(login);
		EncryptText(password);

		cout << "\n��������� ������� ������!\n\n";
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