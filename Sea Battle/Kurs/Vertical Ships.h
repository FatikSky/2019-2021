#pragma once
#include "Header.h"

bool ver_ship_check(Field &field, COORD &cursor, const int count);
void ver_ship_create(Field &field, COORD &arr, const int count);
void ver_ship_remove(Field &field, COORD &arr, const int count);

void vship_area(Field &field, COORD &coor, int count, bool side(const int));

COORD vsearch_p(Field &field, const int count);
COORD vsearch_c(Field &field, const int count, int i);

int vw_check_all(Field &field, COORD &cursor, const int count);
int vs_check_all(Field &field, COORD &cursor, const int count);
int va_check_all(Field &field, COORD &cursor, const int count);
int vd_check_all(Field &field, COORD &cursor, const int count);