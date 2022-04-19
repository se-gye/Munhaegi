#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_LEVEL 5
#define MAX_WIDTH 70
char screen[MAX_LEVEL][MAX_WIDTH];
int screen1[MAX_LEVEL][MAX_WIDTH];
int count = 0;

void draw_tree(int row, int left, int right) {
	int mid;  //중간위치 계산

	if (right - left < 2) return;

	mid = (right + left) / 2;

	//printf("**테스트 row=%d left=%d mid=%d right=%d\n", row, left, mid, right);
	//printf("  (%d %d)에 X를 찍는다\n", row, mid);
	screen[row][mid] = 'X';

	draw_tree(row + 1, left, mid - 1);
	draw_tree(row + 1, mid + 1, right);
}

void draw_tree1(int row, int left, int right) {
	int mid;

	if (right - left < 2) return;

	mid = (right + left) / 2;
	screen1[row][mid] = ++count;

	draw_tree1(row + 1, left, mid - 1);
	draw_tree1(row + 1, mid + 1, right);
}

void init(char s[][MAX_WIDTH]) {
	int i, j;
	for (i = 0; i < MAX_LEVEL; i++)
		for (j = 0; j < MAX_WIDTH; j++)
			s[i][j] = '-';
}

void init1(int s[][MAX_WIDTH]) {
	int i, j;
	for (i = 0; i < MAX_LEVEL; i++)
		for (j = 0; j < MAX_WIDTH; j++)
			s[i][j] = '-';
}

void display(char s[][MAX_WIDTH], int width) {
	int i, j;
	for (i = 0; i < MAX_LEVEL; i++) {
		for (j = 0; j < width; j++)
			printf(" %c", s[i][j]);
		printf("\n");
	}		
}

void display1(int s[][MAX_WIDTH], int width) {
	int i, j;
	for (i = 0; i < MAX_LEVEL; i++) {
		for (j = 0; j < width; j++) {
			if (s[i][j] == '-')
				printf(" -");
			else
				printf(" %d", s[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	int width;
	
	printf("Enter a width(<= 70) of a screen: ");
	scanf("%d", &width);

	//init(screen);
	//draw_tree(0, 0, width - 1);
	//display(screen, width);

	init1(screen1);
	draw_tree1(0, 0, width - 1);
	display1(screen1, width);
	
	return 0;
}