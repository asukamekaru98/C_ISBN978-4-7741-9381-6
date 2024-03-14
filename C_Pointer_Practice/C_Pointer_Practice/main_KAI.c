#include<stdio.h>
#include"read_line_KAI.h"

int main(void) {
	char* line;

	while (read_line(stdin,&line) != READ_LINE_EOF) {
		printf("%s\n", line);
	}
	free_buffer();
}