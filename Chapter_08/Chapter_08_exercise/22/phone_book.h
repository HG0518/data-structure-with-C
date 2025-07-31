#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

typedef struct {
	char name[20];
	char phone_number[20];
}element;

typedef struct Node {
	element data;
	struct Node* left, * right;
}Node;

Node* create_node(element item);
Node* insert_node(Node* root, element item);
Node* delete_node(Node* root, char* name);
Node* min_value_node(Node* root);
void search(Node* root, char* name);
Node* insert(Node* root);
Node* delete_number(Node* root);
void search_number(Node* root);
int is_empty(Node* root);
Node* select(Node* root);
void play();
void error(char* msg);

#endif // !PHONE_BOOK_H

