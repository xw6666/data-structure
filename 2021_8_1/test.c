#define _CRT_SECURE_NO_WARNINGS 1

//leetcod - 1337. 矩阵中战斗力最弱的 K 行
//bool isExit(int* res, int k, int tag)
//{
//    for (int i = 0; i < k; i++)
//    {
//        if (res[i] == tag)
//        {
//            return true;
//        }
//    }
//
//    return false;
//}
//
//int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
//    *returnSize = k;
//    int* res = (int*)malloc(sizeof(int) * k);
//    for (int i = 0; i < k; i++)
//    {
//        res[i] = -1;
//    }
//    int flag = 0;
//    int i = 0;
//    int j = 0;
//    for (j = 0; j < matColSize[0]; j++)
//    {
//        for (i = 0; i < matSize; i++)
//        {
//            if (mat[i][j] == 0 && (!isExit(res, k, i)))
//            {
//                if (flag >= k)
//                {
//                    return res;
//                }
//                res[flag++] = i;
//            }
//
//        }
//    }
//
//    for (int i = 0; i < k; i++)
//    {
//        if (res[i] == -1)
//        {
//            for (int j = 0; j < matSize; j++)
//            {
//                if (!isExit(res, k, j) && i < k)
//                {
//                    res[i++] = j;
//                }
//            }
//
//        }
//    }
//
//    return res;
//}