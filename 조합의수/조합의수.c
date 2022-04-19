#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int comb(int n, int r) {
	if (r == 0 || r == n)
		return 1;
	else
		return comb(n - 1, r - 1) + comb(n - 1, r);
}

int main(void) {
	int n, r;
	
	printf("n과 r을 입력하세요(ex. 5 2): ");
	scanf("%d %d", &n, &r);
	
	printf("\n%d개에서 %d개를 뽑는 가지수 = %d\n", n, r, comb(n, r));
	return 0;
}