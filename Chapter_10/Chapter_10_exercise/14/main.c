#include <stdio.h>
#include "../../graph/adj_mat/adj_mat.h"

void get_bridge(Graph* g);
int get_dfs_count(Graph* g, int v);
void compare(Graph* g, int i, int j);

int main(void)
{
	Graph* g = NULL;
	g = init(g);
	g->n = 10;
	insert_edge(g, 0, 1);
	insert_edge(g, 1, 2);
	insert_edge(g, 1, 3);
	insert_edge(g, 2, 4);
	insert_edge(g, 3, 4);
	insert_edge(g, 3, 5);
	insert_edge(g, 5, 6);
	insert_edge(g, 5, 7);
	insert_edge(g, 6, 7);
	insert_edge(g, 7, 8);
	insert_edge(g, 7, 9);

	
	get_bridge(g);
}

void get_bridge(Graph* g)
{
	printf("브리지 : ");
	for (int i = 0; i < g->n; i++) {
		for (int j = i; j < g->n; j++) {
			if (g->adj_mat[i][j]) {
				compare(g, i, j);
			}
		}
	}
	printf("\n");
}

int get_dfs_count(Graph* g, int v)
{
	int count = 0;
	if (!visited[v]) {
		visited[v] = 1;
		for (int i = 0; i < g->n; i++) {
			if (g->adj_mat[v][i] && !visited[i]) {
				count += get_dfs_count(g, i);
			}
		}
		return 1 + count;
	}
	return count;
}

void compare(Graph* g, int i, int j) {
	int before, after;

	before = get_dfs_count(g, i);
	init_visited(visited);

	g->adj_mat[i][j] = 0;
	after = get_dfs_count(g, i);
	init_visited(visited);

	g->adj_mat[i][j] = 1;
	if (before != after) printf("(%d, %d), ", i, j);
}