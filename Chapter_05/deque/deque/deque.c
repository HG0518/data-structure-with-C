#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

void init_deque(deque* d)
{
	d->front = 0;
	d->rear = 0;
}

int is_full(deque* d)
{
	return d->front == (d->rear + 1) % MAX_DEQUE_SIZE;
}

int is_empty(deque* d)
{
	return d->front == d->rear;
}

void error(char* message)
{
	printf("%s\n", message);
	exit(1);
}

void insert_front(deque* d, element data)
{
	if (is_full(d)) error("덱이 포화상태입니다.");
	d->data[d->front] = data;
	d->front = (d->front + MAX_DEQUE_SIZE - 1) % MAX_DEQUE_SIZE;
}

void insert_rear(deque* d, element data)
{
	if (is_full(d)) error("덱이 포화상태입니다.");
	d->rear = (d->rear + 1) % MAX_DEQUE_SIZE;
	d->data[d->rear] = data;
}

element delete_front(deque* d)
{
	if (is_empty(d))error("덱이 비어있습니다.");
	d->front = (d->front + 1) % MAX_DEQUE_SIZE;
	return d->data[d->front];
}

element delete_rear(deque* d)
{
	if (is_empty(d))error("덱이 비어있습니다.");
	d->rear = (d->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
	return d->data[(d->rear + 1) % MAX_DEQUE_SIZE];
}

element get_front(deque* d)
{
	if (is_empty(d))error("덱이 비어있습니다.");
	return d->data[(d->front + 1) % MAX_DEQUE_SIZE];
}
element get_rear(deque* d)
{
	if (is_empty(d))error("덱이 비어있습니다.");
	return d->data[d->rear];
}

int get_count(deque* d)
{
	if (d->rear > d->front) return d->rear - d->front;
	else if (d->rear == d->front) return 0;
	else return MAX_DEQUE_SIZE - d->front + d->rear;
}
