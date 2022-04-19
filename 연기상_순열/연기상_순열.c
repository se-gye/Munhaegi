/*순열(중복X, 순서O)*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int isIn(int *bucket, int bucketSize, int n) {
	for (int i = 0; i < bucketSize; i++)
		if (n == bucket[i])
			return 1;
	return 0;
}

void pick(char **actor, int n, int *bucket, int bucketSize, int k) {
	int i, actorIndex, lastIndex;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++) {
			actorIndex = bucket[i];
			printf("%10s", actor[actorIndex]);
		}
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;

	for (i = 0; i < n; i++) {
		if (!isIn(bucket, bucketSize, i)) {
			bucket[lastIndex + 1] = i;
			pick(actor, n, bucket, bucketSize, k - 1);
		}
	}
}

int main(void) {
	int *actor[] = {"공유", "김수현", "송중기", "지성", "현빈"};
	int n = 5;
	int *bucket, bucketSize;

	printf("상의 종류는? ");
	scanf("%d", &bucketSize);

	bucket = (int *)malloc(sizeof(int) * bucketSize);
	pick(actor, n, bucket, bucketSize, bucketSize);

	free(bucket);
	return 0;
}