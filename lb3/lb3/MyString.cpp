#include "MyString.h"
#include <iostream>
#include <cstring>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

MyString::MyString()
{
	data = nullptr;
	cout << "Default constructor called." << endl;
}

MyString::MyString(const char* str)
{
	data = new char[strlen(str) + 1];
	strcpy_s(data, strlen(str) + 1, str);
	cout << "Parameterized constructor called." << endl;
}

MyString::MyString(const MyString& other)
{
	data = new char[strlen(other.data) + 1];
	strcpy_s(data, strlen(other.data) + 1, other.data);
	cout << "Copy constructor called." << endl;
}

MyString::~MyString()
{
	if (data) {
		delete[] data;
	}
	cout << "Destructor called." << endl;
}

void MyString::set(const char* str)
{
	cout << "Set string";
	data = new char[strlen(str) + 1];
	strcpy_s(data, strlen(str) + 1, str);
}

void MyString::update()
{
    if (data == nullptr) {
        cout << "String is empty. Cannot update." << endl;
        return;
    }

    // ������� ������ ������� �������
    char* spacePos = strchr(data, ' ');

    if (spacePos == nullptr) {
        
        cout << "No space found. Nothing to update." << endl;
        return;
    }

    // �������� ��������� �� ������� �������3
    int length = spacePos - data;
    char* updatedStr = new char[length + 1];
    strncpy_s(updatedStr, length + 1, data, length);
    updatedStr[length] = '\0';

    // ��������� ������ � ����������� �������� � ����
    std::ofstream file("output.txt");
    if (file.is_open()) {
        file << "Old Value: " << data << std::endl;
        file << "Updated Value: " << updatedStr << std::endl;
        file.close();
        cout << "String updated and saved to 'output.txt'." << endl;
    }

    // ����������� ������ �� ������ ������ � ����������� ����� ��������
    delete[] data;
    data = updatedStr;
}

void MyString::print()
{
	if (data) {
		cout << "String: " << data << endl;
	}
	else {
		cout << "String is empty." << endl;
	}
}
