#include <stdio.h>
#include "../../LinkedListType/LinkedListType/LinkedListType.h"

Header* alternate(Header* a, Header* b);

int main(void)
{
	Header* a = creat_header();
	a = insert_last(a, 10);
	a = insert_last(a, 30);
	a = insert_last(a, 50);
	a = insert_last(a, 70);
	a = insert_last(a, 90);
	print_list(a);

	Header* b = creat_header();
	b = insert_last(b, 20);
	b = insert_last(b, 40);
	b = insert_last(b, 60);
	b = insert_last(b, 80);
	print_list(b);

	Header* c = creat_header();
	c = alternate(a, b);
	print_list(c);

	return 0;
}

Header* alternate(Header* a, Header* b)
{
	Header* c = creat_header();
	c->head = a->head;

	Node* p = a->head;
	Node* q = a->head;
	Node* r = b->head;

	int n = a->size > b->size ? b->size : a->size;
	for (int i = 0; i < n - 1; i++)
	{
		p = p->link;
		q->link = r;
		r = r->link;
		q->link->link = p;
		q = p;
	}

	if (a->size > b->size) {
		p = p->link;
		q->link = r;
		r->link = p;
		c->tail = a->tail;
	}
	else {
		q->link = r;
		c->tail = b->tail;
	}

	c->size = a->size + b->size;
	return c;

}
