#pragma once
#ifndef READ_LINE_H_INCLUDE
#define READ_LINE_H_KAI_INCLUDE

#include<stdio.h>

typedef enum {
	READ_LINE_SUCCESS,		//正常に1行読み込んだ
	READ_LINE_EOF,			//ファイルの終端まで読み込んだ
	READ_LINE_OUT_OF_MEM	//メモリが足りなくて失敗した
}ReadLineStat;

ReadLineStat read_line(FILE* fp,char **line);
void free_buffer(void);

#endif // READ_LINE_H_INCLUDE
