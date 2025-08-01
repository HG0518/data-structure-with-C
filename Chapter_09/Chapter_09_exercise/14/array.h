#ifndef ARRAY_H
#define ARRAY_H

#define MAX_SIZE 100
typedef struct {
	int key;
}element;

typedef struct {
	element arr[MAX_SIZE];
	int size;
}ArrayType;

ArrayType* create(ArrayType* q);
void init(ArrayType* q);
void insert(ArrayType* q, element item);
element delete_max(ArrayType* q);
element find_max(ArrayType* q);
int is_empty(ArrayType* q);
int is_full(ArrayType* q);
void error(char* msg);

#endif 
