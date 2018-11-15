#include <iostream>
#include <fstream>
#ifndef _RATIONAL_
#define _RATIONAL_


class Rational
{
	
	private:
		int numer,denom;

	public:
		Rational();
		Rational(int);
		Rational(int,int);
		Rational operator + (const Rational& r)const;
		Rational operator + (const int &a)const;
		Rational operator +=(const Rational& r)const;
		Rational operator - (const Rational &r)const;
		Rational operator - (const int &a)const;
		Rational operator - ()const;
		Rational operator -= (const Rational &r);
		Rational operator *(const Rational &r)const;
		Rational operator *(const int &a)const;
		Rational operator *(const double &a)const;
		
		Rational operator /(const Rational &r)const;
		Rational operator /(const int &a)const;
		//инкрименты 
		Rational& operator ++ ();	//префикс
		Rational& operator ++ (int);	//постфикс
		
		//операторы сравнения
		bool operator == (const Rational& r) const;
		bool operator != (const Rational& r) const;
		bool operator >(const Rational &r)const;
		bool operator <(const Rational &r)const;
		bool operator >(const int &a)const;
		bool operator <(const int &a)const;
		//операторы преобразования типов
		operator int() const;
		operator double() const;
		
		//Операторы ввода-вывода
		void print();
		void simplify();
		Rational sqrtr(const Rational &r) const;
		friend ifstream operator >>(istream& in, const Rational& r)const;
		friend ofstream operator <<(ostream& out, const Rational& r)const;

};


#endif
