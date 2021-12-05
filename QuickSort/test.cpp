#include <iostream>
using namespace std;
#include <stdio.h>
#include <assert.h>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <stack>
#define MAX 50000
void print(int* a, int size)
{
	assert(a);
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(int* a, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		bool flag = 1;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				flag = 0;
				Swap(&a[j], &a[j + 1]);
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}

void InsertSort(int* a, int begin, int end)
{
	assert(a);
	for (int i = begin + 1; i <= end; i++)
	{
		int temp = a[i];
		int j = i - 1;
		while (j >= begin && a[j] > temp)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}

int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
	else
	{
		//a[left] >= a[mid]
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

//hoare版本快排
int Version1(int* a, int begin, int end)
{
	//对[begin,end]进行快一趟快排
	assert(a);
	int keyi = GetMidIndex(a, begin, end);    //三数取中优化
	Swap(&a[begin], &a[keyi]);
	int temp = a[begin];   //以左边第一个元素为基准
	int left = begin;
	int right = end;
	while (left < right)
	{
		//右边先动找小的
		while (left < right && a[right] >= temp)
		{
			right--;
		}
		//左边后动找大的
		while (left < right && a[left] <= temp)
		{
			left++;
		}
		if (left < right)
		{
			//交换left和right处元素
			Swap(&a[left], &a[right]);
		}
	}
	//left与right相遇，将基准值和left交换
	a[begin] = a[left];
	a[left] = temp;
	return left;
}

//挖坑版
int Version2(int* a, int left, int right)
{
	assert(a);
	//int keyi = GetMidIndex(a, left, right);
	//Swap(&a[keyi], &a[left]);
	int temp = a[left];  //基准
	int hole = left;    //坑
	while (left < right)
	{
		//右边先动 - 找小的
		while (left < right && a[right] >= temp)
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;
		//左边动找大的
		while (left < right && a[left] <= temp)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = temp;
	return hole;
}

//快慢指针版
int Version3(int* a, int left, int right)
{
	assert(a);
	int keyi = GetMidIndex(a, left, right);
	Swap(&a[keyi], &a[left]);
	int temp = a[left];  //基准
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < temp)
		{
			//找到小的
			Swap(&a[++prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[prev], &a[left]);

	return prev;
}
void QuickSort(int* a, int begin, int end)
{
	assert(a);
	if (begin >= end)
	{
		return;
	}
	//if (end - begin <= 15)
	//{
	//	InsertSort(a, begin, end);
	//}
	//else
	{
		int keyi = Version2(a, begin, end);   //进行一趟快排
		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
}

void QuickSortNoneR(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	stack<int> st;
	st.push(begin);
	st.push(end);
	while (!st.empty())
	{
		int right = st.top();
		st.pop();
		int left = st.top();
		st.pop();
		if (left < right)   //进入排序的条件，注意等于都不排
		{
			int keyi = Version3(a, left, right);   //进行单趟快排
			//分割区间为[left,keyi-1],[keyi+1,right]
			st.push(keyi + 1);
			st.push(right);
			st.push(left);
			st.push(keyi - 1);
		}
	}
}

void TestQuickSort()
{
	int* arr = new int[MAX];
	memset(arr, 0, sizeof(arr));
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		int temp = rand() % 1000;
		arr[i] = 1;
	}
	time_t begin;
	time_t end;

	//print(arr, MAX);
	begin = clock();
	QuickSort(arr, 0, MAX - 1);
	end = clock();
	//print(arr, MAX);
	cout << "QuickSort:" << end - begin << "ms" << endl;
	delete[] arr;
}

void TestBubbleSort()
{
	int* arr = new int[MAX];
	memset(arr, 0, sizeof(arr));
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		int temp = rand() % 1000;
		arr[i] = temp;
	}
	time_t begin;
	time_t end;

	//print(arr, MAX);
	begin = clock();
	BubbleSort(arr, MAX);
	end = clock();
	//print(arr, MAX);
	cout << "BubbleSort:" << end - begin << "ms" << endl;
	delete[] arr;
}

void TestInsertSort()
{
	int* arr = new int[MAX];
	memset(arr, 0, sizeof(arr));
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		int temp = rand() % 1000;
		arr[i] = temp;
	}
	time_t begin;
	time_t end;

	//print(arr, MAX);
	begin = clock();
	InsertSort(arr, 0, MAX - 1);
	end = clock();
	//print(arr, MAX);
	cout << "InsertSort:" << end - begin << "ms" << endl;
	delete[] arr;
}

void TestQuickSortNoneR()
{
	int* arr = new int[MAX];
	memset(arr, 0, sizeof(arr));
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		int temp = rand() % 1000;
		arr[i] = temp;
	}
	time_t begin;
	time_t end;

	//print(arr, MAX);
	begin = clock();
	QuickSortNoneR(arr, 0, MAX - 1);
	end = clock();
	print(arr, MAX);
	cout << "QuickSortNoneR:" << end - begin << "ms" << endl;
	delete[] arr;
}

int main()
{
	cout << "本次数据量为" << MAX << "个" << endl;
	//TestBubbleSort();
	TestQuickSort();
	//TestQuickSortNoneR();
	TestInsertSort();

	return 0;
}