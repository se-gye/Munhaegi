#include <stdio.h>

long long pow(int r, int n) {
	if (n == 1)
		return r;
	else
		return r * pow(r, n - 1);
}

int main(void) {
	int r = 2, n = 5;

	printf("%d�� %d������ %d�Դϴ�.\n", r, n, pow(r, n));
	return 0;
}