/*조합(순서X, 중복X)*/
#include <stdio.h>

void pick(char *item, int n, int *bucket, int bucketSize, int k) {
	int i, itemIndex, lastIndex, smallest;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++) {
			itemIndex = bucket[i];
			printf("%c ", item[itemIndex]);
		}			
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;
	if (k == bucketSize)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		bucket[lastIndex + 1] = i;
		pick(item, n, bucket, bucketSize, k - 1);
	}
}

int main(void) {
	char *item = "ABCDEFG";
	int n = 7;
	int *bucket[3];

	pick(item, n, bucket, 3, 3);
	
	return 0;
}