#include "Horisontal Ships.h"

bool hor_ship_check(Field &field, COORD &cursor, const int count)
{	
	for (size_t i = 0; i < count - 1; i++)
	{
		cursor.X += 4;
		if (field.field[(cursor.Y / 2) - 1][(cursor.X / 4) - 1] == 1 ||
			field.field[(cursor.Y / 2) - 1][(cursor.X / 4) - 1] == -1)
		{
			return false;
		}
	}
	return true;
}

void hor_ship_create(Field &field, COORD &arr, const int count)
{
	for (size_t i = 0; i < count; i++)
	{
		field.field[arr.Y][arr.X] = 1;
		arr.X++;
	}
}

void hor_ship_remove(Field &field, COORD &arr, const int count)
{
	for (size_t i = 0; i < count; i++)
	{
		arr.X--;
		field.field[arr.Y][arr.X] = 0;
	}
}


bool left_side(const int coor)
{
	return coor >= 0;
}

bool right_side(const int coor)
{
	return coor <= 9;
}

void hship_area(Field &field, COORD &coor, int count, bool side(const int))
{
	if (coor.X <= 9)
	{
		field.field[coor.Y][coor.X] = -1;
	}
	++coor.Y;
	for (size_t j = 0; j < count + 2; j++)
	{
		if (side(coor.X))
		{
			field.field[coor.Y][coor.X] = -1;
		}
		--coor.X;
	}
	++coor.X;
	--coor.Y;
	if (coor.X >= 0)
	{
		field.field[coor.Y][coor.X] = -1;
	}
	--coor.Y;
	for (size_t j = 0; j < count + 2; j++)
	{
		if (side(coor.X))
		{
			field.field[coor.Y][coor.X] = -1;
		}
		++coor.X;
	}
}


COORD hsearch_c(Field &field, const int count, int i = 0)
{
	bool found = false;
	COORD search;
	search.X = 0;
	search.Y = 0;
	for (; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (field.field[i][j] == 0)
			{
				found = true;
				search.X = (j + 1) * 4;
				search.Y = (i + 1) * 2;
				for (size_t k = 0; k < count; k++)
				{
					j++;
					if (field.field[i][j] != 0 || j >= 10)
					{
						found = false;
						break;
					}
				}
				if (found)
				{
					return search;
				}
			}
		}
	}
	search.X = 0;
	search.Y = 0;
	return search;
}

COORD hsearch_p(Field &field, const int count)
{
	bool found = false;
	COORD search;
	search.X = 0;
	search.Y = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (field.field[i][j] == 0)
			{
				found = true;
				search.X = (j + 1) * 4;
				search.Y = (i + 1) * 2;
				for (size_t k = 0; k < count; k++)
				{
					j++;
					if (field.field[i][j] != 0 || j >= 10)
					{
						found = false;
						break;
					}
				}
				if (found)
				{
					return search;
				}
			}
		}
	}
	return search;
}


COORD w_check_cells(Field &field, COORD &cursor)
{
	int temp = field.field[((cursor.Y / 2) - 1) - 1][(cursor.X / 4) - 1];
	if (cursor.Y <= 2)
	{
		cursor.Y = 0;
		return cursor;
	}
	else if (temp == -1 || temp == 1)
	{
		cursor.Y -= 2;
		w_check_cells(field, cursor);
	}
	else
	{
		return cursor;
	}
}

COORD s_check_cells(Field &field, COORD &cursor)
{
	int temp = field.field[((cursor.Y / 2) - 1) + 1][(cursor.X / 4) - 1];
	if (cursor.Y >= 20)
	{
		cursor.Y = 0;
		return cursor;
	}
	else if (temp == -1 || temp == 1)
	{
		cursor.Y += 2;
		s_check_cells(field, cursor);
	}
	else
	{
		return cursor;
	}
}

COORD a_check_cells(Field &field, COORD &cursor)
{
	int temp = field.field[(cursor.Y / 2) - 1][((cursor.X / 4) - 1) - 1];
	if (cursor.X <= 4)
	{
		cursor.X = 0;
		return cursor;
	}
	else if (temp == -1 || temp == 1)
	{
		cursor.X -= 4;
		a_check_cells(field, cursor);
	}
	else
	{
		return cursor;
	}
}

COORD d_check_cells(Field &field, COORD &cursor)
{
	int temp = field.field[(cursor.Y / 2) - 1][((cursor.X / 4) - 1) + 1];
	if (cursor.X >= 40)
	{
		cursor.X = 0;
		return cursor;
	}
	else if (temp == -1 || temp == 1)
	{
		cursor.X += 4;
		d_check_cells(field, cursor);
	}
	else
	{
		return cursor;
	}
}


int hw_check_all(Field &field, COORD &cursor, const int count)
{
	int* Y_coor = (int*)malloc(sizeof(int) * count);
	COORD temp_cur = cursor;
	for (size_t i = 0; i < count; i++)
	{
		cursor = temp_cur;
		cursor = w_check_cells(field, cursor);
		temp_cur.X += 4;
		Y_coor[i] = cursor.Y;
	}
	int min = 22;
	for (size_t i = 0; i < count; i++)
	{
		if (Y_coor[i] == 0)
		{
			free(Y_coor);
			return 22;
		}
		else if (Y_coor[i] < min)
		{
			min = Y_coor[i];
		}
	}
	free(Y_coor);
	return min;
}

int hs_check_all(Field &field, COORD &cursor, const int count)
{
	int* Y_coor = (int*)malloc(sizeof(int) * count);
	COORD temp_cur = cursor;
	for (size_t i = 0; i < count; i++)
	{
		cursor = temp_cur;
		cursor = s_check_cells(field, cursor);
		temp_cur.X += 4;
		Y_coor[i] = cursor.Y;
	}
	int max = 0;
	for (size_t i = 0; i < count; i++)
	{
		if (Y_coor[i] == 0)
		{
			free(Y_coor);
			return 0;
		}
		else if (Y_coor[i] > max)
		{
			max = Y_coor[i];
		}
	}
	free(Y_coor);
	return max;
}

int ha_check_all(Field &field, COORD &cursor, const int count)
{
	for (size_t i = 0; i < count - 1; i++)
	{
		cursor.X += 4;
	}
	cursor = a_check_cells(field, cursor);
	if (cursor.X == 0)
	{
		return 44;
	}
	else
	{
		for (size_t i = 0; i < count - 1; i++)
		{
			cursor.X -= 4;
			if (field.field[(cursor.Y / 2) - 1][(cursor.X / 4) - 1 - 1] == 1 ||
				field.field[(cursor.Y / 2) - 1][(cursor.X / 4) - 1 - 1] == -1)
			{
				return 44;
			}
		}
	}
	return a_check_cells(field, cursor).X;
}

int hd_check_all(Field &field, COORD &cursor, const int count)
{
	for (size_t i = 0; i < count - 1; i++)
	{
		cursor.X += 4;
	}
	cursor = d_check_cells(field, cursor);
	if (cursor.X == 0)
	{
		return 0;
	}
	else
	{
		for (size_t i = 0; i < count - 1; i++)
		{
			cursor.X += 4;
			if ((cursor.X / 4) - 1 + 1 > 9)
			{
				return 0;
			}
			if (field.field[(cursor.Y / 2) - 1][(cursor.X / 4) - 1 + 1] == 1 ||
				field.field[(cursor.Y / 2) - 1][(cursor.X / 4) - 1 + 1] == -1)
			{
				return 0;
			}
		}
	}
	for (size_t i = 0; i < count - 1; i++)
	{
		cursor.X -= 4;
	}
	return cursor.X;
}