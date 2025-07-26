#include <stdio.h>
#include "../../LinkedListType/LinkedListType/LinkedListType.h"

Header* delete_odd(Header* header);

int main(void)
{
	Header* header = creat_header();
	header = insert_last(header, 10);
	header = insert_last(header, 30);
	header = insert_last(header, 20);
	header = insert_last(header, 40);
	header = insert_last(header, 50);
	print_list(header);
	header = delete_odd(header);
	print_list(header);


	return 0;
}

Header* delete_odd(Header* header)
{
	Node* p = header->head;
	Node* deleted;
	Node* pre = p;
	int n = header->size;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			if (i == 0) {
				delete_first(header);
				p = header->head;
				printf("첫번째 항 삭제\n");
			}
			else if (i == n - 1) {
				delete_last(header);
				printf("마지막 항 삭제\n");
			}
			else {
				deleted = p;
				pre->link = deleted->link;
				p = p->link;
				free(deleted);
				header->size--;
				printf("%d째 항 삭제\n",i);
			}
		}
		else {
			pre = p;
			p = p->link;
		}
	}
	return header;
}
