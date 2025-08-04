#ifndef ADJ_MAT_H
#define ADJ_MAT_H

#define MAX_VERTICES 50

int visited[MAX_VERTICES];
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
void dfs_mat(Graph* g, int v);
void dfs_iterative(Graph* g, int v);
void init_visited(int visited[]);
void bfs_mat(Graph* g, int v);


#endif // !ADJ_MAT_H
