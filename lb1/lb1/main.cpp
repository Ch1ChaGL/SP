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
		cout << "�������� ����� ���� \n1.�������� �����������\n2.��������� ������ ������������\n3.��������� ������ ������������\n4.��������� ������ �����������\n5.��������� ������ ������\n6.������������� �������\n7.�������� �������������\n0.�����" << endl;
		cin >> a;
		switch (a)
		{
		case '1': {
			try {
				cout << "������� ������� ������� ������������" << endl;
				while (!(cin >> side)) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "������ �����. ����������, ������� �����: ";
				}
				cout << "������� ���� ��� ���������" << endl;
				while (!(cin >> angle)) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "������ �����. ����������, ������� �����: ";
				}
				MyTriangle a = MyTriangle();
				if (!a.setSide(side)) {
					cout << "������ ��� ����� �������" << endl;
					break;
				}
				if (!a.setAngle(angle)) {
					cout << "������ ��� ����� ����" << endl;
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
			cout << "�������� �����������" << endl;
			while (!(cin >> triangleNum)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "������ �����. ����������, ������� �����: ";
			}
			cout << "������� ����� � ������� ������ ��������� �����������" << endl;
			while (!(cin >> num)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "������ �����. ����������, ������� �����: ";
			}
			TriangleStore[triangleNum].increase(num);
			break;
		}
		case '3': {
			for (size_t i = 0; i < TriangleStore.size(); i++)
			{
				cout << i << ". " << TriangleStore[i].getInfo() << endl;
			}
			cout << "�������� �����������" << endl;
			while (!(cin >> triangleNum)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "������ �����. ����������, ������� �����: ";
			}
			cout << "������� ����� � ������� ������ ��������� �����������" << endl;
			while (!(cin >> num)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "������ �����. ����������, ������� �����: ";
			}
			TriangleStore[triangleNum].decrease(num);
			break;
		}

		case '4': {
			for (size_t i = 0; i < TriangleStore.size(); i++)
			{
				cout << i << ". " << TriangleStore[i].getInfo() << endl;
			}
			cout << "�������� �����������" << endl;
			while (!(cin >> triangleNum)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "������ �����. ����������, ������� �����: ";
			}
			cout << "�������� ����: 1.��� ��������� 2.��� �������" << endl;
			while (!(cin >> answer)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "������ �����. ����������, ������� �����: ";
			}
			switch (answer)
			{
			case 1: {
				cout << "����������� ����� = " + to_string(TriangleStore[triangleNum].calculatingLengthOfBisector(MyTriangle::TriangleBaseAngle)) << endl;
				break;
			}
			case 2: {
				cout << "����������� ����� = " + to_string(TriangleStore[triangleNum].calculatingLengthOfBisector(MyTriangle::TriangleApex)) << endl;
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
			cout << "�������� �����������" << endl;
			while (!(cin >> triangleNum)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "������ �����. ����������, ������� �����: ";
			}
			cout << "�������� �������: 1.������� 2.���������" << endl;
			while (!(cin >> answer)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "������ �����. ����������, ������� �����: ";
			}
			switch (answer)
			{
			case 1: {
				cout << "������ ����� = " + to_string(TriangleStore[triangleNum].calculatingLengthHeights(MyTriangle::TriangleSide)) << endl;
				break;
			}
			case 2: {
				cout << "������ ����� = " + to_string(TriangleStore[triangleNum].calculatingLengthHeights(MyTriangle::TriangleBase)) << endl;
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
			cout << "�������� �����������" << endl;
			while (!(cin >> triangleNum)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "������ �����. ����������, ������� �����: ";
			}
			cout << "�������� �������: 1.������� 2.���������" << endl;
			while (!(cin >> answer)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "������ �����. ����������, ������� �����: ";
			}
			cout << "������� ����� ��������" << endl;
			while (!(cin >> num)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "������ �����. ����������, ������� �����: ";
			}
			if (answer == 1) {
				TriangleStore[triangleNum].determiningSideValues(MyTriangle::TriangleSide, num);
			}
			else if (answer == 2) {
				TriangleStore[triangleNum].determiningSideValues(MyTriangle::TriangleBase, num);
			}
			else {
				cout << "������� �� ���������� �����" << endl;
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
			cout << "������!" << endl;
			return;
			break;
		}
	}
}