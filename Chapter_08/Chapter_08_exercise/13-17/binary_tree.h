#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct Node {
	int key;
	struct Node* left, * right;
}Node;

int getHeight(Node* root);
int isBalanced(Node* root);
int tree_sum(Node* root);
void print_small(Node* root, int value);
int getNumOneChild(Node* root);
int getMax(Node* root);
int getMin(Node* root);
int is_empty(Node* root);
void error(char* msg);

#endif // !BINARY_TREE_H
