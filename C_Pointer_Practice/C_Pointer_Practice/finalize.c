#include<stdlib.h>
#include"word_manage_p.h"

void word_finalize() {
	int i;

	//単語の数だけ動的メモリを開放する
	for (i = 0;i < num_of_word;i++) {
		free(word_array[i].name);
	}
	num_of_word = 0;
}