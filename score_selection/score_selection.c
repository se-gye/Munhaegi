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
	selectionSortDescendingByKorean(std, n);
	printScore(std, n);
	
	free(std);
	return 0;
}