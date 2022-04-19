#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_cycle_number1(int n) { //반복
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

int get_cycle_number2(int n) { //순환
	if (n == 1)
		return 1;
	else if (n % 2 == 0)
		return get_cycle_number2(n / 2) + 1;
	else
		return get_cycle_number2(n * 3 + 1) + 1;
}

int main(void) {
	int n;

	printf("정수를 입력하세요: ");
	scanf("%d", &n);

	printf("\n정수 %d의 사이클 길이는 %d\n", n, get_cycle_number2(n));
	return 0;
}