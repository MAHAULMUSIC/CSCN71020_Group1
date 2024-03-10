#include <stdio.h>
#include <stdbool.h>
#include<math.h>
#include "main.h"
#include "triangleSolver.h"

#define AMOUNT_OF_SIDES_IN_TRIANGLE 3

int side = 0;

void getTriangleAngles(float* sides, float* angles);

int main() {

	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}

void getTriangleAngles(float* sides, float* angles)
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

}


