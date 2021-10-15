#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkedList.h"

void LinkedListInit(LinkedList* phead)
{
	//给一个哨兵结点 - val用于存放结点个数
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
	//找到最后一个结点
	while (cur != NULL)
	{
		prev = cur;
		cur = cur->next;
	}
	//prev的next为空
	LNode* newNode = GetNewNode();
	newNode->val = x;
	prev->next = newNode;
	phead->val++;   //记录结点个数
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