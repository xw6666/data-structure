#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef enum { Link, Thread } PointerTag;
typedef char TreeDataType;

typedef struct BTNode
{
	TreeDataType val;      //������
	struct BTNode* left;   //��ָ��
	struct BTNode* right;   //��ָ��
	PointerTag LTag;    
	PointerTag RTag;   //���ұ�־
}BTNode, * BiTree;

//ͨ����������ҵ�ǰ�����
BTNode* pre;
void InThreading(BTNode* p)
{
	if (p)
	{
		//�������
		InThreading(p->left);
		if (p->left == NULL)
		{
			//�����ָ��Ϊ��
			//�����ָ����Ϊǰ������
			p->RTag = Thread;
			p->left = pre;
		}

		if (pre != NULL &&pre->right == NULL)
		{
			//�����ָ����Ϊ�������
			pre->RTag = Thread;
			pre->right = p;
		}
		pre = p;
		InThreading(p->right);
	}
}

//void InOrderByThread(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	while (root->left != NULL)
//	{
//		//��������һ���ڵ�
//		root = root->left;
//	}
//	
//}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}

int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->val = 'A';
	A->left = NULL;
	A->right = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->val = 'B';
	B->left = NULL;
	B->right = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->val = 'C';
	C->left = NULL;
	C->right = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->val = 'D';
	D->left = NULL;
	D->right = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->val = 'E';
	E->left = NULL;
	E->right = NULL;

	BTNode* F = (BTNode*)malloc(sizeof(BTNode));
	F->val = 'F';
	F->left = NULL;
	F->right = NULL;

	BTNode* G = (BTNode*)malloc(sizeof(BTNode));
	G->val = 'G';
	G->left = NULL;
	G->right = NULL;

	BTNode* H = (BTNode*)malloc(sizeof(BTNode));
	H->val = 'H';
	H->left = NULL;
	H->right = NULL;

	BTNode* I = (BTNode*)malloc(sizeof(BTNode));
	I->val = 'I';
	I->left = NULL;
	I->right = NULL;

	BTNode* J = (BTNode*)malloc(sizeof(BTNode));
	J->val = 'J';
	J->left = NULL;
	J->right = NULL;

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;
	C->left = F;
	C->right = G;
	D->left = H;
	D->right = I;
	E->left = J;

	//InThreading(A);
	printf("����������������:\n");
	InOrder(A);
}