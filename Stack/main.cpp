
#include <string>
#include <iostream>
#include"TStack.h"
#include "TCalc.h"
using namespace std;
/*bool chec_brack(const string& str) {
	TStack <char> s(str.size());
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			s.push(str[i]);
		}
		if (str[i] == ')')
		{
			if (!s.empty())
			{
				s.pop();

			}
			else
				return false;
		}
	}
	if (!s.empty())
	{
		return false;
	}
	return true;
}
void main() {
	string str = "(2+2)*2+(3*4))";
	if (chec_brack(str))
		cout << "the brackets are placed correctly";
	else
		cout << "the brackets are not placed correctly";
	TStack <char> s(20);
	int Result = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			s.push(str[i]);
		}
		if  (str[i] == ')')
		{
			if (!s.empty())
			{
				s.pop();

			}
			else
				Result = 1;
		}
	}
	if (!s.empty())
	{
		Result = 2;
	}
	

}

	/*проверить правильность расстановки скобок для выражения string str = "(2+2)*2"
	Если встретили скобку положили её в стек,нашли закрывающую скобку вынули,дошли до конца строки проверяем на пустоту - скобки расставлены верно,иначе
	стек не пустой и скобки расставлены не верно.
	функция которая принимает на вход строку и говорит верно или неверрно рассталвены скобки
	*/
int main()
{
	try {
 		TCalc math1("100+3*4");
		double res = math1.Calc();
		cout << res;
		TStack <int> a(3);
		for (int i = 0; i < 3; i++)
		{
			a.push(i);
		}
		TStack <int> b(a);
		cout << a;
		cout << b;
		
	}
	catch (int num)
	{
		if (num == 0)
		{
			cout << "Incorrect brackets";
		}
		else if (num == 1)
		{
			cout << "Invalid numeric expression";
		}
		else if (num == 2)
		{
			cout << "Division by zero expression";
		}
		
	}
	catch (char num1)
	{
		cout << "invalid character: " << num1;
	}
}