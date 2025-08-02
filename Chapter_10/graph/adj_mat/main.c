#include <stdio.h>
#include "adj_mat.h"

int main(void)
{
	Graph* g = NULL;
	g = init(g);
	for (int i = 0; i < 4; i++) insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);

	print_adj_mat(g);
	printf("정점 2의 차수는 %d입니다.\n", get_degree(g, 2));
	g = free_g(g);
	return 0;
}