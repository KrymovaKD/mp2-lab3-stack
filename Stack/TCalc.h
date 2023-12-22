#pragma once
#include <iostream>
#include "TStack.h"
using namespace std;
class TCalc {
private:
	string infix, postfix;
	TStack <double> DNum;//стек дл€ чисел
	TStack<char>C;//стек дл€ знаков
public:
	TCalc(string _inf);
	TCalc()
	{
		infix = "0 ";
	};
	double CalcPostfix();//вычисление постфиксной строчки
	void ToPostfix();//перевод в постфиксную строчку
	void SetInfix(string inf);
	string GetInfix();
	string GetPostfix();
	int prior(const char op);
	double Calc();
	bool chec_brack_and_op_for_infix(const string& str);
};
