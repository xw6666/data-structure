#define _CRT_SECURE_NO_WARNINGS 1
//404. 左叶子之和
//void LeftLeafSum(struct TreeNode* root, int* count)
//{
//    if (root == NULL)
//    {
//        return;
//    }
//    if (root->left && root->left->left == NULL && root->left->right == NULL)
//    {
//        *count = *count + root->left->val;
//    }
//    LeftLeafSum(root->left, count);
//    LeftLeafSum(root->right, count);
//}
//
//int Order(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return 0;
//    }
//    return Order(root->left) + Order(root->right) + 1;
//}

//leetcode - 33. 搜索旋转排序数组
//暴力查找
//int search(int* nums, int numsSize, int target) {
//    //O(n)暴力破解
//    int i = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == target)
//        {
//            return i;
//        }
//    }
//
//    return -1;
//}
//二分查找
//int midSearch(int* nums, int left, int right, int target)
//{
//    while (left < right)
//    {
//        int mid = left + ((right - left) >> 1);
//        if (nums[mid] < target)
//        {
//            left = mid + 1;
//        }
//        else if (nums[mid] > target)
//        {
//            right = mid;
//        }
//        else
//        {
//            return mid;
//        }
//    }
//    return -1;
//}
//
//int search(int* nums, int numsSize, int target) {
//    if (numsSize == 1)
//    {
//        if (nums[0] == target)
//        {
//            return 0;
//        }
//        else
//        {
//            return -1;
//        }
//    }
//
//    int i = 0;
//    while (i < numsSize - 1 && nums[i] < nums[i + 1])
//    {
//        i++;
//    }
//
//    //二分查找
//    int ret = midSearch(nums, 0, i + 1, target);
//    if (ret == -1)
//    {
//        ret = midSearch(nums, i + 1, numsSize, target);
//    }
//    else
//    {
//        return ret;
//    }
//
//    if (ret == -1)
//    {
//        return -1;
//    }
//
//    return ret;
//}

//leetcode - 41. 缺失的第一个正数
//int firstMissingPositive(int* nums, int numsSize) {
//    //哈希表
//    int hash[numsSize];
//    int i = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        hash[i] = 0;
//    }
//
//    for (i = 0; i < numsSize; i++)
//    {
//        if (nums[i] >= 1 && nums[i] <= numsSize)
//        {
//            hash[nums[i] - 1] = hash[nums[i] - 1] + 1;
//        }
//        // for(int j = 0;j < numsSize;j++)
//        // {
//        //     printf("%d ",hash[j]);
//        // }
//        // printf("\n");
//    }
//
//    for (i = 0; i < numsSize; i++)
//    {
//        if (hash[i] == 0)
//        {
//            break;
//        }
//        // printf("%d ",hash[i]);
//    }
//
//    return i + 1;
//
//}