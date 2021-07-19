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

BTNode* Delete(BiTree root, TreeNodeElement x)
{
	//分三种情况
	//1.删除的节点是叶子节点
	//2.删除的节点只有一个儿子
	//3.删除的节点有两个儿子
	//1情况我们直接删除
	//2情况我们先将它的父节点调整指针绕过该节点后删除
	//3情况通过递归找到右子树的最小值，在讲该节点值替换成右子树最小值
	//再把右子树最小值对应的节点删去
	if (root == NULL)
	{
		printf("Elemet not found!\n");
		return NULL;
	}

	if (x < root->val)
	{
		//向左删除
		root->left = Delete(root->left, x);
	}
	else if (x > root->val)
	{
		//向右删除
		root->right = Delete(root->right, x);
	}
	else
	{
		//删除该指针对应val
		if (root->left && root->right)
		{
			//如果左右儿子存在
			//将该节点值改为右子树最小值，并删除右子树最小值所在结点
			BTNode* temp = FindMin(root->right);
			assert(temp != NULL);
			root->val = temp->val;
			root->right = Delete(root->right, root->val);
		}
		else if (root->left)
		{
			BTNode* temp = root;
			root = root->left;
			free(temp);
		}
		else
		{
			BTNode* temp = root;
			root = root->right;
			free(temp);
		}
	}

	return root;
}

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