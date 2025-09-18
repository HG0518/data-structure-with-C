#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int list[MAX_SIZE];

void insertion_sort();
void print_list(int n, int k);
void init_list();

int main(void)
{
	insertion_sort();
}

void insertion_sort()
{
	init_list();
	int i, j;
	print_list(100, -1);
	for (i = 0; i < MAX_SIZE; i++)
	{
		int tmp = list[i];
		for (j = i - 1; j >= 0 && list[j] > tmp; j--)
			list[j + 1] = list[j];
		list[j + 1] = tmp;
		print_list(tmp, i);
	}
}

void print_list(int insert_n, int iteration)
{
	int i = 0;
	printf("(");
	if (iteration >= 0) printf("%d", list[i++]);
	for (; i <= iteration; i++)
		printf(",%d", list[i]);
	printf(")\t");

	printf("(");
	if(i<MAX_SIZE) printf("%d", list[i++]);
	for (; i < MAX_SIZE; i++)
		printf(",%d", list[i]);
	printf(")\t");

	if (iteration >= 0) printf("%d삽입", insert_n);
	printf("\n");
}

void init_list()
{
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++)
		list[i] = rand() % 100;
}
