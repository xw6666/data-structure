#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//��ӡ����Ԫ��
void Print(int* nums, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
}

//�������� - ������
//ʱ�临�Ӷ� O(n^2)
//��õ���� O(n)
void InsertSort(int* nums, int n)
{
	//����[0,end]���򣬰�end + 1 ��������ʹ��[0,end+1]����
	int i = 0;
	for (i = 0; i <= n - 2; i++)
	{
		int end = i;
		int temp = nums[end + 1];
		//�жϴ�С
		while (end >= 0 && temp < nums[end])
		{
			end--;
		}
		//��temp����nums[end + 1]��
		//1.�ƶ�
		int j = i;
		while (j >= end + 1)
		{
			nums[j + 1] = nums[j];
			j--;
		}
		//2.����
		nums[end + 1] = temp;
	}
}

void ShellSort(int* nums, int n)
{
	//ϣ�����򣬿�����Ϊ��ֱ�Ӳ���������Ż�
}

//ð������
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
	printf("����ǰ��");
	Print(nums, size);

	printf("�����");
	InsertSort(nums, size);
	Print(nums, size);

}

void TestBubbleSort()
{
	int nums[] = { 4,3,7,1,2,6,9,8,5 };
	int size = sizeof(nums) / sizeof(nums[0]);
	printf("����ǰ��");
	Print(nums, size);

	printf("�����");
	BubbleSort(nums, size);
	Print(nums, size);
}

int main()
{
	TestInsertSort();
	//TestBubbleSort();
	return 0;
}