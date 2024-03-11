#include "pch.h"
#include "CppUnitTest.h"
extern "C" {
#include"triangleSolver.h"
}
#define AMOUNT_OF_SIDES_IN_TRIANGLE 3
extern "C" void getTriangleAngles(float* sides, float* angles);
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
		TEST_METHOD(Triangle_angle_test_3)
		{

			float sides[AMOUNT_OF_SIDES_IN_TRIANGLE] = { 0 ,0 , 0 };

			float angles[AMOUNT_OF_SIDES_IN_TRIANGLE];

			getTriangleAngles(sides, angles);

			int expected = 180;

			int actual = (int)(angles[0] + angles[1] + angles[2]);

			Assert::AreNotEqual(actual, expected);
		}
		TEST_METHOD(Triangle_angle_test_4)
		{
			float sides[AMOUNT_OF_SIDES_IN_TRIANGLE] = { '&', 1, 2 };
			
			float angles[AMOUNT_OF_SIDES_IN_TRIANGLE];

			getTriangleAngles(sides, angles);

			int expected = 180;

			int actual = (int)(angles[0] + angles[1] + angles[2]);

			Assert::AreNotEqual(actual, expected);
		}
	};
}
