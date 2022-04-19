#include <stdio.h>

#define WIDTH 10
#define HEIGHT 10
int screen[WIDTH][HEIGHT] = {
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1,  0,  0, -1, -1, -1,  0, -1, -1,
		-1, -1, -1,  0,  0,  0,  0,  0, -1, -1,
		-1, -1, -1,  0, -1, -1, -1, -1, -1, -1,
		-1, -1, -1,  0,  0,  0,  0,  0, -1, -1,
		-1, -1, -1,  0, -1,  0, -1, -1, -1, -1,
		-1, -1, -1,  0, -1,  0, -1, -1, -1, -1,
		-1, -1, -1,  0, -1,  0,  0,  0, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1
};

void display(int s[][HEIGHT]) {
	int i, j;
	for (i = 0; i < WIDTH; i++) {
		for (j = 0; j < HEIGHT; j++)
			printf("%3d", s[i][j]);
		printf("\n");
	}
}

void flood_fill(int x, int y) {
	if (screen[x][y] == 0) {
		screen[x][y] = 9;

		flood_fill(x - 1, y); //╩С
		flood_fill(x + 1, y); //го
		flood_fill(x, y - 1); //аб
		flood_fill(x, y + 1); //©Л
	}	
}

int main(void) {
	int x = 4;
	int y = 3;

	display(screen);
	flood_fill(x, y);

	printf("\n");
	display(screen);

	return 0;
}