#include "../../AVLtree/AVLtree/AVLtree.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ITERATION 100
void compare_h(float height, int log_n);
void set_avl(int n);
void start();
int cal_log(int n);

int main(void)
{
	start();
}

void compare_h(float height, int log_n)
{
	printf("평균 높이 : %lf\n", height);
	printf("log값 : %d\n\n", log_n);
}

void set_avl(int n)
{
	printf("n = %d\n", n);

	float avg_height = 0;
	AVLnode* root = NULL;
	srand(time(NULL));

	for(int j=0;j<ITERATION;j++)
	{
		for (int i = 0; i < n; i++)
		{
			int random_N = rand() % (n + 1);
			root = insert_node(root, random_N);
		}
		int height = get_height(root);
		avg_height += height;
		root = free_node(root);
	}
	avg_height /= (float)ITERATION;

	int log_n = cal_log(n);	
	compare_h(avg_height, log_n);
}

void start()
{
	set_avl(100);
	set_avl(500);
	set_avl(1000);
	set_avl(10000);
	set_avl(50000);
}

int cal_log(int n)
{
	return 2 * ceil(log2(n + 1));
}