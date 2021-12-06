#include "Graph.h"

void test1()
{
	MGraph G;
	CreateMGraph(&G);
	for (int i = 0; i < G.numNodes; i++)
	{
		cout << i << " " << endl;
	}
	cout << endl;
	for (int i = 0; i < G.numNodes; i++)
	{
		for (int j = 0; j < G.numNodes; j++)
		{
			cout << G.arc[i][j] << " ";
		}
		cout << endl;
	}
}


int main()
{
	test1();
	return 0;
}