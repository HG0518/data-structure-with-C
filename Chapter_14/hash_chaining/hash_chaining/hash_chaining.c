#include <stdio.h>
#include <stdlib.h>
#include "hash_chaining.h"

int hash_function(int key)
{
	return key % TABLE_SIZE;
}

hash_list* create_node(element item)
{
	hash_list* node = NULL;
	node = (hash_list*)malloc(sizeof(hash_list));
	if (node == NULL)
	{
		printf("NULL값 할당 오류\n");
		exit(1);
	}
	node->item = item;
	node->link = NULL;
	return node;
}

void hash_chain_add(element item, hash_list* ht[])
{
	int hash_value = hash_function(item.key);
	hash_list* node = ht[hash_value];
	hash_list* pre_node = NULL;
	for (; node; pre_node = node, node = node->link)
	{
		if (node->item.key == item.key)
		{
			printf("중복된 키입니다.\n");
			return;
		}
	}

	node = create_node(item);

	if (pre_node)
		pre_node->link = node;
	else
		ht[hash_value] = node;
	printf("인덱스 %d에 저장되었음\n",hash_value);
}

hash_list* hash_chain_search(element item, hash_list* ht[])
{
	int hash_value = hash_function(item.key);

	hash_list* node = ht[hash_value];
	hash_list* pre_node = NULL;
	for (; node; pre_node = node, node = node->link)
	{
		if (node->item.key == item.key)
		{
			printf("해쉬테이블 %d에 있음\n", hash_value);
			if (pre_node)
				return pre_node;
			else
				return node;
		}
	}
	printf("탐색 실패\n");
	return NULL;
}

void hash_chain_print(hash_list* ht[])
{
	printf("====================================\n");
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		hash_list* node;
		printf("[%d] > ", i);
		for (node = ht[i]; node; node = node->link)
			printf("%d > ", node->item.key);
		printf("\n");
	}
	printf("====================================\n");
}

void hash_list_init(hash_list* ht[])
{
	for (int i = 0; i < TABLE_SIZE; i++)	
		ht[i] = NULL;
}

void hash_chain_delete(element item, hash_list* ht[])
{
	hash_list* node = NULL;
	node = hash_chain_search(item, ht);
	int hash_value = hash_function(item.key);


	if(node)
	{
		if (ht[hash_value]==node)
		{
			ht[hash_value] = node->link;
			free(node);
			node = NULL;
		}
		else
		{
			hash_list* deleted;
			deleted = node->link;
			node->link = deleted->link;
			free(deleted);
			deleted = NULL;
		}
		printf("데이터 제거에 성공했습니다.\n");
		printf("제거 후 테이블\n");
		hash_chain_print(ht);
		return;
	}

	printf("데이터가 존재하지 않습니다.\n");
}