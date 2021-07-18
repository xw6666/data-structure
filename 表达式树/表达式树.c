#define _CRT_SECURE_NO_WARNINGS 1
#include "SqStack.h"

BTNode* GetExpressionTree(char* strs)
{
	assert(strs != NULL);
	SqStack s;
	InitStack(&s);
	int i = 0;
	while (strs[i] != '\0')
	{
		//判断是否为操作数，是的话进栈，不是的话出栈两次
		if (strs[i] >= 'a' && strs[i] <= 'z')
		{
			BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
			newNode->left = NULL;
			newNode->right = NULL;
			newNode->val = strs[i];
			PushStack(&s, newNode);
		}
		else
		{
			BTNode* right =  PopStack(&s);
			BTNode* left = PopStack(&s);
			//把出栈元素分别作为右左指针之后入栈
			BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
			newNode->val = strs[i];
			newNode->left = left;
			newNode->right = right;
			PushStack(&s, newNode);
		}

		i++;
	}
	//返回栈中剩下的指针
	return PopStack(&s);
}

//后序遍历检查表达式树的构建
void PostOrder(BTNode* root)
{
	if (!root)
	{
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->val);
}

//中序
void InOrder(BTNode* root)
{
	if (!root)
	{
		return;
	}

	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}

int main()
{
	char strs[] = "ab+cde+**";
	BiTree tree = GetExpressionTree(strs);
	//PostOrder(tree);
	InOrder(tree);
	return 0;
}