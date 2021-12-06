//#include <iostream>
//using namespace std;
//#include <vector>
//#include <cstdio>
//
//void Swap(char& a, char& b)
//{
//	char temp = a;
//	a = b;
//	b = temp;
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	while (n--)
//	{
//		vector<int> ans;
//		vector<int> ans1;
//		int len = 0;
//		cin >> len;
//		char* str = new char[len + 1];
//		scanf("%s", str);
//		int left = 0;
//		int right = len;
//		while (left < right)
//		{
//			//找1
//			while (left < right && str[left] != '1')
//			{
//				left++;
//			}
//			//找0
//			while (left < right && str[right] != '0')
//			{
//				right--;
//			}
//			if (left < right)
//			{
//				Swap(str[left], str[right]);
//				ans.push_back(left);
//				ans1.push_back(right);
//			}
//		}
//		for (int i = ans1.size() - 1; i >= 0; i--)
//		{
//			ans.push_back(ans1[i]);
//		}
//		if (ans.size() != 0)
//		{
//			cout << "1" << endl;
//			cout << ans.size() << " ";
//			for (int i = 0; i < ans.size(); i++)
//			{
//				cout << ans[i] + 1 << " ";
//				if (i == ans.size() - 1)
//				{
//					cout << endl;
//				}
//			}
//		}
//		else
//		{
//			cout << "0" << endl;
//		}
//		delete[] str;
//	}
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	while (n--)
//	{
//		int n = 0;
//		int min = 0;
//		int max = 0;
//		cin >> n >> min >> max;
//		int* arr = new int[n + 1];
//		for (int i = 1; i <= n; i++)
//		{
//			arr[i] = i;
//		}
//		if (min > max)
//		{
//			int temp = arr[min];
//			arr[min] = arr[max];
//			arr[max] = temp;
//		}
//		int left = 1;
//		int right = n;
//		int tag = 1;
//		while (left <= n / 2)
//		{
//			if (arr[left] < min || left > min)
//			{
//				int flag = 1;
//				while (right > n / 2)
//				{
//					if (arr[right] != min && arr[right] != max)
//					{
//						int temp = arr[left];
//						arr[left] = arr[right];
//						arr[right] = temp;
//						right--;
//						flag = 0;
//						break;
//					}
//					right--;
//				}
//				if (flag == 1)
//				{
//					//cout << "-1" << endl;
//					tag = 0;
//					break;
//				}
//			}
//			left++;
//		}
//		int flag = 1;
//		for (int i = 1; i <= n / 2; i++)
//		{
//			if (min > arr[i])
//			{
//				flag = 0;
//				break;
//			}
//		}
//		for (int i = n / 2+ 1; i <= n; i++)
//		{
//			if (max < arr[i])
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1 && tag == 1)
//		{
//			for (int i = 1; i <= n; i++)
//			{
//				cout << arr[i] << " ";
//			}
//			cout << endl;
//		}
//		else
//		{
//			cout << "-1" << endl;
//		}
//		delete[] arr;
//	}
//	return 0;
//}

//#include <iostream>
//using namespace std;
//#include <cstdlib>
//#include <map>
//
//
//int main()
//{
//    long long n = 0;
//    cin >> n;
//    while (n--)
//    {
//        long long r = 0, c = 0;
//        cin >> r >> c;
//        if (r == 1 && c == 1)
//        {
//            cout << 0 << endl;
//        }
//        else
//        {
//            if (r >= 2 && c >= 2)
//            {
//                cout << 2 << endl;
//            }
//            else
//            {
//                cout << (r < c ? r : c) << endl;
//            }
//        }
//    }
//    return 0;
//}

//#include <iostream>
//using namespace std;
//#include <vector>
//
//int dp[1001][1001];
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<vector<int> > data;
//	for (int i = 0; i < n; i++)
//	{
//		vector<int> v;
//		for (int j = 0; j < i + 1; j++)
//		{
//			int temp = 0;
//			cin >> temp;
//			v.push_back(temp);
//		}
//		data.push_back(v);
//	}
//
//	//dp[i][j] 表示到data[i][j]最长路径为dp[i][j]
//	//dp[i][j] = max(dp[i - 1][j],dp[i-1][j-1]) + data[i][j]
//	dp[0][0] = data[0][0];
//	int ans = dp[0][0];
//	for (int i = 1; i < n; i++)
//	{
//		for (int j = 0; j < i + 1; j++)
//		{
//			if (j == 0)
//			{
//				dp[i][j] = dp[i - 1][j] + data[i][j];
//			}
//			else if (j == i)
//			{
//				dp[i][j] = dp[i - 1][j - 1] + data[i][j];
//			}
//			else
//			{
//				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + data[i][j];
//			}
//			ans = max(ans, dp[i][j]);
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}



//#include<iostream>
//using namespace std;
//#include<cstdio>
//#include<cmath>
//#include<string>
//#include<algorithm>
//#include<queue>
//
//int data[21];  //存放各个地窖的地雷数
//bool a[21][21];   //i到j是否能到达
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> data[i];
//	}
//
//	for(int i = 0;;)
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//#include<cstdio>
//#include<cmath>
//#include<string>
//#include<algorithm>
//#include<queue>
//
////int getDiget(int num)
////{
////	int ans = 0;
////	while (num)
////	{
////		ans++;
////		num /= 10;
////	}
////	return ans;
////}
////
////int main()
////{
////	int n = 0;
////	cin >> n;
////	while (n--)
////	{
////		int num = 0;
////		cin >> num;
////		if ((num % 10) % 2 == 0)
////		{
////			cout << 0 << endl;
////		}
////		else
////		{
////			long long digit = getDiget(num);
////			if ((num / (int)(pow(10, digit - 1))) % 2 == 0)
////			{
////				cout << 1 << endl;
////			}
////			else
////			{
////				digit = pow(10, digit - 1);
////				num = num % digit;   //去掉 头位置
////				int flag = 1;
////				int cnt = 0;
////				while (num >= 10)
////				{
////					digit = digit / 10;
////					if ((num / digit) % 2 == 0)
////					{
////						flag = 0;
////						cout << 2 << endl;
////						break;
////					}
////					num = num % digit;
////				}
////				if (flag == 1)
////				{
////					cout << -1 << endl;
////				}
////			}
////		}
////	}
////	return 0;
////}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int a = 0, b = 0;
//	while (n--)
//	{
//		cin >> a >> b;  //假设a更大
//		if (a < b)
//		{
//			long long temp = a;
//			a = b;
//			b = temp;
//		}
//		long long a1 = a;
//		long long b1 = b;
//		long long ans1 = min(a / 2, b / 2);
//		a = a - ans1 * 2;
//		b = b - ans1 * 2;
//		long long ans2 = min(a / 3, b);
//		long long ans = ans2 + ans1;
//		ans1 = min(a1 / 3, b1);
//		a1 = a1 - ans1 * 3;
//		b1 = b1 - ans1;
//		ans2 = min(a1 / 2, b1 / 2);
//		ans = max(ans, ans1 + ans2);
//		cout << ans << endl;
//	}
//	return 0;
//}

#include <set>
#include <iostream>
#include <vector>
using namespace std;
#include  <cstdlib>
#include <algorithm>


int main()
{
	//srand(NULL);
	//int tt = 0;
	//cin >> tt;
	//while (tt--)
	//{
	//	//memset(arr1, 0, sizeof(arr1));
	//	int n = 0;
	//	//set<int> s;
	//	int temp = 0;
	//	cin >> n;
	//	vector<int> v;
	//	for (int i = 0; i < n; i++)
	//	{
	//		cin >> temp;
	//		//int temp = rand();
	//		v.push_back(temp);
	//	}

	//	int sum = n / 2;

	//	sort(v.begin(), v.end());
	//	reverse(v.begin(), v.end());
	//	for (int i = 0; i < v.size(); i++)
	//	{
	//		cout << v[i] << " " << v[v.size() - 1] << endl;
	//		sum--;
	//		if (sum == 0)
	//		{
	//			break;
	//		}
	//	}

	//}
	int arr[100]{ 100,0 };


	return 0;
}