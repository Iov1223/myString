#include <iostream>
#include "my_string.h"
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");
	for (int i = 1; i < argc; i++)
	{
		my_string str = my_string(argv[i]);
		cout << str << endl;
	}
	cout << endl;
	my_string str = "Вова, ";
	cout << str << endl;
	my_string str2 = "Коля ";
	cout << str2 << endl;
	my_string str3 = "и ещё Вася ";
	cout << str3 << endl;
	str += str2;
	cout<< "+++++++++++++++++++\n" << str << endl;
	my_string str4 = str + str3;
	cout << "+++++++++++++++++++\n" << str4 << endl;

	
	return 0;
}