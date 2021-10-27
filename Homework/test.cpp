#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//#include <vector>
//#include <cmath>
#include <cstdio>
#include <cstdlib>
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

//#include <iostream>
//using namespace std;
//#include <vector>
//
//int f(vector<int>& value, int a, int b, bool& flag)
//{
//	int time = 0;
//	cout << time << endl;
//	if (a == b)
//	{
//		return time;
//	}
//	else
//	{
//		if (a + value[a] < value.size() && a - value[a] >= 0)
//		{
//			time += (fmin(f(value, a + value[a], b, flag), f(value, a - value[a], b, flag)) + 1);
//			cout << time << endl;
//
//		}
//		else if (a + value[a] < value.size() && a - value[a] < 0)
//		{
//			time += (f(value, a + value[a], b, flag) + 1);
//			cout << time << endl;
//
//		}
//		else if (a + value[a] >= value.size() && a - value[a] >= 0)
//		{
//			time += (f(value, a - value[a], b, flag) + 1);
//			cout << time << endl;
//
//		}
//		else
//		{
//			flag = false;
//			return -1;
//		}
//	}
//}
//
//int main()
//{
//	vector<int> value;
//	int n = 0;
//	int begin = 0;
//	int end = 0;
//	cin >> n >> begin >> end;
//	begin--;
//	end--;
//	bool flag = true;
//	for (int i = 0; i < n; i++)
//	{
//		int temp = 0;
//		cin >> temp;
//		value.push_back(temp);
//	}
//
//	int ret = f(value, begin, end, flag);
//	if (flag == true)
//	{
//		cout << ret << endl;
//	}
//	else
//	{
//		cout << -1 << endl;
//	}
//
//	return 0;
//}


//int getLowDigit(int n)
//{
//	if (n % 10 == 0 || n % 10 == 1)
//	{
//		return (n % 10);
//	}
//
//	int temp = n % 10;
//	int x = temp;
//	int arr[4] = { 0 };
//	//找到余数循环
//	int i = 1;
//	arr[0] = temp;
//	while (1)
//	{
//		int flag = 1;
//		x = x * temp % 10;
//		for (int j = 0; j < 4; j++)
//		{
//			if (arr[j] == x)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 0)
//		{
//			break;
//		}
//		else
//		{
//			arr[i++] = x;
//		}
//	}
//	//arr数组填充完毕
//	int ret = arr[(n - 1) % i];
//	
//	return ret;
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int ret = getLowDigit(n);
//
//	cout << ret << endl;
//
//	return 0;
//}

//int binary_search(int*nums, int numsSize,int target)
//{
//	int left = 0;
//	int right = numsSize;
//	while (left < right)
//	{
//		int mid = left + ((right - left) >> 1);
//		if (nums[mid] > target)
//		{
//			right = mid;
//		}
//		else if (nums[mid] < target)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	cin >> n >> m;
//	vector<int> nums;
//
//	for (int i = 0; i < n; i++)
//	{
//		int temp = 0;
//		cin >> temp;
//		nums.push_back(temp);
//	}
//
//	while (m--)
//	{
//		int target = 0;
//		cin >> target;
//		int ret = (lower_bound(nums.begin(), nums.end(), target) - nums.begin());
//		if (target == nums[ret])
//		{
//			cout << ret + 1 << " ";
//		}
//		else
//		{
//			cout << "-1" << " ";
//		}
//	}
//	
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d %d", &n, &m);
//	vector<int> nums;
//	int temp = 0;
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &temp);
//		nums.push_back(temp);
//	}
//	int target = 0;
//	
//	while (m--)
//	{
//		scanf("%d", &target);
//		int left = 0;
//		int right = nums.size() - 1;
//		while (left < right)
//		{
//			int mid = left + ((right - left) >> 1);
//			if (nums[mid] >= target)
//			{
//				right = mid - 1;
//			}
//			else
//			{
//				left = mid;
//			}
//		}
//		if (nums[left] != target)
//		{
//			printf("-1 ");
//		}
//		else
//		{
//			printf("%d ", left + 1);
//		}
//	}
//	return 0;
//}

//判断fib数列是否能被3整除
//int main()
//{
//	int arr[8] = { 1,2,0,2,2,1,0,1 };
//	int n = 0;
//	cin >> n;
//	cout << arr[(n - 1) % 8] << endl;
//
//	return 0;
//}


//快速幂 - 递归实现
//int power1(int a, int n)
//{
//	//求a的n次方
//	int ans = 0;
//	if (n == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		ans = power1(a * a, n / 2);
//		if (n % 2)
//		{
//			//奇数情况
//			ans *= a;
//		}
//	}
//	return ans;
//}

//快速幂 - 非递归实现
//int power2(int a, int n)
//{
//	int ans = 1;
//	while (n)
//	{
//		if (n % 2)
//		{
//			//n为奇数
//			ans *= a;
//		}
//		a = a * a;  //底数平方
//		n /= 2;
//	}
//	return ans;
//}
//int main()
//{
//	int a = 0;
//	int n = 0;
//	cin >> a >> n;
//	cout << "pow：" << pow(a, n) << endl;
//	cout << "快速幂递归：" << power1(a, n) << endl;
//	cout << "快速幂非递归：" << power2(a, n) << endl;
//	return 0;
//}


//二分查找

//int lower_binary_search(int* nums, int numsSize, int target)
//{
//	int left = 0;
//	int right = numsSize - 1;
//	while (left <= right)
//	{
//		int mid = left + ((right - left) >> 1);
//		if (nums[mid] >= target)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			left = mid + 1;
//		}
//	}
//	if (nums[left] == target)
//	{
//		return left;
//	}
//	return -1;
//}
//int upper_binary_search(int* nums, int numsSize, int target)
//{
//	int left = 0;
//	int right = numsSize - 1;
//	while (left <= right)
//	{
//		int mid = left + ((right - left) >> 1);
//		if (nums[mid] <= target)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			right = mid - 1;
//		}
//	}
//	if (nums[right] == target)
//	{
//		return right;
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[] = { 0,2,2,2,2,5,6,7,8,9 };
//	int target = 2;
//	cout << lower_binary_search(arr, 10, target) << endl;
//	cout << upper_binary_search(arr, 10, target) << endl;
//	return 0;
//}


//p1226

//long long power(long long a, long long b, long long p)
//{
//	long long ret = 1;
//	while (b)
//	{
//		if (b & 1)
//		{
//			ret = ret * a % p;
//		}
//		a = a * a % p;
//		b = (b >> 1);
//	}
//	return ret;
//}
//
//int main()
//{
//	long long a = 0, b = 0, p = 0;
//	scanf("%lld %lld %lld", &a, &b, &p);
//	long long ret = power(a, b, p);
//	printf("%lld^%lld mod %lld=%lld\n", a, b, p, ret);
//	return 0;
//}

static bool arr[100000005];

int main()
{
	int n = 0;
	scanf("%d", &n);
	arr[1] = 1;
	int i = 2;
	for (i = 2; i * i <= n; i++)
	{
		if (!arr[i])
		{
			//把它的倍数给1
			int j = i * i;
			for (j = i * i; j <= n; j += i)
			{
				arr[j] = 1;
			}
		}
	}
	int ret = 0;
	for (i = 1; i <= n; i++)
	{
		if (arr[i] == 0)
		{
			ret++;
		}
	}
	cout << ret << endl;
	return 0;
}