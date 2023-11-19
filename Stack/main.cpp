
#include <string>
#include <iostream>
#include"TStack.h"
using namespace std;
bool chec_brack(const string& str) {
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
	/*TStack <char> s(20);
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
	}*/
	

}

	/*��������� ������������ ����������� ������ ��� ��������� string str = "(2+2)*2"
	���� ��������� ������ �������� � � ����,����� ����������� ������ ������,����� �� ����� ������ ��������� �� ������� - ������ ����������� �����,�����
	���� �� ������ � ������ ����������� �� �����.
	������� ������� ��������� �� ���� ������ � ������� ����� ��� �������� ����������� ������
	*/
	