#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include "read_line_KAI.h"

#define ALLOC_SIZE 256

//�s��ǂݍ��ރo�b�t�@�A�K�v�ɂ���Ċg���T���B�k�ނ��Ƃ͂Ȃ�
static char* st_line_buffer = NULL;

//st_line_buffer�̐�Ɋ��蓖�Ă��Ă���̈�̃T�C�Y
static int st_current_buffer_size = 0;

//st_line_buffer�̒��ŁA���ݕ������i�[����Ă��镔���̃T�C�Y
static int st_current_used_size = 0;

//st_line_buffer�̖�����1�����ǉ�����
static ReadLineStat add_character(int ch)
{

	//�o�b�t�@���m�ۗ̈��ǂ��z�����狭���I��
	assert(st_current_buffer_size >= st_current_used_size);

	//�o�b�t�@���m�ۗ̈�ɒǂ�������g������
	if (st_current_buffer_size == st_current_used_size) {

		char* temp;
		temp = realloc(st_line_buffer,
						(st_current_buffer_size + ALLOC_SIZE)
						* sizeof(char));

		if (temp == NULL) {
			return READ_LINE_OUT_OF_MEM;
		}

		//���̃o�b�t�@�T�C�Y�Ɏw�蕪�̃T�C�Y��ǉ�����`�ŁA���I�������̈�𑝂₷�B�p�������B
		st_line_buffer = temp;
		st_current_buffer_size += ALLOC_SIZE;
	}

	//�o�b�t�@�����ɕ����ǉ�
	st_line_buffer[st_current_used_size] = ch;

	//�g�p���̃T�C�Y�𑝂₷
	st_current_used_size++;

	return READ_LINE_SUCCESS;
}

//�o�b�t�@�����
void free_buffer(void) {
	free(st_line_buffer);
	st_line_buffer = NULL;
	st_current_buffer_size = 0;
	st_current_used_size = 0;
}

ReadLineStat read_line(FILE* fp, char** line)
{
	int ch;
	ReadLineStat stat = READ_LINE_SUCCESS;
	//char* ret;

	st_current_used_size = 0;

	//�󂯎������������AEOF�ɂȂ�܂ŉ�
	while ((ch = getc(fp)) != EOF) {

		//���s�����͍폜����
		if (ch == '\n') {
			stat = add_character('\0');
			
			if (stat != READ_LINE_SUCCESS){
				goto FUNC_END;
			}

			break;
		}

		stat = add_character(ch);
		
		if (stat != READ_LINE_SUCCESS) {
			goto FUNC_END;
		}
	}

	//EOF�ɗ����Ƃ��i�t�@�C�����I���΁jNULL�ԋp
	if (ch == EOF) {
		if (st_current_used_size > 0) {
			stat = add_character('\0');
			if (stat != READ_LINE_SUCCESS) {
				goto FUNC_END;
			}
		}
		else {
			stat = READ_LINE_EOF;
			goto FUNC_END;
		}
	}

	//�s�ɍ��킹���̈���m�ۂ���
	*line = malloc(sizeof(char) * st_current_used_size);

	if (*line == NULL) {
		stat = READ_LINE_OUT_OF_MEM;
		goto FUNC_END;
	}

	strcpy(*line, st_line_buffer);

FUNC_END:
	if (stat != READ_LINE_SUCCESS && stat != READ_LINE_EOF) {
		free_buffer();
	}
	return stat;

}
