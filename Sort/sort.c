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

//插入排序
void InsertSort(int* nums, int n)
{
	//假设[0,end]有序，把end + 1 插入区间使得[0,end+1]有序
	int end = 0;
	for (end = 0; end <= n - 2; end++)
	{
		int temp = nums[end + 1];
		int i = 0;
		for (i = 0; i <= end; i++)
		{
			if (temp < nums[i])
			{
				//移位
				int j = end;
				while (j >= i)
				{
					nums[j + 1] = nums[j];
					j--;
				}
				//放入
				j++;
				nums[j] = temp;
				break;
			}
		}
		//Print(nums, n);
	}
}

int main(void)
{
	int nums[] = { 4,3,7,1,2,6,9,8,5 };
	int size = sizeof(nums) / sizeof(nums[0]);
	printf("排序前：");
	Print(nums, size);

	printf("排序后：");
	InsertSort(nums, size);
	Print(nums, size);

	return 0;
}