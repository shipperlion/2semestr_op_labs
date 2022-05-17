#pragma once

#include <iostream>

using namespace std;

class TDate
{
	int day;
	int month;
	int year;

public:
	TDate() {
		day = 1;
		month = 1;
		year = 1970;
	}

	TDate(TDate& obj) {
		day = obj.day;
		month = obj.month;
		year = obj.year;
	}

	TDate(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}

	void setDate();

	int getDay() { return day; }

	int getMonth() { return month; }

	int getYear() { return year; }

	void untilTheEnd();

	TDate operator++();

	TDate operator++(int);

	bool operator>(TDate date2);
};