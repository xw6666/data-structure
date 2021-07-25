#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//leetcode - 5196. �����п��Կ���������
//#define N 4
//typedef int StackElement;
//
//typedef struct SqStack
//{
//	StackElement* Stack;//ջ
//	int top; //ջ��ָ�� 
//	int capacity;//����
//}SqStack;
//
//void InitStack(SqStack* ps)
//{
//	ps->Stack = (StackElement*)malloc(N * sizeof(StackElement));
//	int i = 0;
//	for (i = 0; i < N; i++)
//	{
//		*((ps->Stack) + i) = 0;
//	}
//	ps->capacity = N;
//	ps->top = 0;
//}
//
//void ExpanStack(SqStack* ps)
//{
//	ps->capacity = 2 * ps->capacity;
//	//ע��sizeof��������͵��ֽ�����sizeof(ps->Stack)�����ָ����ֽ�����Ҫô��4Ҫô��8
//	ps->Stack = realloc((ps->Stack), (ps->capacity) * sizeof(StackElement));
//	if ((ps->Stack) == NULL)
//	{
//		exit(-1);
//	}
//}
//
//void PushStack(SqStack* ps, StackElement x)
//{
//	//�����ж�ջ�Ƿ���
//	//�������Ҫ����
//	//ͨ��ջ��ָ�����ж�
//	if (ps->top == ps->capacity - 1)
//	{
//		ExpanStack(ps);
//	}
//
//	ps->Stack[ps->top++] = x;
//	//ps->top++;
//}
//
//StackElement PopStack(SqStack* ps)
//{
//	if (ps->top > 0)
//	{
//		StackElement ret = ps->Stack[ps->top - 1];
//		ps->top--;
//		return ret;
//	}
//}
//
//bool EmptyStack(SqStack* ps)
//{
//	if (ps->top > 0)
//	{
//		return false;
//	}
//
//	return true;
//}
//
//StackElement TopStack(SqStack* ps)
//{
//	if (!EmptyStack(ps))
//	{
//		return ps->Stack[ps->top - 1];
//	}
//}
//
//int* canSeePersonsCount(int* heights, int heightsSize, int* returnSize) {
//	*returnSize = heightsSize;
//	int* res = (int*)malloc(sizeof(int) * heightsSize);
//	
//	int tag = heightsSize - 1;
//	res[tag--] = 0;
//	SqStack s;
//	InitStack(&s);
//	PushStack(&s, heights[heightsSize - 1]);
//	for (int i = heightsSize - 2; i >= 0; i--)
//	{
//		int cnt = 0;
//		while (!EmptyStack(&s) && heights[i] > TopStack(&s))
//		{
//			PopStack(&s);
//			cnt++;
//		}
//		if (!EmptyStack(&s))
//		{
//			cnt++;
//		}
//		PushStack(&s, heights[i]);
//		res[tag--] = cnt;
//	}
//
//	return res;
//}
//
//int main()
//{
//	int arr[] = { 10,6,8,5,11,9 };
//	int sz = 6;
//	int returnSize = 0;
//	int* res = canSeePersonsCount(arr, sz, &returnSize);
//
//	for (int i = 0; i < returnSize; i++)
//	{
//		printf("%d ", res[i]);
//	}
//	return 0;
//}

//leetcode - 16. ��ӽ�������֮��
//int cmp(const void* e1, const void* e2)
//{
//    return ((*((int*)e1)) - (*((int*)e2)));
//}
//
//int threeSumClosest(int* nums, int numsSize, int target) {
//
//    long long ret = INT_MAX;
//    //����
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int i = 0;
//    for (i = 0; i < numsSize - 2; i++)
//    {
//        int j = i + 1;
//        int k = numsSize - 1;
//        while (j < k)
//        {
//            int sum = nums[i] + nums[j] + nums[k];
//            if (sum > target)
//            {
//                if (fabs(sum - target) < fabs(ret - target))
//                {
//                    ret = sum;
//                }
//
//                k--;
//            }
//            else if (sum < target)
//            {
//                if (fabs(sum - target) < fabs(ret - target))
//                {
//                    ret = sum;
//                }
//
//                j++;
//            }
//            else
//            {
//                return target;
//            }
//        }
//    }
//
//    return ret;
//}

//leetcode - 31. ��һ������
void reverse(int* nums, int numsSize)
{
    int left = 0;
    int right = numsSize - 1;
    while (left < right)
    {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
}

//void nextPermutation(int* nums, int numsSize) {
//    if (numsSize == 1)
//    {
//        return;
//    }
//
//    int i = numsSize - 1;
//    while (i > 0)
//    {
//        if (nums[i] <= nums[i - 1])
//        {
//            i--;
//            // printf("%d ",i);
//        }
//        else
//        {
//            //����
//            //��i - 1����i������е���СԪ�ؽ���
//            int min = INT_MAX;
//            int tag = 0;
//            int k = 0;
//            for (k = i; k < numsSize; k++)
//            {
//                if (nums[k] <= min && nums[k] > nums[i - 1])
//                {
//                    tag = k;
//                    min = nums[k];
//                }
//            }
//            int temp = nums[i - 1];
//            nums[i - 1] = nums[tag];
//            nums[tag] = temp;
//            //reversei�����
//            reverse(nums + i, numsSize - i);
//            break;
//        }
//    }
//    if (i == 0)
//    {
//        //˵��ȫ��nums[i - 1] >= nums[i]
//        reverse(nums, numsSize);
//    }
//}