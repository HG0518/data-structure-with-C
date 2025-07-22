#ifndef DEQUE_H
#define DEQUE_H

#define MAX_DEQUE_SIZE 30

typedef int element;

typedef struct {
	element data[MAX_DEQUE_SIZE];
	int front, rear;
}deque;

void init_deque(deque* d);
int is_full(deque* d);
int is_empty(deque* d);
void error(char* message);
void insert_front(deque* d, element data);
void insert_rear(deque* d, element data);
element delete_front(deque* d);
element delete_rear(deque* d);
element get_front(deque* d);
element get_rear(deque* d);
int get_count(deque* d);

#endif
