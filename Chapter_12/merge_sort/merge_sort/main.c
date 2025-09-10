#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int list[MAX_SIZE];
int sorted_list[MAX_SIZE];

void merge_sort(int left, int right);
void merge(int left, int mid, int right);
void init_list();
void print_list();

int main(void)
{
	init_list();
	printf("정렬 전\n");
	print_list();

	merge_sort(0, MAX_SIZE - 1);

	printf("정렬 후\n");
	print_list();
}

void merge_sort(int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid, right);
	}
}

void merge(int left, int mid, int right)
{
	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right)
	{
		if (list[i] > list[j])
			sorted_list[k++] = list[j++];
		else
			sorted_list[k++] = list[i++];
	}

	if (i > mid)
		while (j <= right)
			sorted_list[k++] = list[j++];

	else
		while (i <= mid)
			sorted_list[k++] = list[i++];

	for (i = left; i <= right; i++)
		list[i] = sorted_list[i];

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
