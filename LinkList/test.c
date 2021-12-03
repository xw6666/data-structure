#include "LinkedList.h"

void test1()
{
	ListNode* list = ListCreate();
	ListPushBack(list, 1);
	ListPushBack(list, 2);
	ListPushBack(list, 3);
	ListPushBack(list, 4);
	ListPushBack(list, 5);
	//ListPushFront(list, 2);
	//ListPushFront(list, 3);
	//ListPushFront(list, 4);
	//ListPushFront(list, 5);
	//ListPushFront(list,6);
	//ListPopFront(list);
	//ListPopFront(list);
	//ListPopFront(list);
	//ListPopFront(list);
	//ListPopFront(list);
	//ListPopFront(list);
	//ListNode* findx = ListFind(list, 6);
	//if (findx == NULL)
	//{
	//	printf("没有找到!\n");
	//}
	//else
	//{
	//	printf("找到了!\n");
	//}
	ListPrint(list);
}

void test2()
{
	ListNode* list = ListCreate();
	ListPushFront(list, 6);
	ListPushFront(list, 5);
	ListPushFront(list, 4);
	ListPushFront(list, 2);
	ListPushFront(list, 1);
	ListPrint(list);
	//在4前面插入
	ListNode* findx = ListFind(list, 4);
	if (findx == NULL)
	{
		printf("没有找到");
	}
	else
	{
		ListInsert(findx, 3);
	}
	ListPrint(list);
	ListErase(findx);
	findx = NULL;
	ListPrint(list);
	ListDestory(list);
	list = NULL;
}
int main()
{
	//test1();
	test2();
	return 0;
}