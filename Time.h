#include <iostream>
#ifndef _TIME_
#define _TIME_

class Time
{
	
	private:
		int hour,minutes,seconds,year,month,day;

	public:
		Time();
		Time(char*);
		Time(int,int,int);
		Time(int,int,int,int,int,int);
		Time(double);
		Time operator +(const Time &t)const;
		Time operator -(const Time &t)const;

		void printshort();
		void printall();

};

#endif
