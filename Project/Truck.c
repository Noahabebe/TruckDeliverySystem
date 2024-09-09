#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include "math.h"
#include "Truck.h"
#include "mapping.h"

int setTruckInfo(struct Truck* truck) {
	int destinationRow;
	char destinationCol;
	int destinationColInt;
	int c;

	printf("Enter shipment weight, box size and destination (0 0 x to stop): ");

	while (!scanf("%d %lf %d %c", &truck->weight, &truck->size, &destinationRow, &destinationCol)) {
		printf("Enter shipment weight, box size and destination (0 0 x to stop): ");

		//clear buffer
		while ((c = getchar()) != '\n' && c != EOF) {}
	}
	//check if the loops exiting condition is met
	if (truck->weight == 0 && truck->size == 0) {
		return 0;
	}
	destinationCol = toupper(destinationCol);
	//Converting a char to int using ASCII value
	destinationColInt = destinationCol - 'A';
	//Decrement to account for row starting at 0
	destinationRow--;

	//Delcaring a point struct using the inputs received as coordinates.
	struct Point destinationCoords = { destinationRow,destinationColInt };
	truck->destination = destinationCoords;

	//create baseMap to compare inputted coordinates with
	struct Map baseMap = populateMap();

	//Validate if package is valid and can be put onto a truck, and the destination is on a building tile
	if (truck->weight <= TRUCKWEIGHT && truck->weight >= 1) {
		if (validateCargoSize(truck->size)) {
			if (truck->destination.row >= 0 && truck->destination.row <= 24 && truck->destination.col >= 0 && truck->destination.col <= 24 && baseMap.squares[destinationRow][destinationColInt] == 1) {
				return 1;
			}
			else {
				printf("Invalid destination\n");
			}
		}
		else {
			printf("Invalid size\n");
		}
	}
	else {
		printf("Invalid weight (must be 1-2500 Kg.)\n");
	}
	return 0;
}

int validateTruckWeight(struct Truck truck, int* weight) {
	//Check for added weight > 0 to safeguard against invalid weight being given 
	//and check for pointer weight >= 0 to make sure it's not holding negative weight
	if (*weight <= TRUCKWEIGHT && *weight >= 0 && truck.weight > 0) {
		*weight += truck.weight;
		if (*weight <= TRUCKWEIGHT) {
			return 1;
		}
		else {
			*weight -= truck.weight;
			return 0;
		}
	}
	else {
		return 0;
	}
	return 0;
}

int validateTruckSize(struct Truck truck, double* size) {
	//Check for added weight > 0 to safeguard against invalid weight being given 
	//and check for pointer size >= 0 to make sure it's not holding negative weight
	if (*size <= TRUCKSIZE && *size >= 0 && truck.size > 0) {
		*size += truck.size;
		if (*size <= TRUCKSIZE) {
			return 1;
		}
		else {
			*size -= truck.size;
			return 0;
		}
	}
	else {
		return 0;
	}
	return 0;
}

int validateCargoSize(double size) {
	if (size == SMALLSIZE || size == MEDIUMSIZE || size == LARGESIZE) {
		return 1;
	}
	else {
		return 0;
	}
}
