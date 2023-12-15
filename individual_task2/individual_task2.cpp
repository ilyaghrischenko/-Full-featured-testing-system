#include <fstream>
#include "classUser.h"
#include "classGuest.h"
#include "classAdmin.h"
#include <ctime>
using namespace std;

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