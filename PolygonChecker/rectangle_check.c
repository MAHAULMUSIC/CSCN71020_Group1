//Rectangle Check Implemenetation
//Group 1 - CSCN71000


#include "rectangle_check.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define PERCISION 0.001

// this checks if everything is equal
bool mostlyEqual(double a, double b) {
	double difference = fabs(a - b);
	if (difference < PERCISION)
		return true;
	else
		return false;
}

// we need to find the distance between all the points using euclidian distance.
float distance_between_points(POINT point1, POINT point2) {
	float distance = 0;
	distance = sqrt(pow((point1.x - point2.x), 2) + pow((point1.y - point2.y), 2));
	return distance;
}

// this checks distance between all the lines
bool linechecker(POINT p1, POINT p2, POINT p3, POINT p4) {

	// creating an array called corners that will assign every corner 
	POINT corners[4] = { p1,p2,p3,p4 };

	// initializing every point to p1 for the matter of comparison
	// ll - lower left corner
	POINT ll = p1;
	// lr - lower right corner
	POINT lr = p1;
	// ul - upper left corner
	POINT ul = p1;
	// ur - upper right corner 
	POINT ur = p1;


	// Loop through all points to find the corners
	for (int i = 0; i < 4; i++) {

		// Lower left corner: Minimum x and y
		if (corners[i].x <= ll.x && corners[i].y <= ll.y) ll = corners[i];

		// Lower right corner: Maximum x, Minimum y
		if (corners[i].x >= lr.x && corners[i].y <= lr.y) lr = corners[i];

		// Upper left corner: Minimum x, Maximum y
		if (corners[i].x <= ul.x && corners[i].y >= ul.y) ul = corners[i];

		// Upper right corner: Maximum x and y
		if (corners[i].x >= ur.x && corners[i].y >= ur.y) ur = corners[i];
	}

	// calculating all distances 
	float side1 = distance_between_points(ll, ul);
	float side2 = distance_between_points(ul, ur);
	float side3 = distance_between_points(ur, lr);
	float side4 = distance_between_points(lr, ll);
	float diagonal1 = distance_between_points(ll, ur);
	float diagonal2 = distance_between_points(ul, lr);

	// now we will check if its actually a rectangle
	
	if (mostlyEqual(side1, side3) && mostlyEqual(side2, side4) && mostlyEqual(diagonal1, diagonal2)) {
		float perimeter = (side1 + side2 + side3 + side4);
		float area = (side1 * side2);
		fprintf(stdout, "These points make a rectangle. \n Perimeter: %f \n Area: %f\n", perimeter, area);
		return true; 
	}

	else {
		fprintf(stderr, "Points dont make a rectangle.");
		return false; 
	}

}

