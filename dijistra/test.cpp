#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535

typedef struct MGraph
{
	int vexs[MAXVEX];
	int arc[MAXEDGE][MAXEDGE];
	int numVertexes;
	int numEdges;
}MGraph;


void CreateMGraph(MGraph& G)
{
	G.numVertexes = 9;  //9个顶点
	G.numEdges = 16;  //16条边
	for (int i = 0; i < G.numVertexes; i++)
	{
		G.vexs[i] = i;
	}

	for (int i = 0; i < G.numVertexes; i++)
	{
		for (int j = 0; j < G.numVertexes; j++)
		{
			if (i == j)
			{
				G.arc[i][j] = 0;
			}
			else
			{
				G.arc[i][j] = INFINITY;
			}
		}
	}
	
	G.arc[0][1] = 1;
	G.arc[1][0] = 1;
	G.arc[0][2] = 5;
	G.arc[2][0] = 5;
	G.arc[1][2] = 3;
	G.arc[2][1] = 3;
	G.arc[1][4] = 5;
	G.arc[4][1] = 5;
	G.arc[2][4] = 1;
	G.arc[4][2] = 1;
	G.arc[1][3] = 7;
	G.arc[3][1] = 7;
	G.arc[2][5] = 7;
	G.arc[5][2] = 7;
	G.arc[3][4] = 2;
	G.arc[4][3] = 2;
	G.arc[4][5] = 3;
	G.arc[5][4] = 3;
	G.arc[3][6] = 3;
	G.arc[6][3] = 3;
	G.arc[4][6] = 6;
	G.arc[6][4] = 6;
	G.arc[4][7] = 9;
	G.arc[7][4] = 9;
	G.arc[5][7] = 5;
	G.arc[7][5] = 5;
	G.arc[6][7] = 2;
	G.arc[7][6] = 2;
	G.arc[6][8] = 7;
	G.arc[8][6] = 7;
	G.arc[7][8] = 4;
	G.arc[8][7] = 4;

}

void dijistra(int v0, MGraph& G, vector<int>& P, vector<int>& lowcost)
{
	vector<int> visited(G.numVertexes, 0);
	for (int i = 0; i < G.numVertexes; i++)
	{
		P[i] = -1;
		lowcost[i] = G.arc[v0][i];
	}
	visited[v0] = 1;
	for (int i = 1; i < G.numVertexes; i++)
	{
		int k = 0;
		int min = INFINITY;
		for (int j = 0; j < G.numVertexes; j++)
		{
			if (!visited[j] && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
		}
		visited[k] = 1;
		for (int j = 0; j < G.numVertexes; j++)
		{
			if (!visited[j] && lowcost[k] + G.arc[k][j] < lowcost[j])
			{
				lowcost[j] = lowcost[k] + G.arc[k][j];
				P[j] = k;
			}
		}
	}
}

int main()
{
	MGraph G;
	CreateMGraph(G);
	int v0 = 0;
	cout << "请输入v0：" << endl;
	cin >> v0;
	vector<int> P(G.numVertexes, 0);   //记录前驱节点
	vector<int> lowcost(G.numVertexes, 0);    //权值和
	dijistra(v0, G, P, lowcost);
	for (int i = 0; i < G.numVertexes; i++)
	{
		printf("v0到%d的最短路径为：", i);
		vector<int> ans;
		ans.push_back(i);
		int j = i;
		while (P[j] != -1)
		{
			ans.push_back(P[j]);
			j = P[j];
		}
		ans.push_back(v0);
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
		{
			if (i < ans.size() - 1)
			{
				printf("%d->", ans[i]);
			}
			else
			{
				printf("%d\n", ans[i]);
			}
		}
		cout << "V0到" << i << "的权值和为：" << lowcost[i] << endl;
	}
	return 0;
}

