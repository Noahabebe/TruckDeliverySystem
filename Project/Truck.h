#pragma once
#ifndef TRUCK_H
#define TRUCK_H
#include "mapping.h"

//Truck class to store a trucks information
struct Truck {
	int weight;
	double size;
	struct Point destination;
};

/*
*Get user input and store it in Truck. The values include:
*The weight of the package, size of the package and the destination of the package.
*Will repeat until (0 0 x) is entered.
*@param truck The location of structure truck that the data will be stored in.
*@return a integer which acts as a bool to show if valid data has been entered and stored or not
*/
int setTruckInfo(struct Truck* truck);

/*
*Test whether the weight of the truck exceeds the maximum truck weight.
*It takes a truck object paramter and another parameter weight and adds the packages weight to truck.
*It will then test if shipment weight exceeds the maximum truck weight allowed.
*Returns 0 if it exceeds weight limit, return 1 otherwise if weight isn't exceeded.
*/
int validateTruckWeight(struct Truck truck, int* weight);

/*
*Test whether the size of the box can fit inside the truck.
*it takes a parameter truck and another parameter size and add the specified size to truck.
*It will then test if the shipment size exceeds the maximum truck size allowed.
*Return 1 if it does not exceed, otherwise return 0 if it does exceeed.
*/
int validateTruckSize(struct Truck truck, double* size);

/*
*Test whether the size is one of the three size allowed in the truck. 0.5, 1 and 5 cubic meters.
*It takes a parameter size and test whether the size is one of the 3 sizes that are allowed.
*Returns 1 if it is one of the allowed size, otherwise return 0 if it is not an allowed size.
*/
int validateCargoSize(double size);

#endif // TRUCK_H