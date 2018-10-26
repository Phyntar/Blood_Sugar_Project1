//SumList.h
//Brandon Endsley

#pragma once
#include <iostream>
using std::cout;

// This sum works by filling up an int to max and then rolling the number over every time it fills up and then incrementing a counter
// once the counter fills up it will dynamically add a new counter to count how many times that node rolled over working essentially like a
// base 2,147,483,647 counter that automatically creates new digits as they are needed.

class SumList
{
public:
	SumList();													//constructer intitialises list to val=0 power=0 next= NULL 
	SumList(int data, int inpower, SumList* ptrnext=NULL);		//constructer intitialises list to set val and power but next = null
	void listAdd(int in);										//adds in to the sum automatically tests for overflow 
	void setNext(SumList * in);									//sets the next pointer to a new node
	int getVal();												//returns val
	SumList* getNext();											//returns a pointer to next node
	void printSum();											//prints the sum in form of XI^n + XI^n+1
	SumList* combineList(SumList* rhside);						//adds 2 sums together
private:
	int val;
	int power;
	SumList * next;

};


