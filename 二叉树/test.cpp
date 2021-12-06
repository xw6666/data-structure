#define _CRT_SECURE_NO_WARNINGS 1
#include "BiTree.h"

void test1()
{
	BiTree root = NULL;
	TreeDataType data[] = "ABC##D##E##";
	int i = 0;
	GreateBiTree(&root, data, &i);
	PrevOrder(root);
	cout << endl;
	InOrder(root);
	cout << endl;
	PostOrder(root);
	cout << endl;
	LevelOrder(root);
	if (BinaryTreeComplete(root))
	{
		cout << "是完全二叉树" << endl;
	}
	else
	{
		cout << "不是完全二叉树" << endl;
	}
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

BTNode* BinaryTreeFind(BTNode* root, TreeDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->val == x)
	{
		return root;
	}
	
	BTNode* ans = BinaryTreeFind(root->left, x);
	if (ans != NULL)
	{
		return ans;
	}
	return BinaryTreeFind(root->right, x);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	else
	{
		return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
	}
}

int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return (1 + fmax(BinaryTreeDepth(root->left), BinaryTreeDepth(root->right)));
}


int main(void)
{
	test1();
	//BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	//A->val = 'A';
	//A->left = NULL;
	//A->right = NULL;

	//BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	//B->val = 'B';
	//B->left = NULL;
	//B->right = NULL;

	//BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	//C->val = 'C';
	//C->left = NULL;
	//C->right = NULL;

	//BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	//D->val = 'D';
	//D->left = NULL;
	//D->right = NULL;

	//BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	//E->val = 'E';
	//E->left = NULL;
	//E->right = NULL;

	//BTNode* F = (BTNode*)malloc(sizeof(BTNode));
	//F->val = 'F';
	//F->left = NULL;
	//F->right = NULL;

	//A->left = B;
	//A->right = C;
	//B->left = D;
	//B->right = E;
	//C->right = F;
	//printf("%d\n", BinaryTreeLevelKSize(A, 3));
	//printf("%d\n", BinaryTreeDepth(A));
	return 0;
}

