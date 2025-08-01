#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "todo.h"

HeapType* create(HeapType* h)
{
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h)
{
	h->size = 0;
}

void insert(HeapType* h, element item)
{
	h->size++;
	int i = h->size;
	while (i > 1 && h->heap[i / 2].key < item.key) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_max(HeapType* h)
{
	if (is_empty(h))error("힙이 비어있습니다.\n");
	int parent, child;
	element item, temp;
	parent = 1; child = 2;
	item = h->heap[1];
	temp = h->heap[h->size--];

	while (child <= h->size)
	{
		if ((h->heap[child].key < h->heap[child].key) && (child < h->size)) child++;
		if (h->heap[child].key < temp.key)break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

int is_empty(HeapType* h)
{
	return h->size == 0;
}

void display(HeapType* h)
{
	if (is_empty(h))
	{
		printf("NULL\n");
		return;
	}
	for (int i = 1; i <= h->size; i++)
	{
		printf("%d ", h->heap[i].key);
	}
	printf("\n");
}

void error(char* msg)
{
	printf("%s\n", msg);
	exit(1);
}

void play()
{
	HeapType* h = NULL;
	h = create(h);
	init(h);
	while (1)
	{
		select(h);
	}
}

void select(HeapType* h)
{
	char ch;
	printf("삽입(i), 삭제(d) : ");
	ch = getchar();
	getchar();
	switch (ch)
	{
	case'i':
		insert_todo(h);
		break;
	case'd':
		delete_todo(h);
		break;
	default:
		printf("잘못 입력했습니다.\n");
		break;
	}
}

void insert_todo(HeapType* h)
{
	char todo[20];
	int pri;
	element item;
	printf("할일 : ");
	gets_s(todo, sizeof(todo));
	printf("우선순위 : ");
	scanf("%d", &pri);
	strcpy(item.id, todo);
	getchar();
	item.key = pri;
	insert(h, item);
	printf("삽입에 성공했습니다.\n");
}

void delete_todo(HeapType* h)
{
	if (is_empty(h))
	{
		printf("힙이 비어있습니다.\n");
		return;
	}
	element item;
	item = delete_max(h);
	printf("제일 우선 순위가 높은 일은 \"%s\"\n", item.id);
}