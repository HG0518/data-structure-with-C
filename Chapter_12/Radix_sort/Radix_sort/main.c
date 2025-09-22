#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10
#define BUCKET_SIZE 10

typedef struct {
	int data[SIZE + 1];
	int front, rear;
}Queue;

Queue bucket[BUCKET_SIZE];

int list[SIZE];

void radix_sort(int n);
int get_msd();
void init_list();
void print_list();
void init_q(Queue* q);
void inqueue(Queue* q, int n);
int dequeue(Queue* q);
int is_empty_queue(Queue* q);
int is_full_queue(Queue* q);
void error(char* msg);
void init_bucket();
void print_bucket();

int main(void)
{
	init_list();
	printf("정렬 전\n");
	print_list();

	init_bucket();

	int n = get_msd();
	radix_sort(n);

	printf("정렬 후\n");
	print_list();
}

void radix_sort(int n)
{
	int i, j, k, num;
	int factor = 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			num = (list[j] / factor) % 10;
			inqueue(&bucket[num], list[j]);
		}
		print_bucket();
		for (j = k = 0; k < SIZE; k++)
			while (!is_empty_queue(&bucket[k]))
				list[j++] = dequeue(&bucket[k]);
		factor *= 10;
	}
}

int get_msd()
{
	int i, count, num;
	int max_count = 0;
	for (i = 0; i < SIZE; i++)
	{
		count = 0;
		num = list[i];
		do
		{
			num /= 10;
			count++;
		} while (num != 0);
		max_count = max_count < count ? count : max_count;
	}
	return max_count;
}

void init_list()
{
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
		list[i] = rand() % 100;
}

void print_list()
{
	for (int i = 0; i < SIZE; i++)
		printf("%3d ", list[i]);
	printf("\n\n");
}

void init_q(Queue* q)
{
	q->front = q->rear = 0;
}

void inqueue(Queue* q, int n)
{
	if (is_full_queue(q)) error("큐가 포화상태입니다.\n");
	q->rear = (q->rear + 1) % SIZE;
	q->data[q->rear] = n;
}

int dequeue(Queue* q)
{
	if (is_empty_queue(q))error("큐가 공백상태입니다.\n");
	q->front = (q->front + 1) % SIZE;
	return q->data[q->front];
}

int is_empty_queue(Queue* q)
{
	return q->front == q->rear;
}

int is_full_queue(Queue* q)
{
	return (q->rear + 1) % SIZE == q->front;
}

void error(char* msg)
{
	printf("%s", msg);
	exit(1);
}

void init_bucket()
{
	for (int i = 0; i < BUCKET_SIZE; i++)
		init_q(&bucket[i]);
}

void print_bucket()
{
	printf("========================\n");
	for (int i = 0; i < BUCKET_SIZE; i++)
	{
		printf("[%d]-> ", i);
		for (int j = (bucket[i].front + 1) % SIZE; j <= bucket[i].rear; j = (j + 1) % SIZE)
			printf("%d ", bucket[i].data[j]);
		printf("\n");
	}
	printf("========================\n");
}