#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

Node* create(Node* q, element item)
{
	q = (Node*)malloc(sizeof(Node));
	if (q == NULL) error("NULL값 할당");
	q->item = item;
	q->link = NULL;
	return q;
}

void init(Node* q)
{
	q->link = NULL;
}

Node* insert(Node* q, element item)
{
	Node* tmp = NULL;
	tmp = create(tmp, item);
	if (q == NULL) {
		q = tmp;
		return tmp;
	}
	tmp->link = q->link;
	q->link = tmp;
	return q;
}

element delete_max(Node** q)
{
	if (is_empty(*q))error("리스트가 공백상태입니다.\n");
	element item;
	int max;
	Node* p = *q;
	Node* pre = NULL;
	max = p->item.key;
	for (; p->link != NULL; p = p->link)
	{
		if (p->link->item.key > max) {
			max = p->link->item.key;
			pre = p;
		}
	}
	if (pre == NULL) {
		p = *q;
		*q = (*q)->link;
	}
	else {
		p = pre->link;
		pre->link = p->link;
	}
	item = p->item;
	free(p);
	return item;
}

element find_max(Node* q)
{
	if (is_empty(q))error("리스트가 공백상태입니다.\n");
	element item;
	int max;
	Node* p = q;
	max = p->item.key;
	for (; p != NULL; p = p->link)
	{
		if (p->item.key > max) {
			max = p->item.key;
			item = p->item;
		}

	}
	free(p);
	return item;
}

int is_empty(Node* q)
{
	return q == NULL;
}

void error(char* msg)
{
	printf("%s\n", msg);
	exit(1);
}