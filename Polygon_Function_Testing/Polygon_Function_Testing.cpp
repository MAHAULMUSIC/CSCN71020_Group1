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
extern "C" bool linechecker(POINT p1, POINT p2, POINT p3, POINT p4);
extern "C" bool mostlyEqual(double a, double b);

// defining constants 
#define AMOUNT_OF_SIDES_IN_TRIANGLE 3

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonFunctionTesting
{
	TEST_CLASS(TriangleAngleTesting)
	{
	public:

		TEST_METHOD(Triangleangle_Test_1)
		{
			float sides[AMOUNT_OF_SIDES_IN_TRIANGLE] = { 57, 90, 45 };
			float angles[AMOUNT_OF_SIDES_IN_TRIANGLE];
			getTriangleAngles(sides, angles);
			int expected = 180;
			int actual = (int)(angles[0] + angles[1] + angles[2]);
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(Triangleangle_Test_2)
		{
			float sides[AMOUNT_OF_SIDES_IN_TRIANGLE] = { 1, 1, 1 };
			float angles[AMOUNT_OF_SIDES_IN_TRIANGLE];
			getTriangleAngles(sides, angles);
			int expected = 180;
			int actual = (int)(angles[0] + angles[1] + angles[2]);
			Assert::AreEqual(actual, expected);
		} 

	};

	TEST_CLASS(DistanceCheckerTesting)
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
			Assert::IsTrue(mostlyEqual(expected, actual));
		}

		TEST_METHOD(DistanceChecker_Test4) {
			POINT p1 = { 0, 0 };
			POINT p2 = { 0, 0 };
			float expected = 0.0;
			float actual = distance_between_points(p1, p2);
			Assert::AreEqual(expected, actual);
		}

	};

	TEST_CLASS(RectangleCheckerTesting)
	{
	public:

		// testing the Rectangle Checker 

	
		TEST_METHOD(RectangleChecker_Test1) {
			// all sides are equal
			POINT p1 = { 0, 0 };
			POINT p2 = { 1, 0 };
			POINT p3 = { 1, 1 };
			POINT p4 = { 0, 1 };
			Assert::IsTrue(linechecker(p1, p2, p3, p4));

		}

		TEST_METHOD(RectangleChecker_Test2) {
			// one longer side and one shorter side
			POINT p1 = { 0, 0 };
			POINT p2 = { 2, 0 }; 
			POINT p3 = { 2, 1 };
			POINT p4 = { 0, 1 }; 
			Assert::IsTrue(linechecker(p1, p2, p3, p4));
		}

		TEST_METHOD(RectangleChecker_Test3) {
			// this forms a random shape 
			POINT p1 = { 0, 0 };
			POINT p2 = { 1, 0 };
			POINT p3 = { 1, 2 }; 
			POINT p4 = { 0, 1 };
			Assert::IsFalse(linechecker(p1, p2, p3, p4));
		}

		TEST_METHOD(RectangleChecker_Test4) {
			// forms a straight line
			POINT p1 = { 0, 0 };
			POINT p2 = { 1, 1 };
			POINT p3 = { 2, 2 };
			POINT p4 = { 3, 3 };
			Assert::IsFalse(linechecker(p1, p2, p3, p4));
		}


	};
	//TEST_CLASS(TESTING_RECTANGLE_USER_INPUT)
	//{
	//    //Attempting to do user input function testing but I cant figure it out, I want to talk to prof to see if she has any advice on how to do this
	//    //this should work but FILE only exisits in comiplation NOT build/test so I cannot open the file to redirect the scanf input from stdin to take info from the file, that has to be done in main on compile
	//    //TEST_METHOD(Rectangle_user_input_test_1)
	//    //{
	//    //
	//    //    FILE * fp = freopen("\RectangleUnitTest.txt", "r", stdin);
	//    //    POINT p = Rectangleuserinput();
	//    //    int actual_x = p.x;
	//    //    int expected_x = 4;
	//    //    Assert::AreEqual(expected_x, actual_x);

	//    //}
	//};
}
