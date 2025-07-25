#include <stdio.h>
#include "LinkedListType.h"

int main(void)
{
	Node* head = creat_node(10);					print_list(head);
	insert_first(&head, 0);							print_list(head);
	insert_index(head, 2, 20);						print_list(head);

	printf("리스트 길이 : %d\n", get_length(head));
	printf("index = 2 데이터값 : %d\n", get_index(head, 2));
	head = reverse(head);							print_list(head);

	delete_index(head, 2);							print_list(head);
	delete_first(&head);							print_list(head);
	delete_first(&head);							print_list(head);

	if (is_empty(head)) printf("리스트가 비었습니다.\n");


	return 0;
}