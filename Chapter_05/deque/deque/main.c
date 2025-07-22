#include <stdio.h>
#include "deque.h"

int main(void)
{
	deque d;
	init_deque(&d);

	insert_front(&d, 4);
	insert_front(&d, 1);
	insert_rear(&d, 2);
	insert_rear(&d, 3);

	
	return 0;
}