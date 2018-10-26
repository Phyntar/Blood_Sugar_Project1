//Week.cpp
//Brandon Endsley

#include "Week.h"
#include "SumList.h"
#include "Day.h"

Week::Week()
{
	max = 0;
	min = 0;
	count = 0;
	total = new SumList();

	day1 = new Day();
	day2 = new Day();
	day3 = new Day();
	day4 = new Day();
	day5 = new Day();
	day6 = new Day();
	day7 = new Day();
}

int Week::getMax()
{
	return max;
}

int Week::getMin()
{
	return min;
}

int Week::getCount()
{
	return count;
}

int Week::getDeltaDay()
{
	return deltaDay;
}

void Week::printWeek()
{
	calcStat();
	cout << "Max Blood Sugar: " << getMax();
	cout << "\nMin Blood Sugar: " << getMin();
	cout << "\nNumber of Inputs: " << getCount();
	cout << " \nTotal i=2147483647: ";
	total->printSum();
	cout << "\nDay with the biggest delta: Day"<<getDeltaDay();
}

Day * Week::getDay(int num)
{
	if (num == 1 || num == 8)
	{
		return day1;
	}
	if (num == 2 || num == 9)
	{
		return day2;
	}
	if (num == 3 || num == 10)
	{
		return day3;
	}
	if (num == 4 || num == 11)
	{
		return day4;
	}
	if (num == 5 || num == 12)
	{
		return day5;
	}
	if (num == 6 || num == 13)
	{
		return day6;
	}
	if (num == 7 || num == 14)
	{
		return day7;
	}
}

void Week::setMax(int in)
{
	max = in;
}

void Week::setMin(int in)
{
	min = in;
}

void Week::setCount(int in)
{
	count = in;
}

void Week::addToSum(SumList * in)
{
	total = total->combineList(in);
}

void Week::calcStat()
{
	int tempMax = 0, tempMin = 2147483647,tempDelta = 0;

	if (day1->getMax() > tempMax)
	{
		tempMax = day1->getMax();
	}

	if (day2->getMax() > tempMax)
	{
		tempMax = day2->getMax();
	}

	if (day3->getMax() > tempMax)
	{
		tempMax = day3->getMax();
	}

	if (day4->getMax() > tempMax)
	{
		tempMax = day4->getMax();
	}

	if (day5->getMax() > tempMax)
	{
		tempMax = day5->getMax();
	}

	if (day6->getMax() > tempMax)
	{
		tempMax = day6->getMax();
	}

	if (day7->getMax() > tempMax)
	{
		tempMax = day7->getMax();
	}

	if (day1->getMin() < tempMin)
	{
		tempMin = day1->getMin();
	}

	if (day2->getMin() < tempMin)
	{
		tempMin = day2->getMin();
	}

	if (day3->getMin() < tempMin)
	{
		tempMin = day3->getMin();
	}

	if (day4->getMin() < tempMin)
	{
		tempMin = day4->getMin();
	}

	if (day5->getMin() < tempMin)
	{
		tempMin = day5->getMin();
	}

	if (day6->getMin() < tempMin)
	{
		tempMin = day6->getMin();
	}

	if (day7->getMin() < tempMin)
	{
		tempMin = day7->getMin();
	}

	count += day1->getCount();
	count += day2->getCount();
	count += day3->getCount();
	count += day4->getCount();
	count += day5->getCount();
	count += day6->getCount();
	count += day7->getCount();

	addToSum(day1->getSum());
	addToSum(day2->getSum());
	addToSum(day3->getSum());
	addToSum(day4->getSum());
	addToSum(day5->getSum());
	addToSum(day6->getSum());
	addToSum(day7->getSum());

	
	if (tempDelta < day2->getCount()-day1->getCount())
	{
		tempDelta = day2->getCount();
		deltaDay = 2;
	}
	if (tempDelta < day3->getCount()-day2->getCount())
	{
		tempDelta = day3->getCount();
		deltaDay = 3;
	}
	if (tempDelta < day4->getCount()-day3->getCount())
	{
		tempDelta = day4->getCount();
		deltaDay = 4;
	}
	if (tempDelta < day5->getCount()-day4->getCount())
	{
		tempDelta = day5->getCount();
		deltaDay = 5;
	}
	if (tempDelta < day6->getCount()-day5->getCount())
	{
		tempDelta = day6->getCount();
		deltaDay = 6;
	}
	if (tempDelta < day7->getCount()-day6->getCount())
	{
		tempDelta = day7->getCount();
		deltaDay = 7;
	}

	max = tempMax;
	min = tempMin;
}