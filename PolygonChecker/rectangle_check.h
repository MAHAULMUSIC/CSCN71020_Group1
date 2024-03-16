#pragma once
#include <stdbool.h>

//defining a structure that ensures each point has an x and y value
typedef struct point{
	int x;
	int y;
}POINT;

float distance_between_points(POINT point1, POINT point2);
bool linechecker(POINT p1, POINT p2, POINT p3, POINT p4);
bool mostlyEqual(double a, double b);