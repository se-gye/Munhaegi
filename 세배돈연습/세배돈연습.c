/*���起:�ߺ�O,����X => �ߺ�����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int count = 0;

//����ݾ��� ���起���� ������ 0, ������ 1, ũ�� 2 ��ȯ 
int checkMoney(int target, int *money, int *bucket, int lastIndex) {
	int i, sum = 0;

	for (i = 0; i <= lastIndex; i++) {
		sum += money[bucket[i]];
		if (sum == target)
			return 1;
		else if (sum > target)
			return 2;
	}
	return 0;
}

void pick(int *money, int n, int *bucket, int m, int toPick, int target) {
	int i, j, lastIndex, smallest, sum = 0;

	if (toPick == 0) {
		for (i = 0; i < m; i++) {
			sum += money[bucket[i]];
			if (sum == target) {
				for (j = i; j >= 0; j--) {
					if (!money[bucket[j]]) break;
					else printf("%d ", money[bucket[j]]);
				}
				printf("\n"); 
				count++;
				break;
			}
			else if (sum > target) return;
		}
		return;
	}

	lastIndex = m - toPick - 1;
	if (toPick == m)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	int check = checkMoney(target, money, bucket, lastIndex);
	if (check == 0) {  //�� ����
		for (i = smallest; i < n; i++) {
			bucket[lastIndex + 1] = i;
			pick(money, n, bucket, m, toPick - 1, target);
		}
	}
	else if (check == 1) {  //�� ��ġ		
		pick(money, n, bucket, m, 0, target);
		return;
	}
	else if (check == 2)  //�� �ʰ�
		return;
}
		  
int main(void) {
	int money[] = {1000, 5000, 10000};
	int *bucket, giveMoney;
	
	scanf("%d", &giveMoney);
	bucket = (int *)malloc(sizeof(int) * (giveMoney / 1000));

	pick(money, 4, bucket, giveMoney / 1000, giveMoney / 1000, giveMoney);
	printf("count=%d\n", count);

	free(bucket);
	return 0;
}