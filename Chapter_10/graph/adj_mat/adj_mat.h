#ifndef ADJ_MAT_H
#define ADJ_MAT_H

#define MAX_VERTICES 50

typedef struct Graph {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}Graph;

Graph* init(Graph* g);
void insert_vertex(Graph* g, int v);
void insert_edge(Graph* g, int start, int end);
void print_adj_mat(Graph* g);
void error(char* msg);
Graph* free_g(Graph* g);
int get_degree(Graph* g, int v);
#endif // !ADJ_MAT_H
