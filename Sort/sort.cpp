#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>

//��ӡvectorԪ��
template <class T>
void print_vector(vector<T>& v)
{
	for (T i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}

//ð������
template <class T>
void bubble_sort(vector<T>& v)
{
	for (decltype(v.size())i = 0; i < v.size() - 1; i++)
	{
		bool flag = true;
		for (decltype(v.size())j = 0; j < v.size() - i - 1; j++)
		{
			//�Ƚ�
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

//ѡ������
void selec_sort(vector<int>& v)
{
	for (decltype(v.size())i = 0; i < v.size() - 1; i++)
	{
		int min_index = i;
		decltype(v.size())j = 0;
		for (j = i + 1; j < v.size(); j++)
		{
			//��i+1��ʼ��������Сֵ����i��
			if (v[j] < v[min_index])
			{
				min_index = j;
			}
		}
		//��Сֵ�±�Ϊj
		//����
		int temp = v[i];
		v[i] = v[min_index];
		v[min_index] = temp;
	}
}

//��������
//ʱ�临�Ӷ�:��õ����O(n),������O(n^2)
void insert_sort(vector<int>& v)
{
	int i = 1;
	while (i < v.size())
	{
		int j = i - 1;
		while(j >= 0 && v[j] > v[i])
		{
			//�ҵ���λ�㣬���ǰ��Ĵ��ں���ľ�Ҫ�ƶ�
			j--;
		}
		
		//j+1��i-1��Ҫ�ƶ�
		//�ƶ� - ����ƶ�
		//�洢i����ֵ
		int temp = v[i];
		int k = i - 1;
		while (k >= j + 1)
		{
			v[k + 1] = v[k];
			k--;
		}
		//��j+1������temp
		v[j + 1] = temp;
		i++;
	}
}


//ϣ������:ʱ�临�Ӷȣ�O(n^(3/2))
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

//������ʱ�临�Ӷȣ�O(nlogn)
void _heap_adjust(vector<int>& ivec, int index, int size)
{
	int temp = ivec[index];
	//������ڵ�
	for (int i = index * 2 + 1; i < size; i = i * 2 + 1)
	{
		if (i < size - 1 && ivec[i] < ivec[i + 1])
		{
			//��������Ҷ������Ҷ��Ӵ���i���ڵ������
			i++;
		}

		if(temp < ivec[i])
		{
			//���׽���С
			ivec[index] = ivec[i];
			ivec[i] = temp;
			index = i;
			temp = ivec[index];
		}
	}
}
void heap_sort(vector<int>& ivec)
{
	//�����ȴ����� - ����ÿ���ж��ӵĽ��
	for (int i = ivec.size() / 2 - 1; i >= 0; i--)
	{
		_heap_adjust(ivec, i, ivec.size());
		//print_vector(ivec);
	}
	//��ʼ����
	for (int i = ivec.size() - 1; i >= 0; i--)
	{
		//ÿ�ΰѶѶ���Ԫ���õ���������棬֮����ٶѵ�һ��Ԫ���ٵ�����
		//����
		int temp = ivec[0];
		ivec[0] = ivec[i];
		ivec[i] = temp;
		//������
		_heap_adjust(ivec, 0, i);
	}
}

//��������
void quick_sort(vector<int>& ivec, int begin, int end)
{
	//��������Ϊ[begin,end]
	if (begin >= end)
	{
		return;
	}
	int temp = ivec[begin];
	int i = begin;
	int j = end;
	while (i != j)
	{
		//j���ұȻ�׼С����
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
			//����
			int t = ivec[i];
			ivec[i] = ivec[j];
			ivec[j] = t;
		}
	}
	//������j == i
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

