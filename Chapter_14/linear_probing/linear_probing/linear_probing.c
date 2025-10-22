#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linear_probing.h"

void init_table(element ht[])
{
	for (int i = 0; i < TABLE_SIZE; i++)	
		ht[i].key[0] = NULL;
}

int transform(char* key)
{
	int hash_index = 0;
	while (*key)
		hash_index = 31 * hash_index + *(key++);
	if (hash_index < 0) hash_index = -hash_index;
	return hash_index;
}

int hash_function(char* key)
{
	return transform(key) % TABLE_SIZE;
}

void hash_lp_add(element item, element ht[])
{
	int i, hash_index;
	hash_index = i = hash_function(item.key);

	while (!is_empty(ht[i]))
	{
		if (is_equal(item.key, ht[i].key))
		{
			fprintf(stderr, "탐색키가 중복되었습니다.\n");
			exit(1);
		}

		i = (i + 1) % TABLE_SIZE;

		if (i == hash_index)
		{
			fprintf(stderr, "테이블이 포화상태입니다.\n");
			exit(1);
		}
	}
	ht[i] = item;
	printf("key : %s, transform : %d, hash_index : %d, i : %d\n", item.key, transform(item.key), hash_index, i);
}

element hash_lp_search(element item, element ht[])
{
	int i, hash_index;
	hash_index = i = hash_function(item.key);

	while (!is_empty(ht[i]))
	{
		if (is_equal(item.key, ht[i].key))
		{
			printf("탐색 %s : 위치 = %d\n", item.key, i);
			return ht[i];
		}

		i = (i + 1) % TABLE_SIZE;

		if (i == hash_index)
		{
			printf("찾는 값이 테이블에 없습니다.\n");
			return;
		}
	}
	printf("찾는 값이 테이블에 없습니다.\n");
}

void hash_lp_print(element ht[])
{
	printf("===============================================\n");
	for (int i = 0; i < TABLE_SIZE; i++)	
		printf("[%d] %s\n", i, ht[i].key);
	printf("===============================================\n");
}

int is_equal(char* s1, char* s2)
{
	if (strcmp(s1, s2) == 0) return 1;
	else return 0;
}

int is_empty(element bucket)
{
	if (bucket.key[0] == NULL) return 1;
	else return 0;
}