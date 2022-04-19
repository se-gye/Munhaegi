/*중복순열(중복O, 순서O)*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(char *oper, int operSize, int *bucket, int bucketSize, int k) {
	int i, operIndex, lastIndex, sum;

	if (k == 0) {
		sum = 0;
		for (i = 0; i < bucketSize; i++) {
			operIndex = bucket[i];
			printf("%c", oper[operIndex]);
			printf("%d", i + 1);

			if (oper[operIndex] == '+')
				sum += (i + 1);
			else
				sum -= (i + 1);
		}
		printf(" = %d\n", sum);
		return;
	}
	
	lastIndex = bucketSize - k - 1;

	for (i = 0; i < operSize; i++) {
		bucket[lastIndex + 1] = i;
		pick(oper, operSize, bucket, bucketSize, k - 1);
	}
}

int main(void) {
	char oper[] = "+-";
	int *bucket, n;

	printf("정수 n을 입력하세요: ");
	scanf("%d", &n);

	bucket = (int *)malloc(sizeof(int) * n);
	pick(oper, 2, bucket, n, n);

	free(bucket);
	return 0;
}