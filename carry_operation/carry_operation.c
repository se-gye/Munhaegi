#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int carry_count(int a, int b) {
	int count = 0;

	while (a != 0 || b != 0) {
		if ((a % 10 + b % 10) >= 10)
			count++;
		a /= 10;
		b /= 10;
	}
	return count;
}

int main(void) {
	int n1, n2;
	
	printf("�ΰ��� �ڿ����� �Է��ϼ���(ex. 123 999): ");
	scanf("%d %d", &n1, &n2);

	printf("\n%d�� %d�� ���� �� carry�� Ƚ����? %d��\n", n1, n2, carry_count(n1, n2));
	return 0;
}