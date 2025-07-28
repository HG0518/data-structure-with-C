#include <stdio.h>
#include "Circular_linked_list.h"

int main(void)
{
	Node* p = NULL;
	p = insert_first(p, 10);	print_list(p);
	p = insert_first(p, 20);	print_list(p);
	p = insert_last(p, 30);		print_list(p);
	
	printf("리스트의 길이는 %d입니다.\n", get_length(p));

	p = delete_first(p);		print_list(p);
	p = delete_last(p);			print_list(p);
	p = delete_last(p);			print_list(p);
	p = delete_last(p);			print_list(p);

	return 0;
}