#include <stdio.h>
#include "heap.h"

int main(void)
{
	HeapType* h = NULL;
	h = create(h);
	init(h);
	element e1 = { 10 }, e2 = { 20 }, e3 = { 30 };

	insert(h, e1);
	insert(h, e2);
	insert(h, e3);
	display(h);

	for (int i = 0; i < 3; i++)
	{
		element e;
		e = delete_max(h);
		printf("최대값 : %d\n", e.key);
		display(h);
	}
}