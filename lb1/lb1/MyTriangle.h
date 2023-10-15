#include "string"
#pragma once
class MyTriangle {
public:
	static enum Side { TriangleSide, TriangleBase };
	static enum Angle { TriangleApex, TriangleBaseAngle };
	void increase(int a);
	void decrease(int a);
	double calculatingLengthOfBisector(Angle angle);
	double calculatingLengthHeights(Side side);
	bool determiningSideValues(Side side, int size);
	MyTriangle(double side, double angle);
	MyTriangle();
	bool setSide(double side);
	bool setAngle(double angle);
	bool calc();
	double getBase();
	double getSide();
	double getbaseAngle();
	double getApexAngle();
	std::string getInfo();
private:
	double side;
	double base;
	double baseAngle;
	double apexAngle;
	double getBaseSide(double side, double angle);
	double _getSide(double base, double angle);
	double toRadians(double angle);
};



