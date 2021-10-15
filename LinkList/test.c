#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkedList.h"

void test1()
{
	LinkedList list = NULL;
	LinkedListInit(&list);
	for (int i = 6; i <= 10; i++)
	{
		LinkedListPushBack(list, i);
	}
	for (int i = 5; i >= 1; i--)
	{
		LinkedListPushFront(list, i);
	}
	LinkedListPrint(list);
}

int main()
{
	test1();
	return 0;
}