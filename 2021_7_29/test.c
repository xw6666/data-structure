#define _CRT_SECURE_NO_WARNINGS 1
//leetcode - 6. Z 字形变换
//char* convert(char* s, int numRows) {
//    if (numRows == 1)
//    {
//        return s;
//    }
//    int len = strlen(s);
//    // printf("%d", len);
//    if (numRows >= len)
//    {
//        return s;
//    }
//    int* res = (int*)malloc(sizeof(int) * (len + 1));
//    int i = 0;
//    int target = 1;
//    bool flag = false;  //flag == 0时正计数，1时倒计数
//
//    for (i = 0; i < len; i++)
//    {
//        //遍历长度做出标记
//        if (flag == false)
//        {
//            res[i] = target;
//            target++;
//            if (target == numRows)
//            {
//                flag = true;
//            }
//        }
//        else
//        {
//            res[i] = target;
//            target--;
//            if (target == 1)
//            {
//                flag = false;
//            }
//        }
//    }
//
//    char* ret = (char*)malloc(sizeof(char) * (len + 1));
//    int k = 0;
//    for (i = 1; i <= numRows; i++)
//    {
//        for (int j = 0; j < len; j++)
//        {
//            if (res[j] == i)
//            {
//                ret[k++] = s[j];
//            }
//        }
//    }
//    ret[k] = '\0';
//    return ret;
//}