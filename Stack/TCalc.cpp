#include "TCalc.h"
#include "TStack.h"
#include <iostream>
#include<stdio.h>
#include <string>
using namespace std;
//�������� ������������ ����������� ������ � ��������
bool TCalc::chec_brack_and_op_for_infix(const string& str)
{
	int num = 0, op = 0;
	TStack <char> s(str.size());
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			s.push(str[i]);
		}
		else if(str[i] == ')')
		{
			if (!s.empty())
			{
				s.pop();

			}
			else
				throw 0;
		}
		else if ((str[i] >= '0') && (str[i] <= '9'))
		{
			size_t pos;
			double x;
			x = stod(&str[i], &pos);
			i = i + pos - 1;
			num += 1;
		}
		else if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '^')||(str[i]=='/'))
		{
			op += 1;
		}
	}
	if (!s.empty())
	{
		throw 0;
	}
	else if (num != (op + 1))
	{
		throw 1;
	}
	return true;
}

//����������� � ������� �������������
TCalc::TCalc(string _inf)
{
	infix = _inf;
	if (chec_brack_and_op_for_infix(_inf))
	{
		infix = _inf;
		//this->ToPostfix();
	}
}

//���������� ���������(������ ������������ � ��������)
double TCalc::CalcPostfix() {
	//�������� ���� �����
	DNum.clear();
	double res = 0;
	for (int i = 0; i < postfix.length(); i++)
	{
		if ((postfix[i] >= '0') && (postfix[i] <= '9'))
			DNum.push(postfix[i]-'0');
		else if ((postfix[i] == '+') || (postfix[i] == '-') || (postfix[i] == '*') || (postfix[i] == '^'))
		{
			double x1, x2;//������ � ������ �������
			//�������� ���������� +
			if (!(DNum.empty()))
			{
				x2 = DNum.pop();//��� ����� ���� ������� ������� �� ������� ����� ,������ ������ ��������
				x1 = DNum.pop();
				if (postfix[i] == '+')
				{
					res = x1 + x2;
				}
				if (postfix[i] == '-')
				{
					res = x1 - x2;
				}
				if (postfix[i] == '*')
				{
					res = x1 * x2;
				}
				if (postfix[i] == '/')
				{
					if (x2 != 0)
					{
						res = x1 / x2;
					}
					else
						throw 2;
				}
				if (postfix[i] == '^')
				{
					res = 1;
					for (int j = 0; j < x2; j++)
					{
						res *= x1;
					}
				}
				DNum.push(res);
			}
			else
				throw 1;
		}
	}// ������� ������� ��������� � ��������� �� ������� ����� - �������� ���������� +
	res = DNum.pop();
	if (DNum.empty())
	{
		return res;
	}
	else
	{
		throw 1;
	}
}//�������������

//������� �� ��������� ������� � �����������
void TCalc::ToPostfix()
{
	//��������� ���������� ����
	C.clear();
	string str = "("+ infix + ")";//��������� � ������
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			C.push('(');
		}
		else if ((str[i] >= '0') && (str[i] <= '9'))
		{
			postfix += str[i];
		}
		else if(str[i] == ')')
		{
			char el;
			el = C.pop();//�������� ���� �� ���� �������
			while (el != '(')
			{
				postfix += el;
				el = C.pop();
			}

		}
		else if (str[i] == '+')///��������
		{//���������� ��������� ������� � +
			if (1 >= prior(C.top()))
			{
				C.push('+');//���� ��������� ������ ���� ����� ,�� ������ ���������� �� ������� �����
			}
			else
			{//���� ��������� ������ ,�� ��������� ������ �������
				char el;
				while ((1<= prior(C.top())) && (prior(C.top()) != 0))//� ���� ��������� ������ ���� ����� ����������� �� �� �����
				{
					el = C.pop();
					postfix += el;
					
				}
				C.push('+');//����� ���������� ���������� + � ���� � ��������

			}
			
		}
		else if (str[i] == '*')
		{//���������� ��������� ������� � +
			if (2 >= prior(C.top()))
			{
				C.push('*');//���� ��������� ������ ���� ����� ,�� ������ ���������� �� ������� �����
			}
			else
			{//���� ��������� ������ ,�� ��������� ������ �������
				char el = C.pop();
				while ((2 <= prior(el))&&(prior(C.top())!=0))//� ���� ��������� ������ ���� ����� ����������� �� �� �����
				{
					postfix += el;
					el = C.pop();
				}
				C.push('*');//����� ���������� ���������� + � ���� � ��������

			}

		}
		else if (str[i] == '-')///��������
		{//���������� ��������� ������� � +
			if (1 >= prior(C.top()))
			{
				C.push('-');//���� ��������� ������ ���� ����� ,�� ������ ���������� �� ������� �����
			}
			else
			{//���� ��������� ������ ,�� ��������� ������ �������
				char el;
				while ((1 <= prior(C.top())) && (prior(C.top()) != 0))//� ���� ��������� ������ ���� ����� ����������� �� �� �����
				{
					el = C.pop();
					postfix += el;

				}
				C.push('-');//����� ���������� ���������� + � ���� � ��������

			}

		}
		else if (str[i] == '/')///��������
		{//���������� ��������� ������� � +
			if (2 >= prior(C.top()))
			{
				C.push('/');//���� ��������� ������ ���� ����� ,�� ������ ���������� �� ������� �����
			}
			else
			{//���� ��������� ������ ,�� ��������� ������ �������
				char el;
				while ((2 <= prior(C.top())) && (prior(C.top()) != 0))//� ���� ��������� ������ ���� ����� ����������� �� �� �����
				{
					el = C.pop();
					postfix += el;

				}
				C.push('/');//����� ���������� ���������� + � ���� � ��������

			}

		}
		else if (str[i] == '^')
		{
			C.push('^');
		}
		else
		{
		throw (str[i]);
		}
	}
	if (!(C.empty()))
	{
		throw 0;
	}
}

//������� ���������� ��������
int TCalc:: prior(const char op)
{
	if ((op == '(') || (op == ')'))
		return 0;
	else if ((op == '+') || (op == '-'))
		return 1;
	else if ((op == '*') || (op == '/'))
		return 2;
	else if (op == '^')
		return 3;
}

//��������� �������
void TCalc::SetInfix(string inf) {
	infix = inf;
}
string TCalc::GetInfix()
{
	return infix;
}
//��������� ���������
string TCalc::GetPostfix()
{
	return postfix;
}

//������� ����������� ��������� ���������
double TCalc::Calc()
{//�������� ����
	C.clear();
	DNum.clear();
//�������������� ��������� � ������
	string str = "(" + infix + ")";
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			C.push('(');
		}
		else if (str[i] == ')')
		{
			char el = C.pop();
			while(el!='(')
			{
				double x2 = DNum.pop(), x1 = DNum.pop(),result;

				if (el == '+')
				{
					result = x1 + x2;
				} 
				if (el == '-')
				{
					result = x1 - x2;
				}
				if (el == '*')
				{
					result = x1 * x2;
				}
				if (el == '^')
				{
					result = 1;
					for (int j = 0; j < x2; j++)
					{
						result*=x1;
					}
				}
				if (el == '/')
				{
					if (x2 != 0)
					{
						result = x1 / x2;
					}
					else
						throw 2;
				}
				DNum.push(result);
				el = C.pop();
			}
		}
		else if ((str[i] >= '0') && (str[i] <= '9'))
		{
			size_t pos;
			double x;
			x = stod(&str[i], &pos);
			DNum.push(x);
			i = i + pos - 1;
		}
		else if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^'))
		{
			char el=C.pop();
			while (prior(el) >= prior(str[i]))
			{
				double res = 0;
				double x2 = DNum.pop(), x1 = DNum.pop();
				if (el == '+')
				{
					res = x1 + x2;
				}
				if (el == '-')
				{
					res = x1 - x2;
				}
				if (el == '*')
				{
					res = x1 *x2;
				}
				if (el == '/')
				{
					if (x2 != 0)
					{
						res = x1 / x2;
					}
					else
						throw 2;
				}
				if (el == '^')
				{
					res = 1;
					for (int j = 0; j < x2; j++)
					{
						res *= x1;
					}
				}
				DNum.push(res);
				el = C.pop();
			}
			C.push(el);
			C.push(str[i]);
		}
	}
	double Res = DNum.pop();
	return Res ;//�������� ���� � ������(����� ������ ��������), �� ������ ��� � ��������� �� �������(������ �������)
}
/*�������� �������� �� ��������� �������� ������(���������) � ������������ �������� �������������� ����������
1)����� ������ ������ ������ � � ���� ��� ��������
2)���� ����� ������� �� ������ � ���� ���������
3)���� ����� �������� �� �� ��������� �� ����� ��� �������� � ������� ���� ������ ����������� � ���������
4)���� ������� ������ ������ ������ ��������� ��� �������� �� ������ ������ � ������� 
��������� ��� �������� �� ����� ������� � ��������� ��������� � ����

��� ������������ �������� ��������� �� ��������� ��������
3.1415+2.718�5
���� ������� ������� ��������� ������ � ����� �� ������� ��������� �������
������� �� ���, ��� ���������� double ��������� string
double stod(string,size_t * )
size_t - unsigned int ���������� �� ��������� ����� ,������� �������� ������ �� �������� ��������
string to double
stoi(to int)
stof(to float)

&str[i] - ������ ��������� ,������� ������� �� �-��� ������



*/

