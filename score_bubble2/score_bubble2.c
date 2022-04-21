#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
	int id;
	int korean, english, math;
};

void swap(struct Student *a, struct Student *b) {
	struct Student temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(struct Student *std, int n, int choice) {
	int i, j, temp;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			switch (choice) {
			case 1:  //���� ��������
				if (std[j].korean < std[j + 1].korean)
					swap(&std[j], &std[j + 1]);
				break;
			case 2:  //���� ��������
				if (std[j].math < std[j + 1].math)
					swap(&std[j], &std[j + 1]);
				break;
			case 3:  //���� ��������
				if (std[j].english < std[j + 1].english)
					swap(&std[j], &std[j + 1]);
				break;
			case 4:  //id ��������
				if (std[j].id > std[j + 1].id)
					swap(&std[j], &std[j + 1]);
				break;
			default:
				break;
			}
		}
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
	int n, i, choice;
	struct Student *std;

	printf("�л� ���� �Է��ϼ��� : ");
	scanf("%d", &n);  //�л���(n)

	std = (struct Student *)malloc(sizeof(struct Student) * n);

	srand(time(NULL));
	for (i = 0; i < n; i++) {
		std[i].id = i + 1;
		std[i].korean = rand() % 101;
		std[i].math = rand() % 101;
		std[i].english = rand() % 101;
	}
	printScore(std, n);

	printf("���� ���� ����(1:����, 2:����, 3:����, 4:id(��������), 0:������) : ");
	scanf("%d", &choice);

	while (choice) {
		bubbleSort(std, n, choice);
		printScore(std, n);

		printf("���� ���� ����(1:����, 2:����, 3:����, 4:id(��������), 0:������) : ");
		scanf("%d", &choice);
	}

	free(std);
	return 0;
}