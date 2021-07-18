#define _CRT_SECURE_NO_WARNINGS 1
//leetcode - 96. 不同的二叉搜索树
//int numTrees(int n) {
//    if (n <= 2)
//    {
//        return n;
//    }
//    int dp[n + 1];
//    int i = 0;
//    for (i = 0; i < n + 1; i++)
//    {
//        dp[i] = 0;
//    }
//    dp[0] = 1;
//    dp[1] = 1;
//    dp[2] = 2;
//
//    i = 3;
//    for (i = 3; i <= n; i++)
//    {
//        int j = 1;
//        for (j = 1; j <= i; j++)
//        {
//            dp[i] = dp[i] + dp[j - 1] * dp[i - j];
//        }
//    }
//
//    return dp[n];
//}