#include <iostream>
#include "string.h"
#include <conio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	String a("322");
	String b("69");
	String sum = a + b;
	cout << "������ ������: " << a << "������ ������: " << b << endl;
	cout << "�����: " << sum << endl;
	cout << "������� ������:";
	String input;
	cin >> input;
	if (input == sum)
		cout << "����� �� ������" << endl;
	else if (input < sum)
		cout << "���� ������ < �����" << endl;
	else if (input > sum)
		cout << "���� ������ > �����" << endl;
	cout << "������� �����: ";
	int number;
	cin >> number;
	cout << number << endl;
	cout << "������� ���-�� ����������:";
	int amount;
	cin >> amount;
	String repeat;
	input = repeat.repeater(input, amount);
	cout << input;
	_getch();
}