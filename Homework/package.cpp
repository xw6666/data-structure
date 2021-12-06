#include <iostream>
using namespace std;
#include <cstdlib>
//typedef struct S
//{
//	int weight;
//	int value;
//}S;
//
//int main()
//{
//	int target = 0;
//	int n = 0;
//	cin >> target >> n;
//	S* arr = new S[n];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i].weight >> arr[i].value;
//	}
//	long long* dp = new long long[target + 1];
//	memset(dp, 0, sizeof(dp));
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j <= target; j++)
//		{
//			if (j >= arr[i].weight)
//			{
//				dp[j] = max(dp[j],dp[j - arr[i].weight] + arr[i].value);
//			}
//		}
//	}
//	cout << dp[target] << endl;
//	delete[] dp;
//	delete[] arr;
//	return 0;
//}