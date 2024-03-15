#include <stdio.h>

//ñ{óàÇÕÇ±Ç§Ç¢Ç§Å´à”ñ°Ç…Ç»ÇÈ
//void func(int size1,int size2,int (*hoge)[size2])

void func(int size1,int size2,int hoge[size1][size2])
//void func(int hoge[*][*], int size1, int size2)			
//void func(int hoge[size1][size2],int size1, int size2)	
{
	int i, j;

	for (i = 0; i < 4;i++) {
		for (j = 0;j < 3; j++) {
			printf("%d, ", hoge[i][j]);
		}
		putchar('\n');
	}
}

int main() {
	int hoge[][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9},
		{10,11,12},
	};

	func(4,3,hoge);

	return 0;
}