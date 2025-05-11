/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int stopAt;
    int in(TreeNode* root) {
        if (root == NULL)
            return -1;
        int left = in(root->left);
        if (left != -1)
            return left;
        stopAt--;
        if (!stopAt)
            return root->val;
        int right = in(root->right);
        if (right != -1)
            return right;
        return max(left, right);
    }
    int kthSmallest(TreeNode* root, int k) {
        stopAt = k;
        return in(root);
        // return got;
    }
};