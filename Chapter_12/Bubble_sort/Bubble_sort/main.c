#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int list[MAX_SIZE];

void bubble_sort();
void swap(int* a, int* b);
void print_list();
void init_list();

int main(void)
{
	bubble_sort();
}

void bubble_sort()
{
	init_list();
	printf("정렬 전 list \n");
	print_list();

	int step = 1;
	for (int i = MAX_SIZE - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
			if (list[j] > list[j + 1]) swap(&list[j], &list[j + 1]);

		printf("step %d\n", step++);
		print_list();
	}

	printf("정렬 후 list \n");
	print_list();
}

void swap(int* a, int* b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void print_list()
{
	for (int i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	printf("\n\n");
}

void init_list()
{
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++)
		list[i] = rand() % 100;
}
