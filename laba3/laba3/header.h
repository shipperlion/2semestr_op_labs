#pragma once

#include <iostream>		//Standard libraries
#include <string>
#include <iomanip>

using namespace std;

class TEmployee
{
	string name;		//Atributes
	int day;
	int month;
	int year;

public:
	void setInfo();		//Methods

	string getName() {return name;}

	int getDay() {return day;}

	int getMonth() {return month;}

	int getYear() {return year;}

	void getOldest(TEmployee*, int);
};