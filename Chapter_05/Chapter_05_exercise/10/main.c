#include <stdio.h>
#include "../../deque/deque/deque.h"

int fib(int n, deque* d);

int main(void) {
	deque d;
	
	printf("%d\n", fib(2, &d));
	printf("%d\n", fib(3, &d));
	printf("%d\n", fib(4, &d));
	printf("%d\n", fib(5, &d));
	printf("%d\n", fib(6, &d));

	return 0;
}

int fib(int n, deque* d)
{
	init_deque(d);
	insert_rear(d, 0);
	insert_rear(d, 1);

	int result, i;
	for (i = 0; i < n; i++)
	{
		result = get_rear(d) + delete_front(d);
		insert_rear(d, result);
	}
	return result;
}
