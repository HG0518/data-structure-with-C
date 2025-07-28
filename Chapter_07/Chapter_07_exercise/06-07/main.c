#include <stdio.h>
#include "../../Double_linked_list/Double_linked_list/double_linked_list.h"

void print_reverse(Node* head);
Node* search(Node* head, element item);

int main(void)
{
	Node* head = NULL;
	head = init(head);
	int n;
	element item;
	printf("데이터의 개수를 입력하시오 : ");
	scanf("%d", &n);

	Node* before = head;
	for (int i = 0; i < n; i++) {
		printf("노드 #%d의 데이터를 입력하시오 : ", i + 1);
		scanf("%d", &item);
		insert_first(before, item);
		before = before->rlink;
	}
	printf("데이터를 역순으로 출력 : ");
	print_reverse(head);
	Node* p = search(head, 8);
	printf("%d\n", p->data);
}

void print_reverse(Node* head)
{
	if (is_empty(head)) {
		printf("NULL\n");
		return;
	}
	Node* p;
	for (p = head->llink; p != head; p = p->llink)
		printf("%d ", p->data);
	printf("\n");
}

Node* search(Node* head, element item)
{
	if (is_empty(head))error("리스트가 비어있습니다.");
	Node* p = head;
	do {
		p = p->rlink;
		if (p->data == item) return p;
	} while (p != head);
	error("해당 item을 가지고 있는 노드가 없습니다.");
}