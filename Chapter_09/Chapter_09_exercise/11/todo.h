#ifndef TODO_H
#define TODO_H

#define MAX_SIZE 100
typedef struct {
	int key;
	char id[20];
}element;

typedef struct {
	element heap[MAX_SIZE];
	int size;
}HeapType;

HeapType* create(HeapType* h);
void init(HeapType* h);
void insert(HeapType* h, element item);
element delete_max(HeapType* h);
int is_empty(HeapType* h);
void display(HeapType* h);
void error(char* msg);
void play();
void select(HeapType* h);
void insert_todo(HeapType* h);
void delete_todo(HeapType* h);

#endif // !TODO_H
