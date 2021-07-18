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
	//ע�����Ƕ���������
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
		//x�����ڵĽ��Ҫ��˵����������
		return Find(root->right, x);
	}
	else
	{
		//x�����ڵĽ��С��˵����������
		return Find(root->left, x);
	}
}

BTNode* FindMin(BiTree root)
{
	//�������������ֵ������ߵĽ����
	if (root == NULL)
	{
		return NULL;
	}

	if (root->left == NULL)
	{
		//���������ߵĽ��ָ��
		return root;
	}
	else
	{
		return FindMin(root->left);
	}
}

BTNode* FindMax(BiTree root)
{
	//ͬ��
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