#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word_manage_p.h"

static void shift_array(int index) {
	int src;

	//indexより後ろの要素を1つずつ後方にズラす
	for (src = num_of_word - 1;src >= index; src--) {
		word_array[src + 1] = word_array[src];
	}
	num_of_word++;
}

//文字列複製
static char* my_strdup(char* src) {
	char* dest;
	dest = malloc(sizeof(char) * (strlen(src) + 1));
	strcpy(dest, src);

	return dest;
}

//単語追加
void add_word(char* word)
{
	int i;
	int result;

	if (num_of_word >= WORD_NUM_MAX) {
		//単語の数が、配列の要素を超えたら終わり
		fprintf(stderr, "too many words.\n");
		exit(1);
	}

	// ソートされた配列に単語を挿入する適切な位置を探す。
	for (i = 0; i < num_of_word;i++) {
		//strcmpは、2つの単語を見比べ、一致すれば0、不一致であればバイト列の差を返す

		result = strcmp(word_array[i].name, word);
		if (result >= 0)break;
	}

	// 単語が既に配列に存在する場合、その出現回数を増やす
	if (num_of_word != 0 && result == 0) {
		word_array[i].count++;
	}
	else {
		// 単語が存在しない場合は、新しい単語を挿入するために要素をシフトする。
		shift_array(i);

		// 与えられた単語を複製し、正しい位置に格納
		word_array[i].name = my_strdup(word);

		// 新しい単語の出現回数を1で初期化
		word_array[i].count = 1;
	}
}