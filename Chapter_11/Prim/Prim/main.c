#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICIES 100
#define INF 1000

typedef struct {
	int n;
	int weight[MAX_VERTICIES][MAX_VERTICIES];
}Graph;

int selected[MAX_VERTICIES];
int distance[MAX_VERTICIES];

void prim(Graph* g, int s);
int get_min_vertex(int n);

int main(void)
{
	Graph g = { 7,
		{{0,29,INF,INF,INF,10,INF},
		{29,0,16,INF,INF,INF,15},
		{INF,16,0,12,INF,INF,INF},
		{INF,INF,12,0,22,INF,18},
		{INF,INF,INF,22,0,27,25},
		{10,INF,INF,INF,27,0,INF},
		{INF,15,INF,18,25,INF,0}}
	};
	prim(&g, 0);
	return 0;
}

void prim(Graph* g, int s)
{
	int u, v;
	for (int i = 0; i < g->n; i++)
		distance[i] = INF;
	distance[s] = 0;
	
	for (int i = 0; i < g->n; i++)
	{
		u = get_min_vertex(g->n);
		selected[u] = 1;
		if (distance[u] == INF) return;
		printf("정점 %d 추가\n", u);

		for (int j = 0; j < g->n; j++) 
			if (!selected[j] && g->weight[u][j] < distance[j])
				distance[j] = g->weight[u][j];
	}
}

int get_min_vertex(int n)
{
	int v;
	for (int i = 0; i < n; i++)
		if (!selected[i]) {
			v = i;
			break;
		}
	for (int i = 0; i < n; i++)
		if (!selected[i] && distance[i] < distance[v])v = i;
	return v;
}