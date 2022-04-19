#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define X_VALUE 5
#define Y_VALUE 5

void readBombInfo(char grid[][Y_VALUE + 1]) {
	int i;

	printf("Input Grid\n");
	for (i = 0; i < X_VALUE; i++)
		scanf("%s", grid[i]);
}

void countBomb(char grid[][Y_VALUE + 1], int numOfBombs[][Y_VALUE]) {
	int i, j;
	int m, n;

	for (i=0;i<X_VALUE;i++)
		for (j=0;j<Y_VALUE;j++)
			if (grid[i][j] == '*') {				
				for (m = i - 1; m <= i + 1; m++) {
					if (m < 0 || m >= X_VALUE) continue;
					for (n = j - 1; n <= j + 1; n++) {
						if (n < 0 || n >= Y_VALUE) continue;
						numOfBombs[m][n]++;
					}
				}
			}
}

void display_numOfBombs(char grid[][Y_VALUE + 1], int numOfBombs[][Y_VALUE]) {
	int i, j;

	printf("Output Grid\n");
	for (i = 0; i < X_VALUE; i++) {
		for (j = 0; j < Y_VALUE; j++) {
			if (grid[i][j] == '*')
				printf("*");
			else
				printf("%d", numOfBombs[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	char grid[X_VALUE][Y_VALUE + 1];
	int numOfBombs[X_VALUE][Y_VALUE] = {0};

	readBombInfo(grid);
	countBomb(grid, numOfBombs);
	display_numOfBombs(grid, numOfBombs);

	return 0;
}