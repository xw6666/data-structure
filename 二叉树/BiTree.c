#define _CRT_SECURE_NO_WARNINGS 1
#include "BiTree.h"
void GreateBiTree(BiTree* root, TreeDataType data[], int* i)
{
	if (data[*i] == '#')
	{
		*root = NULL;
		(*i)++;
	}
	else
	{
		//构造节点
		*root = (BTNode*)malloc(sizeof(BTNode));
		if (*root == NULL)
		{
			printf("malloc失败\n");
			exit(-1);
		}
		(*root)->val = data[*i];
		(*i)++;
		GreateBiTree(&((*root)->left), data, i);
		GreateBiTree(&((*root)->right), data, i);	
	}
}

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	
	printf("%c ", root->val);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (!root)
	{
		return;
	}
	
	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (!root)
	{
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->val);
}