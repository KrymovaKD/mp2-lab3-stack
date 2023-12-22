#pragma once
#include <iostream>
using namespace std;
template <class T>
class TStack {
private:
	T* pMem;//��������� �� ������ �������
	int MaxSize;//������������ ����� ��������� � �����  
	int CurrIndx;//������ �������� ,������� �� �������� ����� 
public:
	//����������� � ������� ���� � �� ���������
	TStack(int maxsize = 10)
	{
		if (maxsize <= 0)
			throw maxsize;//�������� ����������
		MaxSize = maxsize;
		pMem = new T[MaxSize];
		CurrIndx = -1;
	}

	//����������� �����������
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


	//�������� ������������
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


	
	//��� ������� ���������� ������� ����� ������ ����� �� �����(��� ������)
	friend ostream& operator<<(ostream& out, const TStack <T> & mt)
	{
		for (int i = 0; i < mt.MaxSize; i++)
			out << mt.pMem[i] << endl;
		return out;
	}
	

	//����������� ��� ������������ ��������!�������� �� ������� - ���� ������(���� �� ��������), ���� ����������� (����� �� ���-�� ��������)
	bool empty() {//������ ��� ,������ ��� ��������� � this
		if (CurrIndx == -1) { return true; }//��������� ������ ����� ���� ������
		else return false;
	}


	bool full()
	{
		if (CurrIndx == MaxSize - 1) { return true; }
		else return false;
	}


	//���������� ��������� push()
	void push(const T& elem)
	{
		if (CurrIndx+1 >= MaxSize)
			throw "Stack overflow";
		pMem[CurrIndx + 1] = elem;
		CurrIndx++;
	}


	// ������ � �������� ������������ pop() � �������
	T pop()
	{
		if (CurrIndx == -1)//���� ������
			throw "Stack is empty";
		CurrIndx--;
		return pMem[CurrIndx + 1];
	}


	//����� ��������� ������� ����� top(): ��������� ������� � �������,� ��������� �� �������� ����
	T top()
	{
		if (CurrIndx == -1)//���� ������
			throw "Stack is empty";
		return pMem[CurrIndx];
	}

	//����� �������� ����;
	void clear()
	{
		CurrIndx = -1;
		while (!(empty()))
		{
			this->pop();

		}
	}
	/*����� ������� ����� � �����
	TStack<int> s;
	while(!(s.empty))//���� �� ������
	{s.Pop();//�����������
	}
	*/
};
