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
	//???????Գɹ?

	//??ʼ???Բ???
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
	//???Ҳ??Գɹ?

	//????ɾ??
	tree = Delete(tree, 8);
	tree = Delete(tree, 8);
	tree = Delete(tree, 6);
	InOrder(tree);
}

long long prev = INT_MIN;
bool isValidBST(BTNode* root) {
	if (root == NULL)
	{
		return true;
	}
	if (!isValidBST(root->left))
	{
		return false;
	}
	if (prev >= root->val)
	{
		return false;
	}
	prev = root->val;

	return isValidBST(root->right);
}

void test2()
{
	BiTree tree = NULL;
	tree = MakeEmpty(&tree);
	tree = Insert(tree, 0);
	//tree = Insert(tree, 1);
	//tree = Insert(tree, 4);
	//tree = Insert(tree, 3);
	//tree = Insert(tree, 6);

	printf("%d\n", isValidBST(tree));
}

int main()
{
	//test1();
	test2();
	return 0;
}