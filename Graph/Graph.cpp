#include "Graph.h"


//O(n^2)
void CreateMGraph(MGraph* G)
{
	cout << "�����붥�����ͱߵ�����" << endl;
	cin >> G->numNodes >> G->numEdges;
	for (int i = 0; i < G->numNodes; i++)
	{
		cin >> G->vex[i];
	}
	//��ʼ���߼�
	for (int i = 0; i < G->numNodes; i++)
	{
		for (int j = 0; j < G->numNodes; j++)
		{
			G->arc[i][j] = INFINITY;
		}
	}

	//����ߵ���Ϣ
	for (int w = 0; w < G->numEdges; w++)
	{
		cout << "�������(v1,vj)�ϵ��±�i��j��Ȩֵk" << endl;
		int i, j, k;
		cin >> i >> j >> k;
		G->arc[i][j] = k;
		G->arc[j][i] = G->arc[i][j];
	}
}