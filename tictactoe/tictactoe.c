#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 3

void display(char b[][SIZE]) {
	int i, j;

	printf("    ");
	for (i = 0; i < SIZE; i++)
		printf("%2d", i);
	printf("\n    ------\n");

	for (i = 0; i < SIZE; i++) {
		printf("%d  :", i);
		for (j = 0; j < SIZE; j++)
			printf(" %c", b[i][j]);
		printf("\n");
	}
}

int winCheck(char b[][SIZE], int x, int y) {
	char turn = b[x][y];
	int i, j, count;

	count = 1;
	for (j = y - 1; j >= 0; j--) {  //수평왼쪽
		if (b[x][j] == turn) count++;
		else break;
	}
	for (j = y + 1; j < SIZE; j++) { //수평오른쪽
		if (b[x][j] == turn) count++;
		else break;
	}
	if (count == SIZE) return 1;

	count = 1;
	for (i = x - 1; i >= 0; i--) {  //수직위쪽
		if (b[i][y] == turn) count++;
		else break;
	}
	for (i = x + 1; i < SIZE; i++) { //수직아래쪽
		if (b[i][y] == turn) count++;
		else break;
	}
	if (count == SIZE) return 1;

	count = 1;
	i = x - 1; j = y + 1;
	while (i >= 0 && j < SIZE) {  //대각선위쪽
		if (b[i][j] == turn) count++;
		else break;

		i--; j++;
	}
	i = x + 1; j = y - 1;
	while (i < SIZE && j >= 0) {  //대각선아래쪽
		if (b[i][j] == turn) count++;
		else break;

		i++; j--;
	}
	if (count == SIZE) return 1;

	count = 1;
	i = x - 1; j = y - 1;
	while (i >= 0 && j >= 0) {  //역대각선위쪽
		if (b[i][j] == turn) count++;
		else break;

		i--; j--;
	}
	i = x + 1; j = y + 1;
	while (i < SIZE && j < SIZE) { //역대각선아래쪽
		if (b[i][j] == turn) count++;
		else break;

		i++; j++;
	}
	if (count == SIZE) return 1;

	return 0;
}

int main(void) {
	char board[SIZE][SIZE];
	char turn = 'X', win = ' ';
	int x, y;
	int i, j, count;

	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			board[i][j] = ' ';

	count = 0;
	display(board);

	while (count < SIZE * SIZE) {
		printf("Player %c(행 열):", turn);
		scanf("%d %d", &x, &y);

		if (board[x][y] != ' ') continue;

		board[x][y] = turn;
		display(board);
		count++;

		if (winCheck(board, x, y)) {
			win = turn;
			break;
		}			

		turn = (turn == 'X') ? 'O' : 'X';
	}

	if (win == ' ' && count == SIZE * SIZE)
		printf("Nobody wins!\n");
	else
		printf("Player %c wins!\n", win);
	
	return 0;	
}