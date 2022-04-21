#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *arr, int n) {
	int i, j, temp;

	for (i = 0; i < n - 1; i++)
		for (j=0;j<n-1-i;j++)
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
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
	bubbleSort(arr, n);
	printArray(arr, n);

	free(arr);
	return 0;
}