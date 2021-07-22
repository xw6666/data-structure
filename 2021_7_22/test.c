#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//memset - 
//void* memset(void* ptr, int value, size_t num);
//int main()
//{
//	char str1[] = "hello world!";
//	char* ptr = memset(str1, 'x', 5);
//	printf("%s\n", str1);
//	return 0;
//}
//int is_leap_year(int x)
//{
//	if ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0))
//	{
//		return 1;
//	}
//	return 0;
//}
//int main()
//{
//	int y = 0;
//	for (y = 1000; y <= 2000; y++)
//	{
//		//判断y是否为闰年
//		//函数
//		//是闰年，返回1
//		//不是闰年，返回0
//		if (is_leap_year(y))
//		{
//			printf("%d ", y);
//		}
//	}
//
//	return 0;
//}
//int binary_search(int* nums, int target, int numSize)
//{
//	int left = 0;
//	int right = numSize;
//	while (left < right)
//	{
//		int mid = left + ((right - left) >> 1);
//		if (nums[mid] > target)
//		{
//			right = mid;
//		}
//		else if (nums[mid] < target)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	int nums[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int target = 5;
//	int sz = sizeof(nums) / sizeof(nums[0]);
//	int ret = binary_search(nums, target, sz); // TDD - 测试驱动开发
//	if (-1 == ret)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了，下标为%d\n", ret);
//	}
//	return 0;
//}

//int Add(int num)
//{
//	return ++num;
//}
//
//int main(void)
//{
//	int num = 0;
//	int n = 100;
//	while (n--)
//	{
//		num = Add(num);
//		printf("num = %d\n", num);
//	}
//	return 0;
//}

//void Add(int* num)
//{
//	(*num)++;
//}

//链式访问 - 把一个函数值放左另一个函数的参数
//int main(void)
//{
//	printf("%d\n", strlen("abc"));
//	return 0;
//}


//printf返回值是字符的个数
//int main(void)
//{
//	printf("%d", printf("%d", printf("%d", 43)));
//	return 0;
//}

//leetcode - 455. 分发饼干
//int cmp(const void* e1, const void* e2)
//{
//    return (*((int*)e1) - *((int*)e2));
//}
//
//int findContentChildren(int* g, int gSize, int* s, int sSize) {
//    if (sSize == NULL)
//    {
//        return 0;
//    }
//    qsort(g, gSize, sizeof(int), cmp);
//    qsort(s, sSize, sizeof(int), cmp);
//    int cnt = 0;
//    int i = sSize - 1;
//    int j = gSize - 1;
//    while (i >= 0 && j >= 0)
//    {
//        if (s[i] >= g[j])
//        {
//            cnt++;
//            i--;
//            j--;
//        }
//        else
//        {
//            j--;
//        }
//    }
//    return cnt;
//}

//leetcode - 376. 摆动序列
//int wiggleMaxLength(int* nums, int numsSize) {
//    if (numsSize < 3)
//    {
//        if (numsSize == 2 && nums[0] == nums[1])
//        {
//            return 1;
//        }
//        return numsSize;
//    }
//
//    int i = 0;
//    while (i < numsSize - 1 && nums[i] == nums[i + 1])
//    {
//        i++;
//    }
//    if (i == numsSize - 1)
//    {
//        return 1;
//    }
//    int k = 1;  //用于标记下两个元素相减的正负性
//    int ret = 1;
//    if (nums[i + 1] - nums[i] > 0)
//    {
//        k = -1;
//        ret++;
//        i++;
//    }
//    else if (nums[i + 1] - nums[i] < 0)
//    {
//        k = 1;
//        ret++;
//        i++;
//    }
//
//
//    for (i = i; i < numsSize - 1; i++)
//    {
//        if (nums[i + 1] == nums[i])
//        {
//            continue;
//        }
//        if ((nums[i + 1] - nums[i]) / fabs((nums[i + 1] - nums[i])) == k)
//        {
//            k = -k;
//            ret++;
//        }
//    }
//
//    return ret;
//}