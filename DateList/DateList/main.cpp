// DateList.cpp : Defines the entry point for the console application.
// CST116SRS05
// Wendell Abigania

#include "stdafx.h"
#include <iostream>
#include <iomanip>


int main()
{
	int d1, m1, y1, d2, m2, y2;
	int dim; //Days in month, will update during each loop based on the month that needs checking.

	const int JAN = 1;
	const int FEB = 2;
	const int NOT_LEAP_DAYS = 28;
	const int LEAP_DAYS = 29;
	const int JULY = 7;

	const int MIN_YEAR = 1901;
	const int MAX_YEAR = 2099;
	const int INPUT_LEN = 22;
	const int SECOND_DATE_OFFSET = 11;
	char inputDATE[22];

	std::cout << std::endl;
	//SRS05 spec to read in two dates assuming the user enters dates in ISO format (YYYY-MM-DD) seperatated by whitespace.
	std::cin.getline(inputDATE, 22);

	y1 = ((inputDATE[0] - '0') * 1000) + ((inputDATE[1] - '0') * 100) + ((inputDATE[2] - '0') * 10) + (inputDATE[3] - '0');
	m1 = ((inputDATE[5] - '0') * 10) + (inputDATE[6] - '0');
	d1 = ((inputDATE[8] - '0') * 10) + (inputDATE[9] - '0');

	y2 = ((inputDATE[SECOND_DATE_OFFSET] - '0') * 1000) + ((inputDATE[SECOND_DATE_OFFSET + 1] - '0') * 100) + ((inputDATE[SECOND_DATE_OFFSET + 2] - '0') * 10) + (inputDATE[SECOND_DATE_OFFSET + 3] - '0');
	m2 = ((inputDATE[SECOND_DATE_OFFSET + 5] - '0') * 10) + (inputDATE[SECOND_DATE_OFFSET + 6] - '0');
	d2 = ((inputDATE[SECOND_DATE_OFFSET + 8] - '0') * 10) + (inputDATE[SECOND_DATE_OFFSET + 9] - '0');
	
	std::cout << std::endl;
	//Dates can come in any order but needed this extra feature.
	//Extra Feature rearrange dates so that y1-m1-d1 is BEFORE y2-m2-d2, also to help with my loop statements.
	if (y1 >= y2 && m1 >= m2 && d1 >= d2)
	{
		int tempy, tempm, tempd; //Temporary variables for year, month, day to help with rearrangment.

		tempy = y1;
		tempm = m1;
		tempd = d1;

		y1 = y2;
		m1 = m2;
		d1 = d2;

		y2 = tempy;
		m2 = tempm;
		d2 = tempd;
		//Extra Feature notify user that the dates have been rearranged.
		std::cout << " Your dates are now rearranged accordingly. " << std::endl;
	}
	//show user the inputted dates prior to gathering all dates in between
	std::cout << y1 << '-';
	std::cout << std::setfill('0') << std::setw(2) << m1 << '-';
	std::cout << std::setfill('0') << std::setw(2) << d1;

	std::cout << " => ";

	std::cout << y2 << '-';
	std::cout << std::setfill('0') << std::setw(2) << m2 << '-';
	std::cout << std::setfill('0') << std::setw(2) << d2;

	std::cout << std::endl;
	std::cout << " Press any key to print out all dates in between your two dates. "; //Extra Feature just to allow user to hit a key to execute program
	std::cout << std::endl;

	std::cin.get();//Hold console screen open, to see what our inputs are after rearranging
	
	//SRS05 spec use loop statements, conditionals, practice with cin and cout formatting, zero fill dates to meet ISO format on the output
	while (!(y1 >= y2 && m1 >= m2 && d1 >= d2))
	{
		std::cout << y1 << '-';
		std::cout << std::setfill('0') << std::setw(2) << m1 << '-';
		std::cout << std::setfill('0') << std::setw(2) << d1;
		d1++;
		dim = 31;
		
		if (m1 == FEB)
		{
			dim = NOT_LEAP_DAYS;
				if ((y1 % 400 == 0) || (y1 % 100 != 0 && y1 % 4 == 0))
				{
				dim = LEAP_DAYS;
				}	
		}
		else
		{
			//Found some interesting info regarding Odd months having 31 days, and Even months with 30 days, and after July it flips, which then starts in August.
			//Reference: https://www.timeanddate.com/calendar/months/
			if (m1 <= JULY)
			{
				if (m1 % 2 == 0)
					dim = 30;
			}
			else if (m1 % 2 == 1)
			{
				dim = 30;
			}
		}
		if (d1 > dim)
		{
			m1++;
			d1 = 1;
		}
		if (m1 > 12)
		{
			y1++;
			m1 = JAN;
		}
		if (dim == LEAP_DAYS && d1 == dim) std::cout << " ----Leap Day---- ";//Extra Feature, will mark "Leap Day" next to actual leap day if available between date range. 
		std::cout << std::endl;
	}
	std::cin.get();//Hold console screen open, for user to view results, program will terminate after pressing enter
		
	return 0;
	
}

