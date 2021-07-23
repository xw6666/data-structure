#define _CRT_SECURE_NO_WARNINGS 1

//leetcode - 223. 矩形面积
//int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
//    int a = ax2 - ax1;
//    int b = ay2 - ay1;
//    int c = bx2 - bx1;
//    int d = by2 - by1;
//    int l = fmax(0, fmin(ay2, by2) - fmax(ay1, by1));
//    int e = fmax(0, fmin(ax2, bx2) - fmax(ax1, bx1));
//
//    return a * b + c * d - l * e;
//}

//leetcode - 836. 矩形重叠
//bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size) {
//    if (fmin(rec1[3], rec2[3]) - fmax(rec1[1], rec2[1]) > 0 && fmin(rec1[2], rec2[2]) - fmax(rec1[0], rec2[0]) > 0)
//    {
//        return true;
//    }
//
//    return false;
//}

//leetcode - 701. 二叉搜索树中的插入操作
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//
//typedef struct TreeNode Node;
//struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
//    if (root == NULL)
//    {
//        root = (Node*)malloc(sizeof(Node));
//        root->left = NULL;
//        root->right = NULL;
//        root->val = val;
//        return root;
//    }
//    if (val < root->val)
//    {
//        //插在左边
//        root->left = insertIntoBST(root->left, val);
//    }
//    else if (val > root->val)
//    {
//        root->right = insertIntoBST(root->right, val);
//    }
//
//    return root;
//}