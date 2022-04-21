#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
	int id;  //�й�, 1���� �ο�
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
		printf("�й� : %d\t", std[i].id);
		printf("���� : %d\t���� : %d\t���� : %d\n", std[i].english, std[i].math, std[i].korean);
	}
	printf("\n");
}

int main(void) {
	int n, i;
	struct Student *std;

	printf("�л� ���� �Է��ϼ��� : ");
	scanf("%d", &n);  //�л���(n)

	std = (struct Student *)malloc(sizeof(struct Student) * n);

	srand(time(NULL));
	for (i = 0; i < n; i++) {
		std[i].id = i + 1;  //�й��� 1����
		std[i].korean = rand() % 101;
		std[i].english = rand() % 101;
		std[i].math = rand() % 101;
	}
	printScore(std, n);

	printf("�������� �������� �������� ���ĵ� ��:\n");
	bubbleSortDescendingByKorean(std, n);
	printScore(std, n);

	printf("�й� �������� �������� ���ĵ� ��:\n");
	bubbleSortAscendingById(std, n);
	printScore(std, n);

	free(std);
	return 0;
}