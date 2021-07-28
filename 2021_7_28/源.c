#define _CRT_SECURE_NO_WARNINGS 1

//leetcode - 66. ¼ÓÒ»
//int* plusOne(int* digits, int digitsSize, int* returnSize) {
//    digits[digitsSize - 1] += 1;
//    int i = digitsSize - 1;
//    while (i >= 1 && digits[i] == 10)
//    {
//        digits[i] = 0;
//        digits[i - 1] += 1;
//        i--;
//    }
//    if (digits[0] != 10)
//    {
//        *returnSize = digitsSize;
//        return digits;
//    }
//
//    *returnSize = digitsSize + 1;
//    int* res = (int*)malloc(sizeof(int) * (digitsSize + 1));
//    res[0] = 1;
//    for (int i = 1; i < digitsSize + 1; i++)
//    {
//        res[i] = 0;
//    }
//
//    return res;
//}