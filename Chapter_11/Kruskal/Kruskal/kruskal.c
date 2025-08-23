#include <stdio.h>
#include <stdlib.h>
#include "kruskal.h"

void set_init()
{
	for (int i = 0; i < MAX_VERTICES; i++)
	{
		parent[i] = -1;
	}
}

int set_find(int v)
{
	while (parent[v] != -1)
	{
		v = parent[v];
	}
	return v;
}

void set_union(int v1, int v2)
{
	int root1 = set_find(v1);
	int root2 = set_find(v2);
	if (root1 != root2)
		parent[root2] = root1;
}

Graph* graph_init(Graph* g)
{
	g = (Graph*)malloc(sizeof(Graph));
	if (g == NULL) error("NULL값 할당 오류");
	g->nedge = 0;
	g->nvertex = 0;
	for (int i = 0; i < 2 * MAX_VERTICES; i++)
	{
		g->edges[i].start = -1;
		g->edges[i].end = -1;
		g->edges[i].weight = INF;
	}
	return g;
}

void insert_edge(Graph* g, int start, int end, int weight)
{
	g->edges[g->nedge].start = start;
	g->edges[g->nedge].end = end;
	g->edges[g->nedge].weight = weight;
	g->nedge++;
}

int compare(const void* a, const void* b)
{
	Edge* x = (Edge*)a;
	Edge* y = (Edge*)b;
	return(x->weight - y->weight);
}

void kruskal(Graph* g)
{
	int edge_accepted = 0;
	int uset, vset;
	Edge e;
	int i = 0;

	set_init();
	qsort(g->edges, g->nedge, sizeof(Edge), compare);

	printf("Kruskal 최소 신장 트리 알고리즘\n");
	while (edge_accepted < g->nvertex - 1)
	{
		e = g->edges[i];
		uset = set_find(e.start);
		vset = set_find(e.end);
		if (uset != vset) {
			printf("간선 (%d, %d) %d 선택\n", e.start, e.end, e.weight);
			edge_accepted++;
			set_union(uset, vset);
		}
		i++;
	}
}

void error(char* msg)
{
	printf("%s", msg);
	exit(1);
}

Graph* free_g(Graph* g)
{
	free(g);
	return NULL;
}


