#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElementType;

typedef struct LinkedNode
{
	ElementType val;
	struct LinkedNode* next;
}LNode, *LinkedList;

//��ʼ������
void LinkedListInit(LinkedList* phead);
//��ӡ����
void LinkedListPrint(LinkedList phead);
//β��
void LinkedListPushBack(LinkedList phead, ElementType x);
//ͷ��
void LinkedListPushFront(LinkedList phead, ElementType x);