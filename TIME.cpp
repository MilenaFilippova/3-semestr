#include <iostream>
#include "time.h"

using namespace std;

Time :: Time()
{
	hour=0;
	minutes=0;
	seconds=0;
	day=0;
	month=0;
	year=0; 
}

Time :: Time(int a,int b,int c)
{
	hour=a;
	minutes=b;
	seconds=c;
	day=0;
	month=0;
	year=0; 
}

Time :: Time(int a,int b,int c,int d,int e,int f)
{
	
	day=a;
	month=b;
	year=c; 
	hour=d;
	minutes=e;
	seconds=f;
}


Time :: Time(double A)
{
	hour=int(A);
	minutes=60*(A-int(A));
	seconds=0;
	day=0;
	month=0;
	year=0; 
}

Time :: Time(char* str)
{
	day=0;
	month=0;
	year=0; 
	char chas[10]="";
	char min[10]="";
	char sec[10]="";
	int n=0;
	for(int i=0;i<=strlen(str);i++ )
	{

		if(str[i]==':')
		{
			for(int j=0;j<i;j++ )
			{
				chas[j]=str[j];
				
			}
			for(int k=i+1;k<=strlen(str);k++ )
			{
				if(str[k]!=':')
				{
					min[n]=str[k];
					n++;
				}
				else
				{
					n=0;
					for(int l=k+1;l<=strlen(str);l++ )
					{
						sec[n]=str[l];
						n++;
					}
					break;
				}
			}
			break;
		}
	}
			hour=atoi(chas);
			minutes=atoi(min);
			seconds=atoi(sec);
			
			
}

int Time ::proverka()
{
	int k=1;
	if(hour>23 || 	minutes>59  || seconds>59 || day>31 || month>12 || year>2018 ||
		hour<0 || 	minutes<0  || seconds<0 || day<0 || month<0 || year<0)
	{
		k++;
	}
	return k;
}

Time Time:: operator +(const Time &t)const 
{
	Time temp;
	double sum=(hour + t.hour)*60+(minutes+t.minutes)+(seconds + t.seconds)/60;
	temp.day = (sum/60)/24;
	temp.month = (month+t.month);
	temp.year = (year+t.year);
	temp.hour = (sum/60- temp.day*24 );
	temp.minutes = (int(sum)%60);
	temp.seconds = (seconds + t.seconds)%60;
	temp.day = (sum/60)/24+(day+t.day);
	
	return temp;
}

Time Time:: operator -(const Time &t)const 
{
	Time temp;
	double sum=(hour - t.hour)*60+(minutes-t.minutes)+(seconds - t.seconds)/60;
	temp.day = (sum/60)/24;
	temp.month = (month-t.month);
	temp.year = (year-t.year);
	temp.hour = (sum/60- temp.day*24 );
	temp.minutes =  (int(sum)%60);
	temp.seconds = (seconds - t.seconds)%60;
	temp.day = (sum/60)/24+(day-t.day);
	return temp;
}

void Time ::printshort()
{
	cout<<"hour="<<hour<<" minutes= "<<minutes<<" seconds= "<<seconds<<'\n';
	cout<<"or "<<hour<<":"<<minutes<<":"<<seconds<<endl<<endl;
}


void Time ::printall()
{
	cout<<"  day="<<day<<"  month="<<month<<" year= " <<year<<
		  "  hour="<<hour<<" minutes="<<minutes<<" seconds="<<seconds<<'\n';
	cout<<"or "<<day<<"."<<month<<"."<<year<<"   "<<hour<<":"<<minutes<<":"<<seconds<<endl<<endl;


}

//операторы ввода-вывода 
ifstream operator >>(ifstream& in, const  Time& t)const
{
	in>>t.day>>t.month>>t.year>>t.hour>>t.minutes>>t.seconds;
	return in;
}
ofstream operator <<(ofstream& out, const Time& t)const
{
	out<<t.day<<"."<<t.month<<"."t.year<<"   "t.hour<<":"<<t.minutes<<":"<<t.seconds;;
	return out;
}
