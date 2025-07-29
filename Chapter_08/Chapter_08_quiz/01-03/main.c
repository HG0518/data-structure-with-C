#include <stdio.h>

typedef int element;
typedef struct Node {
	element data;
	struct Node* left, * right;
}Node;

int get_node_count(Node* root);
int get_height(Node* root);
int get_leaf_count(Node* root);
int get_nonleaf_count(Node* root);
int is_equal(Node* r1, Node* r2);
int max(int a, int b);

Node n9 = { 9, NULL, NULL };
Node n10 = { 10, NULL, NULL };
Node n8 = { 8, NULL, &n10 };
Node n1 = { 1, &n8, NULL };
Node n2 = { 2, NULL, NULL };
Node n3 = { 3, NULL, &n9 };
Node n4 = { 4, NULL, NULL };
Node n5 = { 5, &n1, &n2 };
Node n6 = { 6, &n3, &n4 };
Node n7 = { 7, &n5, &n6 };

Node* root1 = &n7;

Node m9 = { 9, NULL, 3 };
Node m10 = { 10, NULL, NULL };
Node m8 = { 8, NULL, &m10 };
Node m1 = { 1, &m8, NULL };
Node m2 = { 2, NULL, NULL };
Node m3 = { 3, NULL, &m9 };
Node m4 = { 4, NULL, NULL };
Node m5 = { 5, &m1, &m2 };
Node m6 = { 6, &m3, &m4 };
Node m7 = { 7, &m5, &m6 };

Node* root2 = &m7;


int main(void)
{
	printf("주어진 트리의 노드 개수는 %d개 입니다.\n", get_node_count(root1));
	printf("주어진 트리의 높이는 %d 입니다.\n", get_height(root1));
	printf("주어진 트리의 단말노드 개수는 %d개 입니다.\n", get_leaf_count(root1));
	printf("주어진 트리의 비단말노드 개수는 %d개 입니다.\n", get_nonleaf_count(root1));

	if (is_equal(root1, root2)) printf("두 노드는 같습니다.\n");
	else printf("두 노드는 다릅니다.\n");

	return 0;
}

int get_node_count(Node* root)
{
	int count = 0;
	if (root == NULL) return 0;
	count = get_node_count(root->left) + 1 + get_node_count(root->right);
	return count;
}

int get_height(Node* root)
{
	int height = 0;
	if (root == NULL) return 0;
	height = 1 + max(get_height(root->left), get_height(root->right));
	return height;
}

int get_leaf_count(Node* root)
{
	int count = 0;
	if (root != NULL) {
		if (!(root->left || root->right)) return 1;
		count = get_leaf_count(root->left) + get_leaf_count(root->right);
	}
	return count;
}

int get_nonleaf_count(Node* root)
{
	int count = 0;
	if (root == NULL)return 0;
	if (!(root->left || root->right)) return 0;
	count = 1 + get_nonleaf_count(root->left) + get_nonleaf_count(root->right);
	return count;
}

int is_equal(Node* r1, Node* r2)
{
	if (r1 == NULL && r2 == NULL)return 1;
	if (r1 == NULL || r2 == NULL)return 0;
	if (r1->data != r2->data)return 0;
	
	return is_equal(r1->left, r2->left) && is_equal(r1->right, r2->right);
}

int max(int a, int b)
{
	int max = a > b ? a : b;
	return max;
}
