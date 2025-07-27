#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int c;
	int r;
	int num;
}element;

typedef struct Node {
	element data;
	struct Node* link;
}Node;

//0이 아닌 항의 행, 열, 숫자만 연결리스트에 입력한다.

int is_empty(Node* matrix);
int get_maxc(Node* matrix);
int get_maxr(Node* matrix);
int get_count(Node* matrix);
Node* insert(Node* matrix, element item);
Node* delete_item(Node* matrix, element item);
Node* delete_pos(Node* matrix, int c, int r);
Node* clear(Node* matrix);
int is_in_item(Node* matrix, element item);
element get_item(Node* matrix, int c, int r);


int main(void)
{

}

