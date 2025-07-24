#include <stdio.h>
#include "ArrayListType.h"

int main(void)
{
	ArrayListType list;
	init(&list);

	insert(&list, 0, 10);		print_list(&list);
	insert_first(&list, 20);	print_list(&list);
	insert_last(&list, 30);		print_list(&list);
	printf("%d번째 데이터 값 : %d\n", 3, get_entry(&list, 2));

	delete_data(&list, 2);		print_list(&list);
	printf("리스트 원소 개수 : %d개\n", get_length(&list));

	replace(&list, 0, 40);		print_list(&list);
	clear(&list);				print_list(&list);
	printf("리스트 원소 개수 : %d개\n", get_length(&list));

	free_list(&list);

	return 0;
}