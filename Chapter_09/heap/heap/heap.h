#ifndef HEAP_H
#define HEAP_H

#define MAX_SIZE 100
typedef struct {
	int key;
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

#endif // !HEAP_H
