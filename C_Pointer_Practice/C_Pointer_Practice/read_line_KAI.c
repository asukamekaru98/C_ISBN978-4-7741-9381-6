#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include "read_line_KAI.h"

#define ALLOC_SIZE 256

//行を読み込むバッファ、必要によって拡張サれる。縮むことはない
static char* st_line_buffer = NULL;

//st_line_bufferの先に割り当てられている領域のサイズ
static int st_current_buffer_size = 0;

//st_line_bufferの中で、現在文字が格納されている部分のサイズ
static int st_current_used_size = 0;

//st_line_bufferの末尾に1文字追加する
static ReadLineStat add_character(int ch)
{

	//バッファが確保領域を追い越したら強制終了
	assert(st_current_buffer_size >= st_current_used_size);

	//バッファが確保領域に追いついたら拡張する
	if (st_current_buffer_size == st_current_used_size) {

		char* temp;
		temp = realloc(st_line_buffer,
						(st_current_buffer_size + ALLOC_SIZE)
						* sizeof(char));

		if (temp == NULL) {
			return READ_LINE_OUT_OF_MEM;
		}

		//今のバッファサイズに指定分のサイズを追加する形で、動的メモリ領域を増やす。継ぎ足し。
		st_line_buffer = temp;
		st_current_buffer_size += ALLOC_SIZE;
	}

	//バッファ末尾に文字追加
	st_line_buffer[st_current_used_size] = ch;

	//使用中のサイズを増やす
	st_current_used_size++;

	return READ_LINE_SUCCESS;
}

//バッファを解放
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

	//受け取った文字列を、EOFになるまで回す
	while ((ch = getc(fp)) != EOF) {

		//改行文字は削除する
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

	//EOFに来たとき（ファイルが終われば）NULL返却
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

	//行に合わせた領域を確保する
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
