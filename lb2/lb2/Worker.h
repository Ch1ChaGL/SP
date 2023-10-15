#include "string"
#pragma once
using namespace std;

class Worker
{
public:
	int age;
	string name;
	string getInfo();
	void eat(double weight);
	double getWeight();
	void dance();
	void walk();
	void work();
private:
	double weight;
	int mood = 10;

};

