#pragma once
#include <iostream>
using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <ctime>

typedef char VertexType;   //��������
typedef int EdgeType;   //������

#define MAXVEX 100   //��󶥵���
#define INFINITY 65535 

typedef struct MGraph
{
	VertexType vex[MAXVEX];      //�㼯
	EdgeType arc[MAXVEX][MAXVEX];   //�ڽӾ���
	int numNodes;    //��ǰ�Ķ�����
	int numEdges;    //��ǰ�ı���
}MGraph; 


//����ͼ
void CreateMGraph(MGraph* G);