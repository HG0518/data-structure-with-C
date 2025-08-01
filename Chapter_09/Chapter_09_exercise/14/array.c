#include <stdio.h>
#include <stdlib.h>
#include "array.h"

ArrayType* create(ArrayType* q)
{
	return (ArrayType*)malloc(sizeof(ArrayType));
}

void init(ArrayType* q)
{
	q->size = 0;
}

void insert(ArrayType* q, element item)
{
	if (is_full(q)) error("리스트가 포화상태입니다.\n");
	q->arr[q->size] = item;
	q->size++;
	printf("삽입 성공\n");
}

element delete_max(ArrayType* q)
{
	if (is_empty(q))error("리스트가 비어있습니다.");
	int index, max;
	max = 0;
	element item;
	for (int i = 0; i < q->size; i++)
	{
		if (q->arr[i].key > max)
		{
			max = q->arr[i].key;
			item = q->arr[i];
			index = i;
		}
	}
	for (int i = index; i < q->size - 1; i++)
	{
		q->arr[i] = q->arr[i + 1];
	}
	q->size--;
	return item;
	
}
element find_max(ArrayType* q)
{
	if (is_empty(q))error("리스트가 비어있습니다.");
	int max = 0;
	element item;
	for (int i = 0; i < q->size; i++)
	{
		if (q->arr[i].key > max)
		{
			max = q->arr[i].key;
			item = q->arr[i];
		}
	}
	return item;
}


int is_empty(ArrayType* q)
{
	return q->size == 0;
}

int is_full(ArrayType* q)
{
	return q->size == MAX_SIZE;
}

void error(char* msg)
{
	printf("%s", msg);
	exit(1);
}