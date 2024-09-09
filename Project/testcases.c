#include <stdio.h>
#include <stdlib.h>
#include <corecrt_math.h>

#include "mapping.h" 

int main() {
    testPopulateMap();
    testAddRoute();
    testDistance();
    testGetNumCols();
    testGetNumRows();
    testPrintMap();
    
    return 0;
}

//===========================================================================================================================
void testPopulateMap() {
    //Test Case 1: Call populateMap without any parameters
    struct Map map1 = populateMap();
    int allDefault = 1;
    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            if (map1.squares[i][j] != 0) {
                allDefault = 0;
                break;
            }
        }
        if (!allDefault) break;
    }
    if (allDefault && map1.numRows == MAP_ROWS && map1.numCols == MAP_COLS) {
        printf("Test Case 1: Passed\n");
    } else {
        printf("Test Case 1: Failed\n");
    }

    //Test Case 2: Call populateMap after a previous call to populateMap
    struct Map map2 = populateMap();
    allDefault = 1;
    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            if (map2.squares[i][j] != 0) {
                allDefault = 0;
                break;
            }
        }
        if (!allDefault) break;
    }
    if (allDefault && map2.numRows == MAP_ROWS && map2.numCols == MAP_COLS) {
        printf("Test Case 2: Passed\n");
    } else {
        printf("Test Case 2: Failed\n");
    }

    //Test Case 3: Call populateMap() and then inspect the squares array in the returned Map
    allDefault = 1;
    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            if (map1.squares[i][j] != 0) {
                allDefault = 0;
                break;
            }
        }
        if (!allDefault) break;
    }
    if (allDefault) {
        printf("Test Case 3: Passed\n");
    } else {
        printf("Test Case 3: Failed\n");
    }

    //Test Case 4: Call populateMap() and then inspect the numRows and numCols fields in the returned Map
    if (map1.numRows == MAP_ROWS && map1.numCols == MAP_COLS) {
        printf("Test Case 4: Passed\n");
    } else {
        printf("Test Case 4: Failed\n");
    }
}

//===========================================================================================================================

void testGetNumRows() {
    //Test Case 1: Call getNumRows() with a valid Map pointer.
    struct Map *map1 = populateMap();
    if (getNumRows(map1) == MAP_ROWS) {
        printf("Test Case 1: Passed\n");
    } else {
        printf("Test Case 1: Failed\n");
    }
    free(map1);

    //Test Case 2: Call getNumRows() with a Map pointer that has been modified to have a different number of rows.
    struct Map* map2 = populateMap();
    map2->numRows = 10; // Modify the number of rows
    if (getNumRows(map2) == 10) {
        printf("Test Case 2: Passed\n");
    } else {
        printf("Test Case 2: Failed\n");
    }
    free(map2);

    //Test Case 4: Call getNumRows() with a NULL pointer.
    struct Map* map = NULL;
    int result = getNumRows(map);
    if (result == -1) {
        printf("Test Case 3: Passed\n");
    } else {
        printf("Test Case 3: Failed\n");
    }

    //Test Case 5: Call getNumRows() with a Map pointer that points to an uninitialized Map structure.
    struct Map* map;
    int result = getNumRows(map);
    if (result == -1) {
        printf("Test Case 4: Passed\n");
    } else {
        printf("Test Case 4: Failed\n");
    }
}

//===========================================================================================================================

void testGetNumCols() {
    //Test Case 1: Call getNumCols() with a valid Map pointer.
    struct Map *map1 = populateMap();
    if (getNumCols(map1) == MAP_COLS) {
        printf("Test Case 1: Passed\n");
    } else {
        printf("Test Case 1: Failed\n");
    }
    free(map1);

    //Test Case 2: Call getNumCols() with a Map pointer that has been modified to have a different number of columns.
    struct Map *map2 = populateMap();
    map2->numCols = 10; // Modify the number of columns
    if (getNumCols(map2) == 10) {
        printf("Test Case 2: Passed\n");
    } else {
        printf("Test Case 2: Failed\n");
    }
    free(map2);

    //Test Case 3: Call getNumCols() with a NULL pointer.
    struct Map* map = NULL;
    int result = getNumCols(map);
    if (result == -1) {
        printf("Test Case 3: Passed\n");
    } else {
        printf("Test Case 3: Failed\n");
    }

    //Test Case 4: Call getNumCols() with a Map pointer that points to an uninitialized Map structure.
    struct Map* map;
    int result = getNumCols(map);

    if (result == -1) {
        printf("Test Case 4: Passed\n");
    } else {
        printf("Test Case 4: Failed\n");
    }
    
}

//===========================================================================================================================

void testPrintMap() {
    //Test Case 1: Call printMap() with a valid Map pointer, base1 set to true, and alphaCols set to true.
    struct Map* map1 = populateMap();
    printMap(map1, 1, 1);
    free(map1);
    
    // Test Case 2: Call printMap() with a valid Map pointer, base1 set to false, and alphaCols set to false.
    struct Map* map2 = populateMap();
    printMap(map2, 0, 0);
    free(map2);

    //Test Case 3: Call printMap() with a NULL pointer.
    struct Map* map = NULL;
    int result = printMap(map, 1, 1); // Assuming 1 for true and 0 for false
    if (result == -1) {
        printf("Test Case 3: Passed\n");
    } else {
        printf("Test Case 3: Failed\n");
    }

    //Test Case 4: Call printMap() with a Map pointer that points to an uninitialized Map structure.
    struct Map* map;
    int result = printMap(map, 0, 0); // Assuming 0 for false
    if (result == -1) {
        printf("Test Case 4: Passed\n");
    } else {
        printf("Test Case 4: Failed\n");
    }
}

//===========================================================================================================================

void testAddRoute() {
    //Test Case 1: Call addRoute() with a valid Map pointer and a Route pointer that contains a valid route.
    struct Map* map1 = populateMap();
    struct Route* route1 = createValidRoute();
    struct Map* resultMap1 = addRoute(map1, route1);
    if (resultMap1 != NULL) {
        printf("Test Case 1: Passed\n");
    } else {
        printf("Test Case 1: Failed\n");
    }
    free(map1);
    free(route1);

    //Test Case 2: Call addRoute() with a Map pointer and a Route pointer that contains an invalid route (e.g., a route that goes through a building).
    struct Map* map2 = populateMap();
    struct Route* invalidRoute = createInvalidRoute();
    struct Map* resultMap2 = addRoute(map2, invalidRoute);
    if (resultMap2 == NULL) {
        printf("Test Case 2: Passed\n");
    } else {
        printf("Test Case 2: Failed\n");
    }
    free(map2);
    free(invalidRoute);

    //Test Case 3: Call addRoute() with a NULL Map pointer.
    struct Map* map = NULL;
    struct Route* route = createValidRoute();
    struct Map* resultMap3 = addRoute(map, route);
    if (resultMap3 == NULL) {
        printf("Test Case 3: Passed\n");
    } else {
        printf("Test Case 3: Failed\n");
    }
    free(route);

    //Test Case 4: Call addRoute() with a Map pointer that points to an uninitialized Map structure and a Route pointer.
    struct Map* uninitializedMap;
    struct Route* route4 = createValidRoute();
    struct Map* resultMap4 = addRoute(uninitializedMap, route4);
    if (resultMap4 == NULL) {
        printf("Test Case 4: Passed\n");
    } else {
        printf("Test Case 4: Failed\n");
    }
    free(route4);
}

//===========================================================================================================================

struct Point* createPoint(double x, double y) {
    struct Point* point = (struct Point*)malloc(sizeof(struct Point));
    point->x = x;
    point->y = y;
    return point;
}

void testDistance() {
    // Test Case 1: Call distance() with two Point pointers that represent two points on the map.
    struct Point* p1 = createPoint(1.0, 2.0);
    struct Point* p2 = createPoint(4.0, 6.0);
    double result1 = distance(p1, p2);
    double expected1 = sqrt(25.0); 
    if (fabs(result1 - expected1) < 0.0001) {
        printf("Test Case 1: Passed\n");
    } else {
        printf("Test Case 1: Failed\n");
    }
    free(p1);
    free(p2);

    // Test Case 2: Call distance() with two Point pointers that represent the same point.
    struct Point* p3 = createPoint(3.0, 3.0);
    double result2 = distance(p3, p3);
    if (result2 == 0.0) {
        printf("Test Case 2: Passed\n");
    } else {
        printf("Test Case 2: Failed\n");
    }
    free(p3);

    // Test Case 3: Call distance() with a NULL pointer for either p1 or p2.
    struct Point* p4 = NULL;
    struct Point* p5 = createPoint(5.0, 5.0);
    double result3 = distance(p4, p5);
    if (isnan(result3)) {
        printf("Test Case 3: Passed\n");
    } else {
        printf("Test Case 3: Failed\n");
    }
    free(p5);

    // Test Case 4: Call distance() with two Point pointers that point to uninitialized Point structures.
    struct Point* uninitializedPoint;
    struct Point* p6 = createPoint(7.0, 7.0);
    double result4 = distance(uninitializedPoint, p6);
    if (isnan(result4)) {
        printf("Test Case 4: Passed\n");
    } else {
        printf("Test Case 4: Failed\n");
    }
    free(p6);
}

//===========================================================================================================================