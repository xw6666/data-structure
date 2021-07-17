#define _CRT_SECURE_NO_WARNINGS 1
//leetcode - 14. 最长公共前缀
//char* longestCommonPrefix(char** strs, int strsSize) {
//    int i = 0;
//    int j = 0;
//    while (strs[i][j] != '\0')
//    {
//        for (i = 0; i < strsSize - 1; i++)
//        {
//            if (strs[i][j] != strs[i + 1][j])
//            {
//                break;
//            }
//        }
//        if (i < strsSize - 1)
//        {
//            break;
//        }
//        j++;
//    }
//    char* res = (char*)malloc(sizeof(char) * (j + 1));
//    for (i = 0; i < j; i++)
//    {
//        res[i] = strs[0][i];
//    }
//    res[i] = '\0';
//    return res;
//}