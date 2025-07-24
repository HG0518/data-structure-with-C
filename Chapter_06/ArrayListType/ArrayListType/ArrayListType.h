#ifndef ARRAYLISTTYPE_H
#define ARRAYLISTTYPE_H

typedef int element;
typedef struct {
	element* data;
	int size;
	int top;
}ArrayListType;

void init(ArrayListType* list);
void insert(ArrayListType* list, int pos, element item);
void insert_last(ArrayListType* list, element item);
void insert_first(ArrayListType* list, element item);
void delete_data(ArrayListType* list, int pos);
void clear(ArrayListType* list);
element get_entry(ArrayListType* list, int pos);
int get_length(ArrayListType* list);
int is_empty(ArrayListType* list);
int is_full(ArrayListType* list);
void print_list(ArrayListType* list);
void replace(ArrayListType* list, int pos, element item);
void error(char* msg);
void free_list(ArrayListType* list);
void extend_list(ArrayListType* list);


#endif // !ARRAYLISTTYPE.H
