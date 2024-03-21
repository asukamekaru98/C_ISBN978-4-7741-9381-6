#pragma once
#ifndef WORD_MANAGE_H_INCLUDE
#define WORD_MANAGE_H_INCLUDE

#include<stdio.h>

void word_init();
void add_word(char* word);
void dump_word(FILE* fp);
void word_finalize();

#endif //WORD_MANAGE_H_INCLUDE