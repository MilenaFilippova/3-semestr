#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>

using namespace std;
void perevod (unsigned long long *&TRstr, char *&ALLstr, const unsigned long long MAX_LENGTH,int k);
int proverka(int x,unsigned long long poz,unsigned long long *&TRstr,int flag);

int main()
{
     setlocale(LC_ALL,"Russian");
	
      const unsigned long long MAX_LENGTH=2000072;
      char *ALLstr=new char[MAX_LENGTH];								//строковый вассив всего файла
      unsigned long long *TRstr=new unsigned long long[MAX_LENGTH];	//массив с числами всего файла

      unsigned long long poz=TRstr[0];								//- будущее 10-значное число
      int k=2,x=0,flag=0;
      unsigned p = 0;

      ifstream in ("D:\\ИГУ\\Программирование\\e2mil.txt"); 
      if (!in.is_open())
      {
          cout<< "Невозможно открыть файл. "<<endl; 
          return 1; 
      } 
      else
      {
          cout<<"Файл открыт"<<endl;
      }
	
      while( in.getline( ALLstr + p, MAX_LENGTH - p) ) //читаем все знаки
      {
          p = strlen(ALLstr) - 1;
      }
	//переводим все символы в число и записываем их в новый массив 
	perevod (*&TRstr,*&ALLstr, MAX_LENGTH,k);
	//проверка простое ли число
	proverka(x,poz,*&TRstr,flag);	//создаем 10-значное число и проверяем его на простату

	in.close();

	delete [] TRstr;
	delete [] ALLstr;
	
	system("pause");
	return 0;
}


void perevod(unsigned long long *&TRstr, char *&ALLstr, const unsigned long long MAX_LENGTH,int k)
{
	for(int i=0;i<MAX_LENGTH ;i++)	
 	{
		TRstr[i]=ALLstr[k]-'0';
		k++;
	}
}

int proverka(int x,unsigned long long poz,unsigned long long *&TRstr,int flag)
{
     bool theend=true;
     while(theend==true)
     {
          for(int j=x;j<x+9;j++)	//переводим эл массива в 10-значное число
          {
              flag=0;				//зануляем снова
              poz=poz*10+TRstr[j+1];
          }
          for(int i=2; i<sqrt((double)poz); i++)		//проверка на простоту
          {
              if(poz % i==0)		// poz не простое, так как делится на i
              {
                 flag++;	
                 x++;			//сдвигаем число
                 poz=TRstr[x];
                 break;		
              }
           }
           if (flag==0)
           {
              cout<<"Найдено простое число : "<<poz<<endl;
              theend=false;
              return 0;
            }
       }
		
	
}
