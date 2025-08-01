#include <stdio.h>
#include "array.h"

int main(void) {
	ArrayType* q = NULL;
	q = create(q);
	init(q);
	element e1 = { 10 };
	element e2 = { 20 };
	element e3 = { 30 };
	insert(q, e1);
	insert(q, e2);
	insert(q, e3);

	element e4;
	e4 = find_max(q);
	printf("최대값 : %d\n", e4.key);

	int n = q->size;
	for (int i = 0; i < n; i++)
	{
		e4 = delete_max(q);
		printf("최대값 : %d\n", e4.key);
	}

	e4 = delete_max(q);

}