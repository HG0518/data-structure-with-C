#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

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

	while (child<=h->size) 
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
