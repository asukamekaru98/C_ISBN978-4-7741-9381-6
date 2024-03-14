#pragma once
#ifndef READ_LINE_H_INCLUDE
#define READ_LINE_H_KAI_INCLUDE

#include<stdio.h>

typedef enum {
	READ_LINE_SUCCESS,		//�����1�s�ǂݍ���
	READ_LINE_EOF,			//�t�@�C���̏I�[�܂œǂݍ���
	READ_LINE_OUT_OF_MEM	//������������Ȃ��Ď��s����
}ReadLineStat;

ReadLineStat read_line(FILE* fp,char **line);
void free_buffer(void);

#endif // READ_LINE_H_INCLUDE
