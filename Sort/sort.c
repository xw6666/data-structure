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

//��������
void InsertSort(int* nums, int n)
{
	//����[0,end]���򣬰�end + 1 ��������ʹ��[0,end+1]����
	int end = 0;
	for (end = 0; end <= n - 2; end++)
	{
		int temp = nums[end + 1];
		int i = 0;
		for (i = 0; i <= end; i++)
		{
			if (temp < nums[i])
			{
				//��λ
				int j = end;
				while (j >= i)
				{
					nums[j + 1] = nums[j];
					j--;
				}
				//����
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
	printf("����ǰ��");
	Print(nums, size);

	printf("�����");
	InsertSort(nums, size);
	Print(nums, size);

	return 0;
}