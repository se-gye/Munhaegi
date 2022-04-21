/*n개의 랜덤 배열 생성 (동적할당)*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int n, i;
	int *arr;

	printf("Enter a number: ");
	scanf("%d", &n);

	arr = (int *)malloc(sizeof(int) * n);
	
	srand(time(NULL));
	for (i = 0; i < n; i++)
		arr[i] = rand() % 1000;

	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	free(arr);
	return 0;
}