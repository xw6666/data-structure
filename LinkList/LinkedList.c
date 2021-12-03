#include "LinkedList.h"

ListNode* _GetNewNode(LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->_next = NULL;
	newNode->_data = x;
	return newNode;
}

ListNode* ListCreate()
{
	ListNode* list = (ListNode*)malloc(sizeof(ListNode));
	if (list == NULL)
	{
		printf("malloc failed!");
		exit(-1);
	}
	list->_data = 0;
	list->_next = list;
	list->_prev = list;
	return list;
}

void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}

void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newNode = _GetNewNode(x);
	newNode->_next = pHead;
	newNode->_prev = pHead->_prev;
	pHead->_prev->_next = newNode;
	pHead->_prev = newNode;
}

void ListPopBack(ListNode* pHead)
{
	assert(pHead && (pHead->_next != pHead));
	ListNode* temp = pHead->_prev;
	pHead->_prev = pHead->_prev->_prev;
	pHead->_prev->_next = pHead;
	free(temp);
	temp = NULL;
}

void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newNode = _GetNewNode(x);
	newNode->_next = pHead->_next;
	newNode->_prev = pHead;
	pHead->_next->_prev = newNode;
	pHead->_next = newNode;
}

void ListPopFront(ListNode* pHead)
{
	assert(pHead && pHead->_next != pHead);
	ListNode* temp = pHead->_next;
	pHead->_next = pHead->_next->_next;
	pHead->_next->_prev = pHead;
	free(temp);
	temp = NULL;
}

ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, LTDataType x)
{
	//在pos前进行插入
	assert(pos);
	ListNode* newNode = _GetNewNode(x);
	newNode->_next = pos;
	newNode->_prev = pos->_prev;
	pos->_prev->_next = newNode;
	pos->_prev = newNode;
}

void ListErase(ListNode* pos)
{
	//删除pos位置的节点
	assert(pos != NULL);
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}

void ListDestory(ListNode* pHead)
{
	assert(pHead);
	while (pHead->_next != pHead)
	{
		ListPopFront(pHead);
	}
	free(pHead);
}

