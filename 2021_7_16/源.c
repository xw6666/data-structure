#define _CRT_SECURE_NO_WARNINGS 1
//404. ×óÒ¶×ÓÖ®ºÍ
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