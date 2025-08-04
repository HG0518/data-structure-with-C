#ifndef STACK_H
#define STACK_H

typedef struct stack {
	int top, size;
	int* list;
}stack;

void init_stack(stack* s);
void push(stack* s, int item);
int pop(stack* s);
int is_stack_empty(stack* s);
void error_s(char* msg);
void free_stack(stack* s);

#endif // !STACK_H
