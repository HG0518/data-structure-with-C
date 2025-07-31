#include <stdio.h>
#include <math.h>
#include "binary_tree.h"

#define MAX pow(2,31)-1
#define MIN -pow(2,31)

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

int tree_sum(Node* root)
{
	if (root == NULL) return 0;
	return root->key + tree_sum(root->left) + tree_sum(root->right);
}

void print_small(Node* root, int value)
{
	if (root == NULL)return;
	if (root->key < value) printf("%d보다 작은 노드 : %d\n", value, root->key);
	print_small(root->left, value);
	print_small(root->right, value);
}
int getNumOneChild(Node* root)
{
	if (!(root->left && root->right)) {
		if (root->left || root->right) return 1;
		else return 0;
	}
	return getNumOneChild(root->left) + getNumOneChild(root->right);
}

int getMax(Node* root)
{
	if (root == NULL) return MIN;
	int left_max = getMax(root->left);
	int right_max = getMax(root->right);
	int max = root->key;
	if (left_max > max) max = left_max;
	if (right_max > max) max = right_max;
	return max;
}

int getMin(Node* root)
{
	if (root == NULL) return MAX;
	int left_min = getMin(root->left);
	int right_min = getMin(root->right);
	int min = root->key;
	if (left_min < min) min = left_min;
	if (right_min < min) min = right_min;
	return min;
}


int is_empty(Node* root)
{
	return root == NULL;
}

void error(char* msg)
{
	printf("%s\n", msg);
	exit(1);
}
