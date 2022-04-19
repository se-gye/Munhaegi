#include <stdio.h>

void print_binary(int x) {
	if (x > 0) {
		print_binary(x / 2);
		printf("%d", x % 2);
	}
}

int main(void) {
	int x = 9;
	
	print_binary(x);
	return 0;
}