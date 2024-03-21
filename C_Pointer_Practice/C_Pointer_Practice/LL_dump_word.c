#include<stdio.h>
#include "LL_word_manage_p.h"

void dump_word(FILE* fp)
{
	Word* pos;

	//‘S’PŒê‚ð•\Ž¦‚·‚é
	for (pos = word_header;pos;pos = pos->next) {
		fprintf(fp, "%-20s%5d", pos->name, pos->count);
	}
}