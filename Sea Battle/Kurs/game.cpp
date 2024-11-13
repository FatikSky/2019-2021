#include "Header.h"


bool is_dead_right(Field &field, COORD comp_cursor)
{
	if (field.field[comp_cursor.Y][comp_cursor.X + 1] == 1)
	{
		return false;
	}
	else if (field.field[comp_cursor.Y][comp_cursor.X + 1] == -10)
	{
		++comp_cursor.X;
		if (is_dead_right(field, comp_cursor) == false)
		{
			return false;
		}
	}
	return true;
}

bool is_dead_left(Field &field, COORD comp_cursor)
{
	if (field.field[comp_cursor.Y][comp_cursor.X - 1] == 1)
	{
		return false;
	}
	else if (field.field[comp_cursor.Y][comp_cursor.X - 1] == -10)
	{
		--comp_cursor.X;
		if (is_dead_left(field, comp_cursor) == false)
		{
			return false;
		}
	}
	return true;
}

bool is_dead_down(Field &field, COORD comp_cursor)
{
	if (field.field[comp_cursor.Y + 1][comp_cursor.X] == 1)
	{
		return false;
	}
	else if (field.field[comp_cursor.Y + 1][comp_cursor.X] == -10)
	{
		++comp_cursor.Y;
		if (is_dead_down(field, comp_cursor) == false)
		{
			return false;
		}
	}
	return true;
}

bool is_dead_up(Field &field, COORD comp_cursor)
{
	if (field.field[comp_cursor.Y - 1][comp_cursor.X] == 1)
	{
		return false;
	}
	else if (field.field[comp_cursor.Y - 1][comp_cursor.X] == -10)
	{
		--comp_cursor.Y;
		if (is_dead_up(field, comp_cursor) == false)
		{
			return false;
		}
	}
	return true;
}

bool is_dead(Field &field, COORD &comp_cursor)
{
	if (is_dead_right(field, comp_cursor) == false)
	{
		return false;
	}
	if (is_dead_left(field, comp_cursor) == false)
	{
		return false;
	}
	if (is_dead_down(field, comp_cursor) == false)
	{
		return false;
	}
	if (is_dead_up(field, comp_cursor) == false)
	{
		return false;
	}
	return true;
}


void player_move(Field &comp, Field &player, COORD &cur_cursor, int &condition)
{
	char move = 'a';
	while (move != 13)
	{
		COORD arr;
		arr.X = ((cur_cursor.X - 60) / 4) - 1;
		arr.Y = (cur_cursor.Y / 2) - 1;
		int temp = comp.field[arr.Y][arr.X];
		comp.field[arr.Y][arr.X] = 2;
		print_game(player, comp, condition);
		my_set_cursor(cur_cursor.X, cur_cursor.Y);
		move = _getch();
		switch (move)
		{
		case 'w':
			if (cur_cursor.Y > 2)
			{
				my_set_cursor(cur_cursor.X, cur_cursor.Y -= 2);
			}
			break;
		case 's':
			if (cur_cursor.Y < 20)
			{
				my_set_cursor(cur_cursor.X, cur_cursor.Y += 2);
			}
			break;
		case 'a':
			if (cur_cursor.X > 64)
			{
				my_set_cursor(cur_cursor.X -= 4, cur_cursor.Y);
			}
			break;
		case 'd':
			if (cur_cursor.X < 100)
			{
				my_set_cursor(cur_cursor.X += 4, cur_cursor.Y);
			}
			break;
		case 13:
			if (temp == 1)
			{
				comp.field[arr.Y][arr.X] = -10;
				temp = -10;
				move = 0;
				if (is_dead(comp, arr))
				{
					condition = -2;
				}
				else
				{
					condition = -1;
				}
			}
			else if (temp == -10)
			{
				comp.field[arr.Y][arr.X] = temp;
			}
			else
			{
				comp.field[arr.Y][arr.X] = -2;
			}
			break;
		default:
			break;
		}
		if (move != 13)
		{
			comp.field[arr.Y][arr.X] = temp;
		}
	}
}


int dvijeniye(const Field &field, const int state, COORD &comp_cursor)
{
	switch (state)
	{
	case 0:
		if (comp_cursor.X < 9)
		{
			return 1;
		}
	case 1:
		if (comp_cursor.X > 0)
		{
			return 2;
		}
	case 2:
		if (comp_cursor.Y < 9)
		{
			return 3;
		}
	case 3:
		if (comp_cursor.Y > 0)
		{
			return 4;
		}
		break;
	default:
		break;
	}
}

void move(Field &field, const int state, COORD &comp_cursor, int &flag)
{
	switch (state)
	{
	case 1:
		++comp_cursor.X;
		while (field.field[comp_cursor.Y][comp_cursor.X] == -10)
		{
			++comp_cursor.X;
		}
		break;
	case 2:
		--comp_cursor.X;
		while (field.field[comp_cursor.Y][comp_cursor.X] == -10)
		{
			--comp_cursor.X;
		}
		break;
	case 3:
		++comp_cursor.Y;
		while (field.field[comp_cursor.Y][comp_cursor.X] == -10)
		{
			++comp_cursor.Y;
		}
		break;
	case 4:
		--comp_cursor.Y;
		while (field.field[comp_cursor.Y][comp_cursor.X] == -10)
		{
			--comp_cursor.Y;
		}
		break;
	default:
		break;
	}
}

void move_back(const int state, COORD &comp_cursor)
{
	switch (state)
	{
	case 1:
		if (comp_cursor.X > 0)
		{
			--comp_cursor.X;
		}
		break;
	case 2:
		if (comp_cursor.X < 9)
		{
			++comp_cursor.X;
		}
		break;
	case 3:
		if (comp_cursor.Y > 0)
		{
			--comp_cursor.Y;
		}
		break;
	case 4:
		if (comp_cursor.Y < 9)
		{
			++comp_cursor.Y;
		}
		break;
	default:
		break;
	}
}


void comp_move(Field &player, Field &comp, COORD &comp_cursor, int &state, int &condition, int &flag)
{
	if (state == 0)
	{
		COORD arr;
		arr.X = rand() % 10;
		arr.Y = rand() % 10;
		while (player.field[arr.Y][arr.X] == -2 || player.field[arr.Y][arr.X] == -10)
		{
			arr.X = rand() % 10;
			arr.Y = rand() % 10;
		}
		comp_cursor = arr;
	}
	while (true)
	{
		int temp = player.field[comp_cursor.Y][comp_cursor.X];
		if (temp == 1)
		{
			player.field[comp_cursor.Y][comp_cursor.X] = -10;
			temp = -10;
			if (flag == 0)
			{
				flag = -2;
			}
			condition = 1;
		}
		else if (temp == -10)
		{
			player.field[comp_cursor.Y][comp_cursor.X] = temp;
			temp = 1;
		}
		else
		{
			player.field[comp_cursor.Y][comp_cursor.X] = -2;
		}
		print_game(player, comp, condition);
		Sleep(1000);
		my_set_cursor((comp_cursor.X + 1) * 4, (comp_cursor.Y + 1) * 2);
		if (flag == -2 || flag == 1 || flag == -1)
		{
			if (is_dead(player, comp_cursor) && (temp == -10 || temp == 1))
			{
				comp_cursor.X = rand() % 10;
				comp_cursor.Y = rand() % 10;
				state = 0;
				condition = 2;
				flag = 0;
				continue;
			}
			if (flag == -2)
			{
				flag = -1;
			}
			if (player.field[comp_cursor.Y][comp_cursor.X] == -1 ||
				player.field[comp_cursor.Y][comp_cursor.X] == -2)
			{
				flag = -1;
				move_back(state, comp_cursor);
			}
			if (flag == -1)
			{
				state = dvijeniye(player, state, comp_cursor);
				flag = 1;
			}
			move(player, state, comp_cursor, flag);
			if (temp == -10)
			{
				continue;
			}
		}
		break;
	}
}


bool the_end(Field &field)
{
	for (size_t i = 0; i < 100; i++)
	{
		if (field.field[0][i] == 1)
		{
			return false;
		}
	}
	return true;
}