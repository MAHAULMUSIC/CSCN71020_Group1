#include "pch.h"
#include "CppUnitTest.h"

// including all the header files 
extern "C" {
#include "triangleSolver.h"
}
extern "C" {
#include "rectangle_check.h"
}
extern "C" {
#include "main.h"
}

// externing all functions that we want to test/use 
extern "C" float distance_between_points(POINT point1, POINT point2);
extern "C" void linechecker(POINT p1, POINT p2, POINT p3, POINT p4);

// defining constants 
#define AMOUNT_OF_SIDES_IN_TRIANGLE 3

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonFunctionTesting
{
	TEST_CLASS(PolygonFunctionTesting)
	{
	public:

		TEST_METHOD(TestMethod1)
		{

		}

		TEST_METHOD(Triangle_angle_Test_1)
		{
			float sides[AMOUNT_OF_SIDES_IN_TRIANGLE] = { 57, 90, 45 };
			float angles[AMOUNT_OF_SIDES_IN_TRIANGLE];
			getTriangleAngles(sides, angles);
			int expected = 180;
			int actual = (int)(angles[0] + angles[1] + angles[2]);
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(Triangle_angle_Test_2)
		{
			float sides[AMOUNT_OF_SIDES_IN_TRIANGLE] = { 1, 1, 1 };
			float angles[AMOUNT_OF_SIDES_IN_TRIANGLE];
			getTriangleAngles(sides, angles);
			int expected = 180;
			int actual = (int)(angles[0] + angles[1] + angles[2]);
			Assert::AreEqual(actual, expected);
		} 
	};

	TEST_CLASS(RectangleFunctionTesting)
	{
	public:

		// testing the distance between the points 

		TEST_METHOD(DistanceChecker_Test1) {
			POINT p1 = { 0, 0 };
			POINT p2 = { 3, 4 };
			float expected = 5.0;
			float actual = distance_between_points(p1, p2);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(DistanceChecker_Test2) {
			POINT p1 = { -1, -1 };
			POINT p2 = { -4, -5 };
			float expected = 5.0;
			float actual = distance_between_points(p1, p2);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(DistanceChecker_Test3) {
			POINT p1 = { 0, 0 };
			POINT p2 = { 1, 1 };
			float expected = 1.414;
			float actual = distance_between_points(p1, p2);
			Assert::AreEqual(expected, actual);
		}

	};
}
