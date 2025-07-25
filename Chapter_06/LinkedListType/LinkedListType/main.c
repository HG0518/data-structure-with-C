#include <stdio.h>
#include "LinkedListType.h"

int main(void)
{
	Header* header = creat_header();							print_list(header);
	header = insert_first(header, 0);							print_list(header);
	header = insert_index(header, 1, 10);						print_list(header);
	header = insert_last(header, 20);							print_list(header);

	printf("index = 2 데이터값 : %d\n", get_index(header, 2));
	header = reverse(header);									print_list(header);

	header = delete_index(header, 1);							print_list(header);
	header = delete_last(header);								print_list(header);
	header = delete_first(header);								print_list(header);

	if (is_empty(header)) printf("리스트가 비었습니다.\n");


	return 0;
}