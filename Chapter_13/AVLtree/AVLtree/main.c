#include <stdio.h>
#include "AVLtree.h"

int main(void)
{
	AVLnode* root = NULL;

	root = insert_node(root, 10);
	root = insert_node(root, 20);
	root = insert_node(root, 30);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 29);



	printf("전위 순회 결과\n");
	preorder(root);

	return 0;
}