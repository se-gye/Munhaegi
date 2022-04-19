#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isOne(int n) {
	while (n != 0) {
		if (n % 10 != 1)
			return 0;
		n /= 10;
	}
	return 1;
}

int main(void) {
	int a, b, result, count = 0;

	scanf("%d", &a);
	
	b = 2;
	while (1) {
		if (isOne(a * b))
			break;
		b++;
	}

	result = a * b;
	while (result != 0) {
		count++;
		result /= 10;
	}

	printf("%d\n", count);
	return 0;
}