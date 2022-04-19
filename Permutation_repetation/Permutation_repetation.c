/*중복순열*/
#include <stdio.h>

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
		bucket[lastIndex + 1] = i;
		pick(n, bucket, bucketSize, k - 1);
	}
}

int main(void) {
	int n = 8;
	int bucket[3];

	pick(n, bucket, 3, 3);

	return 0;
}