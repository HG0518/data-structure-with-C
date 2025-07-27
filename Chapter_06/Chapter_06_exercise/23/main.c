#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
	element data;
	struct Node* link;
}Node;

Node* create_node(element item);
Node* add(Node* list, element item);
Node* delete(Node* list, element item);
Node* clear(Node* list);
int is_in_list(Node* list, element item);
int get_length(Node* list);
int is_empty(Node* list);
void error(char* msg);
void display(Node* p);

int main(void)
{
	Node* list = NULL;
	list = add(list, 10);
	list = add(list, 10);
	list = add(list, 30);
	list = add(list, 30);
	list = add(list, 20);
	list = add(list, 40);
	list = delete(list, 240);
	display(list);
	printf("리스트 원소의 개수는 %d개 입니다.\n", get_length(list));
}

Node* create_node(element data)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL) error("NULL할당");
	p->data = data;
	p->link = NULL;
	return p;
}

Node* add(Node* arr, element data)
{
	if (arr == NULL) return arr = create_node(data);
	else
	{
		Node* p = arr;
		Node* q = create_node(data);

		while (p->link != NULL)
		{
			if (p->link->data > data)
			{
				q->link = p->link;
				p->link = q;
				return arr;
				break;
			}
			p = p->link;
		}
		q->link = p->link;
		p->link = q;
		return arr;
	}
}

Node* delete(Node* list, element item)
{
	if (!is_in_list(list, item))error("리스트안에 해당 숫자가 없습니다.");

	if (list->link == NULL)
	{
		free(list);
		list = NULL;
		return list;
	}

	Node* pre = list;
	Node* p = pre->link;
	Node* deleted;
	while (p->data <= item && p!=NULL)
	{
		if (p->data == item) 
		{
			pre->link = p->link;
			deleted = p;
			p = p->link;
			free(deleted);
		}

		else 
		{
			p = p->link;
			pre = pre->link;
		}
	}

	if (list->data == item)
	{
		deleted = list;
		list = list->link;
		free(deleted);
	}
	return list;

}

Node* clear(Node* list)
{
	if (is_empty(list))error("리스트가 이미 비어있습니다.");

	if (list->link == NULL)
	{
		free(list);
		list = NULL;
		return list;
	}

	Node* pre = list;
	Node* p = pre->link;
	Node* deleted;
	while (p->link != NULL)
	{
		pre->link = p->link;
		deleted = p;
		p = p->link;
		free(deleted);
	}
	free(p);
	list = NULL;
	return list;
}

int is_in_list(Node* list, element item)
{
	int count = 0;
	Node* p = list;
	for (; p; p = p->link)
		if (p->data == item) count++;
	return count;
}


int get_length(Node* list)
{
	int count = 0;
	Node* p = list;
	for (; p; p = p->link) count++;
	return count;
}

int is_empty(Node* list)
{
	return list == NULL;
}

void error(char* msg)
{
	printf("%s\n", msg);
	exit(1);
}

void display(Node* p)
{
	for (; p; p = p->link)
		printf("%d > ", p->data);
	printf("NULL\n");
}

