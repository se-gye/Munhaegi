/*순열*/
#include <stdio.h>

// n이 bucket에 있으면 1, 그렇지 않으면 0 반환
int isIn(int *bucket, int bucketSize, int n) {
	for (int i = 0; i < bucketSize; i++)
		if (bucket[i] == n)
			return 1;
	return 0;
}

void pick(int n, int *bucket, int bucketSize, int k) {
	int i, lastIndex;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;

	for (i = 0; i < n; i++) {
		if (isIn(bucket, lastIndex + 1, i))
			continue;
		else {
			bucket[lastIndex + 1] = i;
			pick(n, bucket, bucketSize, k - 1);
		}
	}
}

int main(void) {
	int n = 8;
	int bucket[4];

	pick(n, bucket, 4, 4);

	return 0;
}