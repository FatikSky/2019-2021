#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <assert.h>
#include <math.h>
using namespace std;

enum Angles
{
	LU = 201,
	RU = 187,
	LD = 200,
	RD = 188,
	LT = 204,
	RT = 185,
	DT = 202,
	UT = 203,
	AR = 206
};
enum Lines
{
	VER = 186,
	GOR = 205
};

enum COLORS {
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	AQUA = 3,
	RED = 4,
	PURPLE = 5,
	YELLOW = 6,
	WHITE = 7,
	GRAY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_AQUA = 11,
	LIGHT_RED = 12,
	LIGHT_PURPLE = 13,
	LIGHT_YELLOW = 14,
	BRIGHT_WHITE = 15
};
void my_set_color(int fg = 7, int bg = 0)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}

void my_set_cursor(int x, int y)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = {};
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(h, coord);
}

void screen()
{
	cout << (char)LU;
	for (int i = 0; i < 15; i++)
	{
		cout << (char)GOR;
	}
	cout << (char)RU << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << (char)VER << endl;
	}
	cout << (char)LT;
	for (int i = 0; i < 3; i++)
	{
		cout << (char)GOR << (char)GOR << (char)GOR << (char)UT;
	}
	cout << (char)GOR << (char)GOR << (char)GOR << (char)RT;
	for (int i = 0; i < 3; i++)
	{
		my_set_cursor(16, i + 1);
		cout << (char)VER;
	}
}

void buttons(char arr[][4], char symbol = ')')
{
	for (int k = 0, i = 0; k < 8; k++, i++)
	{
		my_set_cursor(0, k + 5);
		for (int j = 0; j < 4; j++)
		{
			cout << (char)VER;
			if (symbol == arr[i][j])
			{
				my_set_color(LIGHT_GREEN);
			}
			cout << " " << arr[i][j] << " ";
			my_set_color();
		}
		cout << (char)VER;
		k++;
		my_set_cursor(0, k + 5);
		cout << (char)LT;
		for (int j = 0; j < 4; j++)
		{
			cout << (char)GOR << (char)GOR << (char)GOR << (char)AR;
		}
		cout << "\b" << (char)RT;
	}
	my_set_cursor(0, 12);
	cout << (char)LD;
	for (int j = 0; j < 4; j++)
	{
		cout << (char)GOR << (char)GOR << (char)GOR << (char)DT;
	}
	cout << "\b" << (char)RD;
}

double result(char operation, double number_1, double number_2)
{
	switch (operation)
	{
	case '+':
		return number_1 + number_2;
	case '-':
		return number_1 - number_2;
	case '*':
		return number_1 * number_2;
	case '/':
		assert(number_2);
		return number_1 / number_2;
	case '%':
		return (int)number_1 % (int)number_2;
	default:
		assert(false);
	}
}

int x_num(double number, int count_e)
{
	int x = 1;
	if (number < 0)
	{
		x++;
	}
	do
	{
		x++;
		number /= 10;
	} while ((int)number);
	return x + count_e;
}

int main(void)
{
	////////////////////////////////////////////////////////
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
	////////////////////////////////////////////////////////
	char arr[4][4]{ '7', '8', '9', '+', '4', '5', '6', '-', '1', '2', '3', '*', '=', '0', '%', '/' };
	screen();
	buttons(arr);
	char symbol = ' ';
	int x = 1;
	double number_1 = 0;
	double number_1_e = 0;
	double number_2 = 0;
	double number_2_e = 0;
	char operation = ' ';
	int count_m = 0;
	int count_e = 1;
	bool point = false;
	bool numbers = false;
	while (true)
	{
		my_set_cursor(0, 0);
		symbol = _getch();
		screen();
		buttons(arr, symbol);
		if (symbol <= '9' && symbol >= '0')
		{
			if (numbers && count_m < 6)
			{
				my_set_cursor(x, 2);
				if (point)
				{
					number_2 = number_2 + (symbol - 48) * pow(0.1, count_e);
					count_e++;
				}
				else
				{
					number_2 = number_2 * 10 + symbol - 48;
				}
				cout << number_2;
				count_m++;
			}
			else if (count_m < 6)
			{
				my_set_cursor(1, 2);
				if (point)
				{
					number_1 = number_1 + (symbol - 48) * pow(0.1, count_e);
					count_e++;
				}
				else if (number_1 < 0)
				{
					number_1 = number_1 * 10 - (symbol - 48);
				}
				else
				{
					number_1 = number_1 * 10 + symbol - 48;
				}
				cout << number_1;
				x++;
				count_m = x - 1;
			}
		}
		else if (symbol == '.' && point == false)
		{
			my_set_cursor(x, 2);
			point = true;
			cout << ".";
			x++;
		}
		else if (numbers == false)
		{
			count_m = 0;
			count_e = 0;
			point = false;
			numbers = true;
			my_set_cursor(x, 2);
			cout << symbol;
			operation = symbol;
			x++;
		}
		else if (numbers && symbol == '=')
		{
			numbers = false;
			system("cls");
			my_set_cursor(0, 0);
			screen();
			buttons(arr, symbol);
			my_set_cursor(1, 2);
			number_1 = result(operation, number_1, number_2);
			number_2 = 0;
			cout << number_1;
			x = x_num(number_1, count_e);
			count_m = x - 1;
		}
	}
	return 0;
}