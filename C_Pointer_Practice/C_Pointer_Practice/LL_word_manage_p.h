#pragma once
#define _CRT_SECURE_NO_WARNINGS

#ifndef LL_WORD_MANAGE_P_H_INCLUDE
#define LL_WORD_MANAGE_P_H_INCLUDE

#include "word_manage.h"

typedef struct {
	char* name;						//単語名
	int count;						//単語の出現回数
	struct Word_tag* next;			//次の要素を指すポインタ
}Word;
	
extern Word *word_header;			

#endif	//LL_WORD_MANAGE_P_H_INCLUDE