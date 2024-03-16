#include "rectangle_check.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define PERCISION 0.001


// we need to find the distance between all the points using euclidian distance.
float distance_between_points(POINT point1, POINT point2) {
	float distance = 0;
	distance = sqrt(pow((point1.x - point2.x), 2) + pow((point1.y - point2.y), 2));
	return distance;
}

// this checks distance between all the lines
bool linechecker(POINT p1, POINT p2, POINT p3, POINT p4) {
	float side1 = distance_between_points(p1, p2);
	float side2 = distance_between_points(p2, p3);
	float side3 = distance_between_points(p3, p4);
	float side4 = distance_between_points(p1, p4);

	// now we will check if its actually a rectangle
	
	//case 1 when side1 and side2 are equal
	if ((side1 == side2) && (side3 == side4)) {
		float perimeter = (side1 + side2 + side3 + side4);
		float area = (side1 * side3);
		return true;
	}

	// case 2 when side1 and side3 are equal
	else if ((side1 == side3) && (side2 == side4)) {
		float perimeter = (side1 + side2 + side3 + side4);
		float area = (side1 * side3);
		return true;
	}


	else {
		fprintf(stderr, "Points dont make a rectangle.");
		return false;
	}

}


bool mostlyEqual(double a, double b) {
	double difference = fabs(a - b);
	if (difference < PERCISION)
		return true;
	else
		return false;
}