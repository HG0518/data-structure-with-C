#ifndef HEAP_SORT_H
#define HEAP_SORT_H

typedef struct
{
	int size;
	int* list;
}Heap;

void start();
void init_heap(Heap* h, int heap_size);
void heap_sort(Heap* h, int list_size);
void print_list(Heap* h, int list_size);
void print_heap_sort(Heap* h, int n);

void insert_heap(Heap* h, int data);
int delete_heap(Heap* h);

#endif // !HEAP_SORT_H

