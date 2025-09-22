#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stdlib.h"
#include "time.h"
#include "heap_sort.h"

void start()
{
	int num = 0;
	printf("숫자의 개수 : ");
	scanf("%d", &num);
	
	int* heap = (int*)malloc((num + 1) * sizeof(int));
	if (heap == NULL)
	{
		printf("NULL값 할당 오류\n");
		exit(1);
	}

	srand(time(NULL));
	for (int i = 0; i < num; i++)
	{
		int n = rand() % 100;
		insert_heap(heap, n);
	}

	print_heap(heap, num);
	printf("\n");

	heap_sort(heap, num);
	printf("\n");

	printf("정렬된 배열 : \n");
	print_heap(heap, num);
}

void heap_sort(int list[], int n)
{
	for (int i = n; i > 0; i--)
	{
		list[i] = delete_heap(list, i);
		print_heap_sort(list, i, n);
	}
}

void print_heap(int list[], int n)
{
	for (int i = 1; i <= n; i++)
		printf("%d ", list[i]);
	printf("\n");
}

void print_heap_sort(int list[], int heap_size, int n)
{
	int i = 1;
	for (i; i < heap_size; i++)	
		printf("%d ", list[i]);
	printf("[");
	for (i; i < n; i++)
		printf("%d ", list[i]);
	printf("%d]\n", list[n]);
}

void insert_heap(int heap[], int n)
{

}
int delete_heap(int heap[], int n)
{

}