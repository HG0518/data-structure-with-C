#include <stdio.h>
#include "../../LinkedListType/LinkedListType/LinkedListType.h"

Header* merge(Header* a, Header* b);

int main(void)
{
	Header* a = creat_header();
	a = insert_last(a, 10);
	a = insert_last(a, 20);
	a = insert_last(a, 30);
	a = insert_last(a, 70);
	a = insert_last(a, 90);
	print_list(a);

	Header* b = creat_header();
	b = insert_last(b, 40);
	b = insert_last(b, 60);
	b = insert_last(b, 70);
	b = insert_last(b, 80);
	print_list(b);

	Header* c = creat_header();
	c = merge(a, b);
	print_list(c);
}

Header* merge(Header* a, Header* b)
{
	Header* c = creat_header();
	c->head = a->head->data > b->head->data ? b->head : a->head;
	Node* p, * q, * r;
	p = a->head;
	q = b->head;
	r = c->head;
	int n = a->size + b->size;

	if (p->data > q->data)q = q->link;
	else p = p->link;

	for (int i = 0; i < n - 1; i++)
	{
		if (p == NULL) {
			r->link = q;
			c->tail = b->tail;
			break;
		}
		if (q == NULL) {
			r->link = p;
			c->tail = a->tail;
			break;
		}

		if (p->data > q->data)
		{
			r->link = q;
			q = q->link;
			r = r->link;
		}
		else
		{
			r->link = p;
			p = p->link;
			r = r->link;
		}
	}
	c->size = n;
	return c;
}
