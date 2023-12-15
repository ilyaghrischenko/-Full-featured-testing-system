#include <fstream>
#include "classUser.h"
#include "classGuest.h"
#include "classAdmin.h"
#include <ctime>
using namespace std;

vector<Guest> GetArrFile(const string& path)
{
	vector<Guest> arr;



	return arr;
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