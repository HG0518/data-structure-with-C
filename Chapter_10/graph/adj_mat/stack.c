#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void init_stack(stack* s)
{
	s->top = -1;
	s->size = 1;
	s->list = (int*)malloc(s->size*sizeof(int));
	if (s->list == NULL) error_s("NULL값 할당");
}

void push(stack* s, int item)
{
	if (s->top + 1 == s->size) {
		s->size *= 2;
		s->list = (int*)realloc(s->list, s->size * sizeof(int));
		if (s->list == NULL) error_s("NULL값 할당");
	}
	s->top++;
	s->list[s->top] = item;
}

int pop(stack* s)
{
	if (is_stack_empty(s)) {
		printf("스택이 비어있습니다.");
		return;
	}
	int item = s->list[s->top];
	s->top--;
	return item;
}

int is_stack_empty(stack* s)
{
	return s->top == -1;
}

void error_s(char* msg)
{
	printf("%s\n", msg);
	exit(1);
}

void free_stack(stack* s)
{
	free(s->list);
}