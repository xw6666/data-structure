#define _CRT_SECURE_NO_WARNINGS 1
//leetcode - 6. Z ���α任
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
//    bool flag = false;  //flag == 0ʱ��������1ʱ������
//
//    for (i = 0; i < len; i++)
//    {
//        //���������������
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