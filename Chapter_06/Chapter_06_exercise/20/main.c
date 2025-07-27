#include <stdio.h>
#include <math.h>
#include "../../LinkedListType/LinkedListType/LinkedListType.h"

void insert_co_ex(Header* header, int coef, int expon);
void add_poly(Header* result, Header* a, Header* b);
void print_poly(Header* header);
int eval_poly(Header* header, int x);

int main(void)
{
	Header* a = creat_header();
	Header* b = creat_header();
	Header* c = creat_header();
	element item;

	
	insert_co_ex(a, 3, 6);
	insert_co_ex(a, 7, 3);
	insert_co_ex(a, 2, 2);
	insert_co_ex(a, 9, 0);

	insert_co_ex(b, -2, 6);
	insert_co_ex(b, -4, 4);
	insert_co_ex(b, 6, 2);
	insert_co_ex(b, 6, 1);
	insert_co_ex(b, 1, 0);

	print_poly(a);
	print_poly(b);

	add_poly(c, a, b);
	print_poly(c);
	int x = 0;
	printf("x=%d일 때 다항식의 값은 %d입니다.\n", x, eval_poly(c, x));

	free(a);
	free(b);
	free(c);
}

void insert_co_ex(Header* header, int coef, int expon)
{
	element data;
	data.coef = coef;
	data.expon = expon;
	header = insert_last(header, data);
}

void add_poly(Header* result, Header* poly1, Header* poly2)
{
	Node* a = poly1->head;
	Node* b = poly2->head;
	int sum;

	while (a && b)
	{
		if (a->data.expon == b->data.expon)
		{
			sum = a->data.coef + b->data.coef;
			if (sum != 0) insert_co_ex(result, sum, a->data.expon);
			a = a->link;
			b = b->link;
		}

		else if (a->data.expon > b->data.expon)
		{
			insert_co_ex(result, a->data.coef, a->data.expon);
			a = a->link;
		}

		else {
			insert_co_ex(result, b->data.coef, b->data.expon);
			b = b->link;
		}
	}

	for (; a != NULL; a = a->link) insert_co_ex(result, a->data.coef, a->data.expon);
	for (; b != NULL; b = b->link) insert_co_ex(result, b->data.coef, b->data.expon);
}

void print_poly(Header* header)
{
	Node* p = header->head;

	for (; p; p = p->link) printf("%d^%d + ",p->data.coef,p->data.expon);
	printf("\n");
}

int eval_poly(Header* header, int x)
{
	Node* p = header->head;
	int result = 0;
	for (; p; p = p->link) 
		result += p->data.coef * pow(x, p->data.expon);
	return result;
}


