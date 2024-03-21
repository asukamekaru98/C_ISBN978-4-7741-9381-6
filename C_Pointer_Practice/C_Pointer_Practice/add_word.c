#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word_manage_p.h"

static void shift_array(int index) {
	int src;

	//index�����̗v�f��1������ɃY����
	for (src = num_of_word - 1;src >= index; src--) {
		word_array[src + 1] = word_array[src];
	}
	num_of_word++;
}

//�����񕡐�
static char* my_strdup(char* src) {
	char* dest;
	dest = malloc(sizeof(char) * (strlen(src) + 1));
	strcpy(dest, src);

	return dest;
}

//�P��ǉ�
void add_word(char* word)
{
	int i;
	int result;

	if (num_of_word >= WORD_NUM_MAX) {
		//�P��̐����A�z��̗v�f�𒴂�����I���
		fprintf(stderr, "too many words.\n");
		exit(1);
	}

	// �\�[�g���ꂽ�z��ɒP���}������K�؂Ȉʒu��T���B
	for (i = 0; i < num_of_word;i++) {
		//strcmp�́A2�̒P�������ׁA��v�����0�A�s��v�ł���΃o�C�g��̍���Ԃ�

		result = strcmp(word_array[i].name, word);
		if (result >= 0)break;
	}

	// �P�ꂪ���ɔz��ɑ��݂���ꍇ�A���̏o���񐔂𑝂₷
	if (num_of_word != 0 && result == 0) {
		word_array[i].count++;
	}
	else {
		// �P�ꂪ���݂��Ȃ��ꍇ�́A�V�����P���}�����邽�߂ɗv�f���V�t�g����B
		shift_array(i);

		// �^����ꂽ�P��𕡐����A�������ʒu�Ɋi�[
		word_array[i].name = my_strdup(word);

		// �V�����P��̏o���񐔂�1�ŏ�����
		word_array[i].count = 1;
	}
}