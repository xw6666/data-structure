#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

#define MAXEDGE 20
#define MAXVEX 20
#define GRAPH_INFINITY 65535

typedef struct
{
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;   /* 对边集数组Edge结构的定义 */

/* 构建图 */
void CreateMGraph(MGraph* G)
{
	int i, j;

	G->numEdges = 15;
	G->numVertexes = 9;

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			if (i == j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = G->arc[j][i] = GRAPH_INFINITY;
		}
	}

	G->arc[0][1] = 10;
	G->arc[0][5] = 11;
	G->arc[1][2] = 18;
	G->arc[1][8] = 12;
	G->arc[1][6] = 16;
	G->arc[2][8] = 8;
	G->arc[2][3] = 22;
	G->arc[3][8] = 21;
	G->arc[3][6] = 24;
	G->arc[3][7] = 16;
	G->arc[3][4] = 20;
	G->arc[4][7] = 7;
	G->arc[4][5] = 26;
	G->arc[5][6] = 17;
	G->arc[6][7] = 19;

	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
	printf("图为：\n");
	for (int i = 0; i < G->numVertexes; i++)
	{
		for (int j = i + 1; j < G->numVertexes; j++)
		{
			if (G->arc[i][j] != GRAPH_INFINITY)
			{
				printf("(%d, %d), weight = %d\n", i, j, G->arc[i][j]);
			}
		}
	}
}

/* 交换权值 以及头和尾 */
void Swapn(Edge* edges, int i, int j)
{
	int temp;
	temp = edges[i].begin;
	edges[i].begin = edges[j].begin;
	edges[j].begin = temp;
	temp = edges[i].end;
	edges[i].end = edges[j].end;
	edges[j].end = temp;
	temp = edges[i].weight;
	edges[i].weight = edges[j].weight;
	edges[j].weight = temp;
}

int Find(int* parents, int index)
{
	while (parents[index] >= 0)
	{
		index = parents[index];
	}
	return index;
}

int _cmp(const void* e1, const void* e2)
{
	return ((*(Edge*)e1).weight - (*(Edge*)e2).weight);
}

void Kruskal(MGraph& G)
{
	//制作Edge的数组
	Edge* edges = (Edge*)malloc(sizeof(Edge) * G.numEdges);
	if (edges == NULL)
	{
		printf("Malloc failed!\n");
		exit(-1);
	}
	//添加边到edges中
	int k = 0;  //记录edges下标
	for (int i = 0; i < G.numVertexes; i++)
	{
		for (int j = i + 1; j < G.numVertexes; j++)
		{
			if (G.arc[i][j] != GRAPH_INFINITY)
			{

				edges[k].begin = i;
				edges[k].end = j;
				edges[k].weight = G.arc[i][j];
				k++;

			}
		}
	}

	//对权值排序
	qsort(edges, k, sizeof(Edge), _cmp);
	//建立并查集
	int* parents = (int*)malloc(sizeof(int) * k);
	if (parents == NULL)
	{
		exit(-1);
	}
	for (int i = 0; i < k; i++)
	{
		parents[i] = -1;
	}
	printf("最小生成树：\n");
	for (int i = 0; i < k; i++)
	{
		int v1 = Find(parents, edges[i].begin);
		int v2 = Find(parents, edges[i].end);
		if (v1 != v2)
		{
			//说明在不同的连通分量
			printf("(%d, %d), weight = %d\n", edges[i].begin, edges[i].end, edges[i].weight);
			parents[v1] = v2;
		}
	}
	free(parents);
	parents = NULL;
	free(edges);
	edges = NULL;
}

int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	Kruskal(G);
	return 0;
}