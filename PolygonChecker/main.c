#include <stdio.h>
#include <stdbool.h>
#include<ctype.h>
#include<math.h>
#include "main.h"
#include "rectangle_check.h"
#include "triangleSolver.h"
#define XYCoordinateAmounts 8
#define AMOUNT_OF_SIDES_IN_TRIANGLE 3
POINT Rectangleuserinput();
int side = 0;

int main() {

	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{ 
		 
		case 2: 
			printf("Rectangle selected.\n");
			POINT p1, p2, p3, p4;

			// Input for each point with a single prompt
			printf("Enter First pair of coordinates (x y): ");
			scanf_s("%d %d", &p1.x, &p1.y);
			printf("Enter Second pair of coordinates (x y): ");
			scanf_s("%d %d", &p2.x, &p2.y);
			printf("Enter third pair coordinates (x y): ");
			scanf_s("%d %d", &p3.x, &p3.y);
			printf("Enter fourth pair coordinates (x y): ");
			scanf_s("%d %d", &p4.x, &p4.y);

			// Calling linechecker with the input points
			bool result1 = linechecker(p1, p2, p3, p4);
			printf(result1 ? "Line check passed.\n" : "Line check failed.\n");
			break;
		
			
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
	printf_s("2. Rectangle\n");
	printf_s("1. Triangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	int valid_check = scanf_s("%d", &shapeChoice);
	if (valid_check != 1)
	{
		while (getchar() != '\n');
	}

	return shapeChoice;
}

POINT Rectangleuserinput()
{
	POINT p;
	int input_value_1 = 0;

	while (input_value_1 == 0)
	{
		printf("Please enter a input for x: ");
		int valid_check_1 = scanf("%d", &p.x);
		if (valid_check_1 != 1)
		{
			printf("invalid input\n");
			while (getchar() != '\n');
		}
		else
		{
			input_value_1 = 1;
		}
	}

	int input_value_2 = 0;
	while (input_value_2 == 0)
	{
		printf("please enter a input for y: ");
		int valid_check_2 = scanf("%d", &p.y);
		if (valid_check_2 != 1)
		{
			printf("invalid input\n");
			while (getchar() != '\n');
		}
		else
		{
			input_value_2 = 1;
		}
	}
	return p;
}



