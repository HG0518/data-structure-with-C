#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"

#define LIST_SIZE 10

void init_list(Linked_list* list)
{
	list->n = 0;
	list->node = NULL;

	srand(time(NULL));
	for (int i = 0; i < LIST_SIZE; i++)
	{
		int data = rand() % 100;
		insert_node(list, data);
	}
}

void insert_node(Linked_list* list, int data)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL)
	{
		fprintf(stderr, "NULL값 할당 오류\n");
		exit(1);
	}
	tmp->key = data;
	tmp->link = list->node;
	list->node = tmp;
	list->n++;
}

Node* delete_node(Linked_list* list)
{
	if (list->node == NULL) return NULL;
	Node* deleted;
	deleted = list->node;
	list->node = list->node->link;
	return deleted;
}

void swap_list(Node* front, Node* back, Node* pre)
{
	front->link = back->link;
	back->link = front;
	pre->link = back;
}

void print_list(Linked_list* list)
{
	Node* p;
	for (p = list->node; p != NULL; p = p->link)
		printf("%d ", p->key);
	printf("\n");
}

void insertion_sort(Linked_list* list)
{
	init_list(list);
	print_list(list);
	Node* sorted_list = NULL;
	Node* tmp, * p, *pre;
	pre = NULL;
	tmp = delete_node(list);
	while(tmp!=NULL)
	{
		for (p=sorted_list; p != NULL && p->key < tmp->key; p = p->link)
			pre = p;
		tmp->link = p;
		if (pre == NULL) sorted_list = tmp;
		else pre->link = tmp;
		tmp = delete_node(list);		
	}
	list->node = sorted_list;
	print_list(list);
}