//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//#include <vector>
//#include <cstdlib>
//
////��ӡvectorԪ��
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
////ð������
//template <class T>
//void bubble_sort(vector<T>& v)
//{
//	for (decltype(v.size())i = 0; i < v.size() - 1; i++)
//	{
//		bool flag = true;
//		for (decltype(v.size())j = 0; j < v.size() - i - 1; j++)
//		{
//			//�Ƚ�
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
////ѡ������
//void selec_sort(vector<int>& v)
//{
//	for (decltype(v.size())i = 0; i < v.size() - 1; i++)
//	{
//		int min_index = i;
//		decltype(v.size())j = 0;
//		for (j = i + 1; j < v.size(); j++)
//		{
//			//��i+1��ʼ��������Сֵ����i��
//			if (v[j] < v[min_index])
//			{
//				min_index = j;
//			}
//		}
//		//��Сֵ�±�Ϊj
//		//����
//		int temp = v[i];
//		v[i] = v[min_index];
//		v[min_index] = temp;
//	}
//}
//
////��������
////ʱ�临�Ӷ�:��õ����O(n),������O(n^2)
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
////ϣ������
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
////������ʱ�临�Ӷȣ�O(nlogn)
//void _heap_adjust(vector<int>& ivec, int index, int size)
//{
//	int temp = ivec[index];
//	//������ڵ�
//	for (int i = index * 2 + 1; i < size; i = i * 2 + 1)
//	{
//		if (i < size - 1 && ivec[i] < ivec[i + 1])
//		{
//			//��������Ҷ������Ҷ��Ӵ���i���ڵ������
//			i++;
//		}
//
//		if(temp < ivec[i])
//		{
//			//���׽���С
//			ivec[index] = ivec[i];
//			ivec[i] = temp;
//			index = i;
//			temp = ivec[index];
//		}
//	}
//}
//void heap_sort(vector<int>& ivec)
//{
//	//�����ȴ����� - ����ÿ���ж��ӵĽ��
//	for (int i = ivec.size() / 2 - 1; i >= 0; i--)
//	{
//		_heap_adjust(ivec, i, ivec.size());
//		//print_vector(ivec);
//	}
//	//��ʼ����
//	for (int i = ivec.size() - 1; i >= 0; i--)
//	{
//		//ÿ�ΰѶѶ���Ԫ���õ���������棬֮����ٶѵ�һ��Ԫ���ٵ�����
//		//����
//		int temp = ivec[0];
//		ivec[0] = ivec[i];
//		ivec[i] = temp;
//		//������
//		_heap_adjust(ivec, 0, i);
//	}
//}
//
////�鲢����
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
////��������
//void quick_sort(vector<int>& ivec, int begin, int end)
//{
//	//��������Ϊ[begin,end]
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