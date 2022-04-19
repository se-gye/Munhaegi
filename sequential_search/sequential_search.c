#include <stdio.h>

int list[] = {9, 5, 8, 3, 7};

int seq_search(int key, int low, int high) {
	int i;
	for (i = low; i <= high; i++)
		if (list[i] == key)
			return i;  //Ž������(�ε��� ��ȯ)
	return -1;  //Ž������
}

int seq_search2(int key, int low, int high) {
	int i;

	list[high + 1] = key;  //����Ʈ ���� Ž��Ű ����
	for (i = low; list[i] != key; i++);  //Ű ���� ã���� �ݺ��� ��������
				
	if (i == (high + 1))
		return -1;  //Ž������
	else
		return i;  //Ž������(�ε��� ��ȯ)
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

	printf("**����X - ����Ž��**\n");
	low = 0;
	high = sizeof(list) / sizeof(int) - 1;

	key = 2;
	index = seq_search(key, low, high);

	printf("%d�� ã�� ���\n", key);
	if (index == -1)
		printf("=> Ž�� ����\n");
	else
		printf("=> Ž�� ���� : %d�� �ε����� %d\n", key, index);


	printf("\n**����X - ������ ����Ž��**\n");
	low = 0;
	high = sizeof(list) / sizeof(int) - 1;

	key = 8;
	index = seq_search2(key, low, high);

	printf("%d�� ã�� ���\n", key);
	if (index == -1)
		printf("=> Ž�� ����\n");
	else
		printf("=> Ž�� ���� : %d�� �ε����� %d\n", key, index);

	
	printf("\n**����O - ����Ž��**\n");

	printf("���� ����\n");
	print_array(list, 5);
	sort_array(list, 5);
	print_array(list, 5);

	low = 0;
	high = sizeof(list) / sizeof(int) - 1;

	key = 3;
	index = sorted_seq_search(key, low, high);

	printf("\n%d�� ã�� ���\n", key);
	if (index == -1)
		printf("=> Ž�� ����\n");
	else
		printf("=> Ž�� ���� : %d�� �ε����� %d\n", key, index);

	return 0;
}