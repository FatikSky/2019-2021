#include "Header.h"

int main(void)
{
	////////////////////////////////////////////////////////
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
	////////////////////////////////////////////////////////
	srand(time(0));
	Field player;
	Field comp;
	COORD cur_cursor;
	COORD comp_cursor;
	int flag = 0;
	int state = 0;
	int condition = -5;
	print_game(player, comp, condition);
	cur_cursor.X = 4;
	cur_cursor.Y = 2;
	field_init_player(player, cur_cursor);
	field_init_comp(comp);
	cur_cursor.X = 64;
	cur_cursor.Y = 2;
	while (true)
	{
		char load;
		player_move(comp, player, cur_cursor, condition);
		if (the_end(comp))
		{
			printf("\a");
			_getch();
			WIN(true);
			exit(0);
		}
		comp_move(player, comp, comp_cursor, state, condition, flag);
		if (the_end(player))
		{
			printf("\a");
			_getch();
			WIN(false);
			exit(0);
		}
		my_set_cursor(0, 23);
		my_set_color(LIGHT_YELLOW);
		printf("PRESS F TO SAVE THE GAME\n");
		printf("PRESS R TO LOAD THE GAME\n");
		load = _getch();
		my_set_cursor(0, 23);
		printf("                                 \n"
			   "                                 \n");
		if (load == 'f')
		{
			my_set_cursor(0, 23);
			save(player, comp, cur_cursor, comp_cursor, state, flag);
			my_set_color(LIGHT_YELLOW);
			printf("Game succesfully saved.");
			Sleep(750);
			my_set_cursor(0, 23);
			printf("                                 ");
		}
		else if (load == 'r')
		{
			my_set_cursor(0, 23);
			load_game(player, comp, cur_cursor, comp_cursor, state, flag);
			my_set_color(LIGHT_YELLOW);
			printf("Game succesfully loaded.");
			Sleep(750);
			my_set_cursor(0, 23);
			printf("                                 ");
		}
	}
	return 0;
}