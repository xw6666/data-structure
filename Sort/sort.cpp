#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>

//打印vector元素
template <class T>
void print_vector(vector<T>& v)
{
	for (T i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}

//冒泡排序
template <class T>
void bubble_sort(vector<T>& v)
{
	for (decltype(v.size())i = 0; i < v.size() - 1; i++)
	{
		bool flag = true;
		for (decltype(v.size())j = 0; j < v.size() - i - 1; j++)
		{
			//比较
			if (v[j] > v[j + 1])
			{
				T temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
				flag = false;
			}
		}

		if (flag == true)
		{
			break;
		}
	}
}

//选择排序
void selec_sort(vector<int>& v)
{
	for (decltype(v.size())i = 0; i < v.size() - 1; i++)
	{
		int min_index = i;
		decltype(v.size())j = 0;
		for (j = i + 1; j < v.size(); j++)
		{
			//从i+1开始遍历找最小值放在i处
			if (v[j] < v[min_index])
			{
				min_index = j;
			}
		}
		//最小值下标为j
		//交换
		int temp = v[i];
		v[i] = v[min_index];
		v[min_index] = temp;
	}
}

//插入排序
//时间复杂度:最好的情况O(n),最坏的情况O(n^2)
void insert_sort(vector<int>& v)
{
	int i = 1;
	while (i < v.size())
	{
		int j = i - 1;
		while(j >= 0 && v[j] > v[i])
		{
			//找到移位点，如果前面的大于后面的就要移动
			j--;
		}
		
		//j+1到i-1需要移动
		//移动 - 向后移动
		//存储i处的值
		int temp = v[i];
		int k = i - 1;
		while (k >= j + 1)
		{
			v[k + 1] = v[k];
			k--;
		}
		//在j+1处放入temp
		v[j + 1] = temp;
		i++;
	}
}


//希尔排序:时间复杂度：O(n^(3/2))
void shell_sort(vector<int>& ivec)
{
	int increment = ivec.size();
	do
	{
		increment = increment / 3 + 1;
		for (int i = increment; i < ivec.size(); i++)
		{
			int temp = ivec[i];
			int j = i;
			while (j >= increment && ivec[j] > ivec[i])
			{
				ivec[j] = ivec[j - increment];
				j = j - increment;
			}
			ivec[j] = temp;
		}
	} while (increment != 1);
}

//堆排序：时间复杂度：O(nlogn)
void _heap_adjust(vector<int>& ivec, int index, int size)
{
	int temp = ivec[index];
	//遍历左节点
	for (int i = index * 2 + 1; i < size; i = i * 2 + 1)
	{
		if (i < size - 1 && ivec[i] < ivec[i + 1])
		{
			//如果存在右儿子且右儿子大于i所在的左儿子
			i++;
		}

		if(temp < ivec[i])
		{
			//父亲结点更小
			ivec[index] = ivec[i];
			ivec[i] = temp;
			index = i;
			temp = ivec[index];
		}
	}
}
void heap_sort(vector<int>& ivec)
{
	//首先先创建堆 - 调整每个有儿子的结点
	for (int i = ivec.size() / 2 - 1; i >= 0; i--)
	{
		_heap_adjust(ivec, i, ivec.size());
		//print_vector(ivec);
	}
	//开始排序
	for (int i = ivec.size() - 1; i >= 0; i--)
	{
		//每次把堆顶的元素拿到数组最后面，之后减少堆的一个元素再调整堆
		//交换
		int temp = ivec[0];
		ivec[0] = ivec[i];
		ivec[i] = temp;
		//调整堆
		_heap_adjust(ivec, 0, i);
	}
}

//快速排序
void quick_sort(vector<int>& ivec, int begin, int end)
{
	//排序区间为[begin,end]
	if (begin >= end)
	{
		return;
	}
	int temp = ivec[begin];
	int i = begin;
	int j = end;
	while (i != j)
	{
		//j先找比基准小的数
		while (ivec[j] >= temp && i < j)
		{
			j--;
		}
		while (ivec[i] <= temp && i < j)
		{
			i++;
		}

		if (i < j)
		{
			//交换
			int t = ivec[i];
			ivec[i] = ivec[j];
			ivec[j] = t;
		}
	}
	//到这里j == i
	int flag = 1;
	if (i == begin)
	{
		flag = 0;
	}
	ivec[begin] = ivec[i];
	ivec[i] = temp;
	if (flag == 1)
	{
		print_vector(ivec);
	}
	quick_sort(ivec, begin, i - 1);
	quick_sort(ivec, i + 1, ivec.size() - 1);

}

int main()
{
	vector<int> ivec{ 45 ,53,18,36,72,30,48,93,15,36 };
	//bubble_sort(ivec);
	//selec_sort(ivec);
	//insert_sort(ivec);
	//shell_sort(ivec);
	//heap_sort(ivec);
	quick_sort(ivec, 0, ivec.size() - 1);
	print_vector(ivec);
	return 0;
}

