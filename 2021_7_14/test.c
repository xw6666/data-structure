#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	char str[20];
//	char ptr1 = (char*)str;
//	char ptr2 = (char*)(str + 5);
//	printf("%d\n", ptr2 - ptr1);
//	return 0;
//}

//#define F(X,Y) ((X)+(Y))
//int main()
//{
//	int a = 3, b = 4;
//	printf("%d\n", F(a++, b++));
//}

//#pragma pack(4)/*����ѡ���ʾ4�ֽڶ��� ƽ̨��VS2013�����ԣ�C����*/
//int main(int argc, char* argv[])
//{
//	struct tagTest1
//	{
//		short a;
//		char d;
//		long b;
//		long c;
//	};
//	struct tagTest2
//	{
//		long b;
//		short c;
//		char d;
//		long a;
//	};
//	struct tagTest3
//	{
//		short c;
//		long b;
//		char d;
//		long a;
//	};
//	struct tagTest1 stT1;
//	struct tagTest2 stT2;
//	struct tagTest3 stT3;
//	printf("%d %d %d\n", sizeof(stT1), sizeof(stT2), sizeof(stT3));
//	return 0;
//}

//��unsigned int��������1�ĸ���
//int main()
//{
//	unsigned int num = 0;
//	scanf("%d", &num);
//	int cnt = 0;
//
//	while (num)
//	{
//		cnt++;
//		num = num & (num - 1);
//	}
//
//	printf("%d\n", cnt);
//	return 0;
//}

//leetcode - 226. ��ת������
//void _reverseTree(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return;
//    }
//    struct TreeNode* temp = root->left;
//    root->left = root->right;
//    root->right = temp;
//    _reverseTree(root->left);
//    _reverseTree(root->right);
//}
//
//struct TreeNode* invertTree(struct TreeNode* root) {
//    if (root == NULL)
//    {
//        return NULL;
//    }
//    _reverseTree(root);
//    return root;
//}