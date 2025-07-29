#include <stdio.h>
#include "binary_tree.h"

Node n9 = { 9, NULL, NULL };
Node n8 = { 8, NULL, NULL };
Node n1 = { 1, &n8, NULL };
Node n2 = { 2, NULL, NULL };
Node n3 = { 3, NULL, &n9 };
Node n4 = { 4, NULL, NULL };
Node n5 = { 5, &n1, &n2 };
Node n6 = { 6, &n3, &n4 };
Node n7 = { 7, &n5, &n6 };

Node* root1 = &n7;

int main(void)
{
	printf("%d\n", getHeight(root1));
	printf("%d\n", isBalanced(root1));	
}