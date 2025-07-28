#include <stdio.h>
#include "../../Circular_linked_list/Circular_linked_list/Circular_linked_list.h"

Node* search(Node* head, element item);

int main(void)
{
	Node* head = NULL;
	head = insert_first(head, 10);
	head = insert_first(head, 20);
	head = insert_first(head, 30);
	head = insert_first(head, 40);
	print_list(head);

	Node* p = search(head, 30);
	printf("%d\n", p->data);
	printf("리스트에 저장된 데이터는 %d개입니다.\n", get_length(head));

	
	return 0;
}

Node* search(Node* head, element item)
{
	if (is_empty(head))error("노드가 비어있습니다.");
	
	Node* p=head;
	do{
		p = p->link;
		if (p->data == item) return p;
	} while (p != head);

	error("해당 item을 가지고 있는 노드가 없습니다.");
}