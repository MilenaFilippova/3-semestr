#include <iostream>
#include <fstream>
#ifndef _FIELD_
#define _FIELD_

const int FIELD_WIDTH=7;
const int FIELD_HEIGHT=6; 

//Ячейка может быть в трех состояниях –пустая, красная, желтая
// Переменная типа «перечисление» может равняться одному из 3х перечисленных значений
enum Cell
{
	EMPTY=0,
	RED=2,
	YELLOW=8
};

class Field
{
	public:
		Field(bool isRedFirst);	// 
		void clear(bool isRedFirst);			//очистка поля
		bool makeTurn(int column);			//Выполнение хода
		bool isWon(bool red) const;
		bool isOver() const;				//Контроль окончания игры
		Cell getCell(int i, int j) const;		
		bool isRedTurnNow() const;			// Очередь хода
		void checkWinner() const;			// Определение победителя
		Cell cells[FIELD_WIDTH][FIELD_HEIGHT];  // Двумерный массив для  хранения игрового поля
		bool isRedTurn;					// Очередь хода
		Cell winner;					// Кто выиграл
		Cell start;
		void printResult() const;
		void print() const;
};




#endif
