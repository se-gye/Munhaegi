#include <stdio.h>

int fib(int n) {
	if (n < 2)
		return n;
	else
		return fib(n - 2) + fib(n - 1);
}

int main(void) {
	int n = 9;
	
	printf("fib(%d) = %d\n", n, fib(n));
	return 0;
}