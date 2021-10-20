//#include <iostream>
//using namespace std;
//
//#define MAX_ADD 18
//#define MOD 16
//
//class HashTable
//{
//public:
//	//���캯��
//	HashTable();
//	//��ϣ����
//	int hashFunc(int k);
//	//����
//	void insert(int x);
//	//���Ҳ����ص�ַ�����رȽϴ���
//	int find(int x, int& time);
//
//private:
//	pair<int, bool> data[MAX_ADD];  //��һ���������ڴ�����ݣ��ڶ�������ʶ
//};
//
//int HashTable::hashFunc(int k)
//{
//	return k % MOD;
//}
//
//HashTable::HashTable()
//{
//	for (int i = 0; i < MAX_ADD; i++)
//	{
//		this->data[i].second = false;
//	}
//}
//
//void HashTable::insert(int x)
//{
//	int add = x % MOD;
//	if (data[add].second == false)
//	{
//		data[add].first = x;
//		data[add].second = true;
//	}
//	else
//	{
//		//�ҵ���һ����ַ,��temp + 1��ʼ��
//		int flag = 1;
//		for (int i = add + 1; i < MAX_ADD; i++)
//		{
//			if (data[i].second == false)
//			{
//				data[i].first = x;
//				data[i].second = true;
//				flag = 0;
//				break;
//			}
//		}
//
//		if (flag == 1)
//		{
//			//˵��û���ҵ���λ
//			for (int i = 0; i < add; i++)
//			{
//				if (data[i].second == false)
//				{
//					data[i].first = x;
//					data[i].second = true;
//					flag = 0;
//					break;
//				}
//			}
//		}
//
//	}
//}
//
//int HashTable::find(int x, int& time)
//{
//	int add = this->hashFunc(x);
//	if (this->data[add].first == x && this->data[add].second == true)  //������λ����Ŀ��Ԫ��
//	{
//		time = 1;
//		return add;
//	}
//	else if(this->data[add].second == true)  //������λ����Ԫ�ص�����Ŀ��Ԫ��
//	{
//		//����Ѱ��
//		time = 1;
//		for (int i = add + 1; i < MAX_ADD; i++)
//		{
//			time++;
//			if (this->data[i].first == x && this->data[i].second == true)
//			{
//				//�ҵ���
//				return i;
//			}
//		}
//
//		for (int i = 0; i < add; i++)
//		{
//			time++;
//			if (this->data[i].first == x && this->data[i].second == true)
//			{
//				//�ҵ���
//				return i;
//			}
//		}
//
//		//û�ҵ�
//		return -1;
//	}
//	else  //���λ��û��Ԫ��
//	{
//		time = 1;
//		return -1;
//	}
//}
//int main()
//{
//	HashTable h;
//	for (int i = 0; i < 11; i++)
//	{
//		int temp = 0;
//		cin >> temp;
//		h.insert(temp);
//	}
//
//	int findx = 0;
//	cin >> findx;
//	int time = 0;
//	int add = h.find(findx, time);
//
//	cout << add << " " << time << endl;
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//#include <string>
//int a[18] = { 0 };
////�������� 
//
////ɢ�б���
//int my_hash(int key)
//{
//	return key % 16;
//}
//
////��ͻ��ʱ��
//int newhash(int k)
//{
//	return (k + 1) % 18;
//}
////����
//int insert(int key)
//{
//	int k = my_hash(key);
//	while (a[k] != 0)
//	{
//		k = newhash(k);
//	}
//	a[k] = key;
//	return 1;
//}
////���� 
//int insearch(int key, int& index, int& count)
//{
//	int k = my_hash(key);
//	count = 1;
//	if (a[k] == 0)
//	{
//		index = -1;
//		return -1;
//	}
//	while (a[k] != key)
//	{
//		count++;
//		k = newhash(k);
//		if (a[k] == key)
//		{
//			index = k;
//			return index;
//		}
//	}
//	index = k;
//	return 0;
//}
//
//int main()
//{
//	for (int i = 0; i < 11; i++)
//	{
//		int temp = 0;
//		cin >> temp;
//		insert(temp);
//	}
//	int index, count = 0;
//	int key = 0;
//	insearch(key, index, count);
//
//
//	cout << index << " " << count << endl;
//	return 0;
//}

#include <iostream>
using namespace std;
#include <string>
int a[18] = { 0 };

//�������� 

////ɢ�б���
int my_hash(int key)
{
	return key % 16;
}

//��ͻ��ʱ��
int newhash(int k)
{
	return (k + 1) % 18;
}
////����
int insert(int key)
{
	int k = my_hash(key);
	while (a[k] != 0)
	{
		k = newhash(k);
	}
	a[k] = key;
	return 1;
}
////���� 
int insearch(int key, int& index, int& count)
{
	int k = my_hash(key);
	count = 1;
	if (a[k] == 0)
	{
		//a[k] == 0��˵��û�в��ҵ�	
		index = -1;
		return 0;
	}

	while (a[k] != 0) {
		count++;
		k = newhash(k);
		if (a[k] == key)
		{
			index = k;
			return 1;
		}
	}

	index = -1;
	return 0;
}



int main()
{
	for (int i = 0; i < 11; i++)
	{
		int temp = 0;
		cin >> temp;
		insert(temp);
	}
	int index, count = 0;
	int key = 0;
	cin >> key;
	insearch(key, index, count);




	cout << index << " " << count << endl;
	return 0;
}
