#ifndef HEAP_SORT_H
#define HEAP_SORT_H

void start();
void heap_sort(int list[], int n);
void print_heap(int list[], int n);
void print_heap_sort(int list[], int heap_size, int n);

void insert_heap(int heap[], int n);
int delete_heap(int heap[], int n);

#endif // !HEAP_SORT_H

