#pragma once
#include <iostream>
#include <string>

using namespace std;

class TDate {
protected:
	int day;
	int month;
	int year;
public:
	TDate();
	TDate(int day, int month, int year);
	TDate(string line);
	TDate(TDate& obj);
	int getYear();
	int getMonth();
	int getDay();
	bool operator> (TDate b);
	TDate* increaseDate();
	TDate* decreaseDate();
	void latestDate(TDate* b, int size1, int size2);
	void inInterval(TDate* b, int size1, int size2);
	virtual void showDate();
};

class TDate1 : public TDate
{
public:
	TDate1();
	TDate1(TDate1& obj);
	void showDate() override;
};

class TDate2 : public TDate
{
public:
	TDate2();
	TDate2(TDate2& obj);
	void showDate() override;
};
