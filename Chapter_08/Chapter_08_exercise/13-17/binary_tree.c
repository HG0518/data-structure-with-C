#include <stdio.h>
#include "binary_tree.h"

int getHeight(Node* root)
{
	int height;
	if (root == NULL)return 0;
	height = getHeight(root->left) > getHeight(root->right) ? getHeight(root->left) : getHeight(root->right);
	return height + 1;
}

int isBalanced(Node* root)
{
	if (root == NULL)return 1;
	int gap = getHeight(root->left) - getHeight(root->right);
	if (gap > 1 || gap < -1) return 0;
	return isBalanced(root->left) * isBalanced(root->right);
}

int tree_sum(Node* root);
void print_small(Node* root, int value);
int getNumOneChild(Node* root);
int getMax(Node* root);
int getMin(Node* root);


int is_empty(Node* root)
{
	return root == NULL;
}

void error(char* msg)
{
	printf("%s\n", msg);
	exit(1);
}
