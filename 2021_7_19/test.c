#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//leetcode - 98. ÑéÖ¤¶þ²æËÑË÷Ê÷
//bool PrevOrder1(int val, struct TreeNode* node)
//{
//    if (node == NULL)
//    {
//        return true;
//    }
//
//    if (val >= node->val)
//    {
//        return false;
//    }
//    return PrevOrder1(val, node->left) && PrevOrder1(val, node->right);
//}
//
//bool PrevOrder2(int val, struct TreeNode* node)
//{
//    if (node == NULL)
//    {
//        return true;
//    }
//
//    if (val <= node->val)
//    {
//        return false;
//    }
//    return PrevOrder2(val, node->left) && PrevOrder2(val, node->right);
//}
//
//bool _isLarger(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return true;
//    }
//
//    return PrevOrder1(root->val, root->right);
//}
//
//bool _isSmller(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return true;
//    }
//
//    return PrevOrder2(root->val, root->left);
//}
//
//
//bool isValidBST(struct TreeNode* root) {
//    if (root == NULL)
//    {
//        return true;
//    }
//
//    if (!_isLarger(root) || !_isSmller(root))
//    {
//        return false;
//    }
//
//    return isValidBST(root->left) && isValidBST(root->right);
//
//}
//long long prev = LLONG_MIN;
//bool isValid(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return true;
//    }
//    if (!isValid(root->left))
//    {
//        return false;
//    }
//    if (prev >= root->val)
//    {
//        return false;
//    }
//    prev = root->val;
//
//    return isValid(root->right);
//}
//
//bool isValidBST(struct TreeNode* root) {
//
//    bool res = isValid(root);
//    prev = LLONG_MIN;
//
//    return res;
//}
