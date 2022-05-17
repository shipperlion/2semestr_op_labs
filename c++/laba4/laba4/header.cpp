#include "header.h"

void TDate::setDate()
{
	cout << "Day: "; cin >> day;
	cout << "Month: "; cin >> month;
	cout << "Year: "; (cin >> year).ignore();
}

void TDate::untilTheEnd()
{
	int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int left = months[month - 1] - day;
	for (int i = month; i < 12; i++)
	{
		left += months[i];
	}
	if (!(year % 4) && month < 3)
		left++;

	cout << left;
	if (left == 1)
		cout << " day\n";
	else
		cout << " days\n";
}

TDate TDate::operator++()
{
	if (month == 12)
	{
		year++;
		month = 1;
	}
	else
		month++;
	return *this;
}

TDate TDate::operator++(int)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day == 31) {
			if (month == 12)
			{
				year++;
				day = 1;
				month = 1;
			}
			else {
				day = 1;
				month++;
			}
		}
		else
			day++;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day == 30) {
			if (month == 12)
			{
				year++;
				day = 1;
				month = 1;
			}
			else {
				day = 1;
				month++;
			}
		}
		else
			day++;
	}
	return *this;
}

bool TDate::operator>(TDate date2)
{
	if (year > date2.year)
		return true;
	else if (year < date2.year)
		return false;
	else
	{
		if (month > date2.month)
			return true;
		else if (month < date2.month)
			return false;
		else
		{
			if (day > date2.day)
				return true;
			else
				return false;
		}
	}
}