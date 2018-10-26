//Project1.cpp
//Brandon Endsley

#include <iostream>
#include <string>
#include "SumList.h"
#include "Day.h"
#include "Week.h"

using std::cout;
using std::cin;
using std::string;
using std::stoi;

int main()
{
	Week * week1 = new Week();
	Week * week2 = new Week();
	string input;
	int num;
	int daycounter = 1;
	while (true)
	{
		cout << "\nPlease input a Blood Sugar Reading (mg/dl): ";
		cin >> input;

		if (input._Equal("D") || input._Equal("Day") || input._Equal("d") || input._Equal("day"))
		{
			cout << "* * * * * * Summary for Day" << daycounter << " * * * * * *\n\n";
			if (daycounter < 8)
			{
				week1->getDay(daycounter)->printAll();
			}
			if (daycounter >= 8 && daycounter < 15)
			{
				week2->getDay(daycounter)->printAll();
			}
		}
		else if (input._Equal("W") || input._Equal("w") || input._Equal("Week"))
		{
			if (daycounter < 8)
			{
				cout << "* * * * * * Summary for Week1 * * * * * *\n\n";
				week1->printWeek();
			}
			if (daycounter >= 8 && daycounter < 15)
			{
				cout << "* * * * * * Summary for Week2 * * * * * *\n\n";
				week2->printWeek();
			}
		}
		else if (input._Equal("N") || input._Equal("n") || input._Equal("Next") || input._Equal("next"))
		{
			if (daycounter < 14)
			{
				daycounter++;
			}
			else
			{
				daycounter = 1;
			}
			cout << "switching to next day\n";
		}
		else
		{
			num = stoi(input);
			if (num > 0)
			{
				if (daycounter < 8)
				{
					week1->getDay(daycounter)->inputData(num);
				}
				if (daycounter >= 8 && daycounter < 15)
				{
					week2->getDay(daycounter)->inputData(num);
				}



			}
		}
	}

	cout << "\n";




	system("pause");
	return 0;
}
