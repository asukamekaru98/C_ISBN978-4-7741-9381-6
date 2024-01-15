#include <stdio.h>

int add_func(int a, int b) {
	int result;

	result = a + b;

	return result;
}

int main() {

	int print = add_func(1, 45645644);

	printf("%d", print);
}