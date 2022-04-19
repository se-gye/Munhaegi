#include <stdio.h>

int list[] = {9, 5, 8, 3, 7};

int seq_search(int key, int low, int high) {
	int i;
	for (i = low; i <= high; i++)
		if (list[i] == key)
			return i;  //탐색성공(인덱스 반환)
	return -1;  //탐색실패
}

int seq_search2(int key, int low, int high) {
	int i;

	list[high + 1] = key;  //리스트 끝에 탐색키 저장
	for (i = low; list[i] != key; i++);  //키 값을 찾으면 반복문 빠져나옴
				
	if (i == (high + 1))
		return -1;  //탐색실패
	else
		return i;  //탐색성공(인덱스 반환)
}

void sort_array(int arr[], int size) {
	int i, j;
	int temp;

	for (i=0;i<size;i++)
		for (j=0;j<size-1;j++)
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

void print_array(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int sorted_seq_search(int key, int low, int high) {
	int i;
	for (i = low; i <= high; i++) {
		if (list[i] > key) return -1;
		else if (list[i] == key) return i;
	}
}

int main(void) {
	int low, high;
	int key, index;

	printf("**정렬X - 순차탐색**\n");
	low = 0;
	high = sizeof(list) / sizeof(int) - 1;

	key = 2;
	index = seq_search(key, low, high);

	printf("%d을 찾는 경우\n", key);
	if (index == -1)
		printf("=> 탐색 실패\n");
	else
		printf("=> 탐색 성공 : %d의 인덱스는 %d\n", key, index);


	printf("\n**정렬X - 개선된 순차탐색**\n");
	low = 0;
	high = sizeof(list) / sizeof(int) - 1;

	key = 8;
	index = seq_search2(key, low, high);

	printf("%d을 찾는 경우\n", key);
	if (index == -1)
		printf("=> 탐색 실패\n");
	else
		printf("=> 탐색 성공 : %d의 인덱스는 %d\n", key, index);

	
	printf("\n**정렬O - 순차탐색**\n");

	printf("정렬 전후\n");
	print_array(list, 5);
	sort_array(list, 5);
	print_array(list, 5);

	low = 0;
	high = sizeof(list) / sizeof(int) - 1;

	key = 3;
	index = sorted_seq_search(key, low, high);

	printf("\n%d을 찾는 경우\n", key);
	if (index == -1)
		printf("=> 탐색 실패\n");
	else
		printf("=> 탐색 성공 : %d의 인덱스는 %d\n", key, index);

	return 0;
}