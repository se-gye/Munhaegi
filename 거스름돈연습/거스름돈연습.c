/*거스름돈:중복O,순서X => 중복조합*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int count = 0; //경우의 수

// 비교할 금액보다 작으면 0, 같으면 1, 크면 2 반환
int compareMoney(int target, int *money, int *bucket, int lastIndex) {
	int i, sum = 0;

	for (i = 0; i <= lastIndex; i++) {
		sum += money[bucket[i]];
		if (sum == target) return 1;
		else if (sum > target) return 2;
	}
	return 0;
}

void pick(int *money, int n, int *bucket, int m, int toPick, int target) {
	int i, j, lastIndex, smallest, sum = 0;

	if (toPick == 0) {
		for (i = 0; i < m; i++) {
			sum += money[bucket[i]];
			if (sum == target) {
				for (j = i; j >= 0; j--)
					printf("%d ", money[bucket[j]]);
				printf("\n");
				break;
			}
			else if (sum > target) return;
		}
		count++;
		return;
	}

	lastIndex = m - toPick - 1;
	if (toPick == m)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	int flag = compareMoney(target, money, bucket, lastIndex);
	if (flag == 0) {
		for (i = smallest; i < n; i++) {
			bucket[lastIndex + 1] = i;
			pick(money, n, bucket, m, toPick - 1, target);
		}
	}
	else if (flag == 1) {
		pick(money, n, bucket, m, 0, target);
		return;
	}
	else if (flag == 2)
		return;
}

int main(void) {
	int money[] = {10, 50, 100, 500};
	int *bucket, change;

	scanf("%d", &change);
	bucket = (int *)malloc(sizeof(int) * (change / 10));

	pick(money, 4, bucket, change / 10, change / 10, change, 0);
	printf("count = %d\n", count);

	free(bucket);
	return 0;
}