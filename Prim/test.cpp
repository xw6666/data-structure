#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#include <cmath>
#include <ctime>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXEDGE 20
#define MAXVEX 20
#define GRAPH_INFINITY 65535

typedef int Status;	

typedef struct
{
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph* G)/* 构件图 */
{
	int i, j;

	/* printf("请输入边数和顶点数:"); */
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
	cout << "图：" << endl;
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


void Prim(MGraph& G)
{
	int* adjvex = new int[G.numVertexes];
	int* lowCost = new int[G.numVertexes];
	//初始化adjvex和lowCost，第一个节点选择0号节点
	for (int i = 0; i < G.numVertexes; i++)
	{
		adjvex[i] = 0;
		lowCost[i] = G.arc[0][i];
	}

	//开始选择n-1条边
	printf("最小生成树：\n");
	int sumCost = 0;
	for (int i = 1; i < G.numVertexes; i++)
	{
		//找到最小的边
		int min = GRAPH_INFINITY;
		int k = 1;
		for (int j = 1; j < G.numVertexes; j++)
		{
			if (lowCost[j] < min && lowCost[j] != 0)
			{
				min = lowCost[j];
				k = j;
			}
		}
		//输出
		printf("(%d, %d), weight = %d\n", adjvex[k], k, min);
		sumCost += min;
		adjvex[k] = 0;
		lowCost[k] = 0;
		//更新adjvex和lowCost
		for (int i = 1; i < G.numVertexes; i++)
		{
			if (lowCost[i] != 0 && lowCost[i] > G.arc[k][i])
			{
				adjvex[i] = k;
				lowCost[i] = G.arc[k][i];
			}
		}
	}

	printf("最小权值为：%d\n", sumCost);

	delete[] adjvex;
	delete[] lowCost;
}

int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	Prim(G);

	return 0;

}
