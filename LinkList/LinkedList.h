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

//初始化链表
void LinkedListInit(LinkedList* phead);
//打印链表
void LinkedListPrint(LinkedList phead);
//尾插
void LinkedListPushBack(LinkedList phead, ElementType x);
//头插
void LinkedListPushFront(LinkedList phead, ElementType x);