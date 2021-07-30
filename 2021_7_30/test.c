#define _CRT_SECURE_NO_WARNINGS 1
//leetcode - 171. Excel ±íÁĞĞòºÅ
//int titleToNumber(char* columnTitle) {
//    int ret = 0;
//    int tag = 0;
//    int len = strlen(columnTitle);
//    for (int i = len - 1; i >= 0; i--)
//    {
//        ret = ret + pow(26, tag) * (columnTitle[i] - 'A' + 1);
//        tag++;
//    }
//
//    return ret;
//}