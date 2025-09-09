#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int list[MAX_SIZE];

void selection_sort();
void swap(int* a, int* b);
void print_list();
void init_list();

int main(void)
{
	selection_sort();
}

void selection_sort()
{
	init_list();
	printf("정렬 전 list \n");
	print_list();

	int i, j, min_pos;
	for (i = 0; i < MAX_SIZE - 1; i++)
	{
		min_pos = i;
		for (j = i; j < MAX_SIZE; j++)		
			if (list[j] < list[min_pos])		
				min_pos = j;
			
		
		swap(&list[min_pos], &list[i]);		
		
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
