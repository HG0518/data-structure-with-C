#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

Node* create_node(element item)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL)error("NULL값 할당");
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

Node* search_node(Node* root, element item)
{
	if (is_empty(root))return NULL;
	if (root->key == item)return root;
	else if (root->key > item) return search_node(root->left, item);
	else return search_node(root->right, item);
}

Node* insert_node(Node* root, element item)
{	
	if (is_empty(root)) return create_node(item);
	if (root->key > item) root->left = insert_node(root->left, item);
	else if (root->key < item) root->right = insert_node(root->right, item);
	else error("이미 같은 key를 가진 노드가 있습니다.");
	return root;
}

Node* delete_node(Node* root, element item)
{
	if (is_empty(root))error("해당하는 key를 가진 노드가 없습니다.");
	if (root->key > item) root->left = delete_node(root->left, item);
	else if (root->key < item) root->right = delete_node(root->right, item);
	else {
		if (root->left == NULL) {
			Node* deleted = root;
			root = root->right;
			free(deleted);
		}
		else if (root->right == NULL) {
			Node* deleted = root;
			root = root->left;
			free(deleted);
		}
		else {
			Node* deleted = min_value_node(root->right);
			root->key = deleted->key;
			root->right = delete_node(root->right, deleted->key);	
		}
	}
	return root;
}

Node* min_value_node(Node* root)
{
	Node* tmp = root;
	while (tmp->left != NULL) tmp = tmp->left;
	return tmp;
}

void inorder(Node* root)
{
	if (root == NULL) return;
	inorder(root->left);
	printf("%d ", root->key);
	inorder(root->right);
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