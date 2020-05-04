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
	cout << "первая строка: " << a << "вторая строка: " << b << endl;
	cout << "сумма: " << sum << endl;
	cout << "введите строку:";
	String input;
	cin >> input;
	if (input == sum)
		cout << "такая же строка" << endl;
	else if (input < sum)
		cout << "ваша строка < суммы" << endl;
	else if (input > sum)
		cout << "ваша строка > суммы" << endl;
	cout << "введите число: ";
	int number;
	cin >> number;
	cout << number << endl;
	cout << "введите кол-во повторений:";
	int amount;
	cin >> amount;
	String repeat;
	input = repeat.repeater(input, amount);
	cout << input;
	_getch();
}