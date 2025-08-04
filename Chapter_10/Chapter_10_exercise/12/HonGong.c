#include <stdio.h>
#include "../../graph/adj_mat/adj_mat.h"

void read_graph_mat(Graph* g, char* name);
void write_graph_mat(Graph* g, char* name);

int main(void)
{

}

void read_graph_mat(Graph* g, char* name)
{
	FILE* fp = fopen(name, "r");
	if (fp == NULL)error("파일을 열 수 없습니다.");
}

void write_graph_mat(Graph* g, char* name)
{

}