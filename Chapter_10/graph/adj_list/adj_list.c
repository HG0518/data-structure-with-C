#include <stdio.h>
#include <stdlib.h>
#include "adj_list.h"

Graph* init_graph(Graph* g)
{
	g = (Graph*)malloc(sizeof(Graph));
	if (g == NULL)error("NULL값 할당");
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++)
		g->adj_list[i] = NULL;
	return g;
}

void insert_vertex(Graph* g, int v)
{
	if ((g->n) + 1 > MAX_VERTICES)
	{
		printf("정점 개수 초과\n");
		return;
	}
	g->n++;
}

void insert_edge(Graph* g, int start, int end)
{
	if (start >= g->n || end >= g->n) 
	{
		printf("정점 번호 오류\n");
		return;
	}
	vertex* ver;
	ver = (vertex*)malloc(sizeof(vertex));
	if (ver == NULL)error("NULL값 할당");
	ver->ver = end;
	ver->link = g->adj_list[start];
	g->adj_list[start] = ver;
}

void print_adj_list(Graph* g)
{
	vertex* v;
	for (int i = 0; i < g->n; i++)
	{
		printf("%d : ", i);
		for (v = g->adj_list[i]; v != NULL; v = v->link)
		{
			printf("%d > ", v->ver);
		}
		printf("NULL\n");
	}
}

void error(char* msg)
{
	printf("%s\n", msg);
	exit(1);
}

Graph* free_graph(Graph* g)
{
	vertex* current, * next;
	
	for (int i = 0; i < g->n; i++) {
		current = g->adj_list[i];
		while (current != NULL) {
			next = current->link;
			free(current);
			current = next;
		}
	}
	free(g);
	g = NULL;
	return g;			
}

int get_degree(Graph* g, int v)
{
	int count = 0;
	for (vertex* ver = g->adj_list[v]; ver != NULL; ver = ver->link) count++;
	return count;
}
