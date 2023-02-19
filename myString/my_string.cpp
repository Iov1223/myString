#include "my_string.h"

my_string::my_string()
{
	myStr = nullptr;
	size = 0;
}

my_string::my_string(const char* argv)
{
	CreateStr(argv);
}

my_string::~my_string()
{
	delete[] myStr;
}

my_string::my_string(const my_string& other)
{
	size = strlen(other.myStr);
	myStr = new char[size + 1];

	for (size_t i = 0; i < size; i++)
	{
		myStr[i] = other.myStr[i];
	}

	myStr[size] = '\0';
}

my_string& my_string::operator=(const my_string& other)
{
	if (other.myStr != nullptr)
	{
		delete[] myStr;
	}
	CreateStr(other.myStr);
	return *this;
}

my_string& my_string::operator+(const my_string& other)
{
	Overload(other.myStr);
	return *this;
}

my_string& my_string::operator+=(const my_string& other)
{
	 Overload(other.myStr);
	 return *this;
}

void my_string::CreateStr(const char* argv)
{
	size = strlen(argv);
	myStr = new char[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		myStr[i] = argv[i];
	}
	myStr[size] = '\0';
}

void my_string::Overload(my_string other)
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

std::ostream& operator<<(std::ostream& os, const my_string& other)
{
	return os << other.myStr;
}
