#include <stdio.h>
#include "topo.h"

int main(void)
{
	Graph g;
	init_graph(&g);
	g.n = 6;
	insert_edge(&g, 0, 2);
	insert_edge(&g, 0, 3);
	insert_edge(&g, 1, 3);
	insert_edge(&g, 1, 4);
	insert_edge(&g, 2, 3);
	insert_edge(&g, 2, 5);
	insert_edge(&g, 3, 5);
	insert_edge(&g, 4, 5);

	topo_sort(&g);
	
	return 0;
}