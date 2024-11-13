#include "Horisontal Ships.h"
#include "Vertical Ships.h"


void my_set_color(int fg, int bg) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}

void my_set_cursor(int x, int y) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = {};
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(h, coord);
}

COORD GetConsoleCursorPosition(HANDLE hConsoleOutput)
{
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
	{
		return cbsi.dwCursorPosition;
	}
	else
	{
		COORD invalid = { 0, 0 };
		return invalid;
	}
}

enum Tools
{
	ship = 219,
	ver = 179,
	hor = 196,
	lu = 218,
	ld = 192,
	ru = 191,
	rd = 217,
	left = 195,
	right = 180,
	up = 194,
	down = 193,
	around = 197
};


void field_print(Field &field, int x = 1, char turn = 'p')
{
	char number = 'A';
	int y = 0;
	++x;
	my_set_cursor(x + 2, y);
	for (size_t i = 0; i < 40; i++)
	{
		if (i % 4 == 0)
		{
			my_set_color(BRIGHT_WHITE);
			printf("%c", number++);
			my_set_color();
		}
		else
		{
			printf(" ");
		}
	}
	number = 1;
	my_set_cursor(x, ++y);
	printf("%c", lu);
	for (size_t i = 1; i < 40; i++)
	{
		if (i % 4 == 0)
		{
			printf("%c", up);
		}
		else
		{
			printf("%c", hor);
		}
	}
	printf("%c\n", ru);
	my_set_cursor(x, ++y);
	for (size_t i = 0; i < 10; i++)
	{
		my_set_color(BRIGHT_WHITE);
		my_set_cursor(x - 2, y);
		printf("%d", number++);
		my_set_cursor(x, y);
		my_set_color();
		for (size_t j = 0; j < 41; j++)
		{
			if (j % 4 == 0)
			{
				printf("%c", ver);
			}
			else if (field.field[i][j / 4] == 1 && turn == 'p')
			{
				my_set_color(WHITE);
				printf("%c", ship);
				my_set_color();
			}
			else if (field.field[i][j / 4] == 2)
			{
				my_set_color(LIGHT_YELLOW);
				printf(" ? ");
				my_set_color();
				j += 2;
			}
			else if (field.field[i][j / 4] == -2)
			{
				my_set_color(GRAY);
				printf(" * ");
				my_set_color();
				j += 2;
			}
			else if (field.field[i][j / 4] == -10)
			{
				my_set_color(LIGHT_RED);
				printf(" X ");
				my_set_color();
				j += 2;
			}
			else
			{
				printf(" ");
			}
		}
		my_set_cursor(x, ++y);
		if (i == 9)
		{
			printf("%c", ld);
			for (size_t i = 1; i < 40; i++)
			{
				if (i % 4 == 0)
				{
					printf("%c", down);
				}
				else
				{
					printf("%c", hor);
				}
			}
			printf("%c", rd);
		}
		else
		{
			printf("%c", left);
			for (size_t j = 1; j < 40; j++)
			{
				if (j % 4 == 0)
				{
					printf("%c", around);
				}
				else
				{
					printf("%c", hor);
				}
			}
			printf("%c", right);
			my_set_cursor(x, ++y);
		}
	}
}

void print_game(Field &player, Field &comp, int &condition)
{
	field_print(player, 1);
	field_print(comp, 61, 'c');
	my_set_cursor(0, 22);
	my_set_color(BRIGHT_WHITE);
	printf("CONTROLS: WASD, ROTARE SHIP: R, SUBMIT: ENTER\n");
	if (condition == -5)
	{
		printf("CONFIGURE YOUR SHIPS RANDOMLY: P\n");
	}
	my_set_color(LIGHT_RED);
	if (condition == 1)
	{
		printf("\aCOMPUTER HITS YOUR SHIP");
	}
	else if (condition == -1)
	{
		printf("\aYOU HIT COMPUTER'S SHIP");
	}
	else if (condition == 2)
	{
		printf("\aCOMPUTER KILLS YOUR SHIP");
	}
	else if (condition == -2)
	{
		printf("\aYOU KILL COMPUTER'S SHIP");
		Sleep(500);
	}
	else
	{
		printf("                                 ");
	}
	condition = 0;
}

void WIN(bool winner)
{
	for (size_t i = 0; i < 20; i++)
	{
		system("cls");
		my_set_color(LIGHT_YELLOW);
		if (winner)
		{
			my_set_cursor(50, 11);
			printf("PLAYER WIN!!!");
		}
		else
		{
			my_set_cursor(50, 11);
			printf("COMPUTER WIN!!!");
		}
		Sleep(50);
		system("cls");
		my_set_color(LIGHT_PURPLE);
		if (winner)
		{
			my_set_cursor(50, 11);
			printf("PLAYER WIN!!!");
		}
		else
		{
			my_set_cursor(50, 11);
			printf("COMPUTER WIN!!!");
		}
		Sleep(50);
	}
}


void field_init_player(Field &field, COORD &cur_cursor)
{
	int count = 0;
	bool direct = false;
	while (count < 10)
	{
		HANDLE hnd = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD cursor;
		COORD arr;
		int next[]{ 4,3,3,2,2,2,1,1,1,1 };
		char move;
		int temp;
		my_set_cursor(cur_cursor.X, cur_cursor.Y);
		arr.X = (cur_cursor.X / 4) - 1;
		arr.Y = (cur_cursor.Y / 2) - 1;
		if (direct)
		{
			ver_ship_create(field, arr, next[count]);
		}
		else
		{
			hor_ship_create(field, arr, next[count]);
		}
		field_print(field, 1);
		my_set_cursor(cur_cursor.X, cur_cursor.Y);
		move = _getch();
		switch (move)
		{
		case 'p':
			for (size_t i = 0; i < 100; i++)
			{
				field.field[0][i] = 0;
			}
			field_init_comp(field);
			return;
		case 'r':
			cursor = GetConsoleCursorPosition(hnd);
			if (cursor.X < 40 - ((next[count] - 2) * 4) && direct && hor_ship_check(field, cursor, next[count]))
			{
				direct = false;
				cursor = GetConsoleCursorPosition(hnd);
				ver_ship_remove(field, arr, next[count]);
				arr.X = (cursor.X / 4) - 1;
				arr.Y = (cursor.Y / 2) - 1;
				hor_ship_create(field, arr, next[count]);
			}
			else if (cursor.Y < 20 - ((next[count] - 2) * 2) && ver_ship_check(field, cursor, next[count]))
			{
				direct = true;
				cursor = GetConsoleCursorPosition(hnd);
				hor_ship_remove(field, arr, next[count]);
				arr.X = (cursor.X / 4) - 1;
				arr.Y = (cursor.Y / 2) - 1;
				ver_ship_create(field, arr, next[count]);
			}
			break;
		case 'w':
			cursor = GetConsoleCursorPosition(hnd);
			if (cursor.Y > 2)
			{
				temp = cur_cursor.Y;
				if (direct)
				{
					if (field.field[(cursor.Y / 2) - 1 - 1][(cursor.X / 4) - 1] == 0)
					{
						cur_cursor = w_check_cells(field, cursor);
					}
					else
					{
						cur_cursor.Y = vw_check_all(field, cursor, next[count]);
					}
					if (cur_cursor.Y == 22 || cur_cursor.X == 0)
					{
						cur_cursor.Y = temp;
						break;
					}
					else
					{
						my_set_cursor(cur_cursor.X, cur_cursor.Y -= 2);
					}
				}
				else
				{
					cur_cursor.Y = hw_check_all(field, cursor, next[count]);
					if (cur_cursor.Y == 22)
					{
						cur_cursor.Y = temp;
						break;
					}
					else
					{
						my_set_cursor(cur_cursor.X, cur_cursor.Y -= 2);
					}
				}
			}
			break;
		case 's':
			cursor = GetConsoleCursorPosition(hnd);
			if (cursor.Y < 20)
			{
				temp = cur_cursor.Y;
				if (direct)
				{
					if (field.field[(cursor.Y / 2) - 1 + next[count]][(cursor.X / 4) - 1] == 0 && (cursor.Y / 2) - 1 + next[count] <= 9)
					{
						my_set_cursor(cur_cursor.X, cur_cursor.Y += 2);
					}
					else
					{
						cur_cursor.Y = vs_check_all(field, cursor, next[count]);
						if (cur_cursor.Y == 0)
						{
							cur_cursor.Y = temp;
							break;
						}
						else
						{
							my_set_cursor(cur_cursor.X, cur_cursor.Y += 2);
						}
					}
				}
				else
				{
					cur_cursor.Y = hs_check_all(field, cursor, next[count]);
					if (cur_cursor.Y == 0)
					{
						cur_cursor.Y = temp;
						break;
					}
					else
					{
						my_set_cursor(cur_cursor.X, cur_cursor.Y += 2);
					}
				}
			}
			break;
		case 'a':
			cursor = GetConsoleCursorPosition(hnd);
			temp = cur_cursor.X;
			if (cursor.X > 4)
			{
				if (direct)
				{
					cur_cursor.X = va_check_all(field, cursor, next[count]);
					if (cur_cursor.X == 44)
					{
						cur_cursor.X = temp;
						break;
					}
					else
					{
						my_set_cursor(cur_cursor.X -= 4, cur_cursor.Y);
					}
				}
				else
				{
					if (field.field[(cursor.Y / 2) - 1][(cursor.X / 4) - 1 - 1] == 0)
					{
						cur_cursor = a_check_cells(field, cursor);
					}
					else
					{
						cur_cursor.X = ha_check_all(field, cursor, next[count]);
					}
					if (cur_cursor.X == 44 || cur_cursor.X == 0)
					{
						cur_cursor.X = temp;
						break;
					}
					else
					{
						my_set_cursor(cur_cursor.X -= 4, cur_cursor.Y);
					}
				}
			}
			break;
		case 'd':
			cursor = GetConsoleCursorPosition(hnd);
			temp = cur_cursor.X;
			if (cursor.X < 40)
			{
				if (direct)
				{
					cur_cursor.X = vd_check_all(field, cursor, next[count]);
					if (cur_cursor.X == 0)
					{
						cur_cursor.X = temp;
						break;
					}
					else
					{
						my_set_cursor(cur_cursor.X += 4, cur_cursor.Y);
					}
				}
				else
				{
					if (field.field[(cursor.Y / 2) - 1][(cursor.X / 4) - 1 + next[count]] == 0 && (cursor.X / 4) - 1 + next[count] <= 9)
					{
						my_set_cursor(cur_cursor.X += 4, cur_cursor.Y);
					}
					else
					{
						cur_cursor.X = hd_check_all(field, cursor, next[count]);
						if (cur_cursor.X == 0)
						{
							cur_cursor.X = temp;
							break;
						}
						else
						{
							my_set_cursor(cur_cursor.X += 4, cur_cursor.Y);
						}
					}
				}
			}
			break;
		case 13:
			if (direct)
			{
				if ((cur_cursor.X / 4) - 1 == 0)
				{
					vship_area(field, arr, next[count], left_side);
				}
				else
				{
					vship_area(field, arr, next[count], right_side);
				}
				count++;
				cur_cursor = vsearch_p(field, next[count]);
			}
			else
			{
				if ((cur_cursor.X / 4) - 1 == 0)
				{
					hship_area(field, arr, next[count], left_side);
				}
				else
				{
					hship_area(field, arr, next[count], right_side);
				}
				count++;
				cur_cursor = hsearch_p(field, next[count]);
			}
			my_set_cursor(cur_cursor.X, cur_cursor.Y);
			break;
		default:
			break;
		}
		if (move != 13)
		{
			if (direct)
			{
				ver_ship_remove(field, arr, next[count]);
			}
			else
			{
				hor_ship_remove(field, arr, next[count]);
			}
		}
	}
}

void field_init_comp(Field &field)
{
	int count = 0;
	bool direct = false;
	while (count < 10)
	{
		COORD cursor;
		COORD arr;
		int next[]{ 4,3,3,2,2,2,1,1,1,1 };
		direct = rand() % 2;
		int i = rand() % 10;
		if (direct)
		{
			cursor = vsearch_c(field, next[count], i);
			if (cursor.Y == 0)
			{
				continue;
			}
		}
		else
		{
			cursor = hsearch_c(field, next[count], i);
			if (cursor.X == 0)
			{
				continue;
			}
		}
		my_set_cursor(cursor.X, cursor.Y);
		arr.X = (cursor.X / 4) - 1;
		arr.Y = (cursor.Y / 2) - 1;
		if (direct)
		{
			ver_ship_create(field, arr, next[count]);
			if ((cursor.X / 4) - 1 == 0)
			{
				vship_area(field, arr, next[count], left_side);
			}
			else
			{
				vship_area(field, arr, next[count], right_side);
			}
		}
		else
		{
			hor_ship_create(field, arr, next[count]);
			if ((cursor.X / 4) - 1 == 0)
			{
				hship_area(field, arr, next[count], left_side);
			}
			else
			{
				hship_area(field, arr, next[count], right_side);
			}
		}
		count++;
	}
}


void save(Field &player, Field &comp,
			   COORD &cur_cursor, COORD &comp_cursor,
			   const int state, const int flag)
{
	FILE *file;
	fopen_s(&file, "save.bin", "wb+");
	fwrite(&player, sizeof(Field), 1, file);
	fwrite(&comp, sizeof(Field), 1, file);
	fwrite(&cur_cursor, sizeof(COORD), 1, file);
	fwrite(&comp_cursor, sizeof(COORD), 1, file);
	fwrite(&state, sizeof(int), 1, file);
	fwrite(&flag, sizeof(int), 1, file);
	fclose(file);
}

void load_game(Field &player, Field &comp,
			   COORD &cur_cursor, COORD &comp_cursor,
			   int &state, int &flag)
{
	FILE *file;
	fopen_s(&file, "save.bin", "rb+");
	fread_s(&player, sizeof(Field), sizeof(Field), 1, file);
	fread_s(&comp, sizeof(Field), sizeof(Field), 1, file);
	fread_s(&cur_cursor, sizeof(COORD), sizeof(COORD), 1, file);
	fread_s(&comp_cursor, sizeof(COORD), sizeof(COORD), 1, file);
	fread_s(&state, sizeof(int), sizeof(int), 1, file);
	fread_s(&flag, sizeof(int), sizeof(int), 1, file);
	fclose(file);
}