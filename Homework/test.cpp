#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
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

//static bool nums[100000005];
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	nums[1] = 1;
//	int i = 0;
//	int j = 0;
//	for (i = 2; i * i <= n; i++)
//	{
//		if (nums[i] == 0)
//		{
//			//如果是素数
//			for (j = i * i; j <= n; j += i)
//			{
//				//把它的倍数全部变成合数
//				nums[j] = 1;
//			}
//		}
//	}
//	int ans = 0;
//	for (i = 2; i <= n; i++)
//	{
//		if (nums[i] == 0)
//		{
//			ans++;
//		}
//	}
//	printf("%d\n", ans);
//	return 0;
//}


//struct C
//{
//	int a;
//	int value;
//	double s;
//};
//
//int cmp(const void* e1, const void* e2)
//{
//	return (((C*)e2)->s - ((C*)e1)->s);
//}
//
//int main()
//{
//	int m = 0, n = 0;
//	scanf("%d%d", &m, &n);
//	C* arr = new C[n];
//	int i = 0;
//	while (n--)
//	{
//		//读入n组数据
//		scanf("%d%d", &arr[i].a, &arr[i].value);
//		arr[i].s = double(arr[i].a) / (arr[i].value);
//		i++;
//	}
//
//	qsort(arr, i, sizeof(arr[0]), cmp);
//
//	double ret = 0.0;
//	int j = 0;
//	while (j < i)
//	{
//		if (arr[j].value <= m)
//		{
//			ret += (arr[j].a);
//			m -= (arr[j].value);
//		}
//		else
//		{
//			ret += ((arr[j].s) * m);
//			break;
//		}
//		j++;
//	}
//	printf("%lf\n", ret);
//	delete[] arr; 
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	cin >> n;
//	while (n--)
//	{
//		int arr[410] = { 0 };
//		int m = 0;
//		cin >> m;
//		for (int i = 0; i < m; i++)
//		{
//			int begin = 0;
//			int end = 0;
//			cin >> begin >> end;
//			if (end < begin)
//			{
//				int temp = end;
//				end = begin;
//				begin = temp;
//			}
//			while (begin <= end)
//			{
//				arr[begin] = arr[begin] + 1;
//				begin++;
//			}
//		}
//
//		int max = -1;
//		for (int j = 0; j < 410; j++)
//		{
//			if (arr[j] > max)
//			{
//				max = arr[j];
//			}
//		}
//		cout << max * 10 << endl;
//	}
//	return 0;
//}

//输出删除n个数字后剩下的数字构成最大的数
//int main()
//{
//	char str[241] = { 0 };
//	int n = 0;
//	cin >> str >> n;
//	int len = strlen(str);
//
//	char ans[241] = { 0 };
//
//	while (n--)
//	{
//		int index = -1;
//		int flag = 1;
//		for (int i = 1; i < len - 1; i++)
//		{
//			if (str[i] > str[i - 1] && str[i] < str[i + 1])
//			{
//				flag = 0;
//				index = i;
//				break;
//			}
//		}
//
//		if (flag == 0)
//		{
//			//删除index
//			int j = 0;
//			for (int i = 0; i < len; i++)
//			{
//				if (i == index)
//				{
//					continue;
//				}
//				ans[j++] = str[i];
//			}
//			ans[j++] = '\0';
//		}
//		else
//		{
//			//删除最大数
//			char max = '0' - 1;
//			for (int i = 0; i < len; i++)
//			{
//				if (str[i] > max)
//				{
//					max = str[i];
//					index = i;
//				}
//			}
//			int j = 0;
//			//最大下标在index
//			for (int i = 0; i < len; i++)
//			{
//				if (i == index)
//				{
//					continue;
//				}
//				ans[j++] = str[i];
//			}
//			ans[j++] = '\0';
//		}
//		for (int i = 0; i < 241; i++)
//		{
//			str[i] = ans[i];
//		}
//		len--;
//	}
//	
//	cout << str << endl;
//
//	return 0;
//}


//P1223
//int main()
//{
//	int n = 0;
//	cin >> n;
//	multimap<int, int> m;
//	int temp = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		m.insert(make_pair(temp, i + 1));
//	}
//
//	for (auto i : m)
//	{
//		cout << i.second << " ";
//	}
//
//	cout << endl;
//	double ans = 0.0;
//	auto i = m.begin();
//	i++;
//	for (; i != m.end(); i++)
//	{
//		auto j = i;
//		j--;
//		for (; j != m.begin(); j--)
//		{
//			ans += ((*j).first);
//		}
//		//加上begin处
//		ans += ((*j).first);
//	}
//	ans = ans / n;
//	printf("%.2lf\n", ans);
//	return 0;
//}

//p1478
//struct apple
//{
//	int height;
//	int value;
//};
//
//int cmp(const void* e1, const void* e2)
//{
//	return (((apple*)e1)->value - ((apple*)e2)->value);
//}
//
//int main()
//{
//	int n = 0, s = 0;
//	cin >> n >> s;
//	int a = 0;
//	int b = 0;
//	cin >> a >> b;
//	int height = a + b;
//	apple* v = new apple[n];
//	int j = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a >> b;
//		if (height >= a)
//		{
//			//身高比苹果高
//			apple t = { a,b };
//			v[j++] = t;
//		}
//	}
//	
//	qsort(v, j, sizeof(apple), cmp);
//	int ans = 0;
//	for (int i = 0; i < j; i++)
//	{
//		if (s >= v[i].value)
//		{
//			ans++;
//			s -= (v[i].value);
//		}
//		else
//		{
//			break;
//		}
//	}
//
//	cout << ans << endl;
//
//	return 0;
//}

//int cmp(const void* e1, const void* e2)
//{
//	return ((*(int*)e1) - (*(int*)e2));
//}
//
//int main()
//{
//	int n = 0, m = 0;
//	cin >> n >> m;
//	
//	int ans = 0;
//	int temp = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int a = 0;
//		cin >> a;
//		if (temp + a > m)
//		{
//			ans++;
//			temp = a;
//		}
//		else
//		{
//			temp += a;
//		}
//	}
//	cout << ans + 1 << endl;
//	return 0;
//}


//int main()
//{
//	int n = 0, m = 0;
//	cin >> n >> m;
//	int* arr = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	
//	return 0;
//}

//double a, b, c, d;
//double f(double x)
//{
//	return (a * pow(x, 3) + b * pow(x, 2) + c * x + d);
//}
//
//int main()
//{
//	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
//	int ret = 0;
//	for (int i = -100; i < 100; i++)
//	{
//		double x1 = f(i);
//		if (x1 == 0)
//		{
//			printf("%.2lf ", (double)i);
//			ret++;
//			if (ret == 3)
//			{
//				break;
//			}
//		}
//		else
//		{
//			double x2 = f((double)i + 1);
//			if (x1 * x2 < 0)
//			{
//				double l = i;
//				double r = (double)i + 1;
//				while ((r - l) > 1e-4)
//				{
//					double mid = (l + r) / 2;
//					if (f(mid) * f(l) <= 0)
//					{
//						r = mid;
//					}
//					else
//					{
//						l = mid;
//					}
//				}
//				printf("%.2lf ", l);
//				ret++;
//				if (ret == 3)
//				{
//					break;
//				}
//			}
//		}
//	}
//	return 0;
//}
//long long power(long long a, long long b, long long p)
//{
//	long long ans = 1;
//	while (b)
//	{
//		if (b % 2 == 1)
//		{
//			ans = ans * a % p;
//		}
//		a = a * a % p;
//		b /= 2;
//	}
//
//	return ans;
//}
//
//int main()
//{
//	long long a, b, p;
//	cin >> a >> b >> p;
//	printf("%lld^%lld mod %lld=%lld", a, b, p, power(a, b, p));
//	return 0;
//}

//int check(int* arr, int size, int max)
//{
//	int time = 0;
//	int temp = 0;
//	for (int i = 0; i < size; i++)
//	{
//		if (temp + arr[i] > max)
//		{
//			time++;
//			temp = arr[i];
//		}
//		else
//		{
//			temp += arr[i];
//		}
//	}
//	return (++time);
//}
//
//int main()
//{
//	int n = 0, m = 0;
//	cin >> n >> m;
//	int* arr = new int[n];
//	//cout << INT_MIN << endl;
//	int max = -2147483648;
//	int sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//		sum += arr[i];
//		max = (arr[i] > max ? arr[i] : max);
//	}
//
//	int l = max;
//	int r = sum;
//	while (l <= r)
//	{
//		int mid = ((l + r) >> 1);
//		if (check(arr, n, mid) <= m)
//		{
//			r = mid - 1;
//		}
//		else
//		{
//			l = mid + 1;
//		}
//	}
//	cout << l << endl;
//	delete[]arr;
//	return 0;
//}

//输入n个数，判断能否加成k
//思路：对于每个数ai，我们可以选择加给sum或者不加给sum两种情况，使用dfs

//int arr[1000];
//int n, k;
//
////该函数作用判断ai到an-1能不能加成k
//bool dfs(int i, int sum)
//{
//	if (i == n)
//	{
//		return sum == k;
//	}
//	if (dfs(i + 1, sum + arr[i]))
//	{
//		return true;
//	}
//	if (dfs(i + 1, sum))
//	{
//		return true;
//	}
//	return false;
//}
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	cin >> k;
//	int i = 0;
//	int sum = 0;
//	if (dfs(i, sum))
//	{
//		cout << "yes" << endl;
//	}
//	else
//	{
//		cout << "no" << endl;
//	}
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	int len = 0;
//	int size = 0;
//	scanf("%d", &n);
//	while (n--)
//	{
//		//cin >> len >> size;
//		scanf("%d%d", &len, &size);
//		int* arr = new int[size];
//		int i = 0;
//		for (i = 0; i < size; i++)
//		{
//			scanf("%d", &arr[i]);
//		}
//		int minT = -2147483648;
//		int maxT = -2147483648;
//		for (i = 0; i < size; i++)
//		{
//			int min = fmin(arr[i], len - arr[i]);
//			if (min > minT)
//			{
//				minT = min;
//			}
//			int max = fmax(arr[i], len - arr[i]);
//			if (max > maxT)
//			{
//				maxT = max;
//			}
//		}
//		cout << minT << " " << maxT << endl;
//		delete[] arr;
//	}
//	return 0;
//}

//void dfs(vector< vector<char> >& v, int x, int y)
//{
//	if (v[x][y] == 'W')
//	{
//		v[x][y] = '.';
//		//八个维度dfs
//		//对边界进行特判
//		int i = 0;
//		for (i = x - 1; i <= x + 1; i++)
//		{
//			int j = 0;
//			for (j = y - 1; j <= y + 1; j++)
//			{
//				if (i >= 0 && i < v.size() && j >= 0 && j < v[i].size())
//				{
//					if ((i != x) || (j != y))
//					{
//						dfs(v, i, j);
//					}
//				}
//			}
//		}
//	}
//}
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d%d", &n, &m);
//	vector< vector<char> > v;
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		vector<char> temp;
//		int j = 0;
//		char t = 0;
//		for (j = 0; j < m; j++)
//		{
//			scanf(" %c", &t);
//			temp.push_back(t);
//		}
//		v.push_back(temp);
//	}
//
//	int ans = 0;
//	for (i = 0; i < v.size(); i++)
//	{
//		int j = 0;
//		for (j = 0; j < v[i].size(); j++)
//		{
//			if (v[i][j] == 'W')
//			{
//				dfs(v, i, j);
//				ans++;
//			}
//		}
//	}
//
//	printf("%d\n", ans);
//	return 0;
//}

//poj2386
void dfs(vector<vector<char> >& v, int x, int y)
{
	if (v[x][y] == 'W')
	{
		v[x][y] = '.';
		for (int i = x - 1; i <= x + 1; i++)
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (i >= 0 && i < v.size() && j >= 0 && j < v[i].size() && (i != x || j != y))
				{
					dfs(v, i, j);
				}
			}
		}
	}
}
int main()
{
	int n = 0;
	int m = 0;
	cin >> n >> m;
	vector<vector<char> > v;
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		vector<char> temp;
		char t = 0;
		for (j = 0; j < m; j++)
		{
			cin >> t;
			temp.push_back(t);
		}
		v.push_back(temp);
	}
	int ans = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (v[i][j] == 'W')
			{
				dfs(v, i, j);
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}