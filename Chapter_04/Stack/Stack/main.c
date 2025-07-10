#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int num;
}element;

typedef struct {
	element* data;
	int top;
	int size;
}stack;

void init(stack* s);					//스택을 동적할당하고 초기화시키는 함수
bool is_full(stack* s);					//스택이 꽉 차있는지 검사하는 함수
bool is_empty(stack* s);				//스택이 비어있는지 검사하는 함수
void push(stack* s, element data);		//스택에 data를 넣는 함수
element pop(stack* s);					//스택으로 가장 마지막에 입력된 데이터를 반환하고 삭제하는 함수
element peek(stack* s);					//스택으로 가장 마지막에 입력된 데이터를 반환하는 함수



int main(void) {
	stack s;
	init(&s);
	element d1 = { 1 };
	element d2 = { 2 };
	element d3 = { 3 };
	
	push(&s, d1);
	push(&s, d2);
	push(&s, d3);

	printf("%d %d %d\n", s.data[0].num,s.data[1].num,s.data[2].num);
	element t1 = pop(&s);
	element t2 = peek(&s);
	element t3 = pop(&s);
	element t4 = pop(&s);

	printf("%d %d %d %d\n", t1.num, t2.num, t3.num, t4.num);

	element t5 = pop(&s);

}

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