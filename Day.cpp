//Day.cpp
//Brandon Endsley

#include "Day.h"
#include "SumList.h"


Day::Day()
{
	min = 3001;
	max = 0;
	count = 0;
	total = new SumList();
}

int Day::getMax()
{
	return max;
}

int Day::getMin()
{
	return min;
}

int Day::getCount()
{
	return count;
}

SumList * Day::getSum()
{
	return total;
}

void Day::inputData(int in)
{
	if (in < 0)
	{
		cout << "Reading not in possible range";
	}
	else
	{
		setCount(count + 1);

		if (min > in)
		{
			setMin(in);
		}
		if (max < in)
		{
			setMax(in);
		}
		total->listAdd(in);
	}
}

void Day::printAll()
{
	cout << "Max Blood Sugar: " << getMax();
	cout << "\nMin Blood Sugar: " << getMin();
	cout << "\nNumber of Inputs: " << getCount();
	cout << " \nTotal i=2147483647: ";
	total->printSum();

}

void Day::setMax(int in)
{
	max = in;
}

void Day::setMin(int in)
{
	min = in;
}

void Day::setCount(int in)
{
	count = in;
}

void Day::addToSum(int in)
{
	total->listAdd(in);
}