#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "Truck_r.h"
#include "Test_r.h"
#include "mapping_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		//BLACK BOX

		//Check if Map correct numRows and numCols
		TEST_METHOD(TestPopulateMap)
		{
			Logger::WriteMessage("Testing numRows and numCols after populating, Valid");
			int result = test_populateMap();
			int correct = 1;
			Assert::AreEqual(correct, result);
		}
		//Check if every cell in the created map matches the example map, to make sure
		//it's made with no errors
		TEST_METHOD(TestMapping)
		{
			Logger::WriteMessage("Testing Map Content, Valid");
			struct Map result = populateMap();
			int match = 1;
			struct Map correct = {
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//2
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//5
				{1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},	//6
				{1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//7
				{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//8
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//9
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//10
				{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//11
				{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//12
				{1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//13
				{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//14
				{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//15
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//16
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//17
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//18
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//19
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//20
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},	//21
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},	//22
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},	//23
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}		//24
				},
				MAP_ROWS, MAP_COLS
			};

			for (int i = 0; i < MAP_ROWS && match == 1; i++) {
				for (int j = 0; j < MAP_COLS && match == 1; j++) {
					result.squares[i][j] == correct.squares[i][j] ? match = 1 : match = 0;
				}
			}
			//Test passes if int confirms all cells are the same
			Assert::AreEqual(1, match);
		}
		//Test to see if it returns the correct amount of rows
		TEST_METHOD(TestGetNumRows1)
		{
			Logger::WriteMessage("Testing getNumRows for Map, Valid");
			struct Map map = populateMap();
			int result = getNumRows(&map);
			int correct = MAP_ROWS;
			Assert::AreEqual(correct, result);
		}
		//Test to see if it returns the correct amount of rows after modification
		TEST_METHOD(TestGetNumRows2)
		{
			Logger::WriteMessage("Testing getNumRows for Map after modifying rows, Valid");
			struct Map map = populateMap();
			map.numRows = 34;
			int result = getNumRows(&map);
			int correct = 34;
			Assert::AreEqual(correct, result);
		}
		//Test to see if it throws an exception when getting rows for invalid map
		TEST_METHOD(TestGetNumRows3)
		{
			Logger::WriteMessage("Testing getNumRows to see if it throws an exception for an uninitialized map object, Valid");
			struct Map map;
			int correct = MAP_ROWS;

			Assert::AreNotEqual(correct, getNumRows(&map));
		}
		//Test to see if it returns the correct amount of cols after initialization
		TEST_METHOD(TestGetNumCols1)
		{
			Logger::WriteMessage("Testing getNumCols for Map, Valid");
			struct Map map = populateMap();
			int result = getNumCols(&map);
			int correct = MAP_COLS;
			Assert::AreEqual(correct, result);
		}
		//Test to see if it returns the correct amount of cols after modification
		TEST_METHOD(TestGetNumCols2)
		{
			Logger::WriteMessage("Testing getNumCols for Map after modifying cols, Valid");
			struct Map map = populateMap();
			map.numCols = 34;
			int result = getNumCols(&map);
			int correct = 34;
			Assert::AreEqual(correct, result);
		}
		//Test to see if it throws an exception when getting cols for invalid map
		TEST_METHOD(TestGetNumCols3)
		{
			Logger::WriteMessage("Testing getNumCols to see if it throws an exception for an uninitialized map object, Valid");
			struct Map map;
			int correct = MAP_COLS;

			Assert::AreNotEqual(correct, getNumCols(&map));
		}
		//Test to see if getBlueRoute works as intended
		TEST_METHOD(TestGetBlueRoute)
		{
			Logger::WriteMessage("Testing getBlueRoute to see if it generates and returns a valid route, Valid");
			struct Route blue = getBlueRoute();
			struct Route correct = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8},{4, 9},
			{5, 9},
			{6, 9},
			{7, 9},
			{8, 9},
			{9, 9},
			{10, 9},{10, 10},
			{11, 10},
			{12, 10},
			{13, 10},
			{14, 10},
			{15, 10},
			{16, 10},
			{17, 10},{17, 11},{17, 12},{17, 13},{17, 14},{17, 15},{17, 16},{17, 17},{17, 18},{17, 19},{17, 20},
				{17, 21},{17, 22},{17, 23},{17, 24},
		},
			42, BLUE
			};

			int match = 1;

			for (int i = 0; i < blue.numPoints && match == 1; i++) {
				blue.points[i].col == correct.points[i].col ? match = 1 : match = 0;
				blue.points[i].row == correct.points[i].row ? match = 1 : match = 0;
			}

			Assert::AreEqual(1, match);
		}
		//Test to see if getYellowRoute works as intended
		TEST_METHOD(TestGetYellowRoute)
		{
			Logger::WriteMessage("Testing TestGetYellowRoute to see if it generates and returns a valid route, Valid");
			struct Route yellow = getYellowRoute();
			struct Route correct = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}, {4, 1}, {4, 2}, {4, 3},
			{5, 3},
			{6, 3},
			{7, 3},
			{8, 3},
			{9, 3},{9, 2},{9, 1},
			{10, 1},
			{11, 1},
			{12, 1},
			{13, 1},
			{14, 1},
			{15, 1},
			{16, 1},
			{17, 1},
			{18, 1},
			{19, 1},{19, 2},{19, 3},{19, 4},{19, 5},{19, 6},{19, 7},{19, 8},{19, 9},{19, 10},{19, 11},{19, 12},
				{19, 13},{19, 14},{19, 15},{19, 16},{19, 17},{19, 18},{19, 19},{19, 20},{19, 21},{19, 22},{19, 23},{19, 24}
		},
			48, YELLOW
			};

			int match = 1;

			for (int i = 0; i < yellow.numPoints && match == 1; i++) {
				yellow.points[i].col == correct.points[i].col ? match = 1 : match = 0;
				yellow.points[i].row == correct.points[i].row ? match = 1 : match = 0;
			}

			Assert::AreEqual(1, match);
		}
		//Test to see if getGreenRoute works as intended
		TEST_METHOD(TestGetGreenRoute)
		{
			Logger::WriteMessage("Testing TestGetGreenRoute to see if it generates and returns a valid route, Valid");
			struct Route green = getGreenRoute();
			struct Route correct = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8},{4, 9},{4, 10},{4, 11},
			{3, 11},
			{2, 11},
			{1, 11},
			{0, 11},{0, 12},{0, 13},{0, 14},{0, 15},{0, 16},{0, 17},{0, 18},{0, 19},
			{1, 19},
			{2, 19},
			{3, 19},
			{4, 19},
			{5, 19},
			{6, 19},
			{7, 19},
			{8, 19},
			{9, 19},{9, 20},{9, 21},{9, 22},{9, 23},{9, 24}

		},
			42, GREEN
			};

			int match = 1;

			for (int i = 0; i < green.numPoints && match == 1; i++) {
				green.points[i].col == correct.points[i].col ? match = 1 : match = 0;
				green.points[i].row == correct.points[i].row ? match = 1 : match = 0;
			}

			Assert::AreEqual(1, match);
		}
		//Test to see if setTruckInfo works as intended with valid input
		TEST_METHOD(TestSetTruckInfo1)
		{
			Logger::WriteMessage("Testing TestSetTruckInfo to see if it returns a success with valid input, Valid");
			struct Truck truck;

			freopen("C:\\Users\\Ahmad\\OneDrive\\Documents\\Ahmad\\0_Seneca\\0_Semester 2\\SFT211\\0_Project\\winter24-sft221-nii-3\\SourceCode\\UnitTest1\\Input\\SetTruckInfo1.txt", "r", stdin);

			int result = setTruckInfo(&truck);

			int match = 1;


			Assert::AreEqual(match, result);
		}
		//Test to see if setTruckInfo works as intended with invalid input
		TEST_METHOD(TestSetTruckInfo2)
		{
			Logger::WriteMessage("Testing setTruckInfo to see if it returns a fail with invalid input, Invalid");
			struct Truck truck;

			freopen("C:\\Users\\Ahmad\\OneDrive\\Documents\\Ahmad\\0_Seneca\\0_Semester 2\\SFT211\\0_Project\\winter24-sft221-nii-3\\SourceCode\\UnitTest1\\Input\\SetTruckInfo2.txt", "r", stdin);

			int result = setTruckInfo(&truck);

			int match = 0;


			Assert::AreEqual(match, result);
		}
		//Test to see if setTruckInfo works as intended with invalid input
		TEST_METHOD(TestSetTruckInfo3)
		{
			Logger::WriteMessage("Testing setTruckInfo to see if it returns a fail with invalid input, Invalid");
			struct Truck truck;

			freopen("C:\\Users\\Ahmad\\OneDrive\\Documents\\Ahmad\\0_Seneca\\0_Semester 2\\SFT211\\0_Project\\winter24-sft221-nii-3\\SourceCode\\UnitTest1\\Input\\SetTruckInfo3.txt", "r", stdin);

			int result = setTruckInfo(&truck);

			int match = 0;


			Assert::AreEqual(match, result);
		}
		//Test to see if setTruckInfo works as intended with invalid input
		TEST_METHOD(TestSetTruckInfo4)
		{
			Logger::WriteMessage("Testing setTruckInfo to see if it returns a fail with invalid input, Invalid");
			struct Truck truck;

			freopen("C:\\Users\\Ahmad\\OneDrive\\Documents\\Ahmad\\0_Seneca\\0_Semester 2\\SFT211\\0_Project\\winter24-sft221-nii-3\\SourceCode\\UnitTest1\\Input\\SetTruckInfo4.txt", "r", stdin);

			int result = setTruckInfo(&truck);

			int match = 0;


			Assert::AreEqual(match, result);
		}
		//Test to see if validateTruckWeight works as intended with valid input
		TEST_METHOD(validateTruckWeight1)
		{
			Logger::WriteMessage("Testing validateTruckWeight to see if it returns a pass with valid input, valid");
			//weight being added
			struct Truck truck = { 100,0,{0,0} };

			//truck being checked
			struct Truck blueTruck = { 0,0,{0,0} };

			int result = validateTruckWeight(truck, &blueTruck.weight);

			int match = 1;


			Assert::AreEqual(match, result);
		}
		//Test to see if validateTruckWeight works as intended with valid input
		TEST_METHOD(validateTruckWeight2)
		{
			Logger::WriteMessage("Testing validateTruckWeight to see if it returns a pass with valid input, valid");
			//weight being added
			struct Truck truck = { 100,0,{0,0} };

			//truck being checked
			struct Truck blueTruck = { 500,0,{0,0} };

			int result = validateTruckWeight(truck, &blueTruck.weight);

			int match = 1;


			Assert::AreEqual(match, result);
		}
		//Test to see if validateTruckWeight works as intended with invalid input
		TEST_METHOD(validateTruckWeight3)
		{
			Logger::WriteMessage("Testing validateTruckWeight to see if it returns a fail with invalid input, Invalid");
			//weight being added
			struct Truck truck = { 200,0,{0,0} };

			//truck being checked
			struct Truck blueTruck = { 1100,0,{0,0} };

			int result = validateTruckWeight(truck, &blueTruck.weight);

			int match = 0;


			Assert::AreEqual(match, result);
		}
		//Test to see if validateTruckWeight works as intended with invalid input
		TEST_METHOD(validateTruckWeight4)
		{
			Logger::WriteMessage("Testing validateTruckWeight to see if it returns a fail with invalid input, Invalid");
			//weight being added
			struct Truck truck = { 1,0,{0,0} };

			//truck being checked
			struct Truck blueTruck = { 1200,0,{0,0} };

			int result = validateTruckWeight(truck, &blueTruck.weight);

			int match = 0;


			Assert::AreEqual(match, result);
		}
		//Test to see if validateTruckSize works as intended with valid input
		TEST_METHOD(validateTruckSize1)
		{
			Logger::WriteMessage("Testing validateTruckSize to see if it returns a pass with valid input, valid");
			//size being added
			struct Truck truck = { 0,0.5,{0,0} };

			//truck being checked
			struct Truck blueTruck = { 0,0.0,{0,0} };

			int result = validateTruckSize(truck, &blueTruck.size);

			int match = 1;


			Assert::AreEqual(match, result);
		}
		//Test to see if validateTruckSize works as intended with valid input
		TEST_METHOD(validateTruckSize2)
		{
			Logger::WriteMessage("Testing validateTruckSize to see if it returns a pass with valid input, valid");
			//size being added
			struct Truck truck = { 0,0.5,{0,0} };

			//truck being checked
			struct Truck blueTruck = { 0,40.0,{0,0} };

			int result = validateTruckSize(truck, &blueTruck.size);

			int match = 1;


			Assert::AreEqual(match, result);
		}
		//Test to see if validateTruckSize works as intended with invalid input
		TEST_METHOD(validateTruckSize3)
		{
			Logger::WriteMessage("Testing validateTruckSize to see if it returns a fail with invalid input, invalid");
			//size being added
			struct Truck truck = { 0,5.0,{0,0} };

			//truck being checked
			struct Truck blueTruck = { 0,47.0,{0,0} };

			int result = validateTruckSize(truck, &blueTruck.size);

			int match = 0;


			Assert::AreEqual(match, result);
		}
		//Test to see if validateTruckSize works as intended with invalid input
		TEST_METHOD(validateTruckSize4)
		{
			Logger::WriteMessage("Testing validateTruckSize to see if it returns a fail with invalid input, invalid");
			//size being added
			struct Truck truck = { 0,0.5,{0,0} };

			//truck being checked
			struct Truck blueTruck = { 0,50.0,{0,0} };

			int result = validateTruckSize(truck, &blueTruck.size);

			int match = 0;


			Assert::AreEqual(match, result);
		}
		//Test to see if validateCargoSize works as intended with valid input
		TEST_METHOD(validateCargoSize1)
		{
			Logger::WriteMessage("Testing validateCargoSize to see if it returns a pass with valid input, valid");

			int result = validateCargoSize(0.5);

			int match = 1;

			Assert::AreEqual(match, result);
		}
		//Test to see if validateCargoSize works as intended with valid input
		TEST_METHOD(validateCargoSize2)
		{
			Logger::WriteMessage("Testing validateCargoSize to see if it returns a pass with valid input, valid");

			int result = validateCargoSize(1);

			int match = 1;

			Assert::AreEqual(match, result);
		}
		//Test to see if validateCargoSize works as intended with valid input
		TEST_METHOD(validateCargoSize3)
		{
			Logger::WriteMessage("Testing validateCargoSize to see if it returns a pass with valid input, valid");

			int result = validateCargoSize(5);

			int match = 1;

			Assert::AreEqual(match, result);
		}
		//Test to see if validateCargoSize works as intended with valid input
		TEST_METHOD(validateCargoSize4)
		{
			Logger::WriteMessage("Testing validateCargoSize to see if it returns a pass with valid input, valid");

			int result = validateCargoSize(2);

			int match = 0;

			Assert::AreEqual(match, result);
		}

		//----------------------------------------------------------------------------------------------------------------------------------------------------------
		//--------------------------------------------------------------------- WHITEBOX TESTS ---------------------------------------------------------------------
		//----------------------------------------------------------------------------------------------------------------------------------------------------------

		//Test to see if setTruckInfo works as intended with invalid input
		TEST_METHOD(TestSetTruckInfo5)
		{
			Logger::WriteMessage("Testing TestSetTruckInfo to see if it returns a success with invalid input, invalid");
			struct Truck truck;

			freopen("C:\\Users\\Ahmad\\OneDrive\\Documents\\Ahmad\\0_Seneca\\0_Semester 2\\SFT211\\0_Project\\winter24-sft221-nii-3\\SourceCode\\UnitTest1\\Input\\SetTruckInfo5.txt", "r", stdin);

			int result = setTruckInfo(&truck);

			int match = 0;


			Assert::AreEqual(match, result);
		}
		//Test to see if setTruckInfo works as intended with invalid input
		TEST_METHOD(TestSetTruckInfo6)
		{
			Logger::WriteMessage("Testing setTruckInfo to see if it returns a fail with invalid input, Invalid");
			struct Truck truck;

			freopen("C:\\Users\\Ahmad\\OneDrive\\Documents\\Ahmad\\0_Seneca\\0_Semester 2\\SFT211\\0_Project\\winter24-sft221-nii-3\\SourceCode\\UnitTest1\\Input\\SetTruckInfo6.txt", "r", stdin);

			int result = setTruckInfo(&truck);

			int match = 0;


			Assert::AreEqual(match, result);
		}
		//Test to see if setTruckInfo works as intended with invalid input
		TEST_METHOD(TestSetTruckInfo7)
		{
			Logger::WriteMessage("Testing setTruckInfo to see if it returns a fail with invalid input, Invalid");
			struct Truck truck;

			freopen("C:\\Users\\Ahmad\\OneDrive\\Documents\\Ahmad\\0_Seneca\\0_Semester 2\\SFT211\\0_Project\\winter24-sft221-nii-3\\SourceCode\\UnitTest1\\Input\\SetTruckInfo7.txt", "r", stdin);

			int result = setTruckInfo(&truck);

			int match = 0;


			Assert::AreEqual(match, result);
		}
		//Test to see if setTruckInfo works as intended with invalid input
		TEST_METHOD(TestSetTruckInfo8)
		{
			Logger::WriteMessage("Testing setTruckInfo to see if it returns a fail with invalid input, Invalid");
			struct Truck truck;

			freopen("C:\\Users\\Ahmad\\OneDrive\\Documents\\Ahmad\\0_Seneca\\0_Semester 2\\SFT211\\0_Project\\winter24-sft221-nii-3\\SourceCode\\UnitTest1\\Input\\SetTruckInfo8.txt", "r", stdin);

			int result = setTruckInfo(&truck);

			int match = 0;


			Assert::AreEqual(match, result);
		}
		//Test to see if validateTruckWeight works as intended with valid input
		TEST_METHOD(validateTruckWeight5)
		{
			Logger::WriteMessage("Testing validateTruckWeight to see if it returns a pass with valid input, valid");
			//weight being added
			struct Truck truck = { 1,0,{0,0} };

			//truck being checked
			struct Truck blueTruck = { 1199,0,{0,0} };

			int result = validateTruckWeight(truck, &blueTruck.weight);

			int match = 1;


			Assert::AreEqual(match, result);
		}
		//Test to see if validateTruckWeight works as intended with valid input
		TEST_METHOD(validateTruckWeight6)
		{
			Logger::WriteMessage("Testing validateTruckWeight to see if it returns a pass with valid input, valid");
			//weight being added
			struct Truck truck = { 1,0,{0,0} };

			//truck being checked
			struct Truck blueTruck = { 0,0,{0,0} };

			int result = validateTruckWeight(truck, &blueTruck.weight);

			int match = 1;


			Assert::AreEqual(match, result);
		}
		//Test to see if validateTruckWeight works as intended with invalid input
		TEST_METHOD(validateTruckWeight7)
		{
			Logger::WriteMessage("Testing validateTruckWeight to see if it returns a fail with invalid input, Invalid");
			//weight being added
			struct Truck truck = { -1,0,{0,0} };

			//truck being checked
			struct Truck blueTruck = { 1000,0,{0,0} };

			int result = validateTruckWeight(truck, &blueTruck.weight);

			int match = 0;


			Assert::AreEqual(match, result);
		}
		//Test to see if validateTruckWeight works as intended with invalid input
		TEST_METHOD(validateTruckWeight8)
		{
			Logger::WriteMessage("Testing validateTruckWeight to see if it returns a fail with invalid input, Invalid");
			//weight being added
			struct Truck truck = { 50,0,{0,0} };

			//truck being checked
			struct Truck blueTruck = { -100,0,{0,0} };

			int result = validateTruckWeight(truck, &blueTruck.weight);

			int match = 0;


			Assert::AreEqual(match, result);
		}
		//Test to see if validateTruckSize works as intended with valid input
		TEST_METHOD(validateTruckSize5)
		{
			Logger::WriteMessage("Testing validateTruckSize to see if it returns a pass with valid input, valid");
			//size being added
			struct Truck truck = { 0,0.5,{0,0} };

			//truck being checked
			struct Truck blueTruck = { 0,49.5,{0,0} };

			int result = validateTruckSize(truck, &blueTruck.size);

			int match = 1;


			Assert::AreEqual(match, result);
		}
		//Test to see if validateTruckSize works as intended with valid input
		TEST_METHOD(validateTruckSize6)
		{
			Logger::WriteMessage("Testing validateTruckSize to see if it returns a pass with valid input, valid");
			//size being added
			struct Truck truck = { 0,1.0,{0,0} };

			//truck being checked
			struct Truck blueTruck = { 0,49.0,{0,0} };

			int result = validateTruckSize(truck, &blueTruck.size);

			int match = 1;


			Assert::AreEqual(match, result);
		}
		//Test to see if validateTruckSize works as intended with invalid input
		TEST_METHOD(validateTruckSize7)
		{
			Logger::WriteMessage("Testing validateTruckSize to see if it returns a fail with invalid input, invalid");
			//size being added
			struct Truck truck = { 0,-5.0,{0,0} };

			//truck being checked
			struct Truck blueTruck = { 0,47.0,{0,0} };

			int result = validateTruckSize(truck, &blueTruck.size);

			int match = 0;


			Assert::AreEqual(match, result);
		}
		//Test to see if validateTruckSize works as intended with invalid input
		TEST_METHOD(validateTruckSize8)
		{
			Logger::WriteMessage("Testing validateTruckSize to see if it returns a fail with invalid input, invalid");
			//size being added
			struct Truck truck = { 0,0.5,{0,0} };

			//truck being checked
			struct Truck blueTruck = { 0,-50.0,{0,0} };

			int result = validateTruckSize(truck, &blueTruck.size);

			int match = 0;


			Assert::AreEqual(match, result);
		}
		//Test to see if validateCargoSize works as intended with invalid input
		TEST_METHOD(validateCargoSize5)
		{
			Logger::WriteMessage("Testing validateCargoSize to see if it returns a pass with invalid input, invalid");

			int result = validateCargoSize(-0.5);

			int match = 0;

			Assert::AreEqual(match, result);
		}
		//Test to see if validateCargoSize works as intended with invalid input
		TEST_METHOD(validateCargoSize6)
		{
			Logger::WriteMessage("Testing validateCargoSize to see if it returns a pass with invalid input, invalid");

			int result = validateCargoSize(-1);

			int match = 0;

			Assert::AreEqual(match, result);
		}
		//Test to see if validateCargoSize works as intended with invalid input
		TEST_METHOD(validateCargoSize7)
		{
			Logger::WriteMessage("Testing validateCargoSize to see if it returns a pass with invalid input, invalid");

			int result = validateCargoSize(-5);

			int match = 0;

			Assert::AreEqual(match, result);
		}
		//Test to see if validateCargoSize works as intended with invalid input
		TEST_METHOD(validateCargoSize8)
		{
			Logger::WriteMessage("Testing validateCargoSize to see if it returns a fail with invalid input, invalid");

			int result = validateCargoSize(-2);

			int match = 0;

			Assert::AreEqual(match, result);
		}

		//----------------------------------------------------------------------------------------------------------------------------------------------------------
		//-------------------------------------------------------------------- INTEGRATION TEST --------------------------------------------------------------------
		//----------------------------------------------------------------------------------------------------------------------------------------------------------

		//Test to see if addRoute can add route to baseMap
		TEST_METHOD(addRoute1)
		{
			Logger::WriteMessage("Testing addRoute to see if it successfully adds route to baseMap");

			struct Map baseMap = populateMap();
			struct Route anyRoute = { {0,0}, 0, 0 };
			struct Map routeMap = addRoute(&baseMap, &anyRoute);

			int validate = 0;

			if (routeMap.numCols == MAP_COLS && routeMap.numRows == MAP_ROWS)
				validate = 1;

			Assert::AreEqual(1, validate);
		}
		//Test to see if addRoute can add route to baseMap
		TEST_METHOD(addRoute2)
		{
			Logger::WriteMessage("Testing addRoute to see if it successfully adds route to baseMap");

			struct Map baseMap = populateMap();
			struct Route blueRoute = getBlueRoute();
			struct Map routeMap = addRoute(&baseMap, &blueRoute);

			int validate = 0;

			if (routeMap.numCols == MAP_COLS && routeMap.numRows == MAP_ROWS)
				validate = 1;

			Assert::AreEqual(1, validate);
		}
		//Test to see if addRoute can add route to baseMap
		TEST_METHOD(addRoute3)
		{
			Logger::WriteMessage("Testing addRoute to see if it successfully adds routes to baseMap");

			struct Map baseMap = populateMap();
			struct Route blueRoute = getBlueRoute();
			struct Route yellowRoute = getYellowRoute();
			struct Map routeMap = addRoute(&baseMap, &blueRoute);
			routeMap = addRoute(&routeMap, &yellowRoute);

			int validate = 0;

			if (routeMap.numCols == MAP_COLS && routeMap.numRows == MAP_ROWS)
				validate = 1;

			Assert::AreEqual(1, validate);
		}
		//Test to see if addRoute can add route to baseMap
		TEST_METHOD(addRoute4)
		{
			Logger::WriteMessage("Testing addRoute to see if it successfully adds routes to baseMap");

			struct Map baseMap = populateMap();
			struct Route blueRoute = getBlueRoute();
			struct Route yellowRoute = getYellowRoute();
			struct Route greenRoute = getGreenRoute();
			struct Map routeMap = addRoute(&baseMap, &blueRoute);
			routeMap = addRoute(&routeMap, &yellowRoute);
			routeMap = addRoute(&routeMap, &greenRoute);

			int validate = 0;

			if (routeMap.numCols == MAP_COLS && routeMap.numRows == MAP_ROWS)
				validate = 1;

			Assert::AreEqual(1, validate);
		}
		//Test to see if setTruckInfo and getClosestPoint work together
		TEST_METHOD(getClosestPoint1)
		{
			Logger::WriteMessage("Testing setTruckInfo and getClosestPoint to see if it successfully gets the closest point for truck");

			struct Map baseMap = populateMap();

			struct Truck truck;
			//inputs 100 0.5 12L
			freopen("C:\\Users\\Ahmad\\OneDrive\\Documents\\Ahmad\\0_Seneca\\0_Semester 2\\SFT211\\0_Project\\winter24-sft221-nii-3\\SourceCode\\UnitTest1\\Input\\SetTruckInfo1.txt", "r", stdin);
			setTruckInfo(&truck);

			struct Route blueRoute = getBlueRoute();

			int blueRouteIndex = getClosestPoint(&blueRoute, truck.destination);

			//10,12
			struct Point correct = { 12, 10 };

			Assert::AreEqual(correct.col + 65, blueRoute.points[blueRouteIndex].col + 65);

		}
		//Test to see if setTruckInfo and getClosestPoint work together
		TEST_METHOD(getClosestPoint2)
		{
			Logger::WriteMessage("Testing setTruckInfo and getClosestPoint to see if it successfully gets the closest point for truck");

			struct Map baseMap = populateMap();

			struct Truck truck;
			//inputs 100 0.5 12L
			freopen("C:\\Users\\Ahmad\\OneDrive\\Documents\\Ahmad\\0_Seneca\\0_Semester 2\\SFT211\\0_Project\\winter24-sft221-nii-3\\SourceCode\\UnitTest1\\Input\\SetTruckInfo1.txt", "r", stdin);
			setTruckInfo(&truck);

			struct Route blueRoute = getBlueRoute();

			int blueRouteIndex = getClosestPoint(&blueRoute, truck.destination);

			//10,12
			struct Point correct = { 12, 10 };

			Assert::AreEqual(correct.row + 0, blueRoute.points[blueRouteIndex].row + 1);

		}
		TEST_METHOD(getClosestPoint3)
		{
			Logger::WriteMessage("Testing setTruckInfo and getClosestPoint to see if it successfully gets the closest point for truck");

			Logger::WriteMessage("Testing setTruckInfo and getClosestPoint to see if it successfully gets the closest point for truck");

			struct Map baseMap = populateMap();

			struct Truck truck;
			//inputs 100 0.5 8Y
			freopen("C:\\Users\\Ahmad\\OneDrive\\Documents\\Ahmad\\0_Seneca\\0_Semester 2\\SFT211\\0_Project\\winter24-sft221-nii-3\\SourceCode\\UnitTest1\\Input\\SetTruckInfo9.txt", "r", stdin);
			setTruckInfo(&truck);

			struct Route greenRoute = getGreenRoute();

			int greenRouteIndex = getClosestPoint(&greenRoute, truck.destination);

			struct Point correct = { 10, 24 };

			Assert::AreEqual(correct.col + 65, greenRoute.points[greenRouteIndex].col + 65);

		}
		//Test to see if setTruckInfo and getClosestPoint work together
		TEST_METHOD(getClosestPoint4)
		{
			Logger::WriteMessage("Testing setTruckInfo and getClosestPoint to see if it successfully gets the closest point for truck");

			struct Map baseMap = populateMap();

			struct Truck truck;
			//inputs 100 0.5 8Y
			freopen("C:\\Users\\Ahmad\\OneDrive\\Documents\\Ahmad\\0_Seneca\\0_Semester 2\\SFT211\\0_Project\\winter24-sft221-nii-3\\SourceCode\\UnitTest1\\Input\\SetTruckInfo9.txt", "r", stdin);
			setTruckInfo(&truck);

			struct Route greenRoute = getGreenRoute();

			int greenRouteIndex = getClosestPoint(&greenRoute, truck.destination);

			struct Point correct = { 10, 24 };

			Assert::AreEqual(correct.row + 0, greenRoute.points[greenRouteIndex].row + 1);

		}
		//Test setTruckInfo with getPossibleMoves
		TEST_METHOD(getPossibleMoves1)
		{
			Logger::WriteMessage("Testing setTruckInfo with getPossibleMoves to see if it successfully gets the correct point on the map for truck");

			struct Map baseMap = populateMap();

			struct Truck truck;
			//inputs 100 0.5 12L
			freopen("C:\\Users\\Ahmad\\OneDrive\\Documents\\Ahmad\\0_Seneca\\0_Semester 2\\SFT211\\0_Project\\winter24-sft221-nii-3\\SourceCode\\UnitTest1\\Input\\SetTruckInfo1.txt", "r", stdin);
			setTruckInfo(&truck);

			struct Point tempBackspace = { -1,-1 };
			struct Route possibleMoves = getPossibleMoves(&baseMap, truck.destination, tempBackspace);

			struct Point correct = { 11, 11 };

			Assert::AreEqual(correct.row + 0, possibleMoves.points->row + 1);

		}
		//Test setTruckInfo with getPossibleMoves
		TEST_METHOD(getPossibleMoves2)
		{
			Logger::WriteMessage("Testing setTruckInfo with getPossibleMoves to see if it successfully gets the correct point on the map for truck");

			struct Map baseMap = populateMap();

			struct Truck truck;
			//inputs 100 0.5 12L
			freopen("C:\\Users\\Ahmad\\OneDrive\\Documents\\Ahmad\\0_Seneca\\0_Semester 2\\SFT211\\0_Project\\winter24-sft221-nii-3\\SourceCode\\UnitTest1\\Input\\SetTruckInfo1.txt", "r", stdin);
			setTruckInfo(&truck);

			struct Point tempBackspace = { -1,-1 };
			struct Route possibleMoves = getPossibleMoves(&baseMap, truck.destination, tempBackspace);

			struct Point correct = { 11, 11 };

			Assert::AreEqual(correct.col + 65, possibleMoves.points->col + 65);

		}
		TEST_METHOD(getPossibleMoves3)
		{
			Logger::WriteMessage("Testing setTruckInfo with getPossibleMoves to see if it successfully gets the correct point on the map for truck");

			struct Map baseMap = populateMap();

			struct Truck truck;
			//inputs 100 0.5 8Y
			freopen("C:\\Users\\Ahmad\\OneDrive\\Documents\\Ahmad\\0_Seneca\\0_Semester 2\\SFT211\\0_Project\\winter24-sft221-nii-3\\SourceCode\\UnitTest1\\Input\\SetTruckInfo9.txt", "r", stdin);
			setTruckInfo(&truck);

			struct Point tempBackspace = { -1,-1 };
			struct Route possibleMoves = getPossibleMoves(&baseMap, truck.destination, tempBackspace);

			struct Point correct = { 7, 24 };

			Assert::AreEqual(correct.row + 0, possibleMoves.points->row + 1);

		}
		//Test setTruckInfo with getPossibleMoves
		TEST_METHOD(getPossibleMoves4)
		{
			Logger::WriteMessage("Testing setTruckInfo with getPossibleMoves to see if it successfully gets the correct point on the map for truck");

			struct Map baseMap = populateMap();

			struct Truck truck;
			//inputs 100 0.5 8Y
			freopen("C:\\Users\\Ahmad\\OneDrive\\Documents\\Ahmad\\0_Seneca\\0_Semester 2\\SFT211\\0_Project\\winter24-sft221-nii-3\\SourceCode\\UnitTest1\\Input\\SetTruckInfo9.txt", "r", stdin);
			setTruckInfo(&truck);

			struct Point tempBackspace = { -1,-1 };
			struct Route possibleMoves = getPossibleMoves(&baseMap, truck.destination, tempBackspace);

			struct Point correct = { 7, 24 };

			Assert::AreEqual(correct.col + 65, possibleMoves.points->col + 65);

		}
		//Test shortestPath using all previous functions
		TEST_METHOD(shortestPath1)
		{
			Logger::WriteMessage("Testing shortestPath to see if it successfully gets the shortest path for the given data");

			struct Map baseMap = populateMap();
			struct Route blueRoute = getBlueRoute();
			struct Route blueRouteArray[MAX_ROUTE] = { {0,0},0,0 };
			int blueShortPath = 9999, blueShortIndex = 0;
			int i;

			struct Truck truck;
			//inputs 100 0.5 12L
			freopen("C:\\Users\\Ahmad\\OneDrive\\Documents\\Ahmad\\0_Seneca\\0_Semester 2\\SFT211\\0_Project\\winter24-sft221-nii-3\\SourceCode\\UnitTest1\\Input\\SetTruckInfo1.txt", "r", stdin);
			setTruckInfo(&truck);

			// Get the closest point index from the array of routes of each truck to the destination
			int blueRouteIndex = getClosestPoint(&blueRoute, truck.destination);

			//to hand over a throwaway last spot to getPossibleMoves when checking possible spots around truck.destination
			struct Point tempBackspace = { -1,-1 };

			//get the possible square around the destination for the truck to travel to
			struct Route possibleMoves = getPossibleMoves(&baseMap, truck.destination, tempBackspace);

			//get the closest possible square that each truck can travel to that does not have a building
			int bluePossibleIndex = getClosestPoint(&possibleMoves, blueRoute.points[blueRouteIndex]);

			//get all the possible route of blue truck and put them into a route array
			for (i = 0; i < blueRoute.numPoints; i++) {
				blueRouteArray[i] = shortestPath(&baseMap, blueRoute.points[i], possibleMoves.points[bluePossibleIndex]);

				//find shortest route among possible routes
				if (blueRouteArray[i].numPoints < blueShortPath && blueRouteArray[i].numPoints != -1) {
					blueShortPath = blueRouteArray[i].numPoints;
					blueShortIndex = i;
				}
			}
			int correctIndex = 21; //found using the debugger when running the program

			Assert::AreEqual(correctIndex, blueShortIndex);
		}
		//Test shortestPath using all previous functions
		TEST_METHOD(shortestPath2)
		{
			Logger::WriteMessage("Testing shortestPath to see if it successfully gets the shortest path for the given data");

			struct Map baseMap = populateMap();
			struct Route greenRoute = getGreenRoute();
			struct Route greenRouteArray[MAX_ROUTE] = { {0,0},0,0 };
			int greenShortPath = 9999, greenShortIndex = 0;
			int i;

			struct Truck truck;
			//inputs 100 0.5 12L
			freopen("C:\\Users\\Ahmad\\OneDrive\\Documents\\Ahmad\\0_Seneca\\0_Semester 2\\SFT211\\0_Project\\winter24-sft221-nii-3\\SourceCode\\UnitTest1\\Input\\SetTruckInfo1.txt", "r", stdin);
			setTruckInfo(&truck);

			// Get the closest point index from the array of routes of each truck to the destination
			int greenRouteIndex = getClosestPoint(&greenRoute, truck.destination);

			//to hand over a throwaway last spot to getPossibleMoves when checking possible spots around truck.destination
			struct Point tempBackspace = { -1,-1 };

			//get the possible square around the destination for the truck to travel to
			struct Route possibleMoves = getPossibleMoves(&baseMap, truck.destination, tempBackspace);

			//get the closest possible square that each truck can travel to that does not have a building
			int greenPossibleIndex = getClosestPoint(&possibleMoves, greenRoute.points[greenRouteIndex]);

			//get all the possible route of blue truck and put them into a route array
			for (i = 0; i < greenRoute.numPoints; i++) {
				greenRouteArray[i] = shortestPath(&baseMap, greenRoute.points[i], possibleMoves.points[greenPossibleIndex]);

				//find shortest route among possible routes
				if (greenRouteArray[i].numPoints < greenShortPath && greenRouteArray[i].numPoints != -1) {
					greenShortPath = greenRouteArray[i].numPoints;
					greenShortIndex = i;
				}
			}
			int correctIndex = 13; //found using the debugger when running the program

			Assert::AreEqual(correctIndex, greenShortIndex);
		}
		//Test shortestPath using all previous functions
		TEST_METHOD(shortestPath3)
		{
			Logger::WriteMessage("Testing shortestPath to see if it successfully gets the shortest path for the given data");

			struct Map baseMap = populateMap();
			struct Route yellowRoute = getYellowRoute();
			struct Route yellowRouteArray[MAX_ROUTE] = { {0,0},0,0 };
			int yellowShortPath = 9999, yellowShortIndex = 0;
			int i;

			struct Truck truck;
			//inputs 100 0.5 12L
			freopen("C:\\Users\\Ahmad\\OneDrive\\Documents\\Ahmad\\0_Seneca\\0_Semester 2\\SFT211\\0_Project\\winter24-sft221-nii-3\\SourceCode\\UnitTest1\\Input\\SetTruckInfo1.txt", "r", stdin);
			setTruckInfo(&truck);

			// Get the closest point index from the array of routes of each truck to the destination
			int yellowRouteIndex = getClosestPoint(&yellowRoute, truck.destination);

			//to hand over a throwaway last spot to getPossibleMoves when checking possible spots around truck.destination
			struct Point tempBackspace = { -1,-1 };

			//get the possible square around the destination for the truck to travel to
			struct Route possibleMoves = getPossibleMoves(&baseMap, truck.destination, tempBackspace);

			//get the closest possible square that each truck can travel to that does not have a building
			int yellowPossibleIndex = getClosestPoint(&possibleMoves, yellowRoute.points[yellowRouteIndex]);

			//get all the possible route of blue truck and put them into a route array
			for (i = 0; i < yellowRoute.numPoints; i++) {
				yellowRouteArray[i] = shortestPath(&baseMap, yellowRoute.points[i], possibleMoves.points[yellowPossibleIndex]);

				//find shortest route among possible routes
				if (yellowRouteArray[i].numPoints < yellowShortPath && yellowRouteArray[i].numPoints != -1) {
					yellowShortPath = yellowRouteArray[i].numPoints;
					yellowShortIndex = i;
				}
			}
			int correctIndex = 33; //found using the debugger when running the program

			Assert::AreEqual(correctIndex, yellowShortIndex);
		}
		//Test shortestPath using all previous functions
		TEST_METHOD(shortestPath4)
		{
			Logger::WriteMessage("Testing shortestPath to see if it successfully gets the shortest path for the given data");

			struct Map baseMap = populateMap();
			struct Route anyRoute = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0}, {3, 1}, {3, 2},
			{4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7},
			{5, 7}, {5, 8}, {5, 9},
			{6, 9},
			{7, 9},
			{8, 9},
			{9, 9},
			{10, 9},{10, 10}, {10, 11}, {10, 12},
			{11, 12},
			{12, 12},
			{13, 12},
			{14, 12},
			{15, 12},
			{16, 12},
			{17, 12},{17, 13},{17, 14},{17, 15},{17, 16},{17, 17},{17, 18},{17, 19},{17, 20},
				{17, 21},{17, 22},{17, 23},{17, 24},
		},
			42, 6
			};
			struct Route anyRouteArray[MAX_ROUTE] = { {0,0},0,0 };
			int anyShortPath = 9999, anyShortIndex = 0;
			int i;

			struct Truck truck;
			//inputs 100 0.5 8Y
			freopen("C:\\Users\\Ahmad\\OneDrive\\Documents\\Ahmad\\0_Seneca\\0_Semester 2\\SFT211\\0_Project\\winter24-sft221-nii-3\\SourceCode\\UnitTest1\\Input\\SetTruckInfo9.txt", "r", stdin);
			setTruckInfo(&truck);

			// Get the closest point index from the array of routes of each truck to the destination
			int anyRouteIndex = getClosestPoint(&anyRoute, truck.destination);

			//to hand over a throwaway last spot to getPossibleMoves when checking possible spots around truck.destination
			struct Point tempBackspace = { -1,-1 };

			//get the possible square around the destination for the truck to travel to
			struct Route possibleMoves = getPossibleMoves(&baseMap, truck.destination, tempBackspace);

			//get the closest possible square that each truck can travel to that does not have a building
			int anyPossibleIndex = getClosestPoint(&possibleMoves, anyRoute.points[anyRouteIndex]);

			//get all the possible route of blue truck and put them into a route array
			for (i = 0; i < anyRoute.numPoints; i++) {
				anyRouteArray[i] = shortestPath(&baseMap, anyRoute.points[i], possibleMoves.points[anyPossibleIndex]);

				//find shortest route among possible routes
				if (anyRouteArray[i].numPoints < anyShortPath && anyRouteArray[i].numPoints != -1) {
					anyShortPath = anyRouteArray[i].numPoints;
					anyShortIndex = i;
				}
			}
			int correctIndex = 24; //found using the debugger when running the program

			Assert::AreEqual(correctIndex, anyShortIndex);
		}
		//Test addPtToRoute with empty route
		TEST_METHOD(addPtToRoute1)
		{
			Logger::WriteMessage("Testing addPtToRoute with empty route");
			
			struct Route fillRoute = { {}, 0, BLUE };
			struct Point add = { 0,0 };
			addPtToRoute(&fillRoute, add);
			
			bool correct = true;

			//Assert::AreEqual(correct, fillRoute.numPoints);
			Assert::AreEqual(correct, fillRoute.points[0].row == 0 && fillRoute.points[0].col == 0 && fillRoute.numPoints == 1);
		}
		//Test addPtToRoute with non empty route
		TEST_METHOD(addPtToRoute2)
		{
			Logger::WriteMessage("Testing addPtToRoute with non empty route");

			struct Route fillRoute = { {{1,2}}, 1, BLUE };
			struct Point add = { 1,1 };
			addPtToRoute(&fillRoute, add);

			bool correct = true;

			//Assert::AreEqual(correct, fillRoute.numPoints);
			Assert::AreEqual(correct, fillRoute.points[1].row == 1 && fillRoute.points[1].col == 1 && fillRoute.numPoints == 2 && fillRoute.points[0].row == 1 && fillRoute.points[0].col == 2);
		}
		//Test addPtToRoute with non empty route with diff row and col
		TEST_METHOD(addPtToRoute3)
		{
			Logger::WriteMessage("Testing addPtToRoute with non empty route with diff row and col");

			struct Route fillRoute = { {{1,2}}, 1, BLUE };
			struct Point add = { 3,4 };
			addPtToRoute(&fillRoute, add);

			bool correct = true;

			//Assert::AreEqual(correct, fillRoute.numPoints);
			Assert::AreEqual(correct, fillRoute.points[1].row == 3 && fillRoute.points[1].col == 4 && fillRoute.numPoints == 2 && fillRoute.points[0].row == 1 && fillRoute.points[0].col == 2);
		}
		//Test addPtToRoute with non empty route with row and col same as route
		TEST_METHOD(addPtToRoute4) //!
		{
			Logger::WriteMessage("Testing addPtToRoute with non empty route with row and col same as route");

			struct Route fillRoute = { {{1,2}}, 1, BLUE };
			struct Point add = { 1,2 };
			addPtToRoute(&fillRoute, add);

			bool correct = true;

			//Assert::AreEqual(correct, fillRoute.numPoints);
			Assert::AreEqual(!correct, fillRoute.numPoints == 1 && fillRoute.points[0].row == 1 && fillRoute.points[0].col == 2);
		}
		//Test addPtToRoute with empty route with row and col out of range
		TEST_METHOD(addPtToRoute5)
		{
			Logger::WriteMessage("Testing addPtToRoute with empty route with row and col out of range");

			struct Route fillRoute = { {}, 0, BLUE };
			struct Point add = { 2,30 };
			addPtToRoute(&fillRoute, add);

			bool correct = true;

			//Assert::AreEqual(correct, fillRoute.numPoints);
			Assert::AreEqual(correct, fillRoute.numPoints == 0 && fillRoute.points[0].row == NULL && fillRoute.points[0].col == NULL);
		}
		//Test addPtToRoute with non empty route with row and col out of range
		TEST_METHOD(addPtToRoute6)
		{
			Logger::WriteMessage("Testing addPtToRoute with non empty route with row and col out of range");

			struct Route fillRoute = { { 1,2 }, 1, BLUE };
			struct Point add = { 34,29 };
			addPtToRoute(&fillRoute, add);

			bool correct = true;

			//Assert::AreEqual(correct, fillRoute.numPoints);
			Assert::AreEqual(correct, fillRoute.numPoints == 1 && fillRoute.points[0].row == 1 && fillRoute.points[0].col == 2);
		}
		//Test addPointToRouteIfNot with empty route
		TEST_METHOD(addPointToRouteIfNot1)
		{
			Logger::WriteMessage("Testing addPointToRouteIfNot non empty route");

			struct Route fillRoute = { {}, 0, BLUE };
			struct Point add = { 0,0 };
			struct Point dontAdd = { 0,0 };
			addPointToRouteIfNot(&fillRoute, add.row, add.col, dontAdd);

			bool correct = true;

			//Assert::AreEqual(correct, fillRoute.numPoints);
			Assert::AreEqual(correct, fillRoute.points[0].row == NULL && fillRoute.points[0].col == NULL && fillRoute.numPoints == 0);
		}
		//Test addPointToRouteIfNot with non empty route
		TEST_METHOD(addPointToRouteIfNot2)
		{
			Logger::WriteMessage("Testing addPointToRouteIfNot with non empty route");

			struct Route fillRoute = { { 0,0 }, 1, BLUE };
			struct Point add = { 1,1 };
			struct Point dontAdd = { 1,1 };
			addPointToRouteIfNot(&fillRoute, add.row, add.col, dontAdd);

			bool correct = true;

			//Assert::AreEqual(correct, fillRoute.numPoints);
			Assert::AreEqual(correct, fillRoute.points[0].row == 0 && fillRoute.points[0].col == 0 && fillRoute.numPoints == 1);
		}
		//Test addPointToRouteIfNot with non empty route and dontAdd being different from add
		TEST_METHOD(addPointToRouteIfNot3)
		{
			Logger::WriteMessage("Testing addPointToRouteIfNot with non empty route and dontAdd being different from add");

			struct Route fillRoute = { { 0,0 }, 1, BLUE };
			struct Point add = { 3,4 };
			struct Point dontAdd = { 2,4 };
			addPointToRouteIfNot(&fillRoute, add.row, add.col, dontAdd);

			bool correct = true;

			//Assert::AreEqual(correct, fillRoute.numPoints);
			Assert::AreEqual(correct, fillRoute.points[0].row == 0 && fillRoute.points[0].col == 0 && fillRoute.numPoints == 2 && fillRoute.points[1].row == 3 && fillRoute.points[1].col == 4);
		}
	};
}
