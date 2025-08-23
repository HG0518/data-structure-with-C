#ifndef KRUSKAL_C
#define KRUSKAL_C

#define INF 1000
#define MAX_VERTICES 100

int parent[MAX_VERTICES];

typedef struct {
	int start, end, weight;
}Edge;

typedef struct {
	int nedge;
	int nvertex;
	Edge edges[2 * MAX_VERTICES];
}Graph;

void set_init();
int set_find(int v);
void set_union(int v1, int v2);
Graph* graph_init(Graph* g);
void insert_edge(Graph* g, int start, int end, int weight);
int compare(const void* a, const void* b);
void kruskal(Graph* g);
void error(char* msg);
Graph* free_g(Graph* g);


#endif // !KRUSKAL_C
