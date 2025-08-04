#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void init_queue(queue* q)
{
	q->front = q->rear = 0;
}

int is_queue_empty(queue* q)
{
	return q->front == q->rear;
}

int is_queue_full(queue* q)
{
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(queue* q, int item)
{
	if (is_queue_full(q))error_q("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

int dequeue(queue* q)
{
	if (is_queue_empty(q))error_q("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void error_q(char* msg)
{
	printf("%s\n", msg);
	exit(1);
}