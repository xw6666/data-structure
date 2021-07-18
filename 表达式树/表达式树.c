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
		//�ж��Ƿ�Ϊ���������ǵĻ���ջ�����ǵĻ���ջ����
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
			//�ѳ�ջԪ�طֱ���Ϊ����ָ��֮����ջ
			BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
			newNode->val = strs[i];
			newNode->left = left;
			newNode->right = right;
			PushStack(&s, newNode);
		}

		i++;
	}
	//����ջ��ʣ�µ�ָ��
	return PopStack(&s);
}

//������������ʽ���Ĺ���
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

//����
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