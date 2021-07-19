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

//ʹ��Ϊ��
BiTree MakeEmpty(BiTree* root);

//����ָ��root�о��йؼ���x�Ľ���ָ��
BTNode* Find(BiTree root, TreeNodeElement x);

//���ض�������������СԪ��λ��
BTNode* FindMin(BiTree root);

//���ض��������������Ԫ��λ��
BTNode* FindMax(BiTree root);

//�������
BTNode* Insert(BiTree root, TreeNodeElement x);

//ɾ������
BTNode* Delete(BiTree root, TreeNodeElement x);

//�������
void InOrder(BiTree root);