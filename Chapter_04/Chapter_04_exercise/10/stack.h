#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef char element;

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
void free_s(stack* s);

#endif