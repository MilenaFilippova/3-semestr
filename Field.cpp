#include <iostream>
#include <fstream>
#include "field.h"

using namespace std;

Field::Field(bool isRedFirst)
{
	clear(isRedFirst);	//очистка
}

void Field::clear(bool isRedFirst) //очистка
{
   isRedTurn = isRedFirst;
   winner = EMPTY;
   for (int i=0; i<FIELD_WIDTH; i++)
      for (int j=0; j<FIELD_HEIGHT; j++)
         cells[i][j] = EMPTY;
}

bool Field::makeTurn(int column)
{
	//Проверка. Если кто-то уже выиграл, ход невозможен
	if (winner != EMPTY)
		return false;
	// Проверка номера колонки на корректность
	if (column < 1 || column > FIELD_WIDTH)
		return false;

	int i=column-1;
	for (int j=0; j<FIELD_HEIGHT; j++)			// Ищем первую свободную ячейку
	if (cells[i][j]==EMPTY)						//если ячейка пуста
	{
		cells[i][j] = isRedTurn ? RED : YELLOW;	// чья очередь хода?
		// Проверяем, не выиграл ли кто
		checkWinner();			//победа?
		isRedTurn = !isRedTurn;	//больше нельзя ходить
		return true;
	}
	return false;
}


const int DIR_NUMBER = 4;
const int di[] = { 1, 0, 1, 1 };
const int dj[] = { 0, 1, -1, 1 };
const int WIN_LENGTH = 4;


void Field::checkWinner() const	// Проверяем, не выиграл ли кто
{
	// Перебор всех ячеек, откуда четверка начинается
   for (int i=0; i<FIELD_WIDTH; i++)
      for (int j=0; j<FIELD_HEIGHT; j++)
      {
            start = cells[i][j];	//ячейка старта
			if (start==EMPTY)		// Четверка не может начинаться из пустой ячейки
				continue;
			for (int dir=0; dir<DIR_NUMBER; dir++)
			{		
				int length=0,iline = i, jline = j; //  длина линии и ячейки с линией
				while (++length < WIN_LENGTH)	//если еще не построили линию длиной для выигрыша 
				{
					iline += di[dir];
					jline += dj[dir];
					// Вышли за пределы
					if (iline < 0 || iline >= FIELD_WIDTH ||jline < 0 || jline >= FIELD_HEIGHT)
						break;
					// Другой цвет
					if (cells[iline][jline]!=start)
						break;
				}
				if (length==WIN_LENGTH) //длина поволяет победить
				{
					winner = start;
					return;
				}
			}
		}
}


//контроль окончания игры
bool Field::isWon(bool red) const
{
	return red ? (winner==RED) : (winner==YELLOW);
}
//Контроль окончания игры
bool Field::isOver() const
{
	if (winner != EMPTY)
		return true;
   for (int i=0; i<FIELD_WIDTH; i++)
      for (int j=0; j<FIELD_HEIGHT; j++) // Если хоть одна ячейка свободна, игра не окончена
		if (cells[i][j]==EMPTY)
			return false;
	return true;// Все ячейки заняты
}


Cell Field::getCell(int i, int j) const
{
	if (i<=0 || i>FIELD_WIDTH || j<=0 || j>FIELD_HEIGHT)
		return EMPTY;
	return cells[i-1][j-1];
}

bool Field::isRedTurnNow() const
{
	return isRedTurn;
}

//Ячейка может быть в трех состояниях –пустая, красная, желтая
char sym[] = { '.', 'R', 'Y' };

void Field::print() const	//печать доски
{
	 cout<<"1 2 3 4 5 6 7-"<<endl;
	 for (int i=FIELD_HEIGHT-1; i>=0; i--)
	 {
		  for (int j=0; j<FIELD_WIDTH; j++)
		  {
			 cout<<sym[cells[j][i]]<<" ";
		  }
		  cout<<endl;
	 }
	 cout<<"1 2 3 4 5 6 7-"<<endl;
}
void Field::printResult() const	//вывод итогов
{
	if (isWon(true))
	{
		cout<<"Красный игрок победил"<<endl; 
	}
	else if (isWon(false))
	{
		cout<<"Желтый игрок победил"<<endl;
	}
	else if (isOver())	//winner!=RED и winner!=YELLOW
	{
		cout<<"Ничья"<<endl;
	}
	else
	{
		cout<<"Игра не окончена"<<endl;
	}
}
