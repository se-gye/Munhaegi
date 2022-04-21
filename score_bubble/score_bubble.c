#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
	int id;  //학번, 1부터 부여
	int korean, english, math;
};

void swap(struct Student *a, struct Student *b) {
	struct Student temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSortDescendingByKorean(struct Student *std, int n) {
	int i, j, temp;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - 1 - i; j++)
			if (std[j].korean < std[j + 1].korean)
				swap(&std[j], &std[j + 1]);
}

void bubbleSortAscendingById(struct Student *std, int n) {
	int i, j, temp;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - 1 - i; j++)
			if (std[j].id > std[j + 1].id)
				swap(&std[j], &std[j + 1]);
}

void printScore(struct Student *std, int n) {
	for (int i = 0; i < n; i++) {
		printf("학번 : %d\t", std[i].id);
		printf("영어 : %d\t수학 : %d\t국어 : %d\n", std[i].english, std[i].math, std[i].korean);
	}
	printf("\n");
}

int main(void) {
	int n, i;
	struct Student *std;

	printf("학생 수를 입력하세요 : ");
	scanf("%d", &n);  //학생수(n)

	std = (struct Student *)malloc(sizeof(struct Student) * n);

	srand(time(NULL));
	for (i = 0; i < n; i++) {
		std[i].id = i + 1;  //학번은 1부터
		std[i].korean = rand() % 101;
		std[i].english = rand() % 101;
		std[i].math = rand() % 101;
	}
	printScore(std, n);

	printf("국어점수 기준으로 내림차순 정렬된 후:\n");
	bubbleSortDescendingByKorean(std, n);
	printScore(std, n);

	printf("학번 기준으로 오름차순 정렬된 후:\n");
	bubbleSortAscendingById(std, n);
	printScore(std, n);

	free(std);
	return 0;
}