#include <stdio.h>
#include "word_manage_p.h"

void dump_word(FILE* fp) {
	int i;

	//単語の一覧を表示させる
	for (i = 0;i < num_of_word;i++) {
		fprintf(fp, "%-20s%5d\n", word_array[i].name, word_array[i].count);
	}
}