#include <stdio.h>
#include <stdlib.h>

#define INF 100000
#define MAX_VERTICIES 100

typedef struct {
	int n;
	int weight[MAX_VERTICIES][MAX_VERTICIES];
}Graph;

int A[MAX_VERTICIES][MAX_VERTICIES];

void print_A(int n);
void floyd(Graph *g);

int main(void)
{
	printf("예제 풀이\n");
	Graph g = { 7,
		{{0,7,INF,INF,3,10,INF},
		{7,0,4,10,2,6,INF},
		{INF,4,0,2,INF,INF,INF},
		{INF,10,2,0,11,9,4},
		{3,2,INF,11,0,INF,5},
		{10,6,INF,9,INF,0,INF},
		{INF,INF,INF,4,5,INF,0}}
	};
	floyd(&g);

	printf("\n\n\n\n\n");
	printf("quiz풀이\n");
	Graph g2 = { 3,
		{{0,3,1},
		{2,0,4},
		{5,1,0}}
	};
	floyd(&g2);
	return 0;
}

void print_A(int n)
{
	printf("==============================\n");
	for(int i=0;i<n;i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i][j] == INF) printf("%4c", '*');
			else printf("%4d", A[i][j]);
		}
		printf("\n");
	}
	printf("==============================\n\n");

}

void floyd(Graph *g)
{
	int i, j, k;
	for (i = 0; i < g->n; i++)
		for (j = 0; j < g->n; j++)
			A[i][j] = g->weight[i][j];

	print_A(g->n);
	for (k = 0; k < g->n; k++)
	{
		for (i = 0; i < g->n; i++)
			for (j = 0; j < g->n; j++)
				A[i][j] = A[i][j] < A[i][k] + A[k][j] ? A[i][j] : A[i][k] + A[k][j];
		print_A(g->n);
	}
}