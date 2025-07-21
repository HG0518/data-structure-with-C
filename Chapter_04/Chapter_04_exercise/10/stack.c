#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

void init(stack* s)
{
	s->size = 1;
	s->data = (element*)malloc(s->size * sizeof(element));
	s->top = -1;
}

bool is_full(stack* s)
{
	if (s->top == s->size - 1) return true;
	else return false;
}

bool is_empty(stack* s)
{
	if (s->top == -1) return true;
	else return false;
}

void push(stack* s, element data)
{
	if (is_full(s) == true)
	{
		s->size *= 2;
		s->data = (element*)realloc(s->data, s->size * sizeof(element));
		if (s->data == NULL)
		{
			printf("메모리 할당 실패");
			exit(1);
		}
	}
	s->top++;
	s->data[s->top] = data;
}

element pop(stack* s)
{
	if (is_empty(s) == true)
	{
		printf("스택이 비어있습니다.\n");
		exit(1);
	}
	s->top--;
	return s->data[s->top + 1];
}

element peek(stack* s)
{
	if (is_empty(s) == true)
	{
		printf("스택이 비어있습니다.\n");
		exit(1);
	}
	return s->data[s->top];
}

void free_s(stack* s)
{
	free(s->data);
}
