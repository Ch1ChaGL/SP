// lb3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    MyString str1;
    str1.set("str1");
    str1.print();

    MyString str2("Hello, World!");
    str2.print();

    MyString str3 = str2; // Copy constructor called
    str3.print();

    str2.update();
    str2.print();

    return 0;
}
