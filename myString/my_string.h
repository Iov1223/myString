#pragma once
#include <iostream>

class my_string
{
public:
	char* myStr;
	my_string();
	my_string(const char* argv);
	~my_string();

	my_string(const my_string& other);

	my_string& operator =(const my_string& other);  

	my_string& operator +(const my_string& other); 

	my_string& operator +=(const my_string& other);

private:
	size_t size;
	void CreateStr(const char* argv);
	
	void Overload(my_string other);
	
};

std::ostream& operator<<(std::ostream& os, const my_string& other);


