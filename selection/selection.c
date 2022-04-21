#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int *arr, int n) {
	int i, j, maxIndex, temp;

	for (i = 0; i < n - 1; i++) {
		maxIndex = 0;
		for (j = 0; j < n - i; j++)
			if (arr[maxIndex] < arr[j])
				maxIndex = j;
		
		temp = arr[n - 1 - i];
		arr[n - 1 - i] = arr[maxIndex];
		arr[maxIndex] = temp;
	}
}

void printArray(int *arr, int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void) {
	int n, i;
	int *arr;

	printf("Enter a number: ");
	scanf("%d", &n);

	arr = (int *)malloc(sizeof(int) * n);
	
	srand(time(NULL));
	for (i = 0; i < n; i++)
		arr[i] = rand() % 1000;
	printArray(arr, n);

	printf("정렬된 후:\n");
	selectionSort(arr, n);
	printArray(arr, n);

	free(arr);
	return 0;
}