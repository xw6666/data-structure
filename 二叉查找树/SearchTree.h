#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int TreeNodeElement;

typedef struct BTNode
{
	TreeNodeElement val;
	struct BTNode* left;
	struct BTNode* right;
}BTNode, * BiTree;

//使树为空
BiTree MakeEmpty(BiTree* root);

//返回指向root中具有关键字x的结点的指针
BTNode* Find(BiTree root, TreeNodeElement x);

//返回二叉搜索树的最小元的位置
BTNode* FindMin(BiTree root);

//返回二叉搜索树的最大元的位置
BTNode* FindMax(BiTree root);

//插入操作
BTNode* Insert(BiTree root, TreeNodeElement x);

//删除操作
BTNode* Delete(BiTree root, TreeNodeElement x);

//中序遍历
void InOrder(BiTree root);