#include <stdio.h>
#include <stdlib.h>
#include "adj_mat.h"
#include "stack.h"
#include "queue.h"

Graph* init(Graph* g)
{
	g = (Graph*)malloc(sizeof(Graph));
	if (g == NULL) error("NULL값 할당");
	int r, c;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
	g->n = 0;
	return g;
}

void insert_vertex(Graph* g, int v)
{
	if (g->n + 1 > MAX_VERTICES)
	{
		printf("그래프가 포화상태입니다.\n");
		return;
	}
	g->n++;
}

void insert_edge(Graph* g, int start, int end)
{
	if (start > g->n - 1 || end > g->n - 1)
	{
		printf("잘못된 정점입니다.\n");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void print_adj_mat(Graph* g)
{
	int r, c;
	for (r = 0; r < g->n; r++) {
		for (c = 0; c < g->n; c++) {
			printf("%2d ", g->adj_mat[r][c]);
		}
		printf("\n");
	}
}

void error(char* msg)
{
	printf("%s\n", msg);
	exit(1);
}

Graph* free_g(Graph* g)
{
	free(g);
	g = NULL;
	return g;
}

int get_degree(Graph* g, int v)
{
	int count = 0;
	for (int i = 0; i < g->n; i++)
	{
		if (g->adj_mat[v][i] == 1)count++;
	}
	return count;
}

void dfs_mat(Graph* g, int v)
{
	visited[v] = 1;
	printf("정점 %d > ", v);
	for (int w = 0; w < g->n; w++) {
		if (g->adj_mat[v][w] && !visited[w])
			dfs_mat(g, w);
	}
}

void dfs_iterative(Graph* g, int v)
{
	stack s;
	init_stack(&s);
	push(&s, v);
	while (!is_stack_empty(&s)) {
		v = pop(&s);
		if (!visited[v]) {
			visited[v] = 1;
			printf("정점 %d > ", v);
			for (int w = 0; w < g->n; w++) {
				if (!visited[w] && g->adj_mat[v][w])
					push(&s, w);
			}
		}
	}
	free_stack(&s);
}

void init_visited(int visited[])
{
	for (int i = 0; i < MAX_VERTICES; i++)
		visited[i] = 0;
}

void bfs_mat(Graph* g, int v)
{
	queue q;
	init_queue(&q);
	enqueue(&q, v);
	while (!is_queue_empty(&q))
	{
		v = dequeue(&q);
		visited[v] = 1;
		printf("정점 %d > ", v);
		for (int w = 0; w < g->n; w++) {
			if (g->adj_mat[v][w] && !visited[w]) {
				visited[w] = 1;
				enqueue(&q, w);
			}
		}

	}
}