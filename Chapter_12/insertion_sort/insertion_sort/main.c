#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int list[MAX_SIZE];

void insertion_sort();
void swap(int* a, int* b);
void print_list();
void init_list();

int main(void)
{
	insertion_sort();
}

void insertion_sort()
{
	init_list();
	printf("정렬 전 list \n");
	print_list();

	int i, j;
	for (i = 1; i < MAX_SIZE; i++)
	{
		int tmp = list[i];
		for (j = i - 1; j >= 0 && list[j] > tmp; j--)
			list[j + 1] = list[j];
		list[j + 1] = tmp;
		printf("step %d\n", i);
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
		printf("%2d ", list[i]);
	printf("\n\n");
}

void init_list()
{
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++)
		list[i] = rand() % 100;
}
