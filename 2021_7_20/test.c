#define _CRT_SECURE_NO_WARNINGS 1
//#define CIR(r) r* r
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int t;
//	t = CIR(a + b);
//	printf("%d/n", t);
//	return 0;
//}
//int fun(int x)
//{
//	int count = 0;
//	while (x) {
//		count++;
//		x = x & (x - 1);
//	}
//	
//	return count;
//} 
//int main()
//{
//	printf("fun(2017)=%d\n", fun(2019));
//	return 0;
//}

//int maxSonArr(int* nums, int numsSize)
//{
//	if (nums == NULL)
//	{
//		return NULL;
//	}
//	int* dp = (int*)malloc(sizeof(int) * numsSize);
//	int max = INT_MIN;
//	dp[0] = nums[0];
//	if (max < dp[0])
//	{
//		max = dp[0];
//	}
//
//	int i = 0;
//	for (i = 1; i < numsSize; i++)
//	{
//		dp[i] = fmax(dp[i - 1] + nums[i], nums[i]);
//		if (max < dp[i])
//		{
//			max = dp[i];
//		}
//	}
//
//	return max;
//}
//int main(void)
//{
//	int nums[] = { -1,2,0,10,-4,-7,2,-5,7 };
//	int numsSize = sizeof(nums) / sizeof(nums[0]);
//
//	int ret = maxSonArr(nums, numsSize);
//	printf("ret = %d\n", ret);
//	return 0;
//}

//leetcode - 48. 旋转图像
//void rotate(int** matrix, int matrixSize, int* matrixColSize) {
//    int n = matrixColSize[0];
//    int matrix1[n][n];
//
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            matrix1[j][n - i - 1] = matrix[i][j];
//        }
//    }
//
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            matrix[i][j] = matrix1[i][j];
//        }
//    }
//
//}
//
//void rotate(int** matrix, int matrixSize, int* matrixColSize) {
//    int n = matrixColSize[0];
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < n - 1 - i; j++)
//        {
//            int temp = matrix[i][j];
//            matrix[i][j] = matrix[n - j - 1][n - i - 1];
//            matrix[n - j - 1][n - i - 1] = temp;
//        }
//    }
//
//    for (i = 0; i < n / 2; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            int temp = matrix[i][j];
//            matrix[i][j] = matrix[n - i - 1][j];
//            matrix[n - i - 1][j] = temp;
//        }
//    }
//}

//leetcode - 1877. 数组中最大数对和的最小值
//int cmp(const void* e1, const void* e2)
//{
//    return (*((int*)e1) - *((int*)e2));
//}
//
//int minPairSum(int* nums, int numsSize) {
//    qsort(nums, numsSize, sizeof(int), cmp);
//
//    int max = INT_MIN;
//    int left = 0;
//    int right = numsSize - 1;
//    while (left < right)
//    {
//        max = (max < (nums[left] + nums[right]) ? (nums[left] + nums[right]) : max);
//        left++;
//        right--;
//    }
//    return max;
//}

//leetcode - 222. 完全二叉树的节点个数
//int countNodes(struct TreeNode* root) {
//    if (root == NULL)
//    {
//        return 0;
//    }
//    if (root->left == NULL && root->right == NULL)
//    {
//        return 1;
//    }
//    return countNodes(root->left) + countNodes(root->right) + 1;
//}

//leetcode - 1935. 可以输入的最大单词数
//int canBeTypedWords(char* text, char* brokenLetters) {
//    int ret = 0;
//    int brokenLen = strlen(brokenLetters);
//    int i = 0;
//    while (text[i] != '\0')
//    {
//        int flag = 1;
//        while (text[i] != ' ' && text[i] != '\0')
//        {
//            for (int j = 0; j < brokenLen; j++)
//            {
//                if (text[i] == brokenLetters[j])
//                {
//                    flag = 0;
//                    break;
//                }
//            }
//            i++;
//        }
//        if (flag == 1)
//        {
//            ret++;
//        }
//        if (text[i] == ' ')
//        {
//            i++;
//        }
//    }
//    return ret;
//}

//leetcode - 1936. 新增的最少台阶数
//int addRungs(int* rungs, int rungsSize, int dist) {
//    int ret = 0;
//    int pos = 0;
//    int i = 0;
//    for (i = 0; i < rungsSize; i++)
//    {
//        if (pos + dist < rungs[i])
//        {
//            ret = ret + (rungs[i] - pos - 1) / dist;
//        }
//        pos = rungs[i];
//    }
//
//    return ret;
//}