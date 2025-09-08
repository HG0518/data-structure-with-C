#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICIES 100
#define INF 1000000

typedef struct {
	int n;
	int weight[MAX_VERTICIES][MAX_VERTICIES];
}Graph;

int distance[MAX_VERTICIES];
int selected[MAX_VERTICIES];
int path[MAX_VERTICIES + 1][MAX_VERTICIES + 1];

void dijkstra(Graph g, int start_v);
int get_minpos(int n);
void print_status(int n);
void init_path(Graph g, int u);
void make_path(int new_v, int old_v);
void print_path(int n);

int main(void)
{
	Graph g = { 7,
		{{0,7,INF,INF,3,10,INF},
		{7,0,4,10,2,6,INF},
		{INF,4,0,2,INF,INF,INF},
		{INF,10,2,0,11,9,4},
		{3,2,INF,11,0,INF,5},
		{10,6,INF,9,INF,0,INF},
		{INF,INF,INF,4,5,INF,0}}
	};
	dijkstra(g, 0);
	return 0;

}



void dijkstra(Graph g, int start_v)
{
	int u;
	for (int i = 0; i < g.n; i++)
	{
		distance[i] = g.weight[start_v][i];
		selected[i] = 0;
	}
	init_path(g, start_v);
	selected[start_v] = 1;

	for (int i = 0; i < g.n - 1; i++)
	{
		print_status(g.n);
		u = get_minpos(g.n);
		selected[u] = 1;
		for (int j = 0; j < g.n; j++)
			if (!selected[j] && distance[j] > distance[u] + g.weight[u][j])
			{
				distance[j] = distance[u] + g.weight[u][j];
				make_path(u, j);
			}
	}
	print_status(g.n);
	print_path(g.n);
}

int get_minpos(int n)
{
	int minpos;
	int min = INF;
	for (int i = 0; i < n; i++)
		if (!selected[i] && distance[i] < min) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

void print_status(int n)
{
	static int step = 1;
	printf("STEP %d\n", step++);
	printf("distance : ");
	for (int i = 0; i < n; i++)
	{
		if (distance[i] == INF) printf("%3c ", '*');
		else printf("%3d ", distance[i]);
	}
	printf("\n");

	printf("selected : ");
	for (int i = 0; i < n; i++)
		printf("%3d ", selected[i]);
	printf("\n\n");
}

void init_path(Graph g, int u)
{
	for (int i = 0; i < g.n + 1; i++)
		for (int j = 0; j < g.n + 1; j++)
		{
			if (j == 0)path[i][j] = u;
			else if (i != u && g.weight[u][i] != INF && j == 1) path[i][j] = i;
			else path[i][j] = -1;
		}
}

void make_path(int new_v, int old_v)
{
	int i;
	for (i = 0; path[new_v][i] != -1; i++)
		path[old_v][i] = path[new_v][i];
	path[old_v][i++] = old_v;
	path[old_v][i] = -1;
}

void print_path(int n)
{
	printf("각 정점까지의 최단경로\n");
	for (int i = 0; i < n; i++)
	{
		printf("정점 %d : ", i);
		for (int j = 0; path[i][j] != -1; j++)
			printf("정점 %d > ", path[i][j]);
		printf("\n");
	}
}