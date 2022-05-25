#include "header.h"

int TDate::getYear() { return year; }
int TDate::getMonth() { return month; }
int TDate::getDay() { return day; }

TDate::TDate() {
	cout << "Object\nDay: "; cin >> day;
	cout << "Month: "; cin >> month;
	cout << "Year: "; cin >> year;
	cout << endl;
}

TDate::TDate(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

TDate::TDate(string line) {
	day = stoi(line.substr(0, 2));
	month = stoi(line.substr(3, 2));
	year = stoi(line.substr(6, 4));
}

TDate::TDate(TDate& obj) {
	day = obj.day;
	month = obj.month;
	year = obj.year;
}

bool TDate::operator>(TDate b)
{
	if (year > b.year)
		return true;
	else if (year < b.year)
		return false;
	else {
		if (month > b.month)
			return true;
		else if (month < b.month)
			return false;
		else {
			if (day > b.day)
				return true;
			else
				return false;
		}
	}
}

TDate* TDate::increaseDate()
{
	int ind, inm, iny, tempd = day, tempm = month, tempy = year;
	cout << "\nBy how much do you want to increase the date? "
		<< "(enter 0 if you don`t want to increase some value)\n";
	cout << "Days: "; cin >> ind;
	cout << "Months: "; cin >> inm;
	cout << "Years: "; cin >> iny;
	int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (day + ind > months[month - 1])
	{
		day = (ind + day) - months[month - 1];
		month++;
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}
	else
		day += ind;
	if (inm + month > 12)
	{
		month = (inm + month) % 12;
		year += (inm + month) / 12;
	}
	else
		month += inm;
	year += iny;
	return this;
}

TDate* TDate::decreaseDate()
{
	int ded, dem, dey, tempd = day, tempm = month, tempy = year;
	cout << "\nBy how much do you want to decrease the date? "
		<< "(enter 0 if you don`t want to decrease some value)\n";
	cout << "Days: "; cin >> ded;
	cout << "Months: "; cin >> dem;
	cout << "Years: "; cin >> dey;
	int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (day - ded < 0)
	{
		if (month != 1)
		{
			day = (day - ded) + months[month - 2];
			month--;
		}
		else {
			day = (day - ded) + months[11];
			month = 12;
			year--;
		}
	}
	else
		day -= ded;
	if (month - dem < 0)
	{
		month = (month - dem) % 12;
		year -= (month - dem) / 12;
	}
	else
		month -= dem;
	year -= dey;
	return this;
}

void TDate::latestDate(TDate* b, int size1, int size2)
{
	TDate latest1(0, 0, 0000), latest2(0, 0, 0000);
	for (int i = 0; i < size1; i++)
	{
		if (this[i] > latest1)
			latest1 = TDate(this[i]);
	}

	for (int i = 0; i < size2; i++)
	{
		if (b[i] > latest2)
			latest2 = TDate(b[i]);
	}

	if (latest1 > latest2)
	{
		cout << "The latest date is "; latest1.showDate();
		cout << endl;
	}
	else
	{
		cout << "The latest date is "; latest2.showDate();
		cout << endl;
	}
}

void TDate::inInterval(TDate* b, int size1, int size2)
{
	int sd, sm, sy, ed, em, ey;
	cout << "Enter the start of the timeline:\n"
		<< "Day: "; cin >> sd;
	cout << "Month: "; cin >> sm;
	cout << "Year: "; cin >> sy;
	cout << "Enter the end of the timeline:\n"
		<< "Day: "; cin >> ed;
	cout << "Month: "; cin >> em;
	cout << "Year: "; cin >> ey;
	TDate starttime(sd, sm, sy), endtime(ed, em, ey);
	cout << "Dates that fall within the timeline:\n";
	for (int i = 0; i < size1; i++)
	{
		if (this[i] > starttime && !(this[i] > endtime))
		{
			this[i].showDate();
			cout << endl;
		}
	}
	for (int i = 0; i < size2; i++)
	{
		if (b[i] > starttime && !(b[i] > endtime))
		{
			b[i].showDate();
			cout << endl;
		}
	}
}

void TDate::showDate()
{
	cout << day << " " << month << " " << year << endl;
}

TDate1::TDate1() :TDate() {}

TDate1::TDate1(TDate1& obj) {
	day = obj.day;
	month = obj.month;
	year = obj.year;
}

void TDate1::showDate()
{
	cout << day << "." << month << "." << year << endl;
}

TDate2::TDate2() :TDate() {}
TDate2::TDate2(TDate2& obj) {
	day = obj.day;
	month = obj.month;
	year = obj.year;
}

void TDate2::showDate()
{
	cout << month << "-" << day << "-" << year << endl;
}