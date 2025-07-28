#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"

Node* init(Node* head)
{
	head = (Node*)malloc(sizeof(Node));
	if (head == NULL)error("NULL값 할당");
	head->llink = head;
	head->rlink = head;
	return head;
}

void insert_first(Node* before, element item)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = item;
	p->llink = before;
	p->rlink = before->rlink;
	before->rlink->llink = p;
	before->rlink = p;
}

void delete_removed(Node* head, Node* removed)
{
	if (removed == head) return;
	if (is_empty(head)) error("리스트가 비어있습니다.");
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

void print_list(Node* head)
{
	if (is_empty(head))
	{
		printf("NULL\n");
		return;
	}
	Node* p;
	for (p = head->rlink; p != head; p = p->rlink)
		printf("%d ", p->data);
	printf("\n");
}

void error(char* msg)
{
	printf("%s", msg);
	exit(1);
}
int is_empty(Node* head)
{
	return head->llink == head;
}