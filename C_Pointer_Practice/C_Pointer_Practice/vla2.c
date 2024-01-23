#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sub(const int size1, int size2, int size3) {
	

	int var1;
	int array1[size1];
	int var2;
	int array2[size2][size3];
	int var3;

	printf("array1...%p\n", (void*)array1);
	printf("array2...%p\n", (void*)array2);
	printf("&var1...%p\n", (void*)var1);
	printf("&var2...%p\n", (void*)var2);
	printf("&var3...%p\n", (void*)var3);
}

int main(void) {
	int size1, size2, size3;

	printf("®”’l‚ğ3‚Â“ü—Í‚µ‚Ä\n");
	scanf("%d%d%d", &size1, &size2, &size3);

	sub(size1, size2, size3);
}