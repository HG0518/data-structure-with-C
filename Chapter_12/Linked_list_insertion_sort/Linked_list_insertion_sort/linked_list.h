#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node
{
	int key;
	struct Node* link;
}Node;

typedef struct
{
	int n;
	Node* node;
}Linked_list;

void init_list(Linked_list* list);
void insert_node(Linked_list* list, int data);
Node* delete_node(Linked_list* list);
void swap_list(Node* front, Node* back, Node* pre);
void print_list(Linked_list* list);
void insertion_sort(Linked_list *list);

#endif // !LINKED_LIST_H
