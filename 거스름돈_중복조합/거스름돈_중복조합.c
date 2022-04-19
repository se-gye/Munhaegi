/*거스름돈:중복O,순서X => 중복조합*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int count = 0;

void pick(int *money, int n, int *bucket, int bucketSize, int k) {
	int i, moneyIndex, lastIndex, smallest, sum;

	if (k == 0) {
		sum = 0;
		for (i = 0; i < bucketSize; i++) {
			moneyIndex = bucket[i];
			sum += money[moneyIndex];
		}

		if (sum == bucketSize * 10) {
			for (i = 0; i < bucketSize; i++) {
				moneyIndex = bucket[i];
				printf("%d ", money[moneyIndex]);
			}
			printf("\n");
			count++;
		}
		return;
	}

	lastIndex = bucketSize - k - 1;
	if (k == bucketSize)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	for (i = 0; i < bucketSize; i++) {
		bucket[lastIndex + 1] = i;
		pick(money, n, bucket, bucketSize, k - 1);
	}
}

int main(void) {
	int money[4] = {10, 50, 100, 500};
	int *bucket, change;

	printf("거스름돈을 입력하세요: ");
	scanf("%d", &change);

	bucket = (int *)malloc(sizeof(int) * change);
	pick(money, 4, bucket, change / 10, change / 10);
	
	printf("%d\n", count);
	free(bucket);
	return 0;
}