#include <stdio.h>
#include "double_linked_list.h"

int main(void) 
{
	Node* head = NULL;
	head = init(head);
	printf("추가 단계\n");
	for (int i = 0; i < 5; i++)
	{
		insert_first(head, i);
		print_list(head);
	}

	printf("삭제 단계\n");
	for (int i = 0; i < 5; i++)
	{
		delete_removed(head, head->rlink);
		print_list(head);
	}
	free(head);
	return 0;
}