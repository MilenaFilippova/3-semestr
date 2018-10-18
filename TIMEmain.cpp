#include <iostream>
#include "time.h"

using namespace std;

int main()
{
	setlocale(LC_ALL,"Russian");

	Time T1, T2("02:40:15"), T3(7,40,53), T4(2.5),T5,T6(18,10,18,13,20,14);
	//          чч:мм:сс       чч,мм,сс      чч.мм       дд,мм,гг,чч,мм,сс

	cout<<"T2=  ";
	T2.printshort();
	cout<<"T3=  ";
	T3.printshort();
	cout<<"T4=  ";
	T4.printshort();

	T5=T2+T3;
	cout<<"T5=T2+T3= ";
	T5.printshort();
	
	T5=T3-T2;
	cout<<"T5=T3-T2= ";
	T5.printall();

	T5=T3-T4;
	cout<<"T5=T3-T4= ";
	T5.printshort();

	
	cout<<"T6= ";
	T6.printall();

	T5=T6+T3;
	cout<<"T5=T6+T3 ";
	T5.printall();


	system("pause");
	return 0;
}
