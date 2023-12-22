#pragma once
#include <iostream>
using namespace std;
template <class T>
class TStack {
private:
	T* pMem;//указатель на начало массива
	int MaxSize;//максимальное число элементов в стеке  
	int CurrIndx;//индекс элемента ,который на вершинке стека 
public:
	//конструктор с методом иниц и по умолчанию
	TStack(int maxsize = 10)
	{
		if (maxsize <= 0)
			throw maxsize;//Добавить исключение
		MaxSize = maxsize;
		pMem = new T[MaxSize];
		CurrIndx = -1;
	}

	//конструктор копирования
	TStack(const TStack <T> & tstack)
	{
		MaxSize = tstack.MaxSize;
		pMem = new T[MaxSize];
		CurrIndx = tstack.CurrIndx;
		for (int i = 0; i <= MaxSize; i++)
		{
			pMem[i] = tstack.pMem[i];
		}
	}


	//оператор присваивания
	TStack& operator=(const TStack<T>& tstack)
	{
		if (pMem != tstack.pMem)
		{
			MaxSize = tstack.MaxSize;
			CurrIndx = tstack.CurrIndx;
			delete[]pMem;
			pMem = new T[MaxSize];
			for (int i = 0; i <= MaxSize; i++)
			{
				pMem[i] = tstack.pMem[i];
			}
		}
		return *this;
	}


	
	//для отладки необходимо создать метод вывода стека на экран(как угодно)
	friend ostream& operator<<(ostream& out, const TStack <T> & mt)
	{
		for (int i = 0; i < mt.MaxSize; i++)
			out << mt.pMem[i] << endl;
		return out;
	}
	

	//Обязательно для динамических структур!Проверка на полноту - либо пустая(есть ли элементы), либо заполненная (может ли что-то положить)
	bool empty() {//ничего нет ,потому что принимает у this
		if (CurrIndx == -1) { return true; }//возращает истину когда стек пустой
		else return false;
	}


	bool full()
	{
		if (CurrIndx == MaxSize - 1) { return true; }
		else return false;
	}


	//добавление элементов push()
	void push(const T& elem)
	{
		if (CurrIndx+1 >= MaxSize)
			throw "Stack overflow";
		pMem[CurrIndx + 1] = elem;
		CurrIndx++;
	}


	// убрать и получить одновременно pop() с вершины
	T pop()
	{
		if (CurrIndx == -1)//стек пустой
			throw "Stack is empty";
		CurrIndx--;
		return pMem[CurrIndx + 1];
	}


	//метод просмотра вершины стека top(): возращает элемент с вершины,с проверкой на непустой стек
	T top()
	{
		if (CurrIndx == -1)//стек пустой
			throw "Stack is empty";
		return pMem[CurrIndx];
	}

	//метод очистить стэк;
	void clear()
	{
		CurrIndx = -1;
		while (!(empty()))
		{
			this->pop();

		}
	}
	/*метод очистки стека в мейне
	TStack<int> s;
	while(!(s.empty))//пока не пустой
	{s.Pop();//выталкиваем
	}
	*/
};
