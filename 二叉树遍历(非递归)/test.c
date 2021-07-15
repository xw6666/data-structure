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

//前序遍历
TreeNodeType* PrevOrder(BTNode* root, int* size)
{
	if (root == NULL)
	{
		return NULL;
	}

	TreeNodeType* nums = (TreeNodeType*)malloc(sizeof(TreeNodeType) * 100);
	//初始化栈
	SqStack s;
	InitStack(&s);
	//将第一个节点压栈
	PushStack(&s, root);
	while (!EmptyStack(&s))
	{
		//节点出栈
		BTNode* Node = PopStack(&s);
		nums[(*size)++] = Node->val;
		//压入右节点
		if (Node->right != NULL)
		{
			PushStack(&s, Node->right);
		}
		//压入左节点
		if (Node->left != NULL)
		{
			PushStack(&s, Node->left);
		}
	}
	return nums;
}

//非递归中序遍历
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

//非递归后序遍历
TreeNodeType* PostOrder(BTNode* root, int* size)
{
	if (root == NULL)
	{
		return NULL;
	}
	TreeNodeType* nums = (TreeNodeType*)malloc(sizeof(TreeNodeType) * 100);
	//初始化栈
	SqStack s;
	InitStack(&s);
	//将第一个节点压栈
	PushStack(&s, root);
	while (!EmptyStack(&s))
	{
		//节点出栈
		BTNode* Node = PopStack(&s);
		nums[(*size)++] = Node->val;
		//压入左节点
		if (Node->left != NULL)
		{
			PushStack(&s, Node->left);
		}
		//压入右节点
		if (Node->right != NULL)
		{
			PushStack(&s, Node->right);
		}
	}

	//数组逆序
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
