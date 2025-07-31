#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phone_book.h"

Node* create_node(element item)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL)error("NULL값 할당");
	//temp->data = item;
	strcpy(temp->data.name, item.name);
	strcpy(temp->data.phone_number, item.phone_number);
	temp->left = temp->right = NULL;
	return temp;
}


Node* insert_node(Node* root, element item)
{
	if (is_empty(root)) return create_node(item);
	if (strcmp(root->data.name, item.name) > 0) root->left = insert_node(root->left, item);
	else if (strcmp(root->data.name, item.name) < 0) root->right = insert_node(root->right, item);
	else error("이미 같은 key를 가진 노드가 있습니다.");
	return root;
}

Node* delete_node(Node* root, char* name)
{
	if (is_empty(root))
	{
		printf("해당 이름을 가진 사람이 없습니다.\n");
		return;
	}
	if (strcmp(root->data.name, name) > 0) root->left = delete_node(root->left, name);
	else if (strcmp(root->data.name, name) < 0) root->right = delete_node(root->right, name);
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
			root->data = deleted->data;
			root->right = delete_node(root->right, deleted->data.name);
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

void search(Node* root, char* name)
{
	if (is_empty(root))
	{
		printf("해당 이름을 가진 사람이 없습니다.\n");
		return;
	}
	if (strcmp(root->data.name, name) == 0) {
		printf("친구의 전화번호 : %s\n", root->data.phone_number);
		return;
	}
	else if (strcmp(root->data.name, name) > 0) search(root->left, name);
	else search(root->right, name);
}

Node* insert(Node* root)
{
	element item;
	char name[20];
	char phone_number[20];
	printf("친구의 이름 : ");
	scanf("%s", name);
	printf("친구의 전화번호 : ");
	scanf("%s", phone_number);
	strcpy(item.name, name);
	strcpy(item.phone_number, phone_number);
	root = insert_node(root, item);
	printf("새로운 번호 삽입이 완료되었습니다.\n");
	return root;
}

Node* delete_number(Node* root)
{
	char name[20];
	printf("친구의 이름 : ");
	scanf("%s", name);
	return root = delete_node(root, name);
}

void search_number(Node* root)
{
	char name[20];
	printf("친구의 이름 : ");
	scanf("%s", name);
	search(root, name);
}

int is_empty(Node* root)
{
	return root == NULL;
}

Node* select(Node* root)
{
	char ch;
	printf("삽입(i), 탐색(s), 삭제(d) : ");
	ch = getchar();

	switch (ch) {
	case 'i':
		root = insert(root);
		break;
	case 's':
		search_number(root);
		break;
	case'd':
		root = delete_number(root);
		break;
	default:
		printf("잘못된 입력\n");
	}
	return root;
}

void play()
{
	Node* root = NULL;
	while (1)
	{
		root = select(root);
		getchar();
	}
}

void error(char* msg)
{
	printf("%s\n", msg);
	exit(1);
}