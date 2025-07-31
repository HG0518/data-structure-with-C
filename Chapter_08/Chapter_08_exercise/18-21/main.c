#include <stdio.h>
#include "../../binary_search_tree/binary_search_tree/binary_search_tree.h"

void print_asc(int* arr, int size);
void print_desc(int* arr, int size);
void inorder_r(Node* root);
Node* plusone(Node* root);
int get_max(Node* root);


int main(void)
{
	int arr[11] = { 11,3,4,1,56,5,6,2,98,32,23 };
	print_asc(arr, 11);
	print_desc(arr, 11);

	Node* root = NULL;
	for (int i = 0; i < 11; i++)
		root = insert_node(root, arr[i]);
	printf("이전 : ");
	inorder(root);	printf("\n");
	root = plusone(root);
	printf("이후 : ");
	inorder(root);	printf("\n");

	printf("최대값 : %d\n", get_max(root));
	return 0;
}

void print_asc(int* arr, int size)
{
	Node* root = NULL;
	for (int i = 0; i < size; i++)
		root = insert_node(root, arr[i]);
	printf("오름차순 정렬 : ");
	inorder(root);
	printf("\n");
}

void print_desc(int* arr, int size)
{
	Node* root = NULL;
	for (int i = 0; i < size; i++)
		root = insert_node(root, arr[i]);
	printf("내림차순 정렬 : ");
	inorder_r(root);
	printf("\n");
}

void inorder_r(Node* root)
{
	if (root == NULL) return;
	inorder_r(root->right);
	printf("%d ", root->key);
	inorder_r(root->left);
}

Node* plusone(Node* root)
{
	if (root == NULL) return root;
	root->key += 1;
	plusone(root->left);
	plusone(root->right);
	return root;
}

int get_max(Node* root)
{
	if (root == NULL) error("트리가 비어있습니다.");
	while (root->right != NULL) root = root->right;
	return root->key;
}

