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
			else cout << "������� ��� �������!\n������ ��������: ";
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
		grades = { {"����������",{}},{"��������� ����",{}},{"���������",{}} };
	}
	Guest(const string& pib, const string& address, const string& phone_number) : pib(pib), address(address), phone_number(phone_number)
	{
		grades = { {"����������",{}},{"��������� ����",{}},{"���������",{}} };
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
		cout << "ϲ�: ";
		getline(cin, pib);

		cout << "������: ";
		getline(cin, address);

		cout << "����� ��������: ";
		getline(cin, phone_number);
	}
	void show() const
	{
		cout << "ϲ�: " << pib << " | ������: " << address << " | ����� ��������: " << phone_number << "\n������:\n";

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
		cout << "���� � ����������(������ - 6, ������������ ��� - 12):\n";

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

			cout << ++j << ") " << i.first << endl << "���� �������: ";
			cin >> answer;

			if (answer == i.second) {
				cout << "��������� �������!\n\n";
				++kilk_prav;
			}
			else cout << "³������ �� ���������!\n\n";
		}

		int grade = kilk_prav * 2;
		auto i = grades.find("����������");
		i->second.push_back(grade);

		cout << "��� ���: " << grade << endl << "�-��� ���������� ��������: " << kilk_prav << "/6" << endl << "³������ ���������� ��������: " << kilk_prav * 100 / 6 << "%" << endl;
	}
	void UkrTest(const string& path)
	{
		if (!isRegistered) Registration();
		cout << "���� � ��������� ����(������ - 6, ������������ ��� - 12):\n";

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
			cout << ++j << ") " << i.first << endl << "���� �������(a/b): ";
			cin >> text;

			if (text == i.second) {
				cout << "��������� �������!\n\n";
				++kilk_prav;
			}
			else cout << "³������ �� ���������!\n\n";
		}

		int grade = kilk_prav * 2;
		auto i = grades.find("��������� ����");
		i->second.push_back(grade);

		cout << "��� ���: " << grade << endl << "�-��� ���������� ��������: " << kilk_prav << "/6" << endl << "³������ ���������� ��������: " << kilk_prav * 100 / 6 << "%" << endl;
	}
	void GeoTest(const string& path)
	{
		if (!isRegistered) Registration();
		cout << "���� � ���������(������ - 6, ������������ ��� - 12):\n";

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
			cout << ++j << ") " << i.first << endl << "���� �������(a/b): ";
			cin >> answer;

			if (answer == i.second) {
				cout << "��������� �������!\n\n";
				++kilk_prav;
			}
			else cout << "³������ �� ���������!\n\n";
		}

		int grade = kilk_prav * 2;
		auto i = grades.find("���������");
		i->second.push_back(grade);

		cout << "��� ���: " << grade << endl << "�-��� ���������� ��������: " << kilk_prav << "/6" << endl << "³������ ���������� ��������: " << kilk_prav * 100 / 6 << "%" << endl;
	}

	friend istream& operator>>(istream& s, Guest& x)
	{
		cout << "ϲ�: ";
		getline(s, x.pib);

		cout << "������: ";
		getline(s, x.address);

		cout << "����� ��������: ";
		getline(s, x.phone_number);

		return s;
	}
	friend ostream& operator<<(ostream& s, const Guest& x)
	{
		s << "ϲ�: " << x.pib << " | ������: " << x.address << " | ����� ��������: " << x.phone_number << "\n������:\n";

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