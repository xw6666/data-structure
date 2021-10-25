//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//#include <vector>
//#include <cstdlib>
//
////打印vector元素
//template <class T>
//void print_vector(vector<T>& v)
//{
//	for (T i : v)
//	{
//		cout << i << " ";
//	}
//	cout << endl;
//}
//
////冒泡排序
//template <class T>
//void bubble_sort(vector<T>& v)
//{
//	for (decltype(v.size())i = 0; i < v.size() - 1; i++)
//	{
//		bool flag = true;
//		for (decltype(v.size())j = 0; j < v.size() - i - 1; j++)
//		{
//			//比较
//			if (v[j] > v[j + 1])
//			{
//				T temp = v[j];
//				v[j] = v[j + 1];
//				v[j + 1] = temp;
//				flag = false;
//			}
//		}
//
//		if (flag == true)
//		{
//			break;
//		}
//		print_vector(v);
//	}
//}
//
////选择排序
//void selec_sort(vector<int>& v)
//{
//	for (decltype(v.size())i = 0; i < v.size() - 1; i++)
//	{
//		int min_index = i;
//		decltype(v.size())j = 0;
//		for (j = i + 1; j < v.size(); j++)
//		{
//			//从i+1开始遍历找最小值放在i处
//			if (v[j] < v[min_index])
//			{
//				min_index = j;
//			}
//		}
//		//最小值下标为j
//		//交换
//		int temp = v[i];
//		v[i] = v[min_index];
//		v[min_index] = temp;
//	}
//}
//
////插入排序
////时间复杂度:最好的情况O(n),最坏的情况O(n^2)
//void insert_sort(vector<int>& v)
//{
//	for (int i = 1; i < v.size(); i++)
//	{
//		int j = i - 1;
//		int temp = v[i];
//		while (j >= 0 && v[j] > temp)
//		{
//			v[j + 1] = v[j];
//			j--;
//		}
//		v[j + 1] = temp;
//		print_vector(v);
//	}
//}
//
//
////希尔排序
//void shell_sort(vector<int>& ivec, int* incrementNums, int n)
//{
//	int increment = 0;
//	for (int i = 0; i < n; i++)
//	{
//		increment = incrementNums[i];
//		for (int j = 0; j < ivec.size(); j++)
//		{
//			for (int k = increment + j; k < ivec.size(); k += increment)
//			{
//				int temp = ivec[k];
//				int l = k - increment;
//				while (l >= 0 && ivec[l] > temp)
//				{
//					ivec[l + increment] = ivec[l];
//					l = l - increment;
//				}
//				ivec[l + increment] = temp;
//			}
//		}
//		print_vector(ivec);
//	}
//}
//
////堆排序：时间复杂度：O(nlogn)
//void _heap_adjust(vector<int>& ivec, int index, int size)
//{
//	int temp = ivec[index];
//	//遍历左节点
//	for (int i = index * 2 + 1; i < size; i = i * 2 + 1)
//	{
//		if (i < size - 1 && ivec[i] < ivec[i + 1])
//		{
//			//如果存在右儿子且右儿子大于i所在的左儿子
//			i++;
//		}
//
//		if(temp < ivec[i])
//		{
//			//父亲结点更小
//			ivec[index] = ivec[i];
//			ivec[i] = temp;
//			index = i;
//			temp = ivec[index];
//		}
//	}
//}
//void heap_sort(vector<int>& ivec)
//{
//	//首先先创建堆 - 调整每个有儿子的结点
//	for (int i = ivec.size() / 2 - 1; i >= 0; i--)
//	{
//		_heap_adjust(ivec, i, ivec.size());
//		//print_vector(ivec);
//	}
//	//开始排序
//	for (int i = ivec.size() - 1; i >= 0; i--)
//	{
//		//每次把堆顶的元素拿到数组最后面，之后减少堆的一个元素再调整堆
//		//交换
//		int temp = ivec[0];
//		ivec[0] = ivec[i];
//		ivec[i] = temp;
//		//调整堆
//		_heap_adjust(ivec, 0, i);
//	}
//}
//
////归并排序
//void merge(vector<int>& ivec, int left, int right, int mid)
//{
//	vector<int> ans;
//	int i = left;
//	int j = mid;
//	while ((i < mid) && (j < right))
//	{
//		if (ivec[i] > ivec[j])
//		{
//			ans.push_back(ivec[i]);
//			i++;
//		}
//		else
//		{
//			ans.push_back(ivec[j]);
//			j++;
//		}
//	}
//	while (i < mid)
//	{
//		ans.push_back(ivec[i]);
//		i++;
//	}
//	while (j < right)
//	{
//		ans.push_back(ivec[j]);
//		j++;
//	}
//	ivec = ans;
//}
//
//void merge_sort(vector<int>& ivec, int begin, int end)
//{
//	if (begin >= end)
//	{
//		return;
//	}
//
//	int mid = (begin + end) / 2;
//	merge_sort(ivec, begin, mid);
//	merge_sort(ivec, mid, end);
//	merge(ivec, begin, end, mid);
//}
//
////快速排序
//void quick_sort(vector<int>& ivec, int begin, int end)
//{
//	//排序区间为[begin,end]
//	if (begin >= end)
//	{
//		return;
//	}
//
//	int temp = ivec[begin];
//	int i = begin;
//	int j = end;
//	while (i < j)
//	{
//		while (ivec[j] >= temp && i < j)
//		{
//			j--;
//		}
//		while (ivec[i] <= temp && i < j)
//		{
//			i++;
//		}
//
//		if (i < j)
//		{
//			int t = ivec[i];
//			ivec[i] = ivec[j];
//			ivec[j] = t;
//			i++;
//			j--;
//		}
//	}
//	//i == j
//	ivec[begin] = ivec[i];
//	ivec[i] = temp;
//	quick_sort(ivec, begin, j - 1);
//	quick_sort(ivec, j + 1, end);
//}
//
//
//int main()
//{
//	vector<int> ivec;
//	int m = 0;
//	cin >> m;
//	int n = 0;
//	cin >> n;
//	while (m--)
//	{
//		int temp = 0;
//		cin >> temp;
//		ivec.push_back(temp);
//	}
//	int* increment = new int[n];
//
//	for (int i = 0; i < n; i++)
//	{
//		int temp = 0;
//		cin >> temp;
//		increment[i] = temp;
//	}
//
//	//bubble_sort(ivec);
//	//selec_sort(ivec);
//	//insert_sort(ivec);
//	shell_sort(ivec, increment, n);
//	//heap_sort(ivec);
//	//quick_sort(ivec, 0, ivec.size() - 1);
//	//merge_sort(ivec, 0, ivec.size());
//	print_vector(ivec);
//	//delete[] increment;
//	return 0;
//}
//
//
//

#include <stdio.h>
#include <stdlib.h>

void shellSort(int* a, int len, int* d, int t);

int main(void)
{
    int i, len, * a, * d, j, t;

    scanf("%d %d", &len, &t);
    a = (int*)malloc(len * sizeof(int));
    d = (int*)malloc(j * sizeof(int));
    for (i = 0; i < len; i++) {
        scanf("%d", &a[i]);
    }
    for (j = 0; j < t; j++) {
        scanf("%d", &d[j]);
    }
    shellSort(a, len, d, t);


    printf("\n");

    return 0;
}

void shellSort(int* a, int n, int* d, int t)
{
    int i, j, h, k, x;
    for (h = 0; h < t; h++) {
        k = d[h];
        for (i = k; i < n; i++) {

            x = a[i];
            j = i - k;
            while (j >= 0 && a[j] > x) {
                a[j + k] = a[j];
                j = j - k;

                a[j + k] = x;
            }
            for (i = 0; i < n; i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
        }
    }
}