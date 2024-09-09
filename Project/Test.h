#ifndef FINDER_H
#define FINDER_H
#include <stdio.h>
#include "mapping.h"
#include "Truck.h"

/**
adds routes that reach the specified cargo destination to the "routes" array.
shipment - cargo struct holding the shipment's destination coordinates (row and column).
truck - Truck struct that shows the truck's path on the map.
map - Every point (square) in the map is contained in a map struct.
routes - valid routes are stored in an array of pointers to Route structs.
size - The number of valid routes is stored as a pointer to an integer.
returns - void, updates the "size" variable, and fills the "routes" array.
*/
void findValidTruckPath(struct Shipment shipment, struct Truck truck, const struct Map *map, struct Route *routes[MAX_ROUTE], int *size);

/**
determines the index of the route in the "routes" array that has the least distance between all of the valid routes.
routes - All of the valid routes are contained in an array of route structs.
shipment - cargo struct holding the shipment's destination coordinates (row and column).
size - The "routes" array's valid route count.
returns - The index of the route with the shortest distance in the "routes" array is int. if no valid route is identified, returns -1.
*/

int hasDestination(struct Route *route, struct Shipment shipment);

/**
prints a route's points, or coordinates, to the console.
route - The points (coordinates) of the route are contained in the route struct.
hipment - cargo struct holding the shipment's destination coordinates (row and column).
returns - void just prints to the console and doesn't return a value.
*/
void printRoute(struct Route route, struct Shipment shipment);

/**
Determines whether a certain route crosses any buildings on the map.
route - Use the route construct to look for building intersections.
map - Buildings on the map are contained in the map struct.
returns - 0 if the path does not cross a building, and 1 if it does.
*/
int isBuildingIntersected(const struct Route route, const struct Map *map);

int isTruckOverloaded(Truck truck, Shipment ship);

int isBoxSizeExceeded(Truck truck, float boxSize);

int vaildCargo(float boxsize);

int test_populateMap();

int test_printMap();

#endif