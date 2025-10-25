#include <stdio.h>
#include "hash_chaining.h"

int main(void)
{
	hash_list* hash_table[TABLE_SIZE];
	hash_list_init(hash_table);
	int data[5] = { 8,1,9,6,13 };
	element e;

	for (int i = 0; i < 5; i++)
	{
		e.key = data[i];
		hash_chain_add(e, hash_table);
		hash_chain_print(hash_table);
	}

	for (int i = 0; i < 5; i++)
	{
		e.key = data[i];
		hash_chain_search(e, hash_table);
	}

	for (int i = 0; i < 5; i++)
	{
		e.key = data[i];
		printf("\n%d 삭제\n",e.key);
		hash_chain_delete(e, hash_table);
	}


	return 0;
}