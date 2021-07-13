#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char TreeDataType;

typedef struct BTNode
{
	TreeDataType val;
	struct BTNode* left;
	struct BTNode* right;
}BTNode, * BiTree;

//����һ�Ŷ�����
void GreateBiTree(BiTree* tree, TreeDataType* data, int* i);

//ǰ���������������ӡ
void PrevOrder(BTNode* root);

//�����������������ӡ
void InOrder(BTNode* root);

//�����������������ӡ
void PostOrder(BTNode* root);