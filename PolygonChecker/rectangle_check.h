#pragma once

//defining a structure that ensures each point has an x and y value
typedef struct {
	int x;
	int y;
}POINT;

float distance_between_points(POINT point1, POINT point2);
void linechecker(POINT p1, POINT p2, POINT p3, POINT p4);
