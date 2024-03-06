#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define ALLOC_SIZE 256

//行を読み込むバッファ、必要によって拡張サれる。縮むことはない
static char* st_line_buffer = NULL;

//st_line_bufferの先に割り当てられている領域のサイズ
static int st_current_buffer_size = 0;

//st_line_bufferの中で、現在文字が格納されている部分のサイズ
static int st_current_used_size = 0;

//st_line_bufferの末尾に1文字追加する
static void add_character(int ch)
{
	
	assert(st_current_buffer_size >= st_current_used_size);

	if (st_current_buffer_size == st_current_used_size) {
		st_line_buffer = realloc(st_line_buffer,(st_current_buffer_size + ALLOC_SIZE) * sizeof(char));

		st_current_buffer_size += ALLOC_SIZE;
	}
	st_line_buffer[st_current_used_size] = ch;
	st_current_used_size++;
}

char* read_line(FILE* fp)
{
	int ch;
	char* ret;

	st_current_used_size = 0;
	while ((ch = getc(fp)) != EOF) {
		if (ch == '\n') {
			add_character('\0');
			break;
		}
		add_character(ch);
	}

	if (ch == EOF) {
		if (st_current_used_size > 0) {
			add_character('\0');
		}
		else {
			return NULL;
		}
	}


	ret = malloc(sizeof(char) * st_current_used_size);
	strcpy(ret, st_line_buffer);

	return ret;
}

void free_buffer(void) {
	free(st_line_buffer);
	st_line_buffer = NULL;
	st_current_buffer_size = 0;
	st_current_used_size = 0;
}
