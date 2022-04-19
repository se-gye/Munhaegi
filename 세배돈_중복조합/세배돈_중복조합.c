/*세배돈:중복O,순서X => 중복조합*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int *money, int n, int *bucket, int bucketSize, int k) {
    int i, moneyIndex, lastIndex, smallest,sum;

    if (k == 0) {
        sum = 0;
        for (i = 0; i < bucketSize; i++) {
            moneyIndex = bucket[i];
            sum += money[moneyIndex];
        }
        if (sum == bucketSize * 1000) {
            for (i = 0; i < bucketSize; i++) {
                moneyIndex = bucket[i];
                if (money[moneyIndex])
                    printf("%d ", money[moneyIndex]);
            }
            printf("\n");
        }
        return;
    }

    lastIndex = bucketSize - k - 1;
    if (k == bucketSize)
        smallest = 0;
    else
        smallest = bucket[lastIndex];

    for (i = smallest; i < n; i++) {
        bucket[lastIndex + 1] = i;
        pick(money, n, bucket, bucketSize, k - 1);
    }
}

int main(void) {
    int money[4] = {0, 1000, 5000, 10000};
    int *bucket, giveMoney;

    printf("Enter money to give: ");
    scanf("%d", &giveMoney);

    bucket = (int *)malloc(sizeof(int) * (giveMoney / 1000));
    pick(money, 4, bucket, giveMoney / 1000, giveMoney / 1000);

    free(bucket);
    return 0;
}