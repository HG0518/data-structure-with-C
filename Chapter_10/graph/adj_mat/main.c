#include <stdio.h>
#include "adj_mat.h"

int main(void)
{
	Graph* g = NULL;
	g = init(g);

	for (int i = 0; i < 6; i++) insert_vertex(g, i);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 4);
	insert_edge(g, 1, 5);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 2, 5);
	insert_edge(g, 3, 5);
	insert_edge(g, 4, 5);

	printf("너비 우선 탐색\n");
	bfs_mat(g, 0);
	printf("\n");

	g = free_g(g);
	return 0;
}