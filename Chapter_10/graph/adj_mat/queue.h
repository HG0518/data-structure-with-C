#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE_SIZE 50
typedef struct queue {
	int data[MAX_QUEUE_SIZE];
	int front, rear;
}queue;

void init_queue(queue* q);
int is_queue_empty(queue* q);
int is_queue_full(queue* q);
void enqueue(queue* q, int item);
int dequeue(queue* q);
void error_q(char* msg);
#endif // !QUEUE_H
