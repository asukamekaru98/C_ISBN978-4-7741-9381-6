#include<stdio.h>

int main(void) {
	int		hoge = 5;
	int		piyo = 10;
	int* hoge_p;

	//���ꂼ��̕ϐ��̃A�h���X��\������
	printf("&hoge..%p\n", (void*)&hoge);
	printf("&piyo..%p\n", (void*)&piyo);
	printf("&hoge_p..%p\n", (void*)&hoge_p);
		
		//�|�C���^�ϐ�hoge_p��hoge�̃A�h���X��������
	hoge_p = &hoge;
	printf("hoge_p..%p\n", (void*)hoge_p);

	//hoge_p���o�R����hoge�̒l��\������
	printf("*hoge_p..%d\n", *hoge_p);

	//hoge_p���o�R����hoge�̒l��ύX����
	*hoge_p = 10;
	printf("hoge..%d\n", hoge);

	return 0;
}