#include <iostream>
using namespace std;

class MyString
{
public:
	char* myStr;
	MyString() 
	{
		myStr = nullptr;
		size = 0;
	}
	MyString(const char *argv)
	{
		CreateStr(argv);
	}
	~MyString()
	{
		delete[] myStr;
	}

	MyString(const MyString& other) // Конструктор копирования 
	{
		size = strlen(other.myStr);
		myStr = new char[size + 1];

		for (size_t i = 0; i < size; i++)
		{
			myStr[i] = other.myStr[i];
		}

		myStr[size] = '\0';
	}

	MyString& operator =(const MyString& other)  // Оператор присваивания
	{
		if (other.myStr != nullptr)
		{
			delete[] myStr;
		}
		CreateStr(other.myStr);
		return *this;
	}
	
	MyString& operator+(const MyString& other) // Oператор сложения
	{
		Overload(other.myStr);
		return *this;
	}

	MyString& operator +=(const MyString& other) // Оператор +=
	{
		Overload(other.myStr);
		return *this;
	}

private:
	size_t size;
	void CreateStr(const char* argv)
	{
		size = strlen(argv);
		myStr = new char[size + 1];
		for (size_t i = 0; i < size; i++)
		{
			myStr[i] = argv[i];
		}
		myStr[size] = '\0';
	}
	void Overload(MyString other)
	{
		size_t _size = size + other.size;
		char* tmp = new char[_size + 1];
		for (size_t i = 0; i < strlen(myStr); i++)
		{
			tmp[i] = myStr[i];
		}
		for (size_t j = 0, i = strlen(myStr); j < strlen(other.myStr); j++, i++)
		{
			tmp[i] = other.myStr[j];
		}
		tmp[_size] = '\0';
		delete[] myStr;
		myStr = tmp;
		size = _size;
	}
};

ostream& operator<<(ostream& os, const MyString& other) { // Перегрузка оператора вывода
	return os << other.myStr;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");
	for (int i = 1; i < argc; i++)
	{
		MyString str = MyString(argv[i]);
		cout << str << endl;
	}
	cout << endl;
	MyString str = "Вова, ";
	cout << str << endl;
	MyString str2 = "Коля ";
	cout << str2 << endl;
	MyString str3 = "и ещё Вася ";
	cout << str3 << endl;
	str += str2;
	cout<< "+++++++++++++++++++\n" << str << endl;
	MyString str4 = str + str3;
	cout << "+++++++++++++++++++\n" << str4 << endl;

	
	return 0;
}