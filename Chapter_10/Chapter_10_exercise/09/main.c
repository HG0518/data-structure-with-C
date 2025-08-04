#include <stdio.h>
#include "../../graph/adj_mat/adj_mat.h"

int out_degree(Graph* g, int v);
int in_degree(Graph* g, int v);
int get_edgeN(Graph* g);

int main(void)
{

}

int out_degree(Graph* g, int v)
{
	int count = 0;
	for (int i = 0; i < g->n; i++)	
		if (g->adj_mat[v][i]) count++;	
	return count;
}

int in_degree(Graph* g, int v)
{
	int count = 0;
	for (int i = 0; i < g->n; i++)
		if (g->adj_mat[i][v]) count++;
	return count;
}

int get_edgeN(Graph* g)
{
	int count = 0;
	for (int i = 0; i < g->n; i++)
		for (int j = 0; j < g->n; j++)
			if (g->adj_mat[i][j])count++;
	return count;
}