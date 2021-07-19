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

BTNode* Delete(BiTree root, TreeNodeElement x)
{
	//���������
	//1.ɾ���Ľڵ���Ҷ�ӽڵ�
	//2.ɾ���Ľڵ�ֻ��һ������
	//3.ɾ���Ľڵ�����������
	//1�������ֱ��ɾ��
	//2��������Ƚ����ĸ��ڵ����ָ���ƹ��ýڵ��ɾ��
	//3���ͨ���ݹ��ҵ�����������Сֵ���ڽ��ýڵ�ֵ�滻����������Сֵ
	//�ٰ���������Сֵ��Ӧ�Ľڵ�ɾȥ
	if (root == NULL)
	{
		printf("Elemet not found!\n");
		return NULL;
	}

	if (x < root->val)
	{
		//����ɾ��
		root->left = Delete(root->left, x);
	}
	else if (x > root->val)
	{
		//����ɾ��
		root->right = Delete(root->right, x);
	}
	else
	{
		//ɾ����ָ���Ӧval
		if (root->left && root->right)
		{
			//������Ҷ��Ӵ���
			//���ýڵ�ֵ��Ϊ��������Сֵ����ɾ����������Сֵ���ڽ��
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