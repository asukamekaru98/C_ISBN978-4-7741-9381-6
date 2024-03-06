#pragma once
#ifndef READ_LINE_H_INCLUDE
#define READ_LINE_H_INCLUDE

#include<stdio.h>

char* read_line(FILE* fp);
void free_buffer(void);

#endif // READ_LINE_H_INCLUDE
