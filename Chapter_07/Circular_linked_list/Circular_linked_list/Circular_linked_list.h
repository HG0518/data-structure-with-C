#ifndef CIRCULAR_LINKED_LIST_C
#define CIRCULAR_LINKED_LIST_C

typedef int element;
typedef struct Node {
	element data;
	struct Node* link;
}Node;

Node* insert_first(Node* head, element item);
Node* insert_last(Node* head, element item);
Node* delete_first(Node* head);
Node* delete_last(Node* head);
void print_list(Node* head);
int get_length(Node* head);
int is_empty(Node* head);
void error(char* msg);

#endif // !CIRCULAR_LINKED_LIST_C

