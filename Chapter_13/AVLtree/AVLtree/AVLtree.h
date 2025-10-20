#ifndef AVLTREE_H
#define AVLTREE_H

typedef struct AVLnode
{
	int key;
	struct AVLnode* left;
	struct AVLnode* right;
}AVLnode;

int get_height(AVLnode* node);
int get_balance(AVLnode* node);
AVLnode* turn_left(AVLnode* parent);
AVLnode* turn_right(AVLnode* parent);
AVLnode* create_node(int key);
AVLnode* insert_node(AVLnode* node, int key);
void preorder(AVLnode* node);

#endif // !AVLTREE_H
