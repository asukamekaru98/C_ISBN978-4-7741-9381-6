#define _CRT_SECURE_NO_WARNINGS

#ifndef WORD_MANAGE_P_H_INCLUDE
#define WORD_MANAGE_P_H_INCLUDE

typedef struct {
	char* name;
	int count;

}Word;

#define WORD_NUM_MAX 100000

extern Word word_array[];
extern int num_of_word;


#endif