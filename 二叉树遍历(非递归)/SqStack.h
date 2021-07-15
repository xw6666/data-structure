#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 4

typedef int TreeNodeType;

typedef struct BTNode
{
	TreeNodeType val;
	struct BTNode* left;
	struct BTNode* right;
}BTNode, * BiTree;

typedef BTNode* StackElement;

typedef struct SqStack
{
	StackElement* Stack;//ջ
	int top; //ջ��ָ�� 
	int capacity;//����
}SqStack;

//��ʼ��ջ
void InitStack(SqStack* ps);

//����
void ExpanStack(SqStack* ps);

//��ջ
void PushStack(SqStack* ps, StackElement x);

//��ӡջ��Ԫ�� - ջ����ջ��
void PrintStack(SqStack* ps);

//��ջ
StackElement PopStack(SqStack* ps);

//�ж�ջΪ��
bool EmptyStack(SqStack* ps);