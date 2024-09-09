#include <stdio.h> 
#include "mapping.h"

/* Test Case 1: populateMap()
 *
 * Test if the function correctly initializes a Map structure.
 * Verify that the number of rows and columns are correct.
 */
int test_populateMap() {
	int result;
	struct Map map = populateMap();  /* Create a map */

	/* Verify the number of rows and columns */
	if (map.numRows == MAP_ROWS && map.numCols == MAP_COLS) {
		result = 1;
		printf("populateMap test passed!\n");
	}
	else {
		result = 0;
		printf("populateMap test failed!\n");
	}
	return result;
}

/* Test Case 2: printMap()
 *
 * Test if the function correctly prints a Map structure to the console.
 * Verify that the printed output matches the expected output.
 */
void test_printMap(const struct Map* map, int base1, int alpha_cols) {
	char sym[] = " XB?G?.?Y?-?*?+?P";  /* Symbols used to represent squares */
	int row_max = map->numRows;  /* Maximum number of rows in the map */
	int col_max = map->numCols;  /* Maximum number of columns in the map */
	int r, c;  /* Loop variables */

	printf("%4s", " ");  /* Print a space to align with the left edge of the map */

	/* Print the column headers */
	for (c = 0; c < col_max; c++) {
		char col = 'A' + c;  /* Column header */
		if (alpha_cols)
			printf("%c", col);
		else
			printf("%d", c + base1);
	}
	printf("\n");  /* Newline at the end of the row */

	printf("%4s", " ");  /* Print a space to align with the left edge of the map */

	/* Print the row dividers */
	for (c = 0; c < col_max; c++)
		printf("-");
	printf("\n");  /* Newline at the end of the row */

	/* Print the rows of the map */
	for (r = 1; r <= row_max; r++) {
		printf("%3d|", r + base1 - 1);  /* Print the row header */
		for (c = 0; c < col_max; c++) {
			printf("%c", sym[map->squares[r - 1][c]]);  /* Print a symbol from the symbol array */
		}
		printf("\n");  /* Newline at the end of the row */
	}
}

//int main() {
//	test_populateMap();  /* Run the populateMap() test */
//
//	struct Map map1 = populateMap();  /* Create a map */
//	test_printMap(&map1, 1, 1);  /* Run the printMap() test with map1 and base1=1 and alpha_cols=1 */
//
//	struct Map map2 = populateMap();  /* Create a map */
//	test_printMap(&map2, 10, 0);  /* Run the printMap() test with map2 and base1=10 and alpha_cols=0 */
//
//	struct Map map3 = populateMap();  /* Create a map */
//	test_printMap(&map3, 20, 1);  /* Run the printMap() test with map3 and base1=20 and alpha_cols=1 */
//
//	return 0;
//}

