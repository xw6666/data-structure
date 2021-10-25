//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//#include <vector>
//
//void init(vector<vector<int>>& data, int r, int c, int t)
//{
//	for (int i = 0; i < t; i++)
//	{
//		vector<int> value;
//		for (int i = 0; i < 3; i++)
//		{
//			int temp = 0;
//			cin >> temp;
//			value.push_back(temp);
//		}
//		data.push_back(value);
//	}
//}
//
//void printData(vector < vector<int>>& data, int r, int c, int t)
//{
//	cout << r << " " << c << " " << t << endl;
//	cout << endl;
//	for (int i = 0; i < data.size(); i++)
//	{
//
//		cout << data[i][0] << " " << data[i][1] << " " << data[i][2] << endl;
//		cout << endl;
//	}
//}
//
//int main()
//{
//	vector<vector<int>> data;
//
//	int r = 0;   //行数
//	int c = 0;   //列数
//	int t = 0;   //元素个数
//	cin >> r;
//	cin >> c;
//	cin >> t;
//
//	init(data, r, c, t);
//	//printData(data, r, c, t);
//
//	//对二号位元素进行插排
//	for (int i = 1; i < t; i++)
//	{
//		int temp[3] = { 0 };
//		temp[0] = data[i][0];
//		temp[1] = data[i][1];
//		temp[2] = data[i][2];
//		int j = i - 1;
//		while (j >= 0 && data[j][1] > temp[1])
//		{
//
//			data[j + 1][0] = data[j][0];
//			data[j + 1][1] = data[j][1];
//			data[j + 1][2] = data[j][2];
//			j--;
//			
//		}
//		data[j + 1][0] = temp[0];
//		data[j + 1][1] = temp[1];
//		data[j + 1][2] = temp[2];
//	}
//
//	////行列号互换
//	for (int i = 0; i < t; i++)
//	{
//		int temp = data[i][1];
//		data[i][1] = data[i][0];
//		data[i][0] = temp;
//	}
//
//	printData(data, c, r, t);
//
//	return 0;
//}

#include <iostream>
using namespace std;
#include <vector>

int f(vector<int>& value, int a, int b, bool& flag)
{
	int time = 0;
	cout << time << endl;
	if (a == b)
	{
		return time;
	}
	else
	{
		if (a + value[a] < value.size() && a - value[a] >= 0)
		{
			time += (fmin(f(value, a + value[a], b, flag), f(value, a - value[a], b, flag)) + 1);
			cout << time << endl;

		}
		else if (a + value[a] < value.size() && a - value[a] < 0)
		{
			time += (f(value, a + value[a], b, flag) + 1);
			cout << time << endl;

		}
		else if (a + value[a] >= value.size() && a - value[a] >= 0)
		{
			time += (f(value, a - value[a], b, flag) + 1);
			cout << time << endl;

		}
		else
		{
			flag = false;
			return -1;
		}
	}
}

int main()
{
	vector<int> value;
	int n = 0;
	int begin = 0;
	int end = 0;
	cin >> n >> begin >> end;
	begin--;
	end--;
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		value.push_back(temp);
	}

	int ret = f(value, begin, end, flag);
	if (flag == true)
	{
		cout << ret << endl;
	}
	else
	{
		cout << -1 << endl;
	}

	return 0;
}