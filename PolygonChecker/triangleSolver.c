#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";

	// if any length is less than 0 return no triangle. 

	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}

	// else 

	else {

		// sum of two sides need to be greater than third side for it to be an actual triangle 

		if ((side1 + side2) > side3 && (side3 + side2) > side1 && (side1 + side3) > side2) {

			// if it is an actual triangle since it passes all our tests, find what kind it is 

			// Equilateral Triangle
			if(side1 == side2 && side1 == side3) {
				result = "Equilateral triangle";
			}

			// Isosceles Triangle 
			else if ((side1 == side2 && side1 != side3) || (side1 == side3 && side1 != side2)){
				result = "Isosceles triangle";
			}

			// Scalene Triangle 
			else {
				result = "Scalene Triangle";
			}
		}

		// this case is when the two sides of the triangle are smaller than the third side.

		else {
			result = "Not a Triangle";
		}
	}
	

	return result;
}