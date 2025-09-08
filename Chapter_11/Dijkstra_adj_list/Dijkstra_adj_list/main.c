#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICIES 100
#define INF 100000

typedef struct Node
{
	int n;
	int w;
	struct Node* link;
}Node;

typedef struct
{
	int n;
	Node* adj_list[MAX_VERTICIES];
}Graph;

int selected[MAX_VERTICIES];
int distance[MAX_VERTICIES];

void insert_edge(Graph* g, int start_v, int end_v, int weight);
void init_graph(Graph* g);
void dijkstra(Graph* g, int start_v);
int get_weight(Graph* g, int u, int v);
int choose(int n);
void print_status(int n);

int main(void)
{
	Graph g;
	init_graph(&g);
	g.n = 6;
	insert_edge(&g, 0, 1, 50);
	insert_edge(&g, 0, 2, 45);
	insert_edge(&g, 0, 3, 10);
	insert_edge(&g, 1, 2, 10);
	insert_edge(&g, 1, 3, 15);
	insert_edge(&g, 2, 4, 30);
	insert_edge(&g, 3, 0, 20);
	insert_edge(&g, 3, 4, 15);
	insert_edge(&g, 4, 1, 20);
	insert_edge(&g, 4, 2, 35);
	insert_edge(&g, 5, 4, 3);

	dijkstra(&g, 0);

	return 0;
}

void insert_edge(Graph* g, int start_v, int end_v, int weight)
{
	Node* v = (Node*)malloc(sizeof(Node));
	if (v == NULL)
	{
		fprintf(stderr, "NULL값 할당 오류");
		return;
	}
	v->n = end_v;
	v->w = weight;
	v->link = g->adj_list[start_v];
	g->adj_list[start_v] = v;
}

void init_graph(Graph* g)
{
	g->n = 0;
	for (int i = 0; i < MAX_VERTICIES; i++)
		g->adj_list[i] = NULL;
}

void dijkstra(Graph* g, int start_v)
{
	for (int i = 0; i < g->n; i++)
	{
		selected[i] = 0;
		distance[i] = INF;
	}
	for (Node* p = g->adj_list[start_v]; p != NULL; p = p->link) {
		distance[p->n] = p->w;
	}
	distance[start_v] = 0;

	int v;
	for (int i = 0; i < g->n; i++)
	{
		v = choose(g->n);
		selected[v] = 1;
		for(int j=0;j<g->n;j++)
			if (!selected[j] && distance[j] > distance[v] + get_weight(g, v, j))
				distance[j] = distance[v] + get_weight(g, v, j);
		print_status(g->n);
	}


}
int get_weight(Graph* g, int u, int v)
{
	Node* p;
	for (p = g->adj_list[u]; p != NULL; p = p->link)
		if (p->n == v) break;
	if (p == NULL) return INF;
	else return p->w;
}

int choose(int n)
{
	int v;
	for (int i = 0; i < n; i++)
		if (!selected[i])
		{
			v = i;
			break;
		}

	for (int i = 0; i < n; i++)
		if (!selected[i] && distance[i] < distance[v])v = i;

	return v;
}

void print_status(int n)
{
	static int step = 1;
	printf("step %d\n", step++);

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