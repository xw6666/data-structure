#define _CRT_SECURE_NO_WARNINGS 1
#include "SqStack.h"

//typedef int TreeNodeType;
//
//typedef struct BTNode
//{
//	TreeNodeType val;
//	struct BTNode* left;
//	struct BTNode* right;
//}BTNode, * BiTree;

//ǰ�����
TreeNodeType* PrevOrder(BTNode* root, int* size)
{
	if (root == NULL)
	{
		return NULL;
	}

	TreeNodeType* nums = (TreeNodeType*)malloc(sizeof(TreeNodeType) * 100);
	//��ʼ��ջ
	SqStack s;
	InitStack(&s);
	//����һ���ڵ�ѹջ
	PushStack(&s, root);
	while (!EmptyStack(&s))
	{
		//�ڵ��ջ
		BTNode* Node = PopStack(&s);
		nums[(*size)++] = Node->val;
		//ѹ���ҽڵ�
		if (Node->right != NULL)
		{
			PushStack(&s, Node->right);
		}
		//ѹ����ڵ�
		if (Node->left != NULL)
		{
			PushStack(&s, Node->left);
		}
	}
	return nums;
}

//�ǵݹ��������
TreeNodeType* InOrder(BTNode* root, int* size)
{
	if (root == NULL)
	{
		return NULL;
	}

	TreeNodeType* nums = (TreeNodeType*)malloc(sizeof(TreeNodeType) * 100);
	SqStack s;
	InitStack(&s);
	BTNode* node = root;
	while (node || !EmptyStack(&s))
	{
		while (node)
		{
			PushStack(&s, node);
			node = node->left;
		}
		BTNode* element = PopStack(&s);
		//node = PopStack(&s);
		nums[(*size)++] = element->val;
		if (element->right != NULL)
		{
			node = element->right;
		}
	}

	return nums;
}

//�ǵݹ�������
TreeNodeType* PostOrder(BTNode* root, int* size)
{
	if (root == NULL)
	{
		return NULL;
	}
	TreeNodeType* nums = (TreeNodeType*)malloc(sizeof(TreeNodeType) * 100);
	//��ʼ��ջ
	SqStack s;
	InitStack(&s);
	//����һ���ڵ�ѹջ
	PushStack(&s, root);
	while (!EmptyStack(&s))
	{
		//�ڵ��ջ
		BTNode* Node = PopStack(&s);
		nums[(*size)++] = Node->val;
		//ѹ����ڵ�
		if (Node->left != NULL)
		{
			PushStack(&s, Node->left);
		}
		//ѹ���ҽڵ�
		if (Node->right != NULL)
		{
			PushStack(&s, Node->right);
		}
	}

	//��������
	int left = 0;
	int right = *size - 1;
	while (left < right)
	{
		int temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;
		left++;
		right--;
	}

	return nums;
}

int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->left = NULL;
	A->right = NULL;
	A->val = 1;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->left = NULL;
	B->right = NULL;
	B->val = 2;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->left = NULL;
	C->right = NULL;
	C->val = 3;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->left = NULL;
	D->right = NULL;
	D->val = 4;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->left = NULL;
	E->right = NULL;
	E->val = 5;

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;
	int size = 0;
	//TreeNodeType* nums = PrevOrder(A, &size);
	//TreeNodeType* nums = InOrder(A, &size);
	TreeNodeType* nums = PostOrder(A, &size);  //45231
	for (int i = 0; i < size; i++)
	{
		printf("%d ", nums[i]);
	}
	return 0;
}
