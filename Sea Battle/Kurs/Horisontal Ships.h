#pragma once
#include "Header.h"

bool hor_ship_check(Field &field, COORD &cursor, const int count);
void hor_ship_create(Field &field, COORD &arr, const int count);
void hor_ship_remove(Field &field, COORD &arr, const int count);

bool left_side(const int coor);
bool right_side(const int coor);

void hship_area(Field &field, COORD &coor, int count, bool side(const int));

COORD hsearch_p(Field &field, const int count);
COORD hsearch_c(Field &field, const int count, int i);

int hw_check_all(Field &field, COORD &cursor, const int count);
int hs_check_all(Field &field, COORD &cursor, const int count);
int ha_check_all(Field &field, COORD &cursor, const int count);
int hd_check_all(Field &field, COORD &cursor, const int count);