#include <bits/stdc++.h>
using namespace std;

void binary_search(vector<int>& nums, int t)
{
	int l = 0;
	int r = nums.size() - 1;
	while (l <r)
	{
		int mid = (l + r + 1) >> 1;
		if(nums[mid] <= t)
		{
			l= mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	if(nums[l] != t)
	{
		cout << "-1 -1" << endl;
	}
	else
	{
		cout << l << " ";
		l = 0;
		r = nums.size() - 1;
		while(l < r)
		{
			int mid = (l + r) >> 1;
			if(nums[mid] < t)
			{
				l = mid + 1;
			}
			else
			{
				r = mid;
			}
		}
		cout << l << endl;
	}
}

int main()
{
	vector<int> nums = {1,1,1,2,2,3,4,5,6,6,7,8,9};
	while(3)
	{
		int t = 0;
		cin >> t;
		binary_search(nums,t);
	}
	return 0;
}
