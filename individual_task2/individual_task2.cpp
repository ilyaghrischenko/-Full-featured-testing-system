#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <map>
using namespace std;

typedef map<string, vector<int>> dictionary;
typedef map<string, string> tasks;

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

class Guest :public User {
private:
	string pib;
	string address;
	string phone_number;
	dictionary grades;
public:
	Guest() :pib("NoPib"), address("NoAddress"), phone_number("NoPhoneNumber")
	{
		grades = { {"Математика",{}},{"Українська мова",{}},{"Географія",{}} };
	}
	Guest(const string& pib, const string& address, const string& phone_number) : pib(pib), address(address), phone_number(phone_number)
	{
		grades = { {"Математика",{}},{"Українська мова",{}},{"Географія",{}} };
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
		if (!isRegistered) Registration();
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
		if (!isRegistered) Registration();
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
		if (!isRegistered) Registration();
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
			for (int j : i.second) {
				s << j << ", ";
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
			s << i->first << endl;
			for (auto j = i->second.begin(); j != i->second.end(); ++j) {
				s << *j << endl;
			}
			s << ';' << endl;
		}

		return s;
	}
};

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
			//newGuest.SetEncryptionKey(text);

			file.close();
		}
	}

	void show() const
	{
		for (int i = 0; i < users.size(); ++i) {
			cout << users[i];
		}
	}
};

template<typename T>
void Save(const string& path, const T& obj)
{
	if (!obj.GetIsRegistered()) return;
	fstream file(path, ios::out);
	file << obj;
	file.close();
}

int main()
{
	setlocale(0, "");
	srand((unsigned)time(NULL));
	
	Admin Dima("..\\reg_obj.txt");
	Dima.show();

	cout << endl;
	system("pause");
}