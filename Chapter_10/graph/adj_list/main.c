#include <stdio.h>
#include "adj_list.h"

int main(void)
{
	Graph* g = NULL;
	g = init_graph(g);

	for (int i = 0; i < 4; i++) insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 1, 0);
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 0);
	insert_edge(g, 0, 3);
	insert_edge(g, 3, 0);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 3, 2);
	print_adj_list(g);

	printf("정점 1의 차수는 %d입니다.\n", get_degree(g, 1));
	g = free_graph(g);
	return 0;
}