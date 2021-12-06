#pragma once
#include <iostream>
using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <ctime>

typedef char VertexType;   //顶点类型
typedef int EdgeType;   //边类型

#define MAXVEX 100   //最大顶点数
#define INFINITY 65535 

typedef struct MGraph
{
	VertexType vex[MAXVEX];      //点集
	EdgeType arc[MAXVEX][MAXVEX];   //邻接矩阵
	int numNodes;    //当前的顶点数
	int numEdges;    //当前的边数
}MGraph; 


//构造图
void CreateMGraph(MGraph* G);