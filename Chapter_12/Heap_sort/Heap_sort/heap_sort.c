#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stdlib.h"
#include "time.h"
#include "heap_sort.h"

void start()
{
	int num = 0;
	printf("숫자의 개수 : ");
	scanf("%d", &num);

	Heap h;
	init_heap(&h, num);

	srand(time(NULL));
	for (int i = 0; i < num; i++)
	{
		int data = rand() % 100;
		printf("%d ", data);
		insert_heap(&h, data);
	}
	printf("\n\n");

	heap_sort(&h, num);
	printf("\n");

	printf("정렬된 배열 : \n");
	print_list(&h, num);
}
void init_heap(Heap* h, int heap_size)
{
	h->size = 0;
	h->list = (int*)malloc((heap_size + 1) * sizeof(int));
	if (h->list == NULL)
	{
		printf("NULL값 할당 오류\n");
		exit(1);
	}
}

void heap_sort(Heap* h, int list_size)
{
	for (int i = list_size; i > 0; i--)
	{
		h->list[i] = delete_heap(h);
		print_heap_sort(h, list_size);
	}
}

void print_list(Heap* h, int list_size)
{
	for (int i = 1; i <= list_size; i++)
		printf("%d ", h->list[i]);
	printf("\n");
}

void print_heap_sort(Heap* h, int list_size)
{
	int i = 1;
	for (i; i <= h->size; i++)
		printf("%d ", h->list[i]);
	printf("[");
	for (i; i < list_size; i++)
		printf("%d ", h->list[i]);
	printf("%d]\n", h->list[list_size]);
}

void insert_heap(Heap* h, int data)
{
	h->size++;
	int i = h->size;
	while (i > 1)
	{
		if (data > h->list[i / 2])
		{
			h->list[i] = h->list[i / 2];
			i /= 2;
		}
		else break;
	}
	h->list[i] = data;
}

int delete_heap(Heap* h)
{
	if (h->size < 1)
	{
		printf("히프가 공백상태입니다.\n");
		return;
	}

	int max = h->list[1];
	int last = h->list[h->size--];
	int parent = 1;
	int	child = 2 * parent;
	int tmp;
	while (child <= h->size)
	{
		if (child == h->size) 
			tmp = child;
		else 
			tmp = h->list[child] > h->list[child + 1] ? child : child + 1;

		if (last < h->list[tmp])
		{
			h->list[parent] = h->list[tmp];
			parent = tmp;
			child = 2 * parent;
		}
		else break;
	}
	h->list[parent] = last;

	return max;
}