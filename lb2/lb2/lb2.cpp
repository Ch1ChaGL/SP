// lb2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "string"
#include "Worker.h"


using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	int age = 0;
	string name = "";
	Worker* wrk1 = new Worker();
	
	cout << "Введите имя" << endl;
	cin >> name;
	cout << "Введите возраст" << endl;
	cin >> age;
	cout << "-------1------" << endl;
	wrk1->name = name;
	wrk1->age = age;

	wrk1->eat(2);
	wrk1->eat(3);
	cout << wrk1->getInfo() << endl;

	cout << "-------2------" << endl;
	wrk1->eat(15);
	cout << wrk1->getInfo() << endl;

	cout << "-------3------" << endl;
	wrk1->eat(15);
	cout << wrk1->getInfo() << endl;

	cout << "-------4------" << endl;
	for (int i = 0; i < 100; i++) {
		wrk1->work();
	}
	cout << wrk1->getInfo() << endl;
}

