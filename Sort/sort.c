#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//打印数组元素
void Print(int* nums, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
}

//插入排序 - 有问题
//时间复杂度 O(n^2)
//最好的情况 O(n)
void InsertSort(int* nums, int n)
{
	//假设[0,end]有序，把end + 1 插入区间使得[0,end+1]有序
	int i = 0;
	for (i = 0; i <= n - 2; i++)
	{
		int end = i;
		int temp = nums[end + 1];
		//判断大小
		while (end >= 0 && temp < nums[end])
		{
			end--;
		}
		//将temp放在nums[end + 1]上
		//1.移动
		int j = i;
		while (j >= end + 1)
		{
			nums[j + 1] = nums[j];
			j--;
		}
		//2.放置
		nums[end + 1] = temp;
	}
}

void ShellSort(int* nums, int n)
{
	//希尔排序，可以认为是直接插入排序的优化
}

//冒泡排序
void BubbleSort(int* nums, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int j = 0;
		int flag = 1;
		for (j = 0; j < n - 1 - i; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				flag = 0;
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}

void TestInsertSort()
{
	int nums[] = { 4,3,7,1,2,6,9,8,5 };
	int size = sizeof(nums) / sizeof(nums[0]);
	printf("排序前：");
	Print(nums, size);

	printf("排序后：");
	InsertSort(nums, size);
	Print(nums, size);

}

void TestBubbleSort()
{
	int nums[] = { 4,3,7,1,2,6,9,8,5 };
	int size = sizeof(nums) / sizeof(nums[0]);
	printf("排序前：");
	Print(nums, size);

	printf("排序后：");
	BubbleSort(nums, size);
	Print(nums, size);
}

int main()
{
	TestInsertSort();
	//TestBubbleSort();
	return 0;
}