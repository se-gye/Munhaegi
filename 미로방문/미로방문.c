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

int flood_fill(int x, int y, int cnt) {
	if (screen[x][y] == 0) {
		screen[x][y] = cnt++;

		cnt = flood_fill(x, y + 1, cnt);  //3시
		cnt = flood_fill(x + 1, y, cnt);  //6시
		cnt = flood_fill(x, y - 1, cnt);  //9시ggs
		cnt = flood_fill(x - 1, y, cnt);  //12시
	}
	return cnt;
}

int main(void) {
	int x = 4;
	int y = 3;

	display(screen);
	flood_fill(x, y, 1);

	printf("\n");
	display(screen); 

	return 0;
}