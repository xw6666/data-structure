#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//leetcode - 611. 有效三角形的个数
//int cmp(int* e1, int* e2)
//{
//    return *e1 - *e2;
//}
//
//int triangleNumber(int* nums, int numsSize) {
//    qsort(nums, numsSize, sizeof(int), cmp);
//
//    int ret = 0;
//    for (int i = 0; i < numsSize - 2; i++)
//    {
//        for (int j = i + 1; j < numsSize - 1; j++)
//        {
//            int left = j + 1;
//            int right = numsSize;
//            while (left < right)
//            {
//                int mid = left + ((right - left) >> 1);
//                if (nums[mid] < nums[i] + nums[j])
//                {
//                    left = mid + 1;
//                }
//                else
//                {
//                    right = mid;
//                }
//            }
//
//            ret += left - j - 1;
//        }
//    }
//
//    return ret;
//}

//leetcode - 80. 删除有序数组中的重复项 II
//int removeDuplicates(int* nums, int numsSize) {
//    int len = numsSize;
//    for (int i = 0; i < len - 2; i++)
//    {
//        while (i < len - 2 && nums[i] == nums[i + 2])
//        {
//            for (int j = i + 3; j < len; j++)
//            {
//                nums[j - 1] = nums[j];
//            }
//            len--;
//        }
//    }
//
//    return len;
//}


//leetcode - 81. 搜索旋转排序数组 II
bool binary_search(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize;
    while (left < right)
    {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] > target)
        {
            right = mid;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            return true;
        }
    }

    return false;
}

bool search(int* nums, int numsSize, int target) {
    int i = 0;
    for (i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == target)
        {
            return true;
        }
        if (nums[i] > nums[i + 1])
        {
            break;
        }
    }
    if (i == numsSize - 1)
    {
        if (nums[i] == target)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    if (binary_search(nums, i + 1, target) || binary_search(nums + i + 1, numsSize - i - 1, target))
    {
        return true;
    }

    return false;
}