#include<cstdio>

void swap(int& a, int& b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}

int main(void)
{
	int a = 10;
	int b = 20;


	printf("swap‘O a..%d,b..%d", a, b);

	swap(a, b);

	printf("swapŒã a..%d,b..%d", a, b);
}