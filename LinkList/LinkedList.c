#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkedList.h"

void LinkedListInit(LinkedList* phead)
{
	//��һ���ڱ���� - val���ڴ�Ž�����
	*phead = (LNode*)malloc(sizeof(LNode));
	(*phead)->next = NULL;
	(*phead)->val = 0;
}

LNode* GetNewNode()
{
	LNode* newNode = (LNode*)malloc(sizeof(LNode));
	newNode->next = NULL;
}

void LinkedListPrint(LinkedList phead)
{
	assert(phead != NULL);
	LNode* cur = phead;
	cur = cur->next;
	while (cur != NULL)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

void LinkedListPushBack(LinkedList phead, ElementType x)
{
	assert(phead != NULL);
	LNode* cur = phead->next;
	LNode* prev = phead;
	//�ҵ����һ�����
	while (cur != NULL)
	{
		prev = cur;
		cur = cur->next;
	}
	//prev��nextΪ��
	LNode* newNode = GetNewNode();
	newNode->val = x;
	prev->next = newNode;
	phead->val++;   //��¼������
}

void LinkedListPushFront(LinkedList phead, ElementType x)
{
	assert(phead != NULL);
	LNode* newNode = GetNewNode();
	newNode->val = x;
	newNode->next = phead->next;
	phead->next = newNode;
	phead->val++;
}