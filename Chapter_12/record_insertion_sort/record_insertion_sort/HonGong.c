#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define NAME_SIZE 30

typedef struct
{
	int key;
	char name[NAME_SIZE];
}record;

void insertion_sort(record rd[]);
void swap(record* a, record* b);
void print_list(record rd[]);
void init_list(record rd[]);

int main(void)
{
	record rd[MAX_SIZE];
	insertion_sort(rd);
}

void insertion_sort(record rd[])
{
	init_list(rd);
	printf("정렬 전 list \n");
	print_list(rd);

	
	int i, j;
	for (i = 1; i < MAX_SIZE; i++)
	{
		record tmp = rd[i];
		for (j = i - 1; j >= 0 && rd[j].key > tmp.key; j--)
			swap(&rd[j + 1], &rd[j]);
		rd[j + 1] = tmp;
		printf("step %d\n", i);
		print_list(rd);
	}

	printf("정렬 후 list \n");
	print_list(rd);
	
}

void swap(record* a, record* b)
{
	record t;
	t = *a;
	*a = *b;
	*b = t;
}

void print_list(record rd[])
{
	printf("%7s", "key : ");
	for (int i = 0; i < MAX_SIZE; i++)
		printf("%7d ", rd[i].key);
	printf("\n");

	printf("%7s", "name : ");
	for (int i = 0; i < MAX_SIZE; i++)
		printf("%7s ", rd[i].name);
	printf("\n\n");
}

void init_list(record rd[])
{
	srand(time(NULL));

	printf("이름을 %d개 입력하세요\n", MAX_SIZE);
	for (int i = 0; i < MAX_SIZE; i++)
	{
		scanf("%s", &rd[i].name);
		rd[i].key = rand() % 100;
	}
}
