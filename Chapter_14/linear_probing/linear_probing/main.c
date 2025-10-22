#include <stdio.h>
#include <string.h>
#include "linear_probing.h"

int main(void)
{
	char* s[7] = { "do","for","if","case","else","return","function" };
	element e;

	init_table(hash_table);
	for (int i = 0; i < 7; i++)
	{
		strcpy(e.key, s[i]);
		hash_lp_add(e, hash_table);
		hash_lp_print(hash_table);
	}
	for (int i = 0; i < 7; i++)
	{
		strcpy(e.key, s[i]);
		hash_lp_search(e, hash_table);
	}

	return 0;
}