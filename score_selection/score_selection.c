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

void selectionSortDescendingByKorean(struct Student *std, int n) {
	int i, j, minIndex, temp;

	for (i = 0; i < n - 1; i++) {
		minIndex = 0;
		for (j = 0; j < n - i; j++)
			if (std[minIndex].korean > std[j].korean)
				minIndex = j;

		swap(&std[minIndex], &std[n - 1 - i]);
		/*temp = std[minIndex].korean;
		std[minIndex].korean = std[n - 1 - i].korean;
		std[n - 1 - i].korean = temp;*/
	}		
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
	selectionSortDescendingByKorean(std, n);
	printScore(std, n);
	
	free(std);
	return 0;
}