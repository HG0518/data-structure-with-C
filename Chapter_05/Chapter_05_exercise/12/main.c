#include <stdio.h>
#include <stdlib.h>
#include "../../deque/deque/deque.h"

#define CPU_COUNT 3

void a_steal(deque** d);

int main(void)
{
	return 0;
}

void a_steal(deque** d)
{
	int i, j, task;
	for (i = 0; i < get_count; i++) {
		if (is_empty(d[i]))
		{
			for (j = 0; j < CPU_COUNT; j++)
			{
				if (get_count(d[j]) > 1) insert_rear(d[i], delete_rear(d[j]));
			}
		}
	}
}

