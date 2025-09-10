#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int list[MAX_SIZE];

void shell_sort();
void gap_selection_sort(int gap);
void init_list();
void print_list();

int main(void)
{
	shell_sort();
}

void shell_sort()
{
	init_list();
	printf("정렬 전\n");
	print_list();
	int gap, step = 1;
	for (gap = MAX_SIZE / 2; gap > 0; gap /= 2)
	{
		if (gap % 2 == 0)gap++;
		gap_selection_sort(gap);

		printf("step %d : gap = %d\n", step++, gap);
		print_list();
	}
	printf("정렬 후\n");
	print_list();
}

void gap_selection_sort(int gap)
{
	int i, j, k, key;
	for (k = 0; k < gap; k++)
	{
		for (i = k + gap; i < MAX_SIZE; i += gap)
		{
			key = list[i];
			for (j = i - gap; j >= k && list[j] > key; j -= gap)
				list[j + gap] = list[j];
			list[j + gap] = key;
		}
	}
}

void init_list()
{
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++)
		list[i] = rand() % 100;
}

void print_list()
{
	for (int i = 0; i < MAX_SIZE; i++)
		printf("%3d ", list[i]);
	printf("\n\n");
}