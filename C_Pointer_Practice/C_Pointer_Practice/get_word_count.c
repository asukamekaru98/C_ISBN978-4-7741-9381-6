#include<stdio.h>
#include<string.h>
#include"word_manage_p.h"

int get_word_count(char* word)
{
	int left = 0;
	int right = num_of_word - 1;
	int mid;
	int result;

	//�E�ӂ̂ق����傫���ԃ��[�v
	while (left <= right) {

		//�����l�擾
		mid = (left + right) / 2;

		//�����l�̖��O�ƌ�����������v���Ă��邩
		result = strcmp(word_array[mid].name, word);

		if (result < 0) {
			//�����̒P�ꂪ�ڕW�P������������ꍇ
			//���[�𒆉�+1�ɍX�V���ĉE����T��
			left = mid + 1;
		}
		else if(result < 0) {
			//�����̒P�ꂪ�ڕW�P������傫���ꍇ
			//�E�[�𒆉�-1�ɍX�V���č�����T��
			right = mid - 1;
		}
		else {
			//��v���Ă���ꍇ
			return word_array[mid].count;
		}
	}

	return 0;

}