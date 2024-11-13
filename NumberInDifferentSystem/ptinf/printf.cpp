#include <iostream>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <stdarg.h>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

enum Roman
{
	_1 = 'I',
	_5 = 'V',
	_10 = 'X',
	_50 = 'L',
	_100 = 'C',
	_500 = 'D',
	_1000 = 'M'
};

string roman_number(int num)
{
	int count = 1;
	string roman;
	while (num != 0)
	{
		int temp = num % 10;
		switch (count)
		{
		case 1:
			if (temp == 0) {
				break;
			}
			else if (temp < 4)
			{
				for (int i = 0; i < temp; i++)
				{
					roman.push_back(Roman::_1);
				}
			}
			else if (temp == 4)
			{
				roman.push_back(Roman::_5);
				roman.push_back(Roman::_1);
			}
			else if (temp < 9)
			{
				for (int i = 0; i < temp - 5; i++)
				{
					roman.push_back(Roman::_1);
				}
				roman.push_back(Roman::_5);
			}
			else
			{
				roman.push_back(Roman::_10);
				roman.push_back(Roman::_1);
			}
			break;
		case 10:
			if (temp == 0) {
				break;
			}
			else if (temp < 4)
			{
				for (int i = 0; i < temp; i++)
				{
					roman.push_back(Roman::_10);
				}
			}
			else if (temp == 4)
			{
				roman.push_back(Roman::_50);
				roman.push_back(Roman::_10);
			}
			else if (temp < 9)
			{
				for (int i = 0; i < temp - 5; i++)
				{
					roman.push_back(Roman::_10);
				}
				roman.push_back(Roman::_50);
			}
			else
			{
				roman.push_back(Roman::_100);
				roman.push_back(Roman::_10);
			}
			break;
		case 100:
			if (temp == 0) {
				break;
			}
			if (temp < 4)
			{
				for (int i = 0; i < temp; i++)
				{
					roman.push_back(Roman::_100);
				}
			}
			else if (temp == 4)
			{
				roman.push_back(Roman::_500);
				roman.push_back(Roman::_100);
			}
			else if (temp < 9)
			{
				for (int i = 0; i < temp - 5; i++)
				{
					roman.push_back(Roman::_100);
				}
				roman.push_back(Roman::_500);
			}
			else
			{
				roman.push_back(Roman::_1000);
				roman.push_back(Roman::_100);
			}
			break;
		}
		count *= 10;
		num /= 10;
	}
	string result;
	for (auto str = roman.rbegin(); str != roman.rend(); str++)
	{
		result.push_back(*str);
	}
	return result;
}

char* reverse_str(char* str)
{
	int len = strlen(str);
	char* temp_str = (char*)malloc(len + 1);
	str += len - 1;
	for (int i = 0; i < len; ++i)
	{
		*temp_str = *str;
		++temp_str;
		--str;
	}
	*temp_str = '\0';
	return temp_str - len;
}

int system_number(int system, string str_num)
{
	int result = 0;
	vector<int> numbers;
	for (char& symbol : str_num)
	{
		if (symbol >= '0' && symbol <= '9')
		{
			numbers.push_back((int)symbol - 48);
		}
		else
		{
			numbers.push_back((int)symbol - 55);
		}
	}
	int quantity = numbers.size();
	--quantity;
	for (int &number : numbers)
	{
		result += number * pow(system, quantity);
		--quantity;
	}
	return result;
}

char* number_systems(int num, int system)
{
	int count = 0;
	char* result = (char*)malloc(sizeof(int) * 8);
	while (num != 0)
	{
		int temp = num % system;
		if (temp >= 0 && temp <= 9)
		{
			*result = temp + 48;
			++result;
			++count;
		}
		else
		{
			*result = temp + 55;
			++result;
			++count;
		}
		num /= system;
	}
	*result = '\0';
	result -= count;
	result = reverse_str(result);
	return result;
}

void myprintf(const char* str, ...)
{
	va_list args = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			++str;
			switch (*str)
			{
			case 'x':
				cout << number_systems(va_arg(args, int), 16);
				break;
			case 'd':
				cout << va_arg(args, int);
				break;
			case 'o':
				cout << number_systems(va_arg(args, int), 8);
				break;
			case 'b':
				cout << number_systems(va_arg(args, int), 2);
				break;
			default:
				cout << "%";
				break;
			}
		}
		else
		{
			cout << *str;
		}
		++str;
	}
	va_end(args);
}

int main(void)
{
	int start_system = 0;
	string str_number;
	int number;
	int n_system = 0;
	char answer;
	while (true)
	{
		system("cls");
		cout << "Please, enter the number: ";
		cin >> str_number;
		cout << "Please, enter the system of number: ";
		cin >> start_system;
		cout << "Please, enter the system for number: ";
		cin >> n_system;
		system("cls");
		cout << "Number in " << start_system << " system: " << str_number << endl;
		number = system_number(start_system, str_number);
		cout << "Standart systems: " << endl;
		myprintf("HEX: %x \nDEX: %d \nOCT: %o \nBIN: %b \n", number, number, number, number);
		cout << "Number in roman numeral: " << roman_number(number) << endl;
		cout << "Number in " << n_system << " system: " << number_systems(number, n_system) << endl;
		answer = _getch();
		if (answer == 27)
		{
			exit(0);
		}
	}
	return 0;
}