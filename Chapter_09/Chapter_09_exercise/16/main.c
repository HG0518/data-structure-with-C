#include <stdio.h>
#include <stdlib.h>
#include "../../heap/heap/heap.h"

typedef struct {
	int* list;
	int top, size;
}stack;


void delete_item(HeapType* h, int item);
void delete_index(HeapType* h, int index);
void heapify_up(HeapType* h, int index);
void heapify_down(HeapType* h, int index);
void init_stack(stack* s);
void push(stack* s, int n);
int pop(stack* s);
int is_stack_empty(stack s);



int main(void)
{
	HeapType* h = NULL;
	h = create(h);
	init(h);
	element e1 = { 10 };
	element e2 = { 30 };
	element e3 = { 30 };
	element e4 = { 40 };
	element e5 = { 50 };
	insert(h, e1);
	insert(h, e2);
	insert(h, e3);
	insert(h, e4);
	insert(h, e5);
	display(h);

	delete_item(h, 30);
	display(h);

	free(h);
	return 0;
}

void delete_item(HeapType* h, int item)
{
	if (is_empty(h))error("힙이 공백상태입니다.");
	int i = 1;
	int count = 0;
	stack s;
	init_stack(&s);
	push(&s, i);
	while (!is_stack_empty(s))
	{
		i = pop(&s);
		if (h->heap[i].key < item)
		{
			if (i * 2 > h->size)continue;
			push(&s, 2 * i);
			if (i * 2 + 1 > h->size)continue;
			push(&s, 2 * i + 1);
		}
		else if (h->heap[i].key == item)
		{
			delete_index(h, i);
			count++;
			if (i > h->size) continue;
			push(&s, i);
		}
	}
	if (count == 0)printf("해당하는 item을 가진 요소가 없습니다.\n");
	else printf("%d개 삭제 완료했습니다.\n", count);

	free(s.list);
}

void delete_index(HeapType* h, int index)
{
	if (index == h->size)		//index번째 노드가 가장 마지막 노드라면
	{
		h->size--;
		return;
	}

	else if (index == 1)		//index번째 노드가 root라면
	{
		delete_max(h);
	}

	else
	{
		h->heap[index] = h->heap[h->size];
		h->size--;

		if (h->heap[index].key < h->heap[index / 2].key)	//가장 마지막 노드와 인덱스의 부모노드를 비교.
			heapify_up(h, index);
		else
			heapify_down(h, index);
	}
}

void heapify_up(HeapType* h, int index)
{
	int i = index;
	while (i / 2 > 0 && h->heap[i].key < h->heap[i / 2].key)
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = h->heap[index];
}

void heapify_down(HeapType* h, int index)
{
	element temp = h->heap[index];
	int parent, child;
	parent = index;
	child = 2 * parent;
	while (child + 1 < h->size)
	{
		if (h->heap[child].key > h->heap[child + 1].key) child += 1;
		if (h->heap[child].key > temp.key) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
}

void init_stack(stack* s)
{
	s->top = -1;
	s->size = 1;
	s->list = (int*)malloc(s->size * sizeof(int));
}

void push(stack* s, int n)
{
	if (s->top == s->size - 1)
	{
		s->size *= 2;
		s->list = (int*)realloc(s->list, s->size * sizeof(int));
		if (s == NULL)error("NULL값 할당");
	}
	s->top++;
	s->list[s->top] = n;
}

int pop(stack* s)
{
	if (is_stack_empty(*s)) error("스택이 공백상태입니다.");
	int item;
	item = s->list[s->top];
	s->top--;
	return item;
}

int is_stack_empty(stack s)
{
	return s.top == -1;
}