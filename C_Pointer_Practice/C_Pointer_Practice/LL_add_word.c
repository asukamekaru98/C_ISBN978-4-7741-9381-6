#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LL_word_manage_p.h"

//文字列複製
static char* my_strdup(char* src) {
	char* dest;
	dest = malloc(sizeof(char) * (strlen(src) + 1));
	strcpy(dest, src);

	return dest;
}

static Word* create_word(char* name) {
	Word* new_word;

	new_word = malloc(sizeof(Word));

	new_word->name = my_strdup(name);	//動的メモリを取得しておく
	new_word->count = 1;				
	new_word->next = NULL;				//Nextは次結合されるまでNULL

	return new_word;
}

//単語追加
void add_word(char* word)
{
	Word* pos;
	Word* prev;
	Word* new_word;
	int result;

	prev = NULL;

	// 正しい位置を探すためにリンクリストを走査する
	for (pos = word_header; pos != NULL;pos = pos->next) {
		result = strcmp(pos->name, word);
		if (result >= 0) {
			break;
		}
	}

	if (word_header != NULL && result == 0) {
		// リンクリスト内で単語が見つかれば、その出現回数を増やす
		pos->count++;
	}
	else {
		// 単語が見つからない場合、新しい Word ノードを作成する
		new_word = create_word(word);
		if (prev == NULL) {
			// 単語が見つからない場合、新しい Word ノードを作成する
			new_word->next = word_header;
			word_header = new_word;
		}
		else {
			// リンクリスト内の prev と pos の間に新しいノードを挿入する
			new_word->next = pos;
			prev->next = new_word;
		}
	}
}