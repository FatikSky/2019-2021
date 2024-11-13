#include "Vertical Ships.h"

bool ver_ship_check(Field &field, COORD &cursor, const int count)
{
	for (size_t i = 0; i < count - 1; i++)
	{
		cursor.Y += 2;
		if (field.field[(cursor.Y / 2) - 1][(cursor.X / 4) - 1] == 1 ||
			field.field[(cursor.Y / 2) - 1][(cursor.X / 4) - 1] == -1)
		{
			return false;
		}
	}
	return true;
}

void ver_ship_create(Field &field, COORD &arr, const int count)
{
	for (size_t i = 0; i < count; i++)
	{
		field.field[arr.Y][arr.X] = 1;
		arr.Y++;
	}
}

void ver_ship_remove(Field &field, COORD &arr, const int count)
{
	for (size_t i = 0; i < count; i++)
	{
		arr.Y--;
		field.field[arr.Y][arr.X] = 0;
	}
}


void vship_area(Field &field, COORD &coor, int count, bool side(const int))
{
	field.field[coor.Y][coor.X] = -1;
	++coor.X;
	for (size_t j = 0; j < count + 2; j++)
	{
		if (side(coor.X))
		{
			field.field[coor.Y][coor.X] = -1;
		}
		--coor.Y;
	}
	++coor.Y;
	--coor.X;
	if (coor.X >= 0)
	{
		field.field[coor.Y][coor.X] = -1;
	}
	--coor.X;
	for (size_t j = 0; j < count + 2; j++)
	{
		if (side(coor.X))
		{
			field.field[coor.Y][coor.X] = -1;
		}
		++coor.Y;
	}
}


COORD vsearch_c(Field &field, const int count, int i = 0)
{
	bool found = false;
	COORD search;
	search.X = 0;
	search.Y = 0;
	for (; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (field.field[j][i] == 0)
			{
				found = true;
				search.X = (i + 1) * 4;
				search.Y = (j + 1) * 2;
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

COORD vsearch_p(Field &field, const int count)
{
	bool found = false;
	COORD search;
	search.X = 0;
	search.Y = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (field.field[j][i] == 0)
			{
				found = true;
				search.X = (i + 1) * 4;
				search.Y = (j + 1) * 2;
				for (size_t k = 0; k < count; k++)
				{
					j++;
					if (field.field[j][i] != 0 || j >= 10)
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


int vw_check_all(Field &field, COORD &cursor, const int count)
{
	for (size_t i = 0; i < count - 1; i++)
	{
		cursor.Y += 2;
	}
	cursor = w_check_cells(field, cursor);
	if (cursor.Y == 0)
	{
		return 22;
	}
	else
	{
		for (size_t i = 0; i < count - 1; i++)
		{
			cursor.Y -= 2;
			if (field.field[(cursor.Y / 2) - 1 - 1][(cursor.X / 4) - 1] == 1 ||
				field.field[(cursor.Y / 2) - 1 - 1][(cursor.X / 4) - 1] == -1)
			{
				return 22;
			}
		}
	}
	return w_check_cells(field, cursor).Y;
}

int vs_check_all(Field &field, COORD &cursor, const int count)
{
	for (size_t i = 0; i < count - 1; i++)
	{
		cursor.Y += 2;
	}
	cursor = s_check_cells(field, cursor);
	if (cursor.Y == 0)
	{
		return 0;
	}
	else
	{
		for (size_t i = 0; i < count - 1; i++)
		{
			cursor.Y += 2;
			if ((cursor.Y / 2) - 1 + 1 > 9)
			{
				return 0;
			}
			if (field.field[(cursor.Y / 2) - 1 + 1][(cursor.X / 4) - 1] == 1 ||
				field.field[(cursor.Y / 2) - 1 + 1][(cursor.X / 4) - 1] == -1)
			{
				return 0;
			}
		}
	}
	for (size_t i = 0; i < count - 1; i++)
	{
		cursor.Y -= 2;
	}
	return cursor.Y;
}

int va_check_all(Field &field, COORD &cursor, const int count)
{
	int* X_coor = (int*)malloc(sizeof(int) * count);
	COORD temp_cur = cursor;
	for (size_t i = 0; i < count; i++)
	{
		cursor = temp_cur;
		cursor = a_check_cells(field, cursor);
		temp_cur.Y += 2;
		X_coor[i] = cursor.X;
	}
	int min = 44;
	for (size_t i = 0; i < count; i++)
	{
		if (X_coor[i] == 0)
		{
			free(X_coor);
			return 44;
		}
		else if (X_coor[i] < min)
		{
			min = X_coor[i];
		}
	}
	free(X_coor);
	return min;
}

int vd_check_all(Field &field, COORD &cursor, const int count)
{
	int* X_coor = (int*)malloc(sizeof(int) * count);
	COORD temp_cur = cursor;
	for (size_t i = 0; i < count; i++)
	{
		cursor = temp_cur;
		cursor = d_check_cells(field, cursor);
		temp_cur.Y += 2;
		X_coor[i] = cursor.X;
	}
	int max = 0;
	for (size_t i = 0; i < count; i++)
	{
		if (X_coor[i] == 0)
		{
			free(X_coor);
			return 0;
		}
		else if (X_coor[i] > max)
		{
			max = X_coor[i];
		}
	}
	free(X_coor);
	return max;
}