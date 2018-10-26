//Week.h
//Brandon Endsley

#pragma once
#include <iostream>
#include "SumList.h"
#include "Day.h"
using std::cout;



class Week
{
public:
	Week();
	int getMax();
	int getMin();
	int getCount();
	int getDeltaDay();
	void printWeek();
	Day * getDay(int num);

	void setMax(int in);
	void setMin(int in);
	void setCount(int in);
	void addToSum(SumList * in);
	void calcStat();

private:
	int max;
	int min;
	int count;
	int deltaDay;
	SumList * total;

	Day * day1;
	Day * day2;
	Day * day3;
	Day * day4;
	Day * day5;
	Day * day6;
	Day * day7;
};


