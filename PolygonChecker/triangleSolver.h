#pragma once
#include<stdbool.h>
#include<stdlib.h>
#include <stdio.h>
#include<ctype.h>
#include<math.h>
#include "main.h"
#include "rectangle_check.h"
#include "triangleSolver.h"
//triangle solver interface
//Group 1 - CSCN71000
#define AMOUNT_OF_SIDES_IN_TRIANGLE 3
char* analyzeTriangle(int side1, int side2, int side3);
int* getTriangleSides(int* triangleSides);
bool getTriangleAngles(float* sides, float* angles);