#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef int element;
typedef struct Node {
	element key;
	struct Node* left, * right;
}Node;

Node* create_node(element item);
Node* search_node(Node* root, element item);
Node* insert_node(Node* root, element item);
Node* delete_node(Node* root, element item);
Node* min_value_node(Node* root);
void inorder(Node* root);
int is_empty(Node* root);
void error(char* msg);

#endif // !BINARY_SEARCH_TREE_H
