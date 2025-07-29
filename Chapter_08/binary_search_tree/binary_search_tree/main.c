#include <stdio.h>
#include "binary_search_tree.h"

int main(void)
{
	Node* root = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	printf("이진 탐색 트리 중위 순회 결과 \n");
	inorder(root);
	printf("\n");
	if (search_node(root, 30) != NULL) printf("30 발견 성공\n");
	else printf("발견 실패\n");

	printf("\n\n");

	root = delete_node(root, 30);
	printf("이진 탐색 트리 중위 순회 결과 \n");
	inorder(root);
	printf("\n");
	if (search_node(root, 30) != NULL) printf("30 발견 성공\n");
	else printf("발견 실패\n");


}