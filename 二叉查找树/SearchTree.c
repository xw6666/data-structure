#define _CRT_SECURE_NO_WARNINGS 1
#include "SearchTree.h"
BiTree MakeEmpty(BTNode** root)
{
	if (*root != NULL)
	{
		MakeEmpty(&((*root)->left));
		MakeEmpty(&((*root)->right));
		free(root);
	}
	return NULL;
}

BTNode* Find(BiTree root, TreeNodeElement x)
{
	//注意这是二叉搜索树
	if (root == NULL)
	{
		return NULL;
	}

	if (root->val == x)
	{
		return root;
	}
	else if (root->val < x)
	{
		//x比现在的结点要大，说明在右子树
		return Find(root->right, x);
	}
	else
	{
		//x比现在的结点小，说明在左子树
		return Find(root->left, x);
	}
}

BTNode* FindMin(BiTree root)
{
	//二叉搜索树最大值在最左边的结点中
	if (root == NULL)
	{
		return NULL;
	}

	if (root->left == NULL)
	{
		//这就是最左边的结点指针
		return root;
	}
	else
	{
		return FindMin(root->left);
	}
}

BTNode* FindMax(BiTree root)
{
	//同上
	if (root == NULL)
	{
		return NULL;
	}

	if (root->right == NULL)
	{
		return root;
	}
	else
	{
		return FindMax(root->right);
	}
}

BTNode* Insert(BiTree root, TreeNodeElement x)
{
	if (root == NULL)
	{
		//Insert here
		root = (BTNode*)malloc(sizeof(BTNode));
		if (!root)
		{
			printf("malloc failed!\n");
			exit(-1);
		}
		root->left = NULL;
		root->right = NULL;
		root->val = x;
	}
	else if (root->val < x)
	{
		//Insert the root's right
		root->right = Insert(root->right, x);
	}
	else
	{
		root->left = Insert(root->left, x);
	}

	return root;
}

//BTNode* Delete(BiTree root, TreeNodeElement x)
//{
//
//}

void InOrder(BiTree root)
{
	if (!root)
	{
		return;
	}

	InOrder(root->left);
	printf("%d ", root->val);
	InOrder(root->right);
}