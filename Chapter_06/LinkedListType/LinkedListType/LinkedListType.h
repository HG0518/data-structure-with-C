#ifndef LINKEDLISTTYPE_H
#define LINKEDLISTTYPE_H

typedef int element;

typedef struct Node
{
	element data;
	struct Node* link;
}Node;

typedef struct
{
	Node* head;
	Node* tail;
	int size;
}Header;


Node* creat_node(element item);
Header* creat_header();
Header* insert_first(Header* header, element item);
Header* insert_index(Header* header, int index, element item);
Header* insert_last(Header* header, element item);
Header* delete_first(Header* header);
Header* delete_index(Header* header, int index);
Header* delete_last(Header* header);
void print_list(Header* header);
element get_index(Header* header, int index);
int is_empty(Header* header);
void error(char* msg);
Header* reverse(Header* header);
void delete_item(Header** header, element item);



#endif // !LINKEDLISTTYPE_H

