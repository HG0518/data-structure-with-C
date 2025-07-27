#include <stdio.h>
#include "../../LinkedListType/LinkedListType/LinkedListType.h"

void split(Header** a, Header** b, Header* c);

int main(void) {
	Header* a = creat_header();
	Header* b = creat_header();
	Header* c = creat_header();

	c = insert_last(c, 10);
	c = insert_last(c, 20);
	c = insert_last(c, 30);
	c = insert_last(c, 40);
	c = insert_last(c, 50);
	c = insert_last(c, 60);
	c = insert_last(c, 70);

	print_list(c);
	split(&a, &b, c);
	print_list(a);
	print_list(b);
	print_list(c);
}

void split(Header** a, Header** b, Header* c)
{
	int n = c->size;
	Node* p = c->head;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0) *a = insert_last(*a, p->data);
		else *b = insert_last(*b, p->data);
		p = p->link;
	}
}
