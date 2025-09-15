#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int list[MAX_SIZE];

void quick_sort(int left, int right);
int pivoting(int left, int right);
void swap(int* a, int* b);
void print_list();
void init_list();
void print_low_high(int low, int high);

int main(void)
{
	init_list();
	printf("정렬 전 list \n");
	print_list();
	printf("\n");

	printf("list 정렬과정 \n");
	quick_sort(0, MAX_SIZE - 1);

	printf("정렬 후 list \n");
	print_list();
}

void quick_sort(int left, int right)
{
	if (left < right)
	{
		int pivot = pivoting(left, right);
		quick_sort(left, pivot - 1);
		quick_sort(pivot + 1, right);
	}
}

int pivoting(int left, int right)
{
	int pivot = list[left];
	int i = left;
	int j = right + 1;

	print_low_high(i + 1, j - 1);
	do
	{
		do {
			i++;
		} while (i <= right && list[i] < pivot);

		do {
			j--;
		} while (list[j] > pivot);

		print_low_high(i, j);

		if (i < j) swap(&list[i], &list[j]);
	} while (i < j);

	swap(&list[left], &list[j]);
	print_low_high(i, j);

	return j;
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
		printf("%5d", list[i]);
	printf("\n");
}

void init_list()
{
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++)
		list[i] = rand() % 100;
}

void print_low_high(int low, int high)
{
	print_list();
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (i == low)printf("%5s", "low");
		else if (i == high)printf("%5s", "high");
		else printf("%5c", ' ');
	}
	printf("\n\n");
}
