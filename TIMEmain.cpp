#include <iostream>
#include "time.h"


using namespace std;

int main()
{
	setlocale(LC_ALL,"Russian");

	Time T1, T2("02:40:15"), T3(16,12,53), T4(23.5),T5,T6(18,12,2018,13,20,19);
	//          чч:мм:сс       чч,мм,сс      чч.мм       дд,мм,гг,чч,мм,сс
	if (T2.proverka()==2)
	{
		cout <<"Неверно введенно время T2"<<endl;
	}
	else if(T3.proverka()==2)
	{
		cout <<"Неверно введенно время T3"<<endl;
	}
		else if(T4.proverka()==2)
	{
		cout <<"Неверно введенно время T4"<<endl;
	}
			else if(T6.proverka()==2)
	{
		cout <<"Неверно введенно время T6"<<endl;
	}
	else
	{
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
		if(T5.proverka()==2)
		{

			cout<<"В выражении T5=T3-T2 результат отрецательный.Проверьте значения времени<<endl";
		}
		else
		{
			cout<<"T5=T3-T2= ";
			T5.printall();
		}

		T5=T3-T4;
		if(T5.proverka()==2)
		{
			cout<<"В выражении T5=T3-T4 результат отрецательный.Проверьте значения времени"<<endl;
		}
		else
		{

			cout<<"T5=T3-T4= ";
			T5.printshort();
		}

	
		cout<<endl<<"T6= ";
		T6.printall();

		T5=T6+T3;
		cout<<"T5=T6+T3 ";
		T5.printall();
	}

	system("pause");
	return 0;
}
