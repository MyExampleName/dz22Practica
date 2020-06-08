#include "Birthday.h"
#include <cstdlib>


Birthday::Birthday()
{
	this->date = Date();
	this->time = Time_(0, 0, 0, "utf");  
}

Birthday::Birthday(Date d, int age, string hero, string place)
{
	this->date = d;
	this->time = Time_(0, 0, 0, "utf");  
	this->age = age;
	this->hero = hero;
	this->place = place;
}

Birthday::~Birthday()
{
}

string Birthday::get_Hero()
{
	return this->hero;
}

string Birthday::get_Place()
{
	return this->place;
}

int Birthday::get_Age()
{
	return this->age;
}

void Birthday::set_Hero(string h)
{
	this->hero = h;
}

void Birthday::set_Place(string p)
{
	this->place = p;
}

void Birthday::set_Age(int a)
{
	this->age = a;
}

void Birthday::show()
{
	cout << "----------------------------------" << endl;
	cout << "Дата: " << this->date << endl;
	cout << endl << "Время: " << this->time << endl;
	cout << endl << "Имя: " << this->hero << endl;
	cout << endl << "Место: " << this->place << endl;
	cout << endl << "Возраст: " << this->age << endl;
	cout <<"----------------------------------" << endl;
}

string Birthday::toString()
{
	char buffer[10];
	_itoa_s(date.getDay(), buffer, 10);
	char buffer1[10];
	_itoa_s(date.getMonth(), buffer1, 10);
	char buffer2[10];
	_itoa_s(date.getYear(), buffer, 10);
	string s = "Дата: ";
	s += date.getDay() + " ";
	s += date.getMonth() + " ";
	s += date.getYear() + " ";
	s += "Время: ";
	s += time.getHour();
	s += time.getMinutes() + " ";
	s += time.getSeconds() + " ";
	s += "hero: "+hero;
	s += "place: " + place;
	s += age;
	return  s;
}

string Birthday::type()
{
	return "Birthday";
}
