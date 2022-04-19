/*중복순열(중복O, 순서O)*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int n, int *bucket, int bucketSize, int k) {
	int i, lastIndex;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%d", bucket[i]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;
	
	for (i = 0; i < n; i++) {
		bucket[lastIndex + 1] = i;
		pick(n, bucket, bucketSize, k - 1);
	}
}

int main(void) {
	int *bucket, digit;

	printf("자리수를 입력하세요: ");
	scanf("%d", &digit);

	bucket = (int *)malloc(sizeof(int) * digit);
	pick(digit + 1, bucket, digit, digit);

	free(bucket);
	return 0;
}