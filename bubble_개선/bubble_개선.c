#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int *arr, int n) {
	for (int i = 0; i < n; i++)
		printf("%4d", arr[i]);
	printf("\n");
}

void print_bubbleSort(int *arr, int n) {
	int i, j, temp, flag;

	for (i = 0; i < n - 1; i++) {
		flag = 0;
		for (j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

				flag = 1;
			}
		}
		if (flag) {
			printf("i = %d:", i);
			printArray(arr, n);
		}
	}
}

int main(void) {
	int n, i;
	int *arr;

	printf("Enter a number : ");
	scanf("%d", &n);

	arr = (int *)malloc(sizeof(int) * n);
	//srand(time(NULL));
	for (i = 0; i < n; i++)
		arr[i] = rand() % 100;

	printf("초기 :");
	printArray(arr, n);

	print_bubbleSort(arr, n);
	
	printf("정렬 :");
	printArray(arr, n);
	
	free(arr);
	return 0;
}