/*중복조합*/
#include <stdio.h>

void pick(int n, int *bucket, int bucketSize, int k) {
	int i, lastIndex, smallest;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;
	if (k == bucketSize)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	for (i = smallest; i < n; i++) {
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