/*조합(중복X, 순서X)*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(char **actor, int n, int *bucket, int bucketSize, int k) {
	int i, actorIndex, lastIndex, smallest;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++) {
			actorIndex = bucket[i];
			printf("%10s", actor[actorIndex]);
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
		pick(actor, n, bucket, bucketSize, k - 1);
	}
}

int main(void) {
	char *actor[] = {"공유", "김수현", "송중기", "지성", "현빈"};
	int n = 5;
	int *bucket, bucketSize;

	printf("인기상 몇명? ");
	scanf("%d", &bucketSize);

	bucket = (int *)malloc(sizeof(int) * bucketSize);
	pick(actor, n, bucket, bucketSize, bucketSize);

	free(bucket);
	return 0;
}