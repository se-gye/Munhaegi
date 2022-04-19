#include <stdio.h>

void echo1() {  //반복
	int ch;
	while ((ch = getchar()) != '\n')
		putchar(ch);
}

void echo2() {  //순환
	int ch;
	if ((ch = getchar()) != '\n') {
		putchar(ch);
		echo2();
	}
}

void calculateReverse() {
	int ch;
	if ((ch = getchar()) != '\n') {
		calculateReverse();
		putchar(ch);
	}
}

int main(void) {
	printf("Enter a string and press enter:");
	calculateReverse();

	printf("\nEnter a string and press enter:");
	echo1();

	printf("\nEnter a string and press enter:");
	echo2();

	return 0;
}