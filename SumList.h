//SumList.h
//Brandon Endsley

#pragma once
#include <iostream>
using std::cout;


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


