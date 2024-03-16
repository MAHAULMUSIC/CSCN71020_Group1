//Triangle solver - implimentation
//Group 1 - CSCN71000
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

bool getTriangleAngles(float* sides, float* angles)
{
	float pi = 3.14159;

	float sidessquared[AMOUNT_OF_SIDES_IN_TRIANGLE];

	for (int loop_variable = 0; loop_variable < AMOUNT_OF_SIDES_IN_TRIANGLE; loop_variable++)
	{

			sidessquared[loop_variable] = sides[loop_variable] * sides[loop_variable];

	}

	for (int loop_variable = 0; loop_variable < AMOUNT_OF_SIDES_IN_TRIANGLE; loop_variable++)
	{
		if (loop_variable == 0)
		{
			angles[0] = ((sidessquared[1] + sidessquared[2] - sidessquared[0]) / (2 * (sides[1] * sides[2])));
			angles[0] = acos(angles[0]);
			angles[0] = angles[0] * 180 / pi;
		}
		if (loop_variable == 1)
		{
			angles[1] = ((sidessquared[0] + sidessquared[2] - sidessquared[1]) / (2 * (sides[0] * sides[2])));
			angles[1] = acos(angles[1]);
			angles[1] = angles[1] * 180 / pi;
		}
		if (loop_variable == 2)
		{
			angles[2] = ((sidessquared[0] + sidessquared[1] - sidessquared[2]) / (2 * (sides[0] * sides[1])));
			angles[2] = acos(angles[2]);
			angles[2] = angles[2] * 180 / pi;
		}
	}
	return true;
}

int* getTriangleSides(int* triangleSides) {
	printf("Enter the three sides of the triangle: ");

	for (int i = 0; i < 3; i++) {
		printf("Side %d: ", i + 1);


		while (1) {                                               // Input validation
			if (scanf_s("%d", &triangleSides[i]) == 1) {
				if (triangleSides[i] > 0) {
					break;
				}
				else {
					printf("Invalid input. Please enter a positive integer for side %d: ", i + 1);
				}
			}
			else {

				while (getchar() != '\n'); // Clear the input buffer to handle non - integer inputs

				printf("Invalid input. Please enter a valid integer for side %d: ", i + 1);
			}
		}
	}



	return triangleSides;
}

