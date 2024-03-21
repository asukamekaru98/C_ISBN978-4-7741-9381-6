#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LL_word_manage_p.h"

//�����񕡐�
static char* my_strdup(char* src) {
	char* dest;
	dest = malloc(sizeof(char) * (strlen(src) + 1));
	strcpy(dest, src);

	return dest;
}

static Word* create_word(char* name) {
	Word* new_word;

	new_word = malloc(sizeof(Word));

	new_word->name = my_strdup(name);	//���I���������擾���Ă���
	new_word->count = 1;				
	new_word->next = NULL;				//Next�͎����������܂�NULL

	return new_word;
}

//�P��ǉ�
void add_word(char* word)
{
	Word* pos;
	Word* prev;
	Word* new_word;
	int result;

	prev = NULL;

	// �������ʒu��T�����߂Ƀ����N���X�g�𑖍�����
	for (pos = word_header; pos != NULL;pos = pos->next) {
		result = strcmp(pos->name, word);
		if (result >= 0) {
			break;
		}
	}

	if (word_header != NULL && result == 0) {
		// �����N���X�g���ŒP�ꂪ������΁A���̏o���񐔂𑝂₷
		pos->count++;
	}
	else {
		// �P�ꂪ������Ȃ��ꍇ�A�V���� Word �m�[�h���쐬����
		new_word = create_word(word);
		if (prev == NULL) {
			// �P�ꂪ������Ȃ��ꍇ�A�V���� Word �m�[�h���쐬����
			new_word->next = word_header;
			word_header = new_word;
		}
		else {
			// �����N���X�g���� prev �� pos �̊ԂɐV�����m�[�h��}������
			new_word->next = pos;
			prev->next = new_word;
		}
	}
}