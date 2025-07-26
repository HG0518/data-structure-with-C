#include <stdio.h>
#include <math.h>
#include "../../LinkedListType/LinkedListType/LinkedListType.h"

int get_max(Header* header);
int get_min(Header* header);
#define MAX pow(2,31)-1
#define MIN -pow(2,31)

int main(void)
{
	Header* header = creat_header();
	header = insert_last(header, 10);
	header = insert_last(header, 30);
	header = insert_last(header, 20);
	header = insert_last(header, 40);
	print_list(header);
	printf("최소값 : %d, 최대값 : %d\n", get_min(header), get_max(header));
	
	return 0;
}

int get_max(Header* header)
{
	int max = MIN;
	for (Node* p = header->head; p != NULL; p = p->link)
		if (p->data > max)max = p->data;
	return max;
}

int get_min(Header* header)
{
	int min = MAX;
	for (Node* p = header->head; p != NULL; p = p->link)
		if (p->data < min)min = p->data;
	return min;
}