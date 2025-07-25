#include <stdio.h>
#include "../../LinkedListType/LinkedListType/LinkedListType.h"

int sum(Header* header);
int search(Header* header, element data);

int main(void)
{
	int n;
	printf("노드의 개수 : ");
	scanf("%d", &n);

	Header* header = creat_header();

	element item;
	for (int i = 0; i < n; i++)
	{
		printf("노드 #%d의 데이터 : ", i + 1);
		scanf("%d", &item);
		header = insert_last(header, item);
	}

	printf("생성형 연결 리스트 : ");
	print_list(header);

	printf("연결 리스트 노드의 개수 = %d\n", header->size);
	printf("연결 리스트의 데이터 합 : %d\n", sum(header));
	printf("탐색할 값을 입력하시오 : ");
	scanf("%d", &item);
	printf("%d는 연결 리스트에서 %d번 나타납니다.\n", item, search(header, item));
	delete_item(&header, item);
	print_list(header);

	return 0;
}

int sum(Header* header)
{
	int result = 0;
	for (Node* p = header->head; p != NULL; p = p->link) result += p->data;
	return result;
}

int search(Header* header, element data)
{
	int count = 0;
	for (Node* p = header->head; p != NULL; p = p->link)
	{
		if (p->data == data) count++;
	}
	return count;
}
