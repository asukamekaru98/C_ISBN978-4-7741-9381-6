#pragma once
#define _CRT_SECURE_NO_WARNINGS

#ifndef LL_WORD_MANAGE_P_H_INCLUDE
#define LL_WORD_MANAGE_P_H_INCLUDE

#include "word_manage.h"

typedef struct {
	char* name;						//�P�ꖼ
	int count;						//�P��̏o����
	struct Word_tag* next;			//���̗v�f���w���|�C���^
}Word;
	
extern Word *word_header;			

#endif	//LL_WORD_MANAGE_P_H_INCLUDE