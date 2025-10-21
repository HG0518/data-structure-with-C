#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct binaryNode
{
	int key;
	struct binaryNode* left;
	struct binaryNode* right;
}binaryNode;

binaryNode* create_node(int key);
binaryNode* insert_node(binaryNode* root, int key);
void inorder(binaryNode* root, int list[]);
int* binaryArray(int list[], int n);
void start(int n);
void printList(int list[], int n);

static int size;

int main(void)
{
	start(10);
}

binaryNode* create_node(int key)
{
	binaryNode* node = (binaryNode*)malloc(sizeof(binaryNode));
	if (node == NULL)
	{
		printf("NULL값 할당 오류");
		return NULL;
	}
	node->key = key;
	node->left = node->right = NULL;
	return node;
}

binaryNode* insert_node(binaryNode* root, int key)
{
	if (root == NULL) 
		return create_node(key);
	

	if (key > root->key) 
		root->right = insert_node(root->right, key);
	else if (key < root->key) 
		root->left = insert_node(root->left, key);
	else return root;

	return root;
}

void inorder(binaryNode* root, int list[])
{
	if (root == NULL) return;
	inorder(root->left, list);
	list[size++] = root->key;
	inorder(root->right, list);
}

int* binaryArray(int list[], int n)
{
	binaryNode* root = NULL;

	for (int i = 0; i < n; i++)
		root = insert_node(root, list[i]);
	size = 0;
	inorder(root, list);
	return list;
}

void start(int n)
{
	int* list = (int*)malloc(n * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < n; i++)	
		list[i] = rand() % 100;
	
	printf("정렬 전 배열\n");
	printList(list, n);

	list = binaryArray(list, n);

	printf("정렬 후 배열\n");
	printList(list, size);
}

void printList(int list[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n\n");
}
