#ifndef DOUBLE_LINKED_LIST_C
#define DOUBLE_LINKED_LIST_C

typedef int element;
typedef struct Node {
	element data;
	struct Node* llink;
	struct Node* rlink;
}Node;

Node* init(Node* head);
void insert_first(Node* before, element item);
void delete_removed(Node* head, Node* removed);
void print_list(Node* head);
void error(char* msg);
int is_empty(Node* head);

#endif // !DOUBLE_LINKED_LIST_C

