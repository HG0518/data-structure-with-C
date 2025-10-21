#include <stdio.h>
#include <stdlib.h>
#include "AVLtree.h"
#define MAX(a,b) ((a)>(b)?(a):(b))

int get_height(AVLnode* node)
{
	if (node == NULL) return 0;
	return 1 + MAX(get_height(node->left), get_height(node->right));
}

int get_balance(AVLnode* node)
{
	return get_height(node->left) - get_height(node->right);
}

AVLnode* turn_left(AVLnode* parent)
{
	AVLnode* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}

AVLnode* turn_right(AVLnode* parent)
{
	AVLnode* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}

AVLnode* create_node(int key)
{
	AVLnode* node = (AVLnode*)malloc(sizeof(AVLnode));
	if (node == NULL)
	{
		fprintf(stderr, "NULL값 할당 오류");
		return NULL;
	}
	node->key = key;
	node->left = node->right = NULL;
	return node;
}

AVLnode* insert_node(AVLnode* node, int key)
{
	if (node == NULL) return create_node(key);

	if (key > node->key) node->right = insert_node(node->right, key);
	else if (key < node->key) node->left = insert_node(node->left, key);
	else return node;

	int balance = get_balance(node);

	if (balance > 1 && key < node->left->key)
		return turn_right(node);

	if (balance > 1 && key > node->left->key)
	{
		node->left = turn_left(node->left);
		return turn_right(node);
	}

	if (balance < -1 && key > node->right->key)
		return turn_left(node);

	if (balance < -1 && key < node->right->key)
	{
		node->right = turn_right(node->right);
		return turn_left(node);
	}

	return node;
}

void preorder(AVLnode* node)
{
	if (node == NULL) return;
	printf("[%d] ", node->key);
	preorder(node->left);
	preorder(node->right);
}

AVLnode* free_node(AVLnode* node)
{
	if (node == NULL) return;
	free_node(node->left);
	free_node(node->right);
	free(node);
	node = NULL;
	return node;
}