#include <iostream>
#ifndef _ARRAY_
#define _ARRAY_

const int DEFAULT_CAPACITY=10;


//исключения
class ArrayException {};


class Array
{
	private:
		int* ptr;      // Указатель на массив в динамич. памяти
		int size;      // Текущий размер
		int capacity;  // Вместимость

	public:
		explicit Array(int startCapacity=DEFAULT_CAPACITY);	//аргумент по умолчанию
		~Array();
		Array(const Array& arr);
		Array operator =(const Array& arr); //оператор присваивания
		int get(int index) const;	// Получение элемента с заданным индексом
		void set(int index, int elem);	// Установка значения элемента с заданным индексом
		int operator [](int index);		//исключения
		void insert(int index, int elem);	
		void insert(int elem);		// Вставка элемента в конец массива
		void increaseCapacity(int newCapacity);	//Увеличение предельного размера
		void remove(int index);		// Удаление элемента
		int getSize() const;	//Получение размера
		friend ofstream& operator << (ofstream& out,const Array& arr);		// Вывод массива в поток



};


#endif
