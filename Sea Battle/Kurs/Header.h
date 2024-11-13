#pragma once
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void my_set_cursor(int x, int y);

struct Field
{
	int field[10][10]{};
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

void my_set_color(int fg = 11, int bg = 0);

COORD GetConsoleCursorPosition(HANDLE hConsoleOutput);

void WIN(bool winner);

void field_init_player(Field &field, COORD &cur_cursor);
void field_init_comp(Field &field);

void save(Field &player, Field &comp, COORD &cur_cursor, COORD &comp_cursor, const int state, const int flag);
void load_game(Field &player, Field &comp, COORD &cur_cursor, COORD &comp_cursor, int &state, int &flag);

void field_print(Field &field, int x, char turn);
void print_game(Field &player, Field &comp, int &condition);

void player_move(Field &comp, Field &player, COORD &cur_cursor, int &condition);
void comp_move(Field &player, Field &comp, COORD &comp_cursor, int &state, int &condition, int &flag);

COORD w_check_cells(Field &field, COORD &cursor);
COORD s_check_cells(Field &field, COORD &cursor);
COORD a_check_cells(Field &field, COORD &cursor);
COORD d_check_cells(Field &field, COORD &cursor);

bool the_end(Field &field);