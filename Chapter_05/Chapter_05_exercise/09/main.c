#include <stdio.h>

#define	MAX_STACK_SIZE 5

typedef struct {
	int data[MAX_STACK_SIZE];
	int top;
}stack;

void init_stack(stack* s);
int is_empty(stack* s);
int is_full(stack* s);
void push(stack* s, int data);
int pop(stack* s_in, stack* s_out);
void move(stack* s_in, stack* s_out);
void error(char* msg);
void print_stack(stack* s);
void print_stack_compare(stack* s_in, stack* s_out);


int main(void)
{
	stack s_in, s_out;
	init_stack(&s_in);
	init_stack(&s_out);

	push(&s_in, 10);
	push(&s_in, 20);
	push(&s_in, 30);
	print_stack_compare(&s_in, &s_out);

	printf("출력 요청. %d 출력\n\n", pop(&s_in, &s_out));
	print_stack_compare(&s_in, &s_out);

	printf("출력 요청. %d 출력\n\n", pop(&s_in, &s_out));
	print_stack_compare(&s_in, &s_out);

	return 0;
}

void init_stack(stack* s)
{
	s->top = -1;
}

int is_empty(stack* s)
{
	return s->top == -1;
}

int is_full(stack* s)
{
	return s->top == MAX_STACK_SIZE - 1;
}

void push(stack* s, int data)
{
	if (is_full(s)) error("스택이 포화상태입니다.");
	s->top += 1;
	s->data[s->top] = data;
}

int pop(stack* s_in, stack* s_out)
{
	if (is_empty(s_out)) move(s_in, s_out);
	s_out->top -= 1;
	return s_out->data[s_out->top + 1];
}

void move(stack* s_in, stack* s_out)
{
	if (is_empty(s_in)) error("스택이 모두 비어있습니다.");
	int i, n = s_in->top;
	stack tmp;
	for (i = 0; i <= n; i++)
	{
		push(s_out, pop(&tmp, s_in));
	}
}

void error(char* msg)
{
	printf("%s\n", msg);
	exit(1);
}

void print_stack(stack* s)
{
	int i, n = s->top;
	for (i = 0; i <= n; i++)
	{
		printf("%d ", s->data[i]);
	}
	printf("\n");
}

void print_stack_compare(stack* s_in, stack* s_out)
{
	printf("스택 상태\n");
	printf("s_in : ");
	print_stack(s_in);
	printf("s_out : ");
	print_stack(s_out);
	printf("\n");
}
