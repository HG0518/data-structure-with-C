#include <stdio.h>
#include <stdlib.h>
#include "ArrayListType.h"

void init(ArrayListType* list)
{
	list->size = 1;
	list->top = -1;
	list->data = (element*)malloc(list->size * sizeof(element));
	if (list->data == NULL)
	{
		error("NULL값이 할당되었습니다.");
		exit(1);
	}
}

void insert(ArrayListType* list, int pos, element item)
{
	if (pos<0 || pos>list->top + 1)error("위치 오류");

	if (is_full(list)) extend_list(list);

	int i;
	for (i = list->top; i >= pos; i--)
	{
		list->data[i + 1] = list->data[i];
	}
	list->data[pos] = item;
	list->top++;
}

void insert_last(ArrayListType* list, element item)
{
	if (is_full(list)) extend_list(list);

	list->top++;
	list->data[list->top] = item;
}

void insert_first(ArrayListType* list, element item)
{
	insert(list, 0, item);
}

void delete_data(ArrayListType* list, int pos)
{
	if (list->top < pos || pos < 0)error("위치 오류");

	int i;
	for (i = pos; i < list->top; i++)
	{
		list->data[i] = list->data[i + 1];
	}
	list->top--;
}

void clear(ArrayListType* list)
{
	list->top = -1;
}

element get_entry(ArrayListType* list, int pos)
{
	if (list->top < pos || pos < 0)error("위치 오류");
	return list->data[pos];
}

int get_length(ArrayListType* list)
{
	return list->top + 1;
}

int is_empty(ArrayListType* list)
{
	return list->top == -1;
}

int is_full(ArrayListType* list)
{
	return list->size - 1 == list->top;
}

void print_list(ArrayListType* list)
{
	if (is_empty(list))
	{
		printf("리스트가 비었습니다.\n");
		return;
	}
	int i;
	
	for (i = 0; i < list->top; i++)
	{
		printf("%d > ", list->data[i]);
	}
	printf("%d\n", list->data[i]);
}

void replace(ArrayListType* list, int pos, element item)
{
	if (pos > list->top || pos < 0)error("위치 오류");
	list->data[pos] = item;
}

void error(char* msg)
{
	printf("%s\n", msg);
	exit(1);
}

void free_list(ArrayListType* list)
{
	free(list->data);
}

void extend_list(ArrayListType* list)
{
	list->size *= 2;
	list->data = (element*)realloc(list->data, list->size * sizeof(element));
	if (list->data == NULL)
	{
		error("NULL값이 할당되었습니다.");
		exit(1);
	}
}
