#define _CRT_SECURE_NO_WARNINGS 1
//leetcode - 112. ·���ܺ�
//bool hasPathSum(struct TreeNode* root, int targetSum) {
//	if (root == NULL)
//	{
//		return false;
//	}
//
//	if (root->left == NULL && root->right == NULL)
//	{
//		return targetSum == root->val;
//	}
//
//	return (hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val));
//}