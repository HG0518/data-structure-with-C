#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int list[MAX_SIZE];

void selection_sort();
void swap(int* a, int* b);
void print_list(int iteration, int select_n, int change_n);
void init_list();

int main(void)
{
	selection_sort();
}

void selection_sort()
{
	init_list();
	print_list(-1, 0, 0);

	int i, j, min_pos;
	for (i = 0; i < MAX_SIZE - 1; i++)
	{
		min_pos = i;
		for (j = i + 1; j < MAX_SIZE; j++)
			if (list[j] < list[min_pos])
				min_pos = j;

		if (i != min_pos)
			swap(&list[min_pos], &list[i]);

		print_list(i, list[i], list[min_pos]);

	}
	print_list(i, list[i], list[i]);
}

void swap(int* a, int* b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void print_list(int iteration, int select_n, int change_n)
{
	int i = 0;
	printf("(");
	if (i <= iteration) printf("%d", list[i++]);
	for (; i <= iteration; i++)
		printf(",%d", list[i]);
	printf(")\t\t");

	printf("(");
	if (i < MAX_SIZE) printf("%d", list[i++]);
	for (; i < MAX_SIZE; i++)
		printf(",%d", list[i]);
	printf(")\t\t");

	if (iteration < 0)printf("초기상태\n");
	else printf("%d선택 후 %d와 교환\n", select_n, change_n);
}

void init_list()
{
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++)
		list[i] = rand() % 100;
}
