#include <stdio.h>
#include <stdlib.h>
#include "LinkedListType.h"

Node* creat_node(element item)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL) error("NULL값 할당");
	newnode->data = item;
	newnode->link = NULL;
	return newnode;
}

Header* creat_header()
{
	Header* newheader = (Header*)malloc(sizeof(Header));
	if (newheader == NULL) error("NULL값 할당");
	newheader->head = newheader->tail = NULL;
	newheader->size = 0;
	return newheader;
}

Header* insert_first(Header* header, element item)
{
	Node* newnode = creat_node(item);
	newnode->link = header->head;
	header->head = newnode;
	if (is_empty(header))header->tail = newnode;
	header->size++;
	return header;
}

Header* insert_index(Header* header, int index, element item)
{
	if (index == 0) return insert_first(header, item);
	else if (index == header->size) return insert_last(header, item);
	else if (index > header->size || index < 0)error("인덱스 오류");
	else {
		Node* pre;
		pre = header->head;
		for (int i = 0; i < index - 1; i++)
		{
			pre = pre->link;
		}
		Node* newnode = creat_node(item);
		newnode->link = pre->link;
		pre->link = newnode;
		header->size++;
		return header;
	}
}

Header* insert_last(Header* header, element item)
{
	Node* newnode = creat_node(item);
	header->tail->link = newnode;
	header->tail = newnode;
	if (is_empty(header)) header->head = newnode;
	header->size++;
	return header;
}

Header* delete_first(Header* header)
{
	if (is_empty(header)) error("리스트가 공백상태입니다.");
	Node* tmp = header->head;
	header->head = tmp->link;
	header->size--;
	if (is_empty(header)) header->tail == NULL;
	free(tmp);
	return header;
}

Header* delete_index(Header* header, int index)
{
	if (is_empty(header)) error("리스트가 공백상태입니다.");
	else if (index == 0) return delete_first(header);
	else if (index >= header->size || index < 0)error("인덱스 오류");
	else {
		Node* pre;
		pre = header->head;
		for (int i = 0; i < index - 1; i++)
		{
			pre = pre->link;
		}
		Node* removed = pre->link;
		pre->link = removed->link;
		if (index == header->size) header->tail = pre;
		header->size--;
		free(removed);
		return header;
	}
}

Header* delete_last(Header* header)
{
	header = delete_index(header, header->size - 1);
	if (is_empty(header)) header->head = header->tail == NULL;
	return header;
}

void print_list(Header* header)
{
	for (Node* p = header->head; p != NULL; p = p->link)
	{
		printf("%d > ", p->data);
	}
	printf("NULL \n");
}

element get_index(Header* header, int index)
{
	if (index >= header->size || index < 0) error("인덱스 오류");
	Node* tmp = header->head;
	for (int i = 0; i < index; i++) tmp = tmp->link;
	return tmp->data;
}

int is_empty(Header* header)
{
	return header->size == 0;
}

void error(char* msg)
{
	printf("%s\n", msg);
	exit(1);
}

Header* reverse(Header* header)
{
	Node* p, * q, * r;
	p = header->head;
	r = NULL;
	while (p != NULL)
	{
		q = p;
		p = p->link;
		q->link = r;
		r = q;
	}
	p = header->head;
	header->head = header->tail;
	header->tail = header->head;
	return header;
}


