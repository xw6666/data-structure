#define _CRT_SECURE_NO_WARNINGS 1
#include "SearchTree.h"

void test1()
{
	BiTree tree = NULL;
	tree = MakeEmpty(&tree);
	tree = Insert(tree, 6);
	tree = Insert(tree, 8);
	tree = Insert(tree, 2);
	tree = Insert(tree, 1);
	tree = Insert(tree, 4);
	tree = Insert(tree, 3);
	InOrder(tree);
	printf("\n");
	//插入测试成功

	//开始测试查找
	BTNode* max = FindMax(tree);
	printf("max = %d\n", max->val);  //8
	
	BTNode* min = FindMin(tree);
	printf("min = %d\n", min->val);    //1

	int target = 0;
	BTNode* targetNode = Find(tree, target);
	if (targetNode == NULL)
	{
		printf("Search failed, please change the target number to try it again!\n");
	}
	else
	{
		printf("The target number is %d\n", targetNode->val);
	}
	//查找测试成功

	//测试删除
	tree = Delete(tree, 8);
	tree = Delete(tree, 8);
	tree = Delete(tree, 6);
	InOrder(tree);
}


int main()
{
	test1();
	return 0;
}