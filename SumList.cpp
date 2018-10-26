//SumList.cpp
//Brandon Endsley

#include "SumList.h"

SumList::SumList()
{
	val = 0;
	power = 0;
	next = NULL;
}

SumList::SumList(int data, int inpower, SumList * ptrnext)
{
	val = data;
	power = inpower;
	next = ptrnext;
}

void SumList::listAdd(int in)
{
	if (in < (2147483647 - val))			//tests if the input is less than the remaining space in the int
	{
		val += in;
	}
	else if (in == NULL)
	{
											//does nothing if in is NULL
	}
	else
	{
		if (next != NULL)					//if the next node exists, add 1 to it
		{
			in = in - (2147483647 - val);	//subtracts the amount that would fit in the original int and sets the value equal to the remainder
			val = in;
			next->listAdd(1);
		}
		else								//if the next node doesnt exist it is created and has the power variable set to power+1 and the val = 1
		{
			in = in - (2147483647 - val);
			val = in;
			next = new SumList(1, power + 1, NULL);
		}
	}
}

void SumList::setNext(SumList * in)
{
	next = in;
}

int SumList::getVal()
{
	return val;
}

SumList * SumList::getNext()
{
	return next;
}

void SumList::printSum()
{
	/*
	if (power == 0)
	{
		cout << "i=2147483647\n\n";
	}
	*/
	cout << getVal() << "*i^"<<power;

	if (next != NULL)
	{
		cout << " + ";
		next->printSum();
	}
}

SumList * SumList::combineList(SumList * rhside)
{
	bool l1= false, l2 = false;
	int power=0;

	SumList * newSum = new SumList();
	SumList *temp = newSum;
	SumList *lhside= this;


	while (l1 == false && l2 == false)						//l1 and l2 test if the next node in each list exists
	{
		if (rhside != NULL)									// if the current item exists it is added to the list at the current order of magnitude else sets l1 to true
		{
			temp->listAdd(rhside->getVal());
			rhside = rhside->getNext();
		}
		else
		{
			l1 = true;
		}

		if (lhside != NULL)									// if the current item exists it is added to the list at the current order of magnitude else sets l2 to true
		{
			temp->listAdd(lhside->getVal());
			lhside = lhside->getNext();
		}
		else
		{
			l2 = true;
		}

		if (rhside != NULL || lhside != NULL)				//
		{
			power++;
			temp->setNext(new SumList(0, power, NULL));
			temp = temp->getNext();
		}
	}
	
	
	return newSum;
}