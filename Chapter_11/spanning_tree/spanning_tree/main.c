#include <stdio.h>
#include "../../../Chapter_10/graph/adj_mat/adj_mat.h"

void sp_tree(Graph* g, int v);

int main(void)
{
	Graph* g = NULL;
	g = init(g);
	for (int i = 0; i < 5; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 1, 4);
	insert_edge(g, 3, 4);
	printf("신장 트리 : ");
	sp_tree(g, 0);
}

void sp_tree(Graph* g, int v)
{
	visited[v] = 1;
	for (int i = 0; i < g->n; i++) {
		if (g->adj_mat[v][i] == 1) {
			if (!visited[i]) {
				visited[i] = 1;
				printf("(%d, %d), ", v, i);
				sp_tree(g, i);
			}
		}
	}
}