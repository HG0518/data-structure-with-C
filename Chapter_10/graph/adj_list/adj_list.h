#ifndef ADJ_LIST_C
#define ADJ_LIST_C

#define MAX_VERTICES 50
typedef struct vertex {
	int ver;
	struct vertex* link;
}vertex;

typedef struct Graph {
	int n;
	vertex* adj_list[MAX_VERTICES];
}Graph;

Graph* init_graph(Graph* g);
void insert_vertex(Graph* g, int v);
void insert_edge(Graph* g, int strat, int end);
void print_adj_list(Graph* g);
void error(char* msg);
Graph* free_graph(Graph* g);
int get_degree(Graph* g ,int v);

#endif // !ADJ_LIST_C
