#include <stdio.h>

void pick(int n, int *picked, int m, int toPick) {
	int i, lastIndex, smallest;

	if (toPick == 0) {
		for (i = 0; i < m; i++)
			printf("%d ", picked[i]);
		printf("\n");
		return;
	}

	lastIndex = m - toPick - 1;

	if (toPick == m)
		smallest = 0;
	else
		smallest = picked[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		picked[lastIndex + 1] = i;
		pick(n, picked, m, toPick - 1);
	}
}

int main(void) {
	int picked[4];

	pick(7, picked, 4, 4);
	return 0;
}