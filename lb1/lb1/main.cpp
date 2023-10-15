#include "MyTriangle.h"
#include <iostream>
#include <vector>
#include "string"
using namespace std;
void main() {
	setlocale(LC_ALL, "ru");
	vector<MyTriangle> TriangleStore;
	char a;
	double side = 0;
	double angle = 0;
	int num = 0;
	int triangleNum = 0;
	int answer = 0;
	while (true) {
		cout << "Выберите пункт меню \n1.Добавить треугольник\n2.Увеличить размер треугольника\n3.Уменьшить размер треугольника\n4.Вычислить длинну биссектрисы\n5.Вычислить длинну высоты\n6.Переназначить стороны\n7.Просмотр треугольников\n0.Выйти" << endl;
		cin >> a;
		switch (a)
		{
		case '1': {
			try {
				cout << "Введите боковую сторону треугольника" << endl;
				while (!(cin >> side)) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Ошибка ввода. Пожалуйста, введите число: ";
				}
				cout << "Введите угол при основании" << endl;
				while (!(cin >> angle)) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Ошибка ввода. Пожалуйста, введите число: ";
				}
				MyTriangle a = MyTriangle();
				if (!a.setSide(side)) {
					cout << "Ошибка при вводе стороны" << endl;
					break;
				}
				if (!a.setAngle(angle)) {
					cout << "Ошибка при вводе угла" << endl;
					break;
				}
				a.calc();
				TriangleStore.push_back(a);
			}
			catch (exception e) {
				cout << e.what() << endl;
			}
			break;
		}
		case '2': {
			for (size_t i = 0; i < TriangleStore.size(); i++)
			{
				cout << i << ". " << TriangleStore[i].getInfo() << endl;
			}
			cout << "Выбирите треугольник" << endl;
			while (!(cin >> triangleNum)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Ошибка ввода. Пожалуйста, введите число: ";
			}
			cout << "Введите число в которое хотите увеличить треугольник" << endl;
			while (!(cin >> num)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Ошибка ввода. Пожалуйста, введите число: ";
			}
			TriangleStore[triangleNum].increase(num);
			break;
		}
		case '3': {
			for (size_t i = 0; i < TriangleStore.size(); i++)
			{
				cout << i << ". " << TriangleStore[i].getInfo() << endl;
			}
			cout << "Выбирите треугольник" << endl;
			while (!(cin >> triangleNum)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Ошибка ввода. Пожалуйста, введите число: ";
			}
			cout << "Введите число в которое хотите уменьшить треугольник" << endl;
			while (!(cin >> num)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Ошибка ввода. Пожалуйста, введите число: ";
			}
			TriangleStore[triangleNum].decrease(num);
			break;
		}

		case '4': {
			for (size_t i = 0; i < TriangleStore.size(); i++)
			{
				cout << i << ". " << TriangleStore[i].getInfo() << endl;
			}
			cout << "Выбирите треугольник" << endl;
			while (!(cin >> triangleNum)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Ошибка ввода. Пожалуйста, введите число: ";
			}
			cout << "Выбирите угол: 1.При основании 2.При вершине" << endl;
			while (!(cin >> answer)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Ошибка ввода. Пожалуйста, введите число: ";
			}
			switch (answer)
			{
			case 1: {
				cout << "Биссектриса равна = " + to_string(TriangleStore[triangleNum].calculatingLengthOfBisector(MyTriangle::TriangleBaseAngle)) << endl;
				break;
			}
			case 2: {
				cout << "Биссектриса равна = " + to_string(TriangleStore[triangleNum].calculatingLengthOfBisector(MyTriangle::TriangleApex)) << endl;
				break;
			}
			default:
				break;
			}

			break;
		}

		case '5': {
			for (size_t i = 0; i < TriangleStore.size(); i++)
			{
				cout << i << ". " << TriangleStore[i].getInfo() << endl;
			}
			cout << "Выбирите треугольник" << endl;
			while (!(cin >> triangleNum)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Ошибка ввода. Пожалуйста, введите число: ";
			}
			cout << "Выбирите сторону: 1.Боковая 2.Основание" << endl;
			while (!(cin >> answer)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Ошибка ввода. Пожалуйста, введите число: ";
			}
			switch (answer)
			{
			case 1: {
				cout << "Высота равна = " + to_string(TriangleStore[triangleNum].calculatingLengthHeights(MyTriangle::TriangleSide)) << endl;
				break;
			}
			case 2: {
				cout << "Высота равна = " + to_string(TriangleStore[triangleNum].calculatingLengthHeights(MyTriangle::TriangleBase)) << endl;
				break;
			}
			default:
				break;
			}
			break;
		}

		case '6': {
			for (size_t i = 0; i < TriangleStore.size(); i++)
			{
				cout << i << ". " << TriangleStore[i].getInfo() << endl;
			}
			cout << "Выбирите треугольник" << endl;
			while (!(cin >> triangleNum)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Ошибка ввода. Пожалуйста, введите число: ";
			}
			cout << "Выбирите сторону: 1.Боковая 2.Основание" << endl;
			while (!(cin >> answer)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Ошибка ввода. Пожалуйста, введите число: ";
			}
			cout << "Введите новое значение" << endl;
			while (!(cin >> num)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Ошибка ввода. Пожалуйста, введите число: ";
			}
			if (answer == 1) {
				TriangleStore[triangleNum].determiningSideValues(MyTriangle::TriangleSide, num);
			}
			else if (answer == 2) {
				TriangleStore[triangleNum].determiningSideValues(MyTriangle::TriangleBase, num);
			}
			else {
				cout << "Выбрано не правильное число" << endl;
			}
			break;
		}

		case '7':
			for (size_t i = 0; i < TriangleStore.size(); i++)
			{
				cout << i << ". " << TriangleStore[i].getInfo() << endl;
			}
			break;
		case '0':
			return;
			break;
		default:
			cout << "Ошибка!" << endl;
			return;
			break;
		}
	}
}