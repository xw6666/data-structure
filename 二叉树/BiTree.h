#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <bits/stdc++.h>
using namespace std;
#include <queue>

typedef char TreeDataType;

typedef struct BTNode
{
	TreeDataType val;
	struct BTNode* left;
	struct BTNode* right;
}BTNode, * BiTree;

//创建一颗二叉树
void GreateBiTree(BiTree* tree, TreeDataType* data, int* i);

//前序遍历二叉树并打印
void PrevOrder(BTNode* root);

//中序遍历二叉树并打印
void InOrder(BTNode* root);

//后序遍历二叉树并打印
void PostOrder(BTNode* root);