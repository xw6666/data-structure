#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef enum { Link, Thread } PointerTag;
typedef char TreeDataType;

typedef struct BTNode
{
	TreeDataType val;      //数据域
	struct BTNode* left;   //左指针
	struct BTNode* right;   //右指针
	PointerTag LTag;    
	PointerTag RTag;   //左右标志
}BTNode, * BiTree;

//通过中序遍历找到前驱后继


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
	E->right = J;

	InOrder(A);
}