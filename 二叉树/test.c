#define _CRT_SECURE_NO_WARNINGS 1
#include "BiTree.h"

void test1()
{
	BiTree root = NULL;
	TreeDataType data[] = "ABC##D##E##";
	int i = 0;
	GreateBiTree(&root, data, &i);
	//PrevOrder(root);
	//InOrder(root);
	//PostOrder(root);
}

int main(void)
{
	test1();
	return 0;
}