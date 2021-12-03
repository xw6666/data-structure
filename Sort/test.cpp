#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>
#include <iostream>
using namespace std;
////
////void print_arr(int* fly, int numsSize)
////{
////	int i = 0;
////	for (i = 0; i < numsSize; i++)
////	{
////		printf("%d ", fly[i]);
////	}
////	printf("\n");
////}
////
////void shell_sort(int* fly, int numsSize, int* incrementArr, int incrementSize)
////{
////	int i = 0;
////	for (i = 0; i < incrementSize; i++)
////	{
////		int increment = incrementArr[i];
////		//开始希尔排序
////		int j = 0;
////		for (j = 0; j < numsSize; j++)
////		{
////			int k = 0;
////			for (k = j + increment; k < numsSize; k += increment)
////			{
////				int l = k - increment;
////				int  temp = fly[k];
////				while (l >= j && fly[l] > temp)
////				{
////					//向后移动
////					fly[l + increment] = fly[l];
////					l = l - increment;
////				}
////				//找到插入点
////				fly[l + increment] = temp;
////			}
////		}
////		//打印数组元素
////		print_arr(fly, numsSize);
////	}
////}
////
////int main()
////{
////	int fly[50] = { 0 };
////	int m = 0;
////	scanf("%d", &m);
////	int n = 0;
////	scanf("%d", &n);
////	int i = 0;
////	while (m--)
////	{
////		scanf("%d", &fly[i]);
////		i++;
////	}
////	m = i;
////	int increment[10];
////	i = 0;
////	while (n--)
////	{
////		scanf("%d", &increment[i]);
////		i++;
////	}
////	n = i;
////	shell_sort(fly, m, increment, n);
////
////
////	return 0;
////}
//
//#include <iostream>
//#include <stdio.h>
//using namespace std;
//int main()
//{
//    int i, t, n;
//    scanf("%d", &n);
//    int a[n];
//    int flag = false;
//    for (i = 0; i < n; i++) {
//
//        scanf("%d", &a[i]);
//    }
//    for (int i = 0; i < n - 1; i++)
//    {
//
//        for (int j = 0; j < n - i; j++)
//        {
//            if (a[j] > a[j + 1]) {
//
//                t = a[j];
//                a[j] = a[j + 1];
//                a[j + 1] = t;
//                flag = true;
//            }
//
//        }	for (int j = 0; j < n; j++) {
//            printf("%d ", a[j]);
//        }
//
//        if (!flag) {
//            break;
//        }
//        else {
//            flag = false;
//        }
//
//        printf("\n");
//    }
//
//    return 0;
//}

//#include <iostream>
//using namespace std;
//#include <map>
//#include <vector>;
//
//bool isAchieve(vector<int>& data)
//{
//	int sum = 0;
//	for (int i = 0; i < data.size(); i++)
//	{
//		sum += data[i];
//	}
//	double target = sum / 4.0;
//	
//	for (int i = 0; i < data.size(); i++)
//	{
//		int temp = data[i];
//		if (temp > target)
//		{
//			return false;
//		}
//		else if (temp == target)
//		{
//			continue;
//		}
//		else
//		{
//			//temp < target
//			int flag = 0;
//			for (int j = 0; j < data.size(); j++)
//			{
//				if (j == i)
//				{
//					continue;
//				}
//				//比较
//				if (data[j] + temp == target)
//				{
//					flag = 1;
//					break;
//				}
//			}
//			if (flag == 0)
//			{
//				//没有匹配成边
//				return false;
//			}
//		}
//	}
//
//	return true;
//	
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//
//	while (n--)
//	{
//		int num = 0;
//		cin >> num;
//		vector<int> data;
//		while (num--)
//		{
//			int temp = 0;
//			cin >> temp;
//			data.push_back(temp);
//		}
//		//判断
//		if (isAchieve(data))
//		{
//			cout << "yes" << endl;
//		}
//		else
//		{
//			cout << "no" << endl;
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int arr1[] = { 1,7,8 };
//	int arr2[] = { 2,4,6,8,10,11 };
//	int sz1 = sizeof(arr1) / sizeof(int);
//	int sz2 = sizeof(arr2) / sizeof(int);
//	int* ans = new int[sz1 + sz2];
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	while (i < sz1 && j < sz2)
//	{
//		if (arr1[i] < arr2[j])
//		{
//			ans[k++] = arr1[i++];
//		}
//		else
//		{
//			ans[k++] = arr2[j++];
//		}
//		
//	}
//	while (i < sz1)
//	{
//		ans[k++] = arr1[i++];
//	}
//	while (j < sz2)
//	{
//		ans[k++] = arr2[j++];
//	}
//
//	for (i = 0; i < k; i++)
//	{
//		cout << ans[i] << " ";
//	}
//	cout << endl;
//
//	delete[] ans;
//
//	return 0;
//}

//void MergeSortNonR(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	if (tmp == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//
//	int gap = 1;
//	while (gap < n)
//	{
//		for (int i = 0; i < n; i += 2 * gap)
//		{
//			// [i,i+gap-1] [i+gap,i+2*gap-1]
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i + gap, end2 = i + 2 * gap - 1;
//			//printf("[%d,%d][%d,%d]", begin1, end1, begin2, end2);
//
//			// end1 越界，[begin2,end2]不存在
//			if (end1 >= n)
//			{
//				end1 = n - 1;
//			}
//
//			//[begin1,end1]存在 [begin2,end2]不存在
//			if (begin2 >= n)
//			{
//				begin2 = n - 1;
//				end2 = n - 1;
//			}
//
//			if (end2 >= n)
//			{
//				end2 = n - 1;
//			}
//
//			printf("[%d,%d][%d,%d]", begin1, end1, begin2, end2);
//			if (begin1 == 8 && end1 == 8 && begin2 == 8 && end2 == 8)
//			{
//				int x = 0;
//			}
//
//			int index = i;
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (a[begin1] < a[begin2])
//				{
//					tmp[index++] = a[begin1++];
//				}
//				else
//				{
//					tmp[index++] = a[begin2++];
//				}
//			}
//
//			while (begin1 <= end1)
//			{
//				tmp[index++] = a[begin1++];
//			}
//
//			while (begin2 <= end2)
//			{
//				tmp[index++] = a[begin2++];
//			}
//		}
//		printf("\n");
//
//		// 把归并数据拷贝回原数组
//		for (int i = 0; i < n; ++i)
//		{
//			a[i] = tmp[i];
//		}
//
//		gap *= 2;
//	}
//
//	free(tmp);
//	tmp = NULL;
//}