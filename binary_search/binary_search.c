#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int list[] = {1, 3, 5, 6, 7, 9, 11, 20, 30};
int list2[] = {47,45,42,41,38,34,30,29,27,22,20,18,13,11,6,2};

int sort_list(int list[], int size) {
	int i, j, temp;

	for (i=0;i<size;i++)
		for (j=0;j<size-1;j++)
			if (list[j] > list[j + 1]) {
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
}

void print_list(int list[], int size) {
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", list[i]);
	printf("\n");
}

int search_binary_loop(int list[], int key, int low, int high) {
	int middle;

	while (low <= high) {
		middle = (low + high) / 2;

		if (key == list[middle])
			return middle;
		else if (key < list[middle])  //왼쪽
			high = middle - 1;
		else  //오른쪽
			low = middle + 1;
	}
	return -1;
}

int search_binary_recur(int list[], int key, int low, int high) {
	int middle;

	if (low <= high) {
		middle = (low + high) / 2;
		if (key == list[middle])
			return middle;
		else if (key < list[middle])  //왼쪽
			return search_binary_recur(list, key, low, middle - 1);
		else  //오른쪽
			return search_binary_recur(list, key, middle + 1, high);
	}
	return -1;
}

int main(void) {
	int low = 0;
	//int high = sizeof(list) / sizeof(int) - 1;
	int high = sizeof(list2) / sizeof(int) - 1;
	int key, index;

	sort_list(list2, high+1);
	print_list(list2, high+1);

	printf("\nkey를 입력하세요(-1 입력시 종료): ");
	scanf("%d", &key);

	while (key != -1) {
		printf("\n%d를 탐색하는 경우\n", key);
		//index = search_binary_loop(list, key, low, high);
		index = search_binary_recur(list2, key, low, high);
		if (index == -1)
			printf("=> 탐색실패\n");
		else
			printf("=> 탐색성공 : %d의 인덱스는 %d\n", key, index);

		printf("\nkey를 입력하세요(-1 입력시 종료): ");
		scanf("%d", &key);
	}
	
	return 0;
}