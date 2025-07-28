#include <stdio.h>
#include <stdlib.h>
#include "Circular_linked_list.h"

Node* insert_first(Node* head, element item)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL) error("NULL값 할당");
	p->data = item;
	if (is_empty(head))
	{
		head = p;
		p->link = head;
	}
	else
	{
		p->link = head->link;
		head->link = p;
	}
	return head;
}

Node* insert_last(Node* head, element item)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL) error("NULL값 할당");
	p->data = item;
	if (is_empty(head))
	{
		head = p;
		p->link = head;
	}
	else
	{
		p->link = head->link;
		head->link = p;
		head = p;
	}
	return head;
}

Node* delete_first(Node* head)
{
	if (is_empty(head))error("리스트가 비어있습니다.");
	if (get_length(head) == 1)
	{
		free(head);
		head = NULL;
		return head;
	}
	Node* deleted = head->link;
	head->link = deleted->link;
	free(deleted);
	return head;
}

Node* delete_last(Node* head)
{
	if (is_empty(head))error("리스트가 비어있습니다.");
	if (get_length(head) == 1)
	{
		free(head);
		head = NULL;
		return head;
	}
	Node* deleted = head;
	Node* pre = head->link;
	for (; pre->link != head; pre = pre->link);
	pre->link = head->link;
	head = pre;
	free(deleted);
	return head;
}

void print_list(Node* head)
{
	if (head == NULL) {
		printf("NULL\n");
		return;
	}	
	Node* p = head;
	do{
		p = p->link;
		printf("%d > ", p->data);
	} while (p != head);
	printf("NULL\n");
	
}

int get_length(Node* head)
{
	if (head->link == head) return 1;
	int count = 0;
	Node* p = head->link;
	do {
		p = p->link;
		count++;
	} while (p != head);
	count++;
	return count;
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