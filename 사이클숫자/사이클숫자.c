#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_cycle_number1(int n) { //�ݺ�
	int count = 1;

	printf("%d", n);
	while (n != 1) {
		if (n % 2 == 0)
			n = n / 2;
		else
			n = n * 3 + 1;

		printf(" %d", n);
		count++;
	}
	printf("\n");

	return count;
}

int get_cycle_number2(int n) { //��ȯ
	if (n == 1)
		return 1;
	else if (n % 2 == 0)
		return get_cycle_number2(n / 2) + 1;
	else
		return get_cycle_number2(n * 3 + 1) + 1;
}

int main(void) {
	int n;

	printf("������ �Է��ϼ���: ");
	scanf("%d", &n);

	printf("\n���� %d�� ����Ŭ ���̴� %d\n", n, get_cycle_number2(n));
	return 0;
}