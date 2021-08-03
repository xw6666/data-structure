#define _CRT_SECURE_NO_WARNINGS 1
//leetcode - 581. 最短无序连续子数组
//int cmp(const void* e1, const void* e2)
//{
//    return ((*((int*)e1)) - (*((int*)e2)));
//}
//
//int findUnsortedSubarray(int* nums, int numsSize) {
//    int* nums1 = (int*)malloc(sizeof(int) * numsSize);
//    for (int i = 0; i < numsSize; i++)
//    {
//        nums1[i] = nums[i];
//    }
//
//    qsort(nums1, numsSize, sizeof(int), cmp);
//    int left = 0;
//    int right = numsSize - 1;
//    while ((left < right) && (nums1[left] == nums[left] || nums1[right] == nums[right]))
//    {
//        if (nums1[left] == nums[left])
//        {
//            left++;
//        }
//        if (nums1[right] == nums[right])
//        {
//            right--;
//        }
//    }
//
//    if (left < right)
//    {
//        return right - left + 1;
//    }
//
//    return 0;
//}
