#include <stdio.h>
#include <stdlib.h>
#include "LinkedListType.h"

Node* creat_node(element item)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL) error("NULL값 할당");
	newnode->data = item;
	newnode->link = NULL;
	return newnode;
}

void insert_first(Node** head, element item)
{
	Node* newnode = creat_node(item);
	newnode->link = *head;
	*head = newnode;
}

void insert_index(Node* head, int index, element item)
{
	if (index == 0) insert_first(&head, item);
	else if (index > get_length(head) || index < 0)error("인덱스 오류");
	else {
		Node* pre;
		pre = head;
		for (int i = 0; i < index - 1; i++)
		{
			pre = pre->link;
		}
		Node* newnode = creat_node(item);
		newnode->link = pre->link;
		pre->link = newnode;
	}
}

void delete_first(Node** head)
{
	Node* tmp = *head;
	*head = tmp->link;
	free(tmp);
}

void delete_index(Node* head, int index)
{
	if (index == 0) delete_first(&head);
	else if (index >= get_length(head) || index < 0)error("인덱스 오류");
	else {
		Node* pre;
		pre = head;
		for (int i = 0; i < index - 1; i++)
		{
			pre = pre->link;
		}
		Node* removed = pre->link;
		pre->link = removed->link;
		free(removed);		
	}
}

void print_list(Node* head)
{
	for (Node* p = head; p != NULL; p = p->link)
	{
		printf("%d > ", p->data);
	}
	printf("NULL \n");
}

element get_index(Node* head, int index)
{
	if (index >= get_length(head) || index < 0) error("인덱스 오류");
	Node* tmp = head;
	for (int i = 0; i < index; i++) tmp = tmp->link;
	return tmp->data;
}

int get_length(Node* head)
{
	int len = 0;
	for (Node* n = head; n != NULL; n = n->link)len++;
	return len;
}

int is_empty(Node* head)
{
	return head == NULL;
}

void error(char* msg)
{
	printf("%s\n", msg);
	exit(1);
}

