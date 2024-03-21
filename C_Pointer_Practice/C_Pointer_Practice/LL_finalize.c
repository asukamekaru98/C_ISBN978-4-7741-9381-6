#include<stdlib.h>
#include"LL_word_manage_p.h"

void word_finalize() {
	Word* temp;

	//全単語の動的メモリを開放する
	while (word_header != NULL) {

		temp = word_header;
		word_header = word_header->next;

		free(temp->name);
		free(temp);
	}
}