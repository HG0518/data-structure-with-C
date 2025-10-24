#include <stdio.h>
#include <string.h>
#include "../../hash_chaining/hash_chaining/hash_chaining.h"

void start();
void select(hash_list* ht[]);
int transform(char* str);

int main(void)
{
	start();
}

int transform(char* str)
{
	int hash_value = 0;
	while (*str)
		hash_value = hash_value * 31 + *str++;
	if (hash_value < 0) hash_value = -hash_value;
	return hash_value;
}

void start()
{
	hash_list* hash_table[TABLE_SIZE];
	hash_list_init(hash_table);

	while(1)
	{
		select(hash_table);
		printf("\n");
	}
}

void select(hash_list* ht[])
{
	char ch;
	char animal[15];
	element e;

	printf("삽입(i), 탐색(s), 삭제(d) : ");
	ch = getchar();
	printf("동물의 이름 : ");
	scanf("%s", animal);
	

	int keyN = transform(animal);
	e.key = keyN;

	switch (ch)
	{
	case 'i':
		hash_chain_add(e, ht);
		break;
	case 's':
		hash_chain_search(e, ht);
		break;
	default:
		printf("잘못된 입력입니다.\n");
		break;
	}

	getchar();
}