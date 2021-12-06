#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cassert>

typedef struct HFNode
{
	int val;
	struct HFNode* left;
	struct HFNode* right;
	struct HFNode* next;
}HFNode;

HFNode* GetNewNode(int val)
{
	HFNode* newNode = (HFNode*)malloc(sizeof(HFNode));
	if (newNode == NULL)
	{
		cout << "Malloc failed!" << endl;
		exit(-1);
	}
	newNode->next = NULL;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->val = val;
	return newNode;
}

HFNode* CreateLL(vector<int>& ivec)
{
	HFNode* head = GetNewNode(0);
	for (int i = ivec.size() - 1; i >= 0; i--)
	{
		//头插
		HFNode* newNode = GetNewNode(ivec[i]);
		newNode->next = head->next;
		head->next = newNode;
	}
	return head;
}

HFNode* CreateTree(HFNode* head)
{
	assert(head);
	HFNode* cur = head->next;
	while (cur && cur->next)
	{
		if (cur->val <= cur->next->val)
		{
			//升序直接合并
			HFNode* newNode = GetNewNode(cur->val + cur->next->val);
			newNode->next = cur->next->next;
			newNode->left = cur;
			newNode->right = cur->next;
			head->next = newNode;
			cur = newNode;
		}
		else
		{
			//降序
			//1.cur后面有两个及以上节点
			//2.cur后面只有一个节点了
			if (cur->next->next)
			{
				//合并cur->next和cur->next->next
				HFNode* newNode = GetNewNode(cur->next->val + cur->next->next->val);
				newNode->next = cur->next->next->next;
				newNode->left = cur->next;
				newNode->right = cur->next->next;
				cur->next = newNode;
			}
			else
			{
				//直接合并cur和cur->next然后跳出循环
				HFNode* newNode = GetNewNode(cur->val + cur->next->val);
				newNode->next = cur->next->next;
				newNode->left = cur;
				newNode->right = cur->next;
				head->next = newNode;
				cur = newNode;
			}
		}
	}
	return head;
}

int i = 0;
void dfs(HFNode* prev, HFNode* head, char* ans, int findx)
{
	if (head == NULL)
	{
		if (i > 0)
		{
			ans[--i] = 0;
		}
		return;
	}
	if (findx == head->val && head->right == NULL && head->left == NULL)
	{
		cout << ans << endl;
		ans[--i] = 0;
		//删除head
		if (prev->next == head)
		{
			free(head);
			prev->next = NULL;
		}
		else if (prev->left == head)
		{
			free(head);
			prev->left = NULL;
		}
		else
		{
			free(head);
			prev->right = NULL;
		}
		return;
	}
	ans[i++] = '0';
	dfs(head, head->right, ans, findx);
	ans[i++] = '1';
	dfs(head, head->left, ans, findx);
	if (i > 0)
	{
		ans[--i] = 0;
	}
}

int main()
{
	int n = 0;
	cin >> n;
	vector<int> ivec;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		ivec.push_back(temp);
	}

	//数组排序
	vector<int> ivec1 = ivec;
	sort(ivec.begin(), ivec.end());
	
	HFNode* head = CreateLL(ivec);
	head = CreateTree(head);
	
	char ans[100] = { 0 };
	for (int i = 0; i < ivec1.size(); i++)
	{
		dfs(head, head->next, ans, ivec1[i]);
	}

	return 0;
}