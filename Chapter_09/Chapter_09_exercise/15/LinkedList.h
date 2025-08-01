#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct {
	int key;
}element;

typedef struct Node{
	element item;
	struct Node* link;
}Node;

Node* create(Node* q, element item);
void init(Node* q);
Node* insert(Node* q, element item);
element delete_max(Node** q);
element find_max(Node* q);
int is_empty(Node* q);
void error(char* msg);

#endif 
