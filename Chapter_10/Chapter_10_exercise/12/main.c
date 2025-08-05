#include <stdio.h>
#include "../../graph/adj_mat/adj_mat.h"

void read_graph_mat(Graph* g, char* name);
void write_graph_mat(Graph* g, char* name);

int main(void)
{
	Graph* g = NULL;
	g = init(g);
	read_graph_mat(g, "name.txt");
	print_adj_mat(g);
	write_graph_mat(g, "name1.txt");
}

void read_graph_mat(Graph* g, char* name)
{
	FILE* fp = fopen(name, "r");
	if (fp == NULL) {
		fprintf(stderr, "파일 열기 실패\n");
		return;
	}
	fscanf(fp, "%d", &g->n);
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			fscanf(fp, "%d", &(g->adj_mat[i][j]));
		}
	}
	fclose(fp);
}

void write_graph_mat(Graph* g, char* name)
{
	FILE* fp = fopen(name, "w");
	if (fp == NULL) {
		fprintf(stderr, "파일 열기 실패\n");
		return;
	}
	fprintf(fp, "%d\n", g->n);
	for(int i=0;i<g->n;i++)
	{
		for (int j = 0; j < g->n; j++)
		{
			fprintf(fp, "%d ", g->adj_mat[i][j]);
		}
		fprintf(fp, "\n");
	}
}