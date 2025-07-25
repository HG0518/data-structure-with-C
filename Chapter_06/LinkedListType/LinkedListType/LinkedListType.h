#ifndef LINKEDLISTTYPE_H
#define LINKEDLISTTYPE_H

typedef int element;
typedef struct Node
{
	element data;
	struct Node* link;
}Node;

Node* creat_node(element item);
void insert_first(Node** head, element item);
void insert_index(Node* head, int index, element item);
void delete_first(Node** head);
void delete_index(Node* head, int index);
void print_list(Node* head);
element get_index(Node* head, int index);
int get_length(Node* head);
int is_empty(Node* head);
void error(char* msg);


#endif // !LINKEDLISTTYPE_H

