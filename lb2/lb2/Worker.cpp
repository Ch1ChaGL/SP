#include "Worker.h"
#include <string>
using namespace std;
string Worker::getInfo()
{
	string age = "Возраст: " + to_string(this->age) + "\n";
	string name = "Имя: " + this->name + "\n";
	string mood = "Настроение: " + to_string(this->mood) + "\n";
	string weight = "Вес: " + to_string(this->weight) + "\n";
	return name + age + mood + weight;
}

void Worker::eat(double weight)
{
	if (weight >= 10) {
		this->age += 1;
		this->weight += weight / 2;
	}
	else {
		this->weight += weight;
	}
	walk();
	walk();
	dance();
	dance();
	dance();
}

double Worker::getWeight()
{
	return this->weight;
}

void Worker::dance()
{
	this->mood += 2;
}

void Worker::walk()
{
	this->mood += 1;
}

void Worker::work()
{
	if (this->mood - 2 < 0) this->mood = 0;
	else this->mood -= 2;
}
