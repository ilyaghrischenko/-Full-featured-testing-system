#include <fstream>
#include "classUser.h"
#include "classGuest.h"
#include "classAdmin.h"
#include <ctime>
using namespace std;

int main()
{
	setlocale(0, "");
	srand((unsigned)time(NULL));

	Guest ilya("pib", "address", "+347328572");
	ilya.MathTest("..\\Tests\\Mathematics\\test1.txt");
	Save("..\\reg_obj.txt", ilya);

	Admin Dima("..\\reg_obj.txt");
	Dima.show();

	fstream file("..\\reg_obj.txt", ios::out);
	file.close();

	cout << endl;
	system("pause");
}