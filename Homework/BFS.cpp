#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>

//typedef pair<int, int> p;
//
//int n = 0, m = 0;
//
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };   //dxdy是四个向量
//
//bool dfs(vector<vector<char> >& map, p& begin, p& end)
//{
//	if (begin.first == end.first && begin.second == end.second)
//	{
//		return true;
//	}
//
//	for (int i = 0; i < 4; i++)
//	{
//		if (begin.second + dy[i] >= 0 && begin.second + dy[i] < m && begin.first + dx[i] >= 0 && begin.first + dx[i] < n)
//		{
//			if (map[begin.first + dx[i]][begin.second + dy[i]] != '#')
//			{
//				map[begin.first][begin.second] = '#';
//				p temp;
//				temp.first = begin.first + dx[i];
//				temp.second = begin.second + dy[i];
//				cout << temp.first << " " << temp.second << endl;
//				if (dfs(map, temp, end))
//				{
//					return true;
//				}
//				map[begin.first][begin.second] = '.';
//			}
//		}
//	}
//
//	return false;
//}
//
//int bfs(vector<vector<char> >& map, p& begin, p& end)
//{
//	int** d = new int* [n];  //d数组为结果数组，答案在d[end.first][end.second]中
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		d[i] = new int[m];
//	}
//	//初始化d数组
//	for (i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			d[i][j] = -1;
//		}
//	}
//
//	d[begin.first][begin.second] = 0;  //初始化坐标
//	queue<p> q;
//	q.push(p(begin.first, begin.second));  //第一个坐标入栈
//	while (!q.empty())
//	{
//		//q不为空时入队
//		p ch = q.front();
//		q.pop();
//
//		if (ch.first == end.first && ch.second == end.second)
//		{
//			break;
//		}
//
//		for (i = 0; i < 4; i++)
//		{
//			//判断坐标合法性并做出选择
//			if (ch.first + dx[i] >= 0 && ch.first + dx[i] < n && ch.second + dy[i] >= 0 && ch.second + dy[i] < m)
//			{
//				//该坐标处值为-1，则可以搜索
//				if (d[ch.first + dx[i]][ch.second + dy[i]] == -1)
//				{
//					if (map[ch.first + dx[i]][ch.second + dy[i]] == '.' || map[ch.first + dx[i]][ch.second + dy[i]] == 'G')
//					{
//						d[ch.first + dx[i]][ch.second + dy[i]] = d[ch.first][ch.second] + 1;
//						q.push(p(ch.first + dx[i], ch.second + dy[i]));
//					}
//				}
//			}
//		}
//	}
//
//
//	return d[end.first][end.second];
//}
//
//int main()
//{
//	cin >> n >> m;
//	vector<vector<char> > map;
//	int i = 0;
//	p begin, end;
//	for (i = 0; i < n; i++)
//	{
//		vector<char> temp;
//		char ch = 0;
//		int j = 0;
//		for (j = 0; j < m; j++)
//		{
//			cin >> ch;
//			if (ch == 'S')
//			{
//				//起点 - 记录坐标
//				begin.first = i;
//				begin.second = j;
//			}
//			else if (ch == 'G')
//			{
//				//终点 - 记录坐标
//				end.first = i;
//				end.second = j;
//			}
//			temp.push_back(ch);
//		}
//		map.push_back(temp);
//	}
//
//	int ans = bfs(map, begin, end);
//	cout << ans << endl;
//	bool ret = dfs(map, begin, end);
//	cout << ret << endl;
//	return 0;
//}

//void select_sort(int* nums, int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		int min = nums[i];
//		int index = i;
//		for (int j = i + 1; j < n; j++)
//		{
//			if (nums[j] < min)
//			{
//				min = nums[j];
//				index = j;
//			}
//		}
//		//最小值放入i处
//		int temp = nums[i];
//		nums[i] = min;
//		nums[index] = temp;
//		for (int j = 0; j < n; j++)
//		{
//			cout << nums[j] << " ";
//		}
//		cout << endl;
//	}
//}
//
//void merge_sort(int nums, int begin, int end)
//{
//	int mid = (begin + end) / 2;
//
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int* nums = new int[n];
//	for (int i = 0;i < n;i++)
//	{
//		cin >> nums[i];
//	}
//	select_sort(nums, n);
//	delete[] nums;
//	return 0;
//}
//
//double a, b, c, d;
//double f(double x)
//{
//	return a * pow(x, 3) + b * pow(x, 2) +c * x + d;
//}
//
//int main()
//{
//	cin >> a >> b >> c >> d;
//	int s = 0;
//	for (int i = -100; i < 100; i++)
//	{
//		double x1 = (double)f(i);
//		double x2 = (double)f((double)i + 1);
//		if (x1 == 0)
//		{
//			printf("%.2lf ", (double)i);
//			s++;
//		}
//		else if (x1 * x2 < 0)
//		{
//			double l = (double)i;
//			double r = ((double)i + 1);
//			while (r - l >= 1e-4)
//			{
//				double mid = (l + r) / 2;
//				if (f(mid) * f(l) < 0)
//				{
//					r = mid;
//				}
//				else
//				{
//					l = mid;
//				}
//			}
//			printf("%.2lf ", l);
//			s++;
//		}
//		if (s == 3)
//		{
//			break;
//		}
//	}
//	
//	return 0;
//}
