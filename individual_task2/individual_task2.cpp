#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <map>
using namespace std;

typedef map<string, vector<int>> dictionary;
typedef map<string, int> tasks;
typedef map<string, char> mas;

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

	void MathTest()
	{
		if (!isRegistered) Registration();
		cout << "���� � ����������(������ - 6, ������������ ��� - 12):\n";

		tasks arr;
		for (int i = 0; i < 6; ++i) {
			int x = rand() % 15 - 5;
			int y = rand() % 10 - 5;
			string str_x = to_string(x);
			string str_y = to_string(y);
			arr.insert({ str_x + " * " + str_y, x * y });
		}

		int j = 0;
		int kilk_prav = 0;
		for (auto i : arr) {
			int answer = 0;

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
	}
	void UkrTest()
	{
		if (!isRegistered) Registration();
		cout << "���� � ��������� ����(������ - 6, ������������ ��� - 12):\n";

		mas arr;
		arr.insert({ "�)������/b)�����",'a'});
		arr.insert({ "�)����������/b)����������",'b'});
		arr.insert({ "�)��������/b)��������",'a'});
		arr.insert({ "�)�����/b)�����",'a'});
		arr.insert({ "�)������������/b)������������",'a' });
		arr.insert({ "�)�������/b)�������",'b' });

		int j = 0;
		int kilk_prav = 0;
		for (auto i : arr) {
			char text;
			cout << ++j << ") " << i.first << "?" << endl << "���� �������(a/b): ";
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
	}
	void GeoTest()
	{
		if (!isRegistered) Registration();
		cout << "���� � ���������(������ - 6, ������������ ��� - 12):\n";

		mas arr;
		arr.insert({ "���������� ����� ����? a)������/b)���",'b' });
		arr.insert({ "�������� ����� � ���? a)������/b)�������",'b' });
		arr.insert({ "�-��� ��������? a)7/b)6",'a' });
		arr.insert({ "��� �������� ������ ��䳿? a)����/b)����",'b' });
		arr.insert({ "ǳ ������� ����� ����������� �������� �����? a)50/b)48",'a' });
		arr.insert({ "��� ������� �������, �������� �������? a)�������� ����/b)����� �����",'b' });

		int j = 0;
		int kilk_prav = 0;
		for (auto i : arr) {
			char answer;
			cout << ++j << ") " << i.first << endl << "���� �������(a/b): ";
			cin >> answer;

			if (answer == i.second) {
				cout << "��������� �������!\n\n";
				++kilk_prav;
			}
			else cout << "³������ �� ���������!\n\n";

			int grade = kilk_prav * 2;
			auto i = grades.find("���������");
			i->second.push_back(grade);
		}
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
	size_t size;
	string path;
public:
	Admin() :size(3), path("NoPath"), users(vector<Guest>())
	{
		fstream file(path, ios::in);

		file >> *this;

		file.close();
	}
	Admin(const string& path) :path(path), size(3), users(vector<Guest>())
	{
		fstream file(path, ios::in);

		file >> *this;

		file.close();
	}

	inline size_t GetSize() const
	{
		return size;
	}

	inline void show() const
	{
		for (int i = 0; i < size; ++i) {
			cout << ++i << ")\n" << users[i];
		}
	}

	friend fstream& operator>>(fstream& s, Admin& obj) {
		string text;
		while (getline(s, text)) {
			Guest newGuest;
			newGuest.SetPib(text);

			getline(s, text);
			newGuest.SetAddress(text);

			getline(s, text);
			newGuest.SetPhoneNumber(text);

			getline(s, text);
			newGuest.SetLogin(text);

			getline(s, text);
			newGuest.SetPassword(text);

			int key = 0;
			s >> key;
			newGuest.SetEncryptionKey(key);
			s.ignore();

			while (getline(s, text)) {
				if (text == ";") {
					break;
				}
				else {
					string subject = text;
					getline(s, text);
					int grade = stoi(text);
					newGuest.GetGrades()[subject].push_back(grade);
				}
			}

			obj.users.push_back(newGuest);
		}

		obj.size = obj.users.size();

		return s;
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
	
	Guest Illya("pib", "address", "+380970878346");
	Save<Guest>("reg_obj.txt", Illya);

	Admin ILLYA("reg_obj.txt");
	ILLYA.show();

	cout << endl;
	system("pause");
}