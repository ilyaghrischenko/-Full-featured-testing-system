#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "classUser.h"

typedef map<string, vector<int>> dictionary;
typedef map<string, string> tasks;

class Admin;
class Guest :public User {
private:
	string pib;
	string address;
	string phone_number;
	dictionary grades;
	friend class Admin;
public:
	Guest() :pib("NoPib"), address("NoAddress"), phone_number("NoPhoneNumber")
	{
		grades = { {"Mathematics",{}},{"Ukrainian",{}},{"Geography",{}} };
		Registration();
	}
	Guest(const string& pib, const string& address, const string& phone_number, const dictionary& grades, const bool& isRegistered, const string& login, const string& password, const int& encryption_key)
		:User(isRegistered, login, password, encryption_key),
		 pib(pib), address(address), phone_number(phone_number), grades(grades) {}
	Guest(const string& pib, const string& address, const string& phone_number) : pib(pib), address(address), phone_number(phone_number)
	{
		grades = { {"Mathematics",{}},{"Ukrainian",{}},{"Geography",{}} };
		Registration();
	}
	Guest(const Guest& x)
	{
		pib = x.pib;
		address = x.address;
		phone_number = x.phone_number;
		grades = x.grades;
	}
	Guest(Guest&& x) noexcept
	{
		pib = x.pib;
		address = x.address;
		phone_number = x.phone_number;

		grades = x.grades;
		x.grades.clear();
	}
	Guest& operator=(const Guest& x)
	{
		if (this != &x) {
			grades.clear();
			grades = x.grades;
			pib = x.pib;
			address = x.address;
			phone_number = x.phone_number;
		}
		return *this;
	}

	inline bool GetIsRegistered() const
	{
		return isRegistered;
	}

	inline string GetPib() const
	{
		return pib;
	}
	inline void SetPib(const string& pib)
	{
		this->pib = pib;
	}

	inline string GetAddress() const
	{
		return address;
	}
	inline void SetAddress(const string& address)
	{
		this->address = address;
	}

	inline string GetPhoneNumber() const
	{
		return phone_number;
	}
	inline void SetPhoneNumber(const string& phone_number)
	{
		this->phone_number = phone_number;
	}

	inline dictionary GetGrades() const
	{
		return grades;
	}
	inline void SetGrades(dictionary& arr)
	{
		for (auto i = arr.begin(); i != arr.end(); ++i) {
			grades[i->first] = {};
			for (auto j = i->second.begin(); j != i->second.end(); ++j) {
				grades[i->first].push_back(*j);
			}
		}
	}

	inline void input()
	{
		cout << "ПІБ: ";
		getline(cin, pib);

		cout << "Адреса: ";
		getline(cin, address);

		cout << "Номер телефону: ";
		getline(cin, phone_number);
	}
	void show() const
	{
		cout << "ПІБ: " << pib << " | Адреса: " << address << " | Номер телефону: " << phone_number << "\nОцінки:\n";

		for (auto i : grades) {
			cout << i.first << ": ";
			for (int j : i.second) {
				cout << j << ", ";
			}
			cout << endl;
		}

		cout << endl;
	}

	void MathTest(const string& path)
	{
		cout << "Тест з математики(питань - 6, максимальний бал - 12):\n";

		fstream file(path, ios::in);
		tasks arr;

		string key;
		string val;
		while (getline(file, key).good()) {
			getline(file, val);
			arr.insert({ key,val });
		}
		file.close();

		int j = 0;
		int kilk_prav = 0;
		for (auto i : arr) {
			string answer;

			cout << ++j << ") " << i.first << endl << "Ваша відповідь: ";
			cin >> answer;

			if (answer == i.second) {
				cout << "Правильна відповідь!\n\n";
				++kilk_prav;
			}
			else cout << "Відповідь не правильна!\n\n";
		}

		int grade = kilk_prav * 2;
		auto i = grades.find("Математика");
		i->second.push_back(grade);

		cout << "Ваш бал: " << grade << endl << "К-сть правильних відповідей: " << kilk_prav << "/6" << endl << "Відсоток правильних відповідей: " << kilk_prav * 100 / 6 << "%" << endl;
	}
	void UkrTest(const string& path)
	{
		cout << "Тест з української мови(питань - 6, максимальний бал - 12):\n";

		fstream file(path, ios::in);
		tasks arr;
		string key;
		string val;
		while (getline(file, key).good()) {
			getline(file, val);
			arr.insert({ key,val });
		}
		file.close();

		int j = 0;
		int kilk_prav = 0;
		for (auto i : arr) {
			string text;
			cout << ++j << ") " << i.first << endl << "Ваша відповідь(a/b): ";
			cin >> text;

			if (text == i.second) {
				cout << "Правильна відповідь!\n\n";
				++kilk_prav;
			}
			else cout << "Відповідь не правильна!\n\n";
		}

		int grade = kilk_prav * 2;
		auto i = grades.find("Українська мова");
		i->second.push_back(grade);

		cout << "Ваш бал: " << grade << endl << "К-сть правильних відповідей: " << kilk_prav << "/6" << endl << "Відсоток правильних відповідей: " << kilk_prav * 100 / 6 << "%" << endl;
	}
	void GeoTest(const string& path)
	{
		cout << "Тест з географії(питань - 6, максимальний бал - 12):\n";

		fstream file(path, ios::in);
		tasks arr;
		string key;
		string val;
		while (getline(file, key).good()) {
			getline(file, val);
			arr.insert({ key,val });
		}
		file.close();

		int j = 0;
		int kilk_prav = 0;
		for (auto i : arr) {
			string answer;
			cout << ++j << ") " << i.first << endl << "Ваша відповідь(a/b): ";
			cin >> answer;

			if (answer == i.second) {
				cout << "Правильна відповідь!\n\n";
				++kilk_prav;
			}
			else cout << "Відповідь не правильна!\n\n";
		}

		int grade = kilk_prav * 2;
		auto i = grades.find("Географія");
		i->second.push_back(grade);

		cout << "Ваш бал: " << grade << endl << "К-сть правильних відповідей: " << kilk_prav << "/6" << endl << "Відсоток правильних відповідей: " << kilk_prav * 100 / 6 << "%" << endl;
	}

	friend istream& operator>>(istream& s, Guest& x)
	{
		cout << "ПІБ: ";
		getline(s, x.pib);

		cout << "Адреса: ";
		getline(s, x.address);

		cout << "Номер телефону: ";
		getline(s, x.phone_number);

		return s;
	}
	friend ostream& operator<<(ostream& s, const Guest& x)
	{
		s << "ПІБ: " << x.pib << " | Адреса: " << x.address << " | Номер телефону: " << x.phone_number << "\nОцінки:\n";

		for (auto i : x.grades) {
			s << i.first << ": ";
			for (int j = 0; j < i.second.size(); ++j) {
				s << i.second[j] << ", ";
			}
			s << endl;
		}

		s << endl;

		return s;
	}

	friend fstream& operator<<(fstream& s, const Guest& x)
	{
		s << x.pib << endl << x.address << endl << x.phone_number << endl << x.login << endl << x.password << endl << x.encryption_key << endl;
		for (auto i = x.grades.begin(); i != x.grades.end(); ++i) {
			if (i->second.size() == 0) continue;
			s << i->first << endl;
			for (auto j = i->second.begin(); j != i->second.end(); ++j) {
				s << *j << endl;
			}
			s << ';' << endl;
		}

		return s;
	}
};

void Save(const string& path, const Guest& obj)
{
	if (!obj.GetIsRegistered()) return;
	fstream file(path, ios::out);
	file << obj;
	file.close();
}