#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int four_bonacci(int n) {  //수열은 0부터 시작
	if (n < 4)
		return n;
	else
		return four_bonacci(n - 4) + four_bonacci(n - 3) + four_bonacci(n - 2) + four_bonacci(n - 1);
}

int kbonacci(int k, int n) {

	if (n < k)
		return n;
	else {
		int i, sum = 0;
		for (i = k; i > 0; i--)
			sum += kbonacci(k, n - i);
		return sum;
	}
}

int main(void) {
	int k, n;

	scanf("%d %d", &k, &n);
	//printf("%d ", four_bonacci(1));

	for (int i=0;i<n;i++)
		printf("%d ", kbonacci(k, i));
	printf("\n");

	//printf("%d\n", kbonacci(k, n - 1));  //수열이 0부터 시작하므로 1을 뺴줘야함

	return 0;
}