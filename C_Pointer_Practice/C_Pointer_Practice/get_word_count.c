#include<stdio.h>
#include<string.h>
#include"word_manage_p.h"

int get_word_count(char* word)
{
	int left = 0;
	int right = num_of_word - 1;
	int mid;
	int result;

	//右辺のほうが大きい間ループ
	while (left <= right) {

		//中央値取得
		mid = (left + right) / 2;

		//中央値の名前と検索文字が一致しているか
		result = strcmp(word_array[mid].name, word);

		if (result < 0) {
			//中央の単語が目標単語よりも小さい場合
			//左端を中央+1に更新して右側を探索
			left = mid + 1;
		}
		else if(result < 0) {
			//中央の単語が目標単語よりも大きい場合
			//右端を中央-1に更新して左側を探索
			right = mid - 1;
		}
		else {
			//一致している場合
			return word_array[mid].count;
		}
	}

	return 0;

}