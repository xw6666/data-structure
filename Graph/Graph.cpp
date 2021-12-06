#include "Graph.h"


//O(n^2)
void CreateMGraph(MGraph* G)
{
	cout << "请输入顶点数和边的数：" << endl;
	cin >> G->numNodes >> G->numEdges;
	for (int i = 0; i < G->numNodes; i++)
	{
		cin >> G->vex[i];
	}
	//初始化边集
	for (int i = 0; i < G->numNodes; i++)
	{
		for (int j = 0; j < G->numNodes; j++)
		{
			G->arc[i][j] = INFINITY;
		}
	}

	//读入边的信息
	for (int w = 0; w < G->numEdges; w++)
	{
		cout << "请输入边(v1,vj)上的下标i，j和权值k" << endl;
		int i, j, k;
		cin >> i >> j >> k;
		G->arc[i][j] = k;
		G->arc[j][i] = G->arc[i][j];
	}
}