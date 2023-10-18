#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
class MyString
{
private:
	char* data;
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	~MyString();
	void set(const char* str);
	void update();
	void print();
};

