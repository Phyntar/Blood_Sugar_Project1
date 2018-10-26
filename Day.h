//Day.h
//Brandon Endsley

#pragma once
#include <iostream>
#include "SumList.h"
using std::cout;



class Day
{
public:
	Day();
	int getMax();
	int getMin();
	int getCount();
	SumList * getSum();
	void printAll();

	void inputData(int in);
	void setMax(int in);
	void setMin(int in);
	void setCount(int in);
	void addToSum(int in);

private:
	int max;
	int min;
	int count;
	SumList * total;
};


