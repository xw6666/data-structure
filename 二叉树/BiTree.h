#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
using namespace std;
#include <queue>

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

//�����������������ӡ
void LevelOrder(BTNode* root);

// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root);
