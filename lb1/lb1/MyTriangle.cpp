#include "MyTriangle.h"
#define _USE_MATH_DEFINES
#include "cmath"
#include "string"
#include "math.h"
using namespace std;

MyTriangle::MyTriangle(double side, double angle) {
	if (angle >= 90) throw exception("Ошибка при создании треугольника, угол при основании может быть только меньше 90");
	this->side = side;
	this->baseAngle = angle;
	this->apexAngle = 180 - angle*2;
	this->base = this->getBaseSide(side, apexAngle);
}
MyTriangle::MyTriangle(){}

bool MyTriangle::setSide(double side)
{
	if (side <= 0) return false;
	this->side = side;
	return true;
}

bool MyTriangle::setAngle(double angle)
{
	if (angle <= 0) return false;
	this->baseAngle = angle;
	return true;
}

bool MyTriangle::calc()
{
	try {
		this->apexAngle = 180 - this->baseAngle * 2;
		this->base = this->getBaseSide(side, apexAngle);
		return true;
	}
	catch (exception e) {
		return false;
	}

}

double MyTriangle::getBase()
{
	return this->base;
}

double MyTriangle::getSide()
{
	return this->side;
}

double MyTriangle::getbaseAngle()
{
	return this->baseAngle;
}

double MyTriangle::getApexAngle()
{
	return this->apexAngle;
}

string MyTriangle::getInfo()
{
	string a = "Боковая сторона = " + to_string(this->side); + "см";
	string b = "Основание = " + to_string(this->base); +"см";
	string c = "Угол при вершине = " + to_string(this->apexAngle); +"градусов";
	string d = "Угол при основание = " + to_string(this->baseAngle); +"градусов";

	return a + "\n" + b + "\n" + c + "\n" + d + "\n";
}

double MyTriangle::getBaseSide(double side, double angle) {
	double a = cos(this->toRadians(angle));
	return sqrt(pow(side, 2) + pow(side, 2) - 2 * side * side * cos(this->toRadians(angle)));
}

double MyTriangle::_getSide(double base, double angle)
{
	return (base / (2 * cos(toRadians(angle))));
}

double MyTriangle::toRadians(double angle)
{
	return angle * M_PI / 180;
}

void MyTriangle::increase(int size) {
	this->side = this->side * size;
	this->base = this->base * size;
}

void MyTriangle::decrease(int size) {
	this->side = this->side / size;
	this->base = this->base / size;
}

double MyTriangle::calculatingLengthOfBisector(Angle angle)
{
	if (angle == MyTriangle::TriangleApex) {
		return (((2 * side * side) * (cos(this->toRadians((this->apexAngle / 2))))) / (side + side));
	}
	if (angle == MyTriangle::TriangleBaseAngle) {
		return (((2 * side * base) * (cos(this->toRadians((this->baseAngle / 2))))) / (base + side));
	}
	else return -1;
}

double MyTriangle::calculatingLengthHeights(Side side)
{
	double p = ((this->side + this->side + this->base) / 2);

	if (side == MyTriangle::TriangleBase) {
		return ((2 * sqrt(p*(p - this->side)*(p - this->side)*(p-base))) / (base));
	}
	if (side == MyTriangle::TriangleSide) {
		return ((2 * sqrt(p * (p - this->side) * (p - this->side) * (p - base))) / (this->side));
	}
	else return -1;
}

bool MyTriangle::determiningSideValues(Side side, int size)
{
	if (side == MyTriangle::TriangleBase) {
		// Изменяем значение основания и пересчитываем боковые стороны и угол
		this->base = size;
		this->side = this->_getSide(base, baseAngle);
		return true;
	}
	if (side == MyTriangle::TriangleSide) {
		this->side = size;
		this->base = this->getBaseSide(size, this->apexAngle);
		return true;
	}
	else return false;
}

