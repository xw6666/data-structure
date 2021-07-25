#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//leetcode - 3. 无重复字符的最长子串
//int lengthOfLongestSubstring(char* s) {
//    int slen = strlen(s);
//    if (slen == 0)
//    {
//        return 0;
//    }
//
//    int maxlen = 1;
//    int left = 0;
//    int right = 0;
//    while (right < slen - 1)
//    {
//        right++;
//        int i = 0;
//        for (i = left; i < right; i++)
//        {
//            if (s[i] == s[right])
//            {
//                left = i + 1;
//                break;
//            }
//        }
//        int len = right - left + 1;
//        // printf("len = %d\n",len);
//        if (len > maxlen)
//        {
//            maxlen = len;
//        }
//    }
//
//    return maxlen;
//}

//leetcode - 866. 回文素数
//bool _isPrime(int n)
//{
//    if (n < 2)
//    {
//        return false;
//    }
//    int i = 0;
//    for (i = 2; i <= sqrt(n); i++)
//    {
//        if (n % i == 0)
//        {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//int getDiget(int n)
//{
//    int diget = 0;
//    while (n > 0)
//    {
//        diget++;
//        n = n / 10;
//    }
//    return diget;
//}
//
//bool _isPalindrome(int n)
//{
//    int diget = getDiget(n);
//    char* num = (char*)malloc(sizeof(char) * diget);
//    for (int i = 0; i < diget; i++)
//    {
//        num[i] = n % 10 + '0';
//        n = n / 10;
//    }
//    int left = 0;
//    int right = diget - 1;
//    while (left < right)
//    {
//        if (num[left] != num[right])
//        {
//            return false;
//        }
//        left++;
//        right--;
//    }
//
//    return true;
//}
//
//int primePalindrome(int n) {
//    int i = n;
//    while (1)
//    {
//        int diget = getDiget(i);
//        if (diget == 8)
//        {
//            i = 100000000;
//            continue;
//        }
//        if (diget % 2 == 0)
//        {
//            if (i != 11)
//            {
//                i++;
//            }
//            else
//            {
//                return i;
//            }
//        }
//        else
//        {
//            if (_isPrime(i) && _isPalindrome(i))
//            {
//                return i;
//            }
//            i++;
//        }
//    }
//
//}

int* canSeePersonsCount(int* heights, int heightsSize, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * heightsSize);
    *returnSize = heightsSize;

    int i = 0;
    for (i = 0; i < heightsSize; i++)
    {
        int j = i + 1;
        int cnt = 0;

        while (j < heightsSize && heights[j] < heights[i])
        {
            j++;
            cnt++;
        }
        if (j < heightsSize)
        {
            cnt++;
        }

        int k = 0;
        int max = INT_MIN;
        int tags = INT_MIN;
        int flag = 1;
        for (k = i + 1; k <= j - 1; k++)
        {
            flag = 0;
            if (heights[k] > max)
            {
                max = heights[k];
                tags = k;
            }
        }
        if (flag == 0)
        {
            int temp = j - tags - 1;
            cnt = cnt - temp;
        }
      
        res[i] = cnt;

    }

    res[heightsSize - 1] = 0;
    return res;
}

int main()
{
    int arr[] = { 5,1,2,3,10 };
    int returnSize = 0;
    int* res = canSeePersonsCount(arr, 5, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", res[i]);
    }
    return 0;
}