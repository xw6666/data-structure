//#define _CRT_SECURE_NO_WARNINGS 1
//#include <bits/stdc++.h>
//using namespace std;


//int main()
//{
//	int n = 0;
//	cin >> n;
//	int* dp = new int[n + 1];
//	dp[1] = 1;
//	int sum = 0;
//	for (int i = 2; i < n + 1; i++)
//	{
//		sum = 0;
//		int j = i / 2;
//		while (j >= 1)
//		{
//			sum += dp[j];
//			j--;
//		}
//		dp[i] = sum + 1;
//	}
//	cout << dp[n] << endl;
//	return 0;
//}

//vector<int> ans;
//
//void dfs(int i, int n)
//{
//	ans.push_back(i);
//	for (int i = 1; i <= n; i++)
//	{
//		int j = 0;
//		while (j < ans.size())
//		{
//			if (ans[j] == i)
//			{
//				break;
//			}
//			j++;
//		}
//		if (j == ans.size())
//		{
//			dfs(i, n);
//		}
//	}
//	if (ans.size() == (long unsigned int)n)
//	{
//		for (auto i : ans)
//		{
//			printf("%5d", i);
//		}
//		printf("\n");
//	}
//	ans.pop_back();
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		dfs(i, n);
//	}
//	return 0;
//}

//int ans = 0;
//void print(vector<vector<char> >map)
//{
//	for (int i = 0; i < map.size(); i++)
//	{
//		for (int j = 0; j < map.size(); j++)
//		{
//			cout << map[i][j];
//		}
//		cout << endl;
//	}
//}
//void dfs(vector<vector<char> >&map, int x, int y)
//{
//	if (x < 0 || x >= map.size() || y < 0 || y >= map[x].size())
//	{
//		return;
//	}
//
//	if (map[x][y] == 'W')
//	{
//		map[x][y] = '.';
//		for (int i = x - 1; i <= x + 1; i++)
//		{
//			for (int j = y - 1; j <= y + 1; j++)
//			{
//				if (i != x || j != y)
//				{
//					dfs(map, i, j);
//				}
//			}
//		}
//	}
//}
//int main()
//{
//	vector<vector<char> > map;
//	int n = 0, m = 0;
//	cin >> n >> m;
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		vector<char> temp;
//		int j = 0;
//		for (j = 0; j < m; j++)
//		{
//			char t = 0;
//			cin >> t;
//			temp.push_back(t);
//		}
//		map.push_back(temp);
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (map[i][j] == 'W')
//			{
//				dfs(map, i, j);
//				ans++;
//				//print(map);
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}

//p1434
//int dfs(vector<vector<int> >& map, int x, int y)
//{
//	int ans = 0;
//	if (x < 0 || x >= map.size() || y < 0 || y >= map[x].size())
//	{
//		return 0;
//	}
//	//合法坐标
//	int flag = 1;
//	int temp = 0;
//	int tx = 0;
//	int ty = 0;
//	if (x - 1 >= 0 && map[x - 1][y] < map[x][y])
//	{
//		//x-1,y为合法坐标
//		temp = map[x - 1][y];
//		tx = x - 1;
//		ty = y;
//		flag = 0;
//	}
//	if (x + 1 < map.size() && map[x + 1][y] < map[x][y])
//	{
//		//x+1,y为合法坐标
//		if (abs(map[x][y] - map[x + 1][y]) < abs(map[x][y] - temp))
//		{
//			temp = map[x + 1][y];
//			tx = x + 1;
//			ty = y;
//			flag = 0;
//		}
//	}
//	if (y + 1 < map[x].size() && map[x][y + 1] < map[x][y])
//	{
//		if (abs(map[x][y] - map[x][y + 1]) < abs(map[x][y] - temp))
//		{
//			temp = map[x][y + 1];
//			tx = x;
//			ty = y + 1;
//			flag = 0;
//		}
//	}
//	if (y - 1 >= 0 && map[x][y - 1] < map[x][y])
//	{
//		if (abs(map[x][y] - map[x][y - 1]) < abs(map[x][y] - temp))
//		{
//			temp = map[x][y - 1];
//			tx = x;
//			ty = y - 1;
//			flag = 0;
//		}
//	}
//	if (flag == 0)
//	{
//		ans = dfs(map, tx, ty) + 1;
//	}
//	return ans;
//}
//int main()
//{
//	int r = 0, c = 0;
//	cin >> r >> c;
//	vector<vector<int> > map;
//	for (int i = 0; i < r; i++)
//	{
//		vector<int> temp;
//		int j = 0;
//		int t = 0;
//		for (j = 0; j < c; j++)
//		{
//			cin >> t;
//			temp.push_back(t);
//		}
//		map.push_back(temp);
//	}
//
//	int max = -1;
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			int temp = dfs(map, i, j);
//			//cout << temp << endl;
//			max = (temp > max ? temp : max);
//			//cout << max << endl;
//		}
//	}
//	cout << max + 1 << endl;
//	return 0;
//}

//int main()
//{
//	vector<int> target;
//	int n = 0;
//	cin >> n;
//	int temp = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		target.push_back(temp);
//	}
//	cin >> n;  //n包饲料
//
//	return 0;
//}

//#include <cstdio>
//#include <iostream>
//using namespace std;
//#include <cstdlib>
//
//typedef struct S
//{
//	int value;
//	int t;
//}S;
//int main()
//{
//	int target = 0, m = 0;
//	cin >> target >> m;
//	int* dp = new int[target + 1];
//	memset(dp, 0, sizeof(dp));
//	S* arr = new S[m];
//	for (int i = 0; i < m; i++)
//	{
//		cin >> arr[i].value;
//		cin >> arr[i].t;
//	}
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = target; j >= arr[i].value; j--)
//		{
//			dp[j] = max(dp[j], dp[j - arr[i].value] + arr[i].value * arr[i].t);
//		}
//	}
//	cout << dp[target] << endl;
//	delete[] dp;
//
//	return 0;
//}