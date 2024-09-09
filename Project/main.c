#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Truck.h"
#include "mapping.h"

int main(void)
{
	//initialize all routes with maps
	struct Map baseMap = populateMap();
	struct Route blueRoute = getBlueRoute();
	struct Route yellowRoute = getYellowRoute();
	struct Route greenRoute = getGreenRoute();
	struct Map routeMap = addRoute(&baseMap, &blueRoute);
	routeMap = addRoute(&routeMap, &yellowRoute);
	routeMap = addRoute(&routeMap, &greenRoute);

	//print map for display
	printMap(&routeMap, 1, 1);

	//initialize trucks, and variables for logic
	struct Truck truck;
	struct Truck blueTruck = { 0,0,{0,0} };
	struct Truck greenTruck = { 0,0,{0,0} };
	struct Truck yellowTruck = { 0,0,{0,0} };
	int loopFlag = 1;
	int i, truckSuccess;

	printf("==================\nSeneca Polytechnic Deliveries\n==================\n");

	while (loopFlag) {
		struct Route blueRouteArray[MAX_ROUTE] = { {0,0},0,0 };
		struct Route greenRouteArray[MAX_ROUTE] = { {0,0},0,0 };
		struct Route yellowRouteArray[MAX_ROUTE] = { {0,0},0,0 };

		int blueShortPath = 9999, blueShortIndex = 0;
		int greenShortPath = 9999, greenShortIndex = 0;
		int yellowShortPath = 9999, yellowShortIndex = 0;

		//get the truck values and returns 1 if succeed
		truckSuccess = setTruckInfo(&truck);

		//check if the condition is met for exiting the loop
		if (truck.size == 0 && truck.weight == 0) {
			loopFlag = 0;
		}

		//execute when data is successfully stored
		if (truckSuccess && loopFlag == 1) {
			// Get the closest point index from the array of routes of each truck to the destination
			int blueRouteIndex = getClosestPoint(&blueRoute, truck.destination);
			int greenRouteIndex = getClosestPoint(&greenRoute, truck.destination);
			int yellowRouteIndex = getClosestPoint(&yellowRoute, truck.destination);

			//to hand over a throwaway last spot to getPossibleMoves when checking possible spots around truck.destination
			struct Point tempBackspace = { -1,-1 };

			//get the possible square around the destination for the truck to travel to
			struct Route possibleMoves = getPossibleMoves(&baseMap, truck.destination, tempBackspace);

			//get the closest possible square that each truck can travel to that does not have a building
			int bluePossibleIndex = getClosestPoint(&possibleMoves, blueRoute.points[blueRouteIndex]);
			int greenPossibleIndex = getClosestPoint(&possibleMoves, greenRoute.points[greenRouteIndex]);
			int yellowPossibleIndex = getClosestPoint(&possibleMoves, yellowRoute.points[yellowRouteIndex]);

			//get all the possible route of blue truck and put them into a route array
			for (i = 0; i < blueRoute.numPoints; i++) {
				blueRouteArray[i] = shortestPath(&baseMap, blueRoute.points[i], possibleMoves.points[bluePossibleIndex]);
				
				//find shortest route among possible routes
				if (blueRouteArray[i].numPoints < blueShortPath && blueRouteArray[i].numPoints != -1) {
					blueShortPath = blueRouteArray[i].numPoints;
					blueShortIndex = i;
				}
			}

			//get all the possible route of green truck and put them into a route array
			for (i = 0; i < greenRoute.numPoints; i++) {
				greenRouteArray[i] = shortestPath(&baseMap, greenRoute.points[i], possibleMoves.points[greenPossibleIndex]);

				//find shortest route among possible routes
				if (greenRouteArray[i].numPoints < greenShortPath && greenRouteArray[i].numPoints != -1) {
					greenShortPath = greenRouteArray[i].numPoints;
					greenShortIndex = i;
				}
			}
			//get all the possible rotue of yellow truck and put them into a route array
			for (i = 0; i < yellowRoute.numPoints; i++) {
				yellowRouteArray[i] = shortestPath(&baseMap, yellowRoute.points[i], possibleMoves.points[yellowPossibleIndex]);

				//find shortest route among possible routes
				if (yellowRouteArray[i].numPoints < yellowShortPath && yellowRouteArray[i].numPoints != -1) {
					yellowShortPath = yellowRouteArray[i].numPoints;
					yellowShortIndex = i;
				}
			}

			//check if  number of points of the bluetruck route is less than the greentruck route and yellowtruck route
			if (blueRouteArray[blueShortIndex].numPoints <= greenRouteArray[greenShortIndex].numPoints && blueRouteArray[blueShortIndex].numPoints <= yellowRouteArray[yellowShortIndex].numPoints) {

				//validate whether blue truck has enough room and can carry it.
				if (validateTruckWeight(truck, &blueTruck.weight) && validateTruckSize(truck, &blueTruck.size)) {

					//determine if the number of point is greater than 0 then print the appropriate message
					if (blueRouteArray[blueShortIndex].numPoints > 0) {
						if (blueRouteArray[blueShortIndex].numPoints > DIVERSION) {
							blueTruck.weight -= truck.weight;
							blueTruck.size -= truck.size;
							printf("Invalid destination\n");
						}
						else {
							printf("Ship on BLUE LINE, divert: ");
							printf("%d%c, ", blueRoute.points[blueShortIndex].row + 1, blueRoute.points[blueShortIndex].col + 65);

							for (i = 0; i < blueRouteArray[blueShortIndex].numPoints; i++) {
								printf("%d%c, ", blueRouteArray[blueShortIndex].points[i].row + 1, blueRouteArray[blueShortIndex].points[i].col + 65);
							}
							printf("%d%c\n", truck.destination.row + 1, truck.destination.col + 65);
						}
					}
					else {
						printf("Ship on BLUE LINE, no diversion\n");
					}
				}
				else {
					//check if number of point of the yellowtruck route is less than the greentruck route.
					if (yellowRouteArray[yellowShortIndex].numPoints <= greenRouteArray[greenShortIndex].numPoints) {

						//validate whether yellow truck has enough room and can carry it.
						if (validateTruckWeight(truck, &yellowTruck.weight) && validateTruckSize(truck, &yellowTruck.size)) {

							//determine if the number of point is greater than 0 then print the appropriate message
							if (yellowRouteArray[yellowShortIndex].numPoints > 0) {
								if (yellowRouteArray[yellowShortIndex].numPoints > DIVERSION) {
									yellowTruck.weight -= truck.weight;
									yellowTruck.size -= truck.size;
									printf("Invalid destination\n");
								}
								else {
									printf("Ship on YELLOW LINE, divert: ");
									printf("%d%c, ", yellowRoute.points[yellowShortIndex].row + 1, yellowRoute.points[yellowShortIndex].col + 65);

									for (i = 0; i < yellowRouteArray[yellowShortIndex].numPoints; i++) {
										printf("%d%c, ", yellowRouteArray[yellowShortIndex].points[i].row + 1, yellowRouteArray[yellowShortIndex].points[i].col + 65);
									}
									printf("%d%c\n", truck.destination.row + 1, truck.destination.col + 65);
								}
							}
							else {
								printf("Ship on YELLOW LINE, no diversion\n");
							}
						}
						else {
							if (validateTruckWeight(truck, &greenTruck.weight) && validateTruckSize(truck, &greenTruck.size)) {
								//determine if the number of point is greater than 0 then print the appropriate message
								if (greenRouteArray[greenShortIndex].numPoints > 0) {
									if (greenRouteArray[greenShortIndex].numPoints > DIVERSION) {
										greenTruck.weight -= truck.weight;
										greenTruck.size -= truck.size;
										printf("Invalid destination\n");
									}
									else {
										printf("Ship on GREEN LINE, divert: ");
										printf("%d%c, ", greenRoute.points[greenShortIndex].row + 1, greenRoute.points[greenShortIndex].col + 65);

										for (i = 0; i < greenRouteArray[greenShortIndex].numPoints; i++) {
											printf("%d%c, ", greenRouteArray[greenShortIndex].points[i].row + 1, greenRouteArray[greenShortIndex].points[i].col + 65);
										}
										printf("%d%c\n", truck.destination.row + 1, truck.destination.col + 65);
									}
								}
								else {
									printf("Ship on GREEN LINE, no diversion\n");
								}
							}
							else {
								printf("Ship Tomorrow\n");
							}
						}
					}
					else {
						//validate whether green truck has enough room and can carry it.
						if (validateTruckWeight(truck, &greenTruck.weight) && validateTruckSize(truck, &greenTruck.size)) {

							//determine if the number of point is greater than 0 then print the appropriate message
							if (greenRouteArray[greenShortIndex].numPoints > 0) {
								if (greenRouteArray[greenShortIndex].numPoints > DIVERSION) {
									greenTruck.weight -= truck.weight;
									greenTruck.size -= truck.size;
									printf("Invalid destination\n");
								}
								else {
									printf("Ship on GREEN LINE, divert: ");
									printf("%d%c, ", greenRoute.points[greenShortIndex].row + 1, greenRoute.points[greenShortIndex].col + 65);

									for (i = 0; i < greenRouteArray[greenShortIndex].numPoints; i++) {
										printf("%d%c, ", greenRouteArray[greenShortIndex].points[i].row + 1, greenRouteArray[greenShortIndex].points[i].col + 65);
									}
									printf("%d%c\n", truck.destination.row + 1, truck.destination.col + 65);
								}
							}
							else {
								printf("Ship on GREEN LINE, no diversion\n");
							}
						}
						else if (validateTruckWeight(truck, &yellowTruck.weight) && validateTruckSize(truck, &yellowTruck.size)) {
							//determine if the number of point is greater than 0 then print the appropriate message
							if (yellowRouteArray[yellowShortIndex].numPoints > 0) {
								if (yellowRouteArray[yellowShortIndex].numPoints > DIVERSION) {
									yellowTruck.weight -= truck.weight;
									yellowTruck.size -= truck.size;
									printf("Invalid destination\n");
								}
								else {
									printf("Ship on YELLOW LINE, divert: ");
									printf("%d%c, ", yellowRoute.points[yellowShortIndex].row + 1, yellowRoute.points[yellowShortIndex].col + 65);

									for (i = 0; i < yellowRouteArray[yellowShortIndex].numPoints; i++) {
										printf("%d%c, ", yellowRouteArray[yellowShortIndex].points[i].row + 1, yellowRouteArray[yellowShortIndex].points[i].col + 65);
									}
									printf("%d%c\n", truck.destination.row + 1, truck.destination.col + 65);
								}
							}
							else {
								printf("Ship on YELLOW LINE, no diversion\n");
							}
						}
						else {
							printf("Ship Tomorrow\n");
						}
					}
				}
			}
			//check if the number of points of the greentruck route is less than the bluetruck route and yellowtruck route
			else if (greenRouteArray[greenShortIndex].numPoints <= blueRouteArray[blueShortIndex].numPoints && greenRouteArray[greenShortIndex].numPoints <= yellowRouteArray[yellowShortIndex].numPoints) {
				//validate whether green truck has enough room and can carry it.
				if (validateTruckWeight(truck, &greenTruck.weight) && validateTruckSize(truck, &greenTruck.size)) {

					//determine if the number of point is greater than 0 then print the appropriate message
					if (greenRouteArray[greenShortIndex].numPoints > 0) {
						if (greenRouteArray[greenShortIndex].numPoints > DIVERSION) {
							greenTruck.weight -= truck.weight;
							greenTruck.size -= truck.size;
							printf("Invalid destination\n");
						}
						else {
							printf("Ship on GREEN LINE, divert: ");
							printf("%d%c, ", greenRoute.points[greenShortIndex].row + 1, greenRoute.points[greenShortIndex].col + 65);

							for (i = 0; i < greenRouteArray[greenShortIndex].numPoints; i++) {
								printf("%d%c, ", greenRouteArray[greenShortIndex].points[i].row + 1, greenRouteArray[greenShortIndex].points[i].col + 65);
							}
							printf("%d%c\n", truck.destination.row + 1, truck.destination.col + 65);
						}
					}
					else {
						printf("Ship on GREEN LINE, no diversion\n");
					}
				}
				else {
					//check if number of point of the bluetruck route is less than the yellowtruck route.
					if (blueRouteArray[blueShortIndex].numPoints <= yellowRouteArray[yellowShortIndex].numPoints) {

						//validate whether blue truck has enough room and can carry it.
						if (validateTruckWeight(truck, &blueTruck.weight) && validateTruckSize(truck, &blueTruck.size)) {

							//determine if the number of point is greater than 0 then print the appropriate message
							if (blueRouteArray[blueShortIndex].numPoints > 0) {
								if (blueRouteArray[blueShortIndex].numPoints > DIVERSION) {
									blueTruck.weight -= truck.weight;
									blueTruck.size -= truck.size;
									printf("Invalid destination\n");
								}
								else {
									printf("Ship on BLUE LINE, divert: ");
									printf("%d%c, ", blueRoute.points[blueShortIndex].row + 1, blueRoute.points[blueShortIndex].col + 65);

									for (i = 0; i < blueRouteArray[blueShortIndex].numPoints; i++) {
										printf("%d%c, ", blueRouteArray[blueShortIndex].points[i].row + 1, blueRouteArray[blueShortIndex].points[i].col + 65);
									}
									printf("%d%c\n", truck.destination.row + 1, truck.destination.col + 65);
								}
							}
							else {
								printf("Ship on BLUE LINE, no diversion\n");
							}
						}
						else if (validateTruckWeight(truck, &yellowTruck.weight) && validateTruckSize(truck, &yellowTruck.size)) {
							//determine if the number of point is greater than 0 then print the appropriate message
							if (yellowRouteArray[yellowShortIndex].numPoints > 0) {
								if (yellowRouteArray[yellowShortIndex].numPoints > DIVERSION) {
									yellowTruck.weight -= truck.weight;
									yellowTruck.size -= truck.size;
									printf("Invalid destination\n");
								}
								else {
									printf("Ship on YELLOW LINE, divert: ");
									printf("%d%c, ", yellowRoute.points[yellowShortIndex].row + 1, yellowRoute.points[yellowShortIndex].col + 65);

									for (i = 0; i < yellowRouteArray[yellowShortIndex].numPoints; i++) {
										printf("%d%c, ", yellowRouteArray[yellowShortIndex].points[i].row + 1, yellowRouteArray[yellowShortIndex].points[i].col + 65);
									}
									printf("%d%c\n", truck.destination.row + 1, truck.destination.col + 65);
								}
							}
							else {
								printf("Ship on YELLOW LINE, no diversion\n");
							}
						}
						else {
							printf("Ship Tomorrow\n");
						}
					}
					else {
						//validate whether yellow truck has enough room and can carry it.
						if (validateTruckWeight(truck, &yellowTruck.weight) && validateTruckSize(truck, &yellowTruck.size)) {

							//determine if the number of point is greater than 0 then print the appropriate message
							if (yellowRouteArray[yellowShortIndex].numPoints > 0) {
								if (yellowRouteArray[yellowShortIndex].numPoints > DIVERSION) {
									yellowTruck.weight -= truck.weight;
									yellowTruck.size -= truck.size;
									printf("Invalid destination\n");
								}
								else {
									printf("Ship on YELLOW LINE, divert: ");
									printf("%d%c, ", yellowRoute.points[yellowShortIndex].row + 1, yellowRoute.points[yellowShortIndex].col + 65);

									for (i = 0; i < yellowRouteArray[yellowShortIndex].numPoints; i++) {
										printf("%d%c, ", yellowRouteArray[yellowShortIndex].points[i].row + 1, yellowRouteArray[yellowShortIndex].points[i].col + 65);
									}
									printf("%d%c\n", truck.destination.row + 1, truck.destination.col + 65);
								}
							}
							else {
								printf("Ship on YELLOW LINE, no diversion\n");
							}
						}
						else if (validateTruckWeight(truck, &blueTruck.weight) && validateTruckSize(truck, &blueTruck.size)) {
							//determine if the number of point is greater than 0 then print the appropriate message
							if (blueRouteArray[blueShortIndex].numPoints > 0) {
								if (blueRouteArray[blueShortIndex].numPoints > DIVERSION) {
									blueTruck.weight -= truck.weight;
									blueTruck.size -= truck.size;
									printf("Invalid destination\n");
								}
								else {
									printf("Ship on BLUE LINE, divert: ");
									printf("%d%c, ", blueRoute.points[blueShortIndex].row + 1, blueRoute.points[blueShortIndex].col + 65);

									for (i = 0; i < blueRouteArray[blueShortIndex].numPoints; i++) {
										printf("%d%c, ", blueRouteArray[blueShortIndex].points[i].row + 1, blueRouteArray[blueShortIndex].points[i].col + 65);
									}
									printf("%d%c\n", truck.destination.row + 1, truck.destination.col + 65);
								}
							}
							else {
								printf("Ship on BLUE LINE, no diversion\n");
							}
						}
						else {
							printf("Ship Tomorrow\n");
						}
					}

				}
			}
			//check if  number of points of the yellowtruck route is less than the greentruck route and bluetruck route
			else if (yellowRouteArray[yellowShortIndex].numPoints <= blueRouteArray[blueShortIndex].numPoints && yellowRouteArray[yellowShortIndex].numPoints <= greenRouteArray[greenShortIndex].numPoints) {
				//calidate whether yellow truck has enough room and can carry it.
				if (validateTruckWeight(truck, &yellowTruck.weight) && validateTruckSize(truck, &yellowTruck.size)) {
					//determine if the number of point is greater than 0 then print the appropriate message
					if (yellowRouteArray[yellowShortIndex].numPoints > 0) {
						if (yellowRouteArray[yellowShortIndex].numPoints > DIVERSION) {
							yellowTruck.weight -= truck.weight;
							yellowTruck.size -= truck.size;
							printf("Invalid destination\n");
						}
						else {
							printf("Ship on YELLOW LINE, divert: ");
							printf("%d%c, ", yellowRoute.points[yellowShortIndex].row + 1, yellowRoute.points[yellowShortIndex].col + 65);

							for (i = 0; i < yellowRouteArray[yellowShortIndex].numPoints; i++) {
								printf("%d%c, ", yellowRouteArray[yellowShortIndex].points[i].row + 1, yellowRouteArray[yellowShortIndex].points[i].col + 65);
							}
							printf("%d%c\n", truck.destination.row + 1, truck.destination.col + 65);
						}
					}
					else {
						printf("Ship on YELLOW LINE, no diversion\n");
					}
				}
				else {
					//check if number of point of the bluetruck route is less than the greentruck route.
					if (blueRouteArray[blueShortIndex].numPoints <= greenRouteArray[greenShortIndex].numPoints) {
						//validate whether blue truck has enough room and can carry it.
						if (validateTruckWeight(truck, &blueTruck.weight) && validateTruckSize(truck, &blueTruck.size)) {
							//determine if the number of point is greater than 0 then print the appropriate message
							if (blueRouteArray[blueShortIndex].numPoints > 0) {
								if (blueRouteArray[blueShortIndex].numPoints > DIVERSION) {
									blueTruck.weight -= truck.weight;
									blueTruck.size -= truck.size;
									printf("Invalid destination\n");
								}
								else {
									printf("Ship on BLUE LINE, divert: ");
									printf("%d%c, ", blueRoute.points[blueShortIndex].row + 1, blueRoute.points[blueShortIndex].col + 65);

									for (i = 0; i < blueRouteArray[blueShortIndex].numPoints; i++) {
										printf("%d%c, ", blueRouteArray[blueShortIndex].points[i].row + 1, blueRouteArray[blueShortIndex].points[i].col + 65);
									}
									printf("%d%c\n", truck.destination.row + 1, truck.destination.col + 65);
								}
							}
							else {
								printf("Ship on BLUE LINE, no diversion\n");
							}
						}
						else if (validateTruckWeight(truck, &greenTruck.weight) && validateTruckSize(truck, &greenTruck.size)) {
							//determine if the number of point is greater than 0 then print the appropriate message
							if (greenRouteArray[greenShortIndex].numPoints > 0) {
								if (greenRouteArray[greenShortIndex].numPoints > DIVERSION) {
									greenTruck.weight -= truck.weight;
									greenTruck.size -= truck.size;
									printf("Invalid destination\n");
								}
								else {
									printf("Ship on GREEN LINE, divert: ");
									printf("%d%c, ", greenRoute.points[greenShortIndex].row + 1, greenRoute.points[greenShortIndex].col + 65);

									for (i = 0; i < greenRouteArray[greenShortIndex].numPoints; i++) {
										printf("%d%c, ", greenRouteArray[greenShortIndex].points[i].row + 1, greenRouteArray[greenShortIndex].points[i].col + 65);
									}
									printf("%d%c\n", truck.destination.row + 1, truck.destination.col + 65);
								}
							}
							else {
								printf("Ship on GREEN LINE, no diversion\n");
							}
						}
						else {
							printf("Ship Tomorrow\n");
						}
					}
					else {
						//validate whether green truck has enough room and can carry it.
						if (validateTruckWeight(truck, &greenTruck.weight) && validateTruckSize(truck, &greenTruck.size)) {
							//determine if the number of point is greater than 0 then print the appropriate message
							if (greenRouteArray[greenShortIndex].numPoints > 0) {
								if (greenRouteArray[greenShortIndex].numPoints > DIVERSION) {
									greenTruck.weight -= truck.weight;
									greenTruck.size -= truck.size;
									printf("Invalid destination\n");
								}
								else {
									printf("Ship on GREEN LINE, divert: ");
									printf("%d%c, ", greenRoute.points[greenShortIndex].row + 1, greenRoute.points[greenShortIndex].col + 65);

									for (i = 0; i < greenRouteArray[greenShortIndex].numPoints; i++) {
										printf("%d%c, ", greenRouteArray[greenShortIndex].points[i].row + 1, greenRouteArray[greenShortIndex].points[i].col + 65);
									}
									printf("%d%c\n", truck.destination.row + 1, truck.destination.col + 65);
								}
							}
							else {
								printf("Ship on GREEN LINE, no diversion\n");
							}

						}
						else if (validateTruckWeight(truck, &blueTruck.weight) && validateTruckSize(truck, &blueTruck.size)) {
							//determine if the number of point is greater than 0 then print the appropriate message
							if (blueRouteArray[blueShortIndex].numPoints > 0) {
								if (blueRouteArray[blueShortIndex].numPoints > DIVERSION) {
									blueTruck.weight -= truck.weight;
									blueTruck.size -= truck.size;
									printf("Invalid destination\n");
								}
								else {
									printf("Ship on BLUE LINE, divert: ");
									printf("%d%c, ", blueRoute.points[blueShortIndex].row + 1, blueRoute.points[blueShortIndex].col + 65);

									for (i = 0; i < blueRouteArray[blueShortIndex].numPoints; i++) {
										printf("%d%c, ", blueRouteArray[blueShortIndex].points[i].row + 1, blueRouteArray[blueShortIndex].points[i].col + 65);
									}
									printf("%d%c\n", truck.destination.row + 1, truck.destination.col + 65);
								}
							}
							else {
								printf("Ship on BLUE LINE, no diversion\n");
							}
						}
						else {
							printf("Ship Tomorrow\n");
						}
					}

				}
			}
			else {
				printf("Ship Tomorrow\n");
			}
		}
	}
	printf("Thanks for shipping with Seneca Polytechnic!\n");
	return 0;
}