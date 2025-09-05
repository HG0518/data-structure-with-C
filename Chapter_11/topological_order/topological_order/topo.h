#ifndef TOPO_H
#define TOPO_H

#define MAX_VERTICIES 100

typedef struct Node {
	int n;
	struct Node* link;
}Node;

typedef struct {
	int n;
	Node* list[MAX_VERTICIES];
}Graph;

typedef struct {
	int top;
	int list[MAX_VERTICIES];
}Stack;

int in_degree[MAX_VERTICIES];

void init_graph(Graph* g);
void insert_vertex(Graph* g);
void insert_edge(Graph* g, int start, int end);

void init_stack(Stack* s);
void push(Stack* s, int item);
int pop(Stack* s);
int is_empty(Stack* s);
int is_full(Stack* s);

void init_degree(Graph *g);
void topo_sort(Graph* g);


#endif // !TOPO_H
