#define _CRT_SECURE_NO_WARNINGS 1

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