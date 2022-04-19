#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long calculateReverse(long long n) {
	int result = 0;

	while (n != 0) {
		result = (result * 10) + (n % 10);
		n /= 10;
	}
	return result;
}

int isPalindrome(long long n) {
	if (n == calculateReverse(n))
		return 1;
	else
		return 0;
}

void find_palindrome(long long n) {
	int step = 1;
	long long checkNum = n + calculateReverse(n);
	
	while (!isPalindrome(checkNum)) {
		step++;
		checkNum += calculateReverse(checkNum);

		if (step >= 1000) break;
	}
	
	if (step >= 1000)
		printf("NaN\n");
	else
		printf("%d %d\n", step, checkNum);
}

int main(void) {
	int n;

	scanf("%d", &n);
	find_palindrome(n);

	return 0;
}