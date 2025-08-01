#include <stdio.h>
#include "LinkedList.h"

int main(void) {
	Node* q = NULL;
	element e1 = { 10 };
	element e2 = { 20 };
	element e3 = { 30 };
	q = insert(q, e1);
	q = insert(q, e2);
	q = insert(q, e3);

	element e4;
	e4 = find_max(q);
	printf("최대값 : %d\n", e4.key);

	while (1)
	{
		e4 = delete_max(&q);
		printf("최대값 : %d\n", e4.key);
	}

}