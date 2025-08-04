#include <stdio.h>
#include "../../graph/adj_list/adj_list.h"

int out_degree(Graph* g, int v);
int in_degree(Graph* g, int v);
int get_edgeN(Graph* g);

int main(void)
{

}

int out_degree(Graph* g, int v)
{
	int count = 0;
	vertex* p;
	for (p = g->adj_list[v]; p; p = p->link)
		count++;
	return count;
}

int in_degree(Graph* g, int v)
{
	int count = 0;
	vertex* p;
	for (int i = 0; i < g->n; i++) {
		for (p = g->adj_list[i]; p; p = p->link) {
			if (p->ver == v) count++;
		}
	}
	return count;
}

int get_edgeN(Graph* g)
{
	int count = 0;
	vertex* p;
	for (int i = 0; i < g->n; i++) {
		for (p = g->adj_list[i]; p; p = p->link) {
			count++;
		}
	}
	return count;
}