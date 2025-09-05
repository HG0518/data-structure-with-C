#include <stdio.h>
#include <stdlib.h>
#include "topo.h"

void init_graph(Graph* g)
{
	g->n = 0;
	for (int i = 0; i < MAX_VERTICIES; i++)
		g->list[i] = NULL;
}

void insert_vertex(Graph* g)
{
	if (g->n == MAX_VERTICIES)
	{
		fprintf(stderr, "그래프 정점 개수 초과\n");
		return;
	}
	g->n++;

}

void insert_edge(Graph* g, int start, int end)
{
	Node* node;
	if (start > g->n || end > g->n)
	{
		fprintf(stderr, "그래프 정점 오류\n");
		return;
	}

	node = (Node*)malloc(sizeof(Node));
	if (node == NULL)
	{
		fprintf(stderr, "NULL값 할당 오류\n");
		return;
	}
	node->n = end;
	node->link = g->list[start];
	g->list[start] = node;
}

void init_stack(Stack* s)
{
	s->top = -1;
}

void push(Stack* s, int item)
{
	if (is_full(s))
	{
		fprintf(stderr, "스택 포화 상태 오류\n");
		return;
	}
	s->top++;
	s->list[s->top] = item;
}

int pop(Stack* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택 공백 상태 오류\n");
		return;
	}
	int item = s->list[s->top];
	s->top--;
	return item;
}

int is_empty(Stack* s)
{
	return s->top == -1;
}

int is_full(Stack* s)
{
	return s->top == MAX_VERTICIES;
}

void init_degree(Graph* g)
{
	for (int i = 0; i < g->n; i++) in_degree[i] = 0;
	for (int i = 0; i < g->n; i++)
		for (Node* p = g->list[i]; p != NULL; p = p->link)
			in_degree[p->n]++;
}

void topo_sort(Graph* g)
{
	init_degree(g);


	Stack s;
	init_stack(&s);

	int u;

	for (int i = 0; i < g->n; i++)
		if (in_degree[i] == 0) push(&s, i);
	
	while (!is_empty(&s))
	{
		u = pop(&s);
		printf("정점 %d > ", u);
		for (Node* p = g->list[u]; p != NULL; p = p->link)
		{
			in_degree[p->n]--;
			if (in_degree[p->n] == 0)push(&s, p->n);
		}
	}
	printf("\n");
}

